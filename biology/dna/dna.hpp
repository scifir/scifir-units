#ifndef BIOLOGY_DNA_DNA_HPP_INCLUDED
#define BIOLOGY_DNA_DNA_HPP_INCLUDED

#include "chemistry/general/molecules/bit_molecule.hpp"

#include <bitset>
#include <map>
#include <string>
#include <vector>

#include "rapidxml/rapidxml.hpp"

using namespace std;

namespace msci
{
	enum dna_type {natural_dna,extraterrestrial_dna,artificial_dna,ultimate_dna};

	class chromosome;

	class dna : public msci::bit_molecule
	{
		public:
			dna();
			explicit dna(dna_type,const map<string,chromosome>&);
			explicit dna(const string&);

			inline map<string,chromosome> get_cromosomes() const
			{
				return chromosomes;
			}

			inline dna_type get_type() const
			{
				return type;
			}

			inline string get_file_name() const
			{
				return file_name;
			}

			chromosome& operator [](const string&);
			const chromosome& operator [](const string&) const;

			inline bool is_natural_dna() const
			{
				return (type == natural_dna);
			}

			inline bool is_extraterrestrial_dna() const
			{
				return (type == extraterrestrial_dna);
			}

			inline bool is_artificial_dna() const
			{
				return (type == artificial_dna);
			}

			inline bool is_ultimate_dna() const
			{
				return (type == ultimate_dna);
			}

			bool is_chromosome_loaded(const string&) const;
			void load_chromosome(vector<string>) const;
			void unload_chromosome(const string&) const;
			void load_all_chromosomes() const;
			void load_chromosomes(vector<int>) const;
			void unload_chromosomes(vector<int>) const;

			void switch_chromosome(int,int,chromosome);
			void insert_chromosome(int,int,chromosome);
			void remove_chromosome(int,int);

			inline int number_of_chromosomes() const
			{
				return chromosomes.size();
			}

			virtual bool is_cyclical() const;
			virtual bool is_acyclical() const;

		private:
			mutable map<string,chromosome> chromosomes;
			dna_type type;
			string file_name;
			rapidxml::xml_document<> xml_file;
	};
}

#endif // BIOLOGY_DNA_DNA_HPP_INCLUDED
