#ifndef BIOLOGY_DNA_GENE_HPP_INCLUDED
#define BIOLOGY_DNA_GENE_HPP_INCLUDED

#include "boost/variant.hpp"

#include "chemistry/general/molecules/normal_molecule.hpp"

#include <cstdint>
#include <vector>

using namespace std;

namespace msci
{
	typedef boost::variant<vector<uint8_t>,vector<uint16_t>,vector<uint32_t>> vector_nitrogenous_bases;
	typedef int gen_index_type;

	class gene
	{
		public:
			gene();
			explicit gene(vector_nitrogenous_bases,const string&);
			explicit gene(const string&,const string&);

			inline int get_bases() const
			{
				return 1;
				//return bases;
			}

			inline int number_of_bases() const
			{
				return 1;
				//return bases.size();
			}

			//molecule operator[](int) const;

			void switch_base(gen_index_type,uint8_t);
			void insert_base(gen_index_type,uint8_t);
			void remove_base(gen_index_type);

			//vector<protein> get_codons_proteins() const;

		private:
			//vector_nitrogenous_bases bases;
			string name;
	};
}

#endif // BIOLOGY_DNA_GENE_HPP_INCLUDED
