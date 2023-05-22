#ifndef MSCI_UNITS_UTIL_MATRIX_HPP_INCLUDED
#define MSCI_UNITS_UTIL_MATRIX_HPP_INCLUDED

#include "msci/units/units/scalar_unit.hpp"

#include <iostream>
#include <sstream>
#include <stdexcept>
#include <vector>

using namespace std;

namespace msci
{
	template<typename T, int M, int N>
	class matrix
	{
		public:
			matrix() : data(vector<vector<T>>(M, vector<T>(N)))
			{
			}

			matrix(initializer_list<vector<T>> x) : matrix()
			{
				if(x.size() != M)
				{
					return;
				}
				for(const auto& column : x)
				{
					if(column.size() != N)
					{
						return;
					}
				}
				int i = 0;
				for(const auto& column : x)
				{
					for(int j = 0; j < N; j++)
					{
						data[i][j] = column[j];
					}
					i++;
				}
			}

			virtual matrix<T, M, N>* clone() const
			{
				return new matrix<T, M, N>(static_cast<const matrix<T, M, N>&>(*this));
			}

			inline int row_size() const
			{
				return M;
			}

			inline int column_size() const
			{
				return N;
			}

			matrix<T,1,N> row(int i) const
			{
				if (outside_row_limits(i))
				{
					return;
				}
				matrix<T,1,N> x = matrix<T,1,N>();
				for (int j = 0; j < N; j++)
				{
					x(1,j + 1) = data[i - 1][j];
				}
				return move(x);
			}

			matrix<T,M,1> column(int j) const
			{
				if (outside_column_limits(j))
				{
					return;
				}
				matrix<T,M,1> x = matrix<T,M,1>();
				for (int i = 0; i < M; i++)
				{
					x(i + 1,1) = data[i][j - 1];
				}
				return move(x);
			}

			const T& operator()(int i, int j) const
			{
				if (outside_limits(i,j))
				{
					return;
				}
				return data[i - 1][j - 1];
			}

			T& operator()(int i, int j)
			{
				if (outside_limits(i,j))
				{
					return;
				}
				return data[i - 1][j - 1];
			}

			matrix<T, M, N> operator +(const matrix<T, M, N>& x)
			{
				matrix<T, M, N> y = *clone();
				y += x;
				return move(y);
			}

			matrix<T, M, N> operator -(const matrix<T, M, N>& x)
			{
				matrix<T, M, N> y = *clone();
				y -= x;
				return move(y);
			}

			template<int N2>
			matrix<T, N, N2> operator *(const matrix<T, N, N2>& x)
			{
				matrix<T, N, N2> new_matrix = matrix<T, N, N2>();
				for(int i = 0; i < M; i++)
				{
					for(int j = 0; j < N2; j++)
					{
						T a = 0;
						for(int k = 0; k < N; k++)
						{
							a += data[i][k] * x(k + 1,j + 1);
						}
						new_matrix(i + 1,j + 1) = a;
					}
				}
				return move(new_matrix);
			}

			template<typename U, typename = typename enable_if<is_integer_number<T>::value>::type>
			matrix<T, M, N> operator ^(U x)
			{
				matrix<T, M, N> y = *clone();
				y ^= x;
				return move(y);
			}

			void operator +=(const matrix<T, M, N>& x)
			{
				for(int i = 0; i < M; i++)
				{
					for(int j = 0; j < N; j++)
					{
						data[i][j] += x(i + 1,j + 1);
					}
				}
			}

			void operator -=(const matrix<T, M, N>& x)
			{
				for(int i = 0; i < M; i++)
				{
					for(int j = 0; j < N; j++)
					{
						data[i][j] -= x(i + 1,j + 1);
					}
				}
			}

			template<typename U, typename = typename enable_if<is_integer_number<T>::value>::type>
			void operator ^=(U x)
			{
				matrix<T,M,N> new_data = *clone();
				for(int i = 2; i <= x; i++)
				{
					new_data = (new_data * (*this));
				}
				for (int i = 0; i < M; i++)
				{
					for (int j = 0; j < N; j++)
					{
						data[i][j] = new_data(i + 1,j + 1);
					}
				}
			}

			matrix<T, N, M> t() const
			{
				matrix<T, N, M> new_data = matrix<T, N, M>();
				for(int i = 0; i < M; i++)
				{
					for(int j = 0; j < N; j++)
					{
						new_data(j + 1,i + 1) = data[i][j];
					}
				}
				return move(new_data);
			}

			bool is_square() const
			{
				if(M == N)
				{
					return true;
				}
				else
				{
					return false;
				}
			}

			bool is_diagonal() const
			{
				for(int i = 0; i < M; i++)
				{
					for(int j = 0; j < N; j++)
					{
						if(i != j and data[i][j] != 0)
						{
							return false;
						}
					}
				}
				return true;
			}

		private:
			vector<vector<T>> data;

			bool outside_row_limits(int i) const
			{
				if (i < 1 or i > M)
				{
					return true;
				}
				return false;
			}

			bool outside_column_limits(int i) const
			{
				if (i < 1 or i > N)
				{
					return true;
				}
				return false;
			}

			bool outside_limits(int i,int j) const
			{
				if (outside_row_limits(i) or outside_column_limits(j))
				{
					return true;
				}
				return false;
			}
	};
}

template<typename T, int M, int N>
bool operator ==(const msci::matrix<T, M, N>& x,const msci::matrix<T, M, N>& y)
{
	for(int i = 0; i < x.row_size(); i++)
	{
		for(int j = 0; j < x.column_size(); j++)
		{
			if (x(i,j) != y(i,j))
			{
				return false;
			}
		}
	}
	return true;
}

template<typename T, int M, int N>
bool operator !=(const msci::matrix<T, M, N>& x,const msci::matrix<T, M, N>& y)
{
	return !(x == y);
}

template<typename T, int M, int N>
ostream& operator <<(ostream& os, const msci::matrix<T, M, N>& x)
{
	ostringstream output;
	output << "[";
	for(int i = 1; i <= x.row_size(); i++)
	{
		for(int j = 1; j <= x.column_size(); j++)
		{
			output << x(i, j);
			if(j < x.column_size())
			{
				output << ", ";
			}
		}
		if(i < x.row_size())
		{
			output << endl;
		}
	}
	output << "]";
	return os << output.str();
}

#endif // MSCI_UNITS_UTIL_MATRIX_HPP_INCLUDED
