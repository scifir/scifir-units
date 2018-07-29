#include "dna.hpp"
#include "chromosome.hpp"

#include <fstream>

#include "rapidxml/rapidxml.hpp"

using namespace std;

namespace msci
{
	dna::dna() : bit_molecule(),chromosomes(),type(),file_name(),xml_file()
	{
	}

	dna::dna(dna_type new_type,const map<string,chromosome>& new_chromosomes) : bit_molecule(),chromosomes(new_chromosomes),type(new_type)
	{
	}

	dna::dna(const string& new_file) : bit_molecule(),chromosomes(),type(natural_dna),file_name(new_file),xml_file()
	{
		ifstream theFile (new_file);
		stringstream buffer;
		buffer << theFile.rdbuf();
		theFile.close();
		string file_content (buffer.str());
		vector<char> file_content_vector (file_content.begin(),file_content.end());
		file_content_vector.push_back('\0');
		xml_file.parse<0>(&file_content_vector[0]);
		rapidxml::xml_node<> * root_node;
		root_node = xml_file.first_node("dna");
		for (rapidxml::xml_node<>* chromosome_node = root_node->first_node("chromosome"); chromosome_node; chromosome_node = chromosome_node->next_sibling())
		{
			string chromosome_name = chromosome_node->first_attribute("name")->value();
			chromosome new_chromosome(chromosome_name,this,chromosome_node);
			chromosomes[chromosome_name] = new_chromosome;
			vector_nitrogenous_bases new_gen_nitrogenous_bases = vector_nitrogenous_bases();
		}
	}

	chromosome& dna::operator [](const string& i)
	{
		return chromosomes.at(i);
	}

	const chromosome& dna::operator [](const string& i) const
	{
		return chromosomes.at(i);
	}

	bool dna::is_chromosome_loaded(const string& x) const
	{
		return (chromosomes.count(x) > 0);
	}

	void dna::load_chromosome(vector<string> new_chromosomes) const
	{
		rapidxml::xml_node<>* root_node = xml_file.first_node("dna");
		vector<string> loadable_chromosomes;
		for (const string& new_chromosome : new_chromosomes)
		{
			if (!is_chromosome_loaded(new_chromosome))
			{
				loadable_chromosomes.push_back(new_chromosome);
			}
		}
		for (rapidxml::xml_node<>* chromosome_node = root_node->first_node("chromosome"); chromosome_node; chromosome_node = chromosome_node->next_sibling())
		{
			for (const string& loadable_chromosome : loadable_chromosomes)
			{
				string chromosome_name = chromosome_node->first_attribute("name")->value();
				if (loadable_chromosome == chromosome_name)
				{
					chromosome new_chromosome (chromosome_name,const_cast<dna*>(this),chromosome_node);
					chromosomes[chromosome_name] = new_chromosome;
				}
			}
		}
	}

	bool dna::is_cyclical() const
    {
		return true;
    }

    bool dna::is_acyclical() const
    {
		return false;
    }
}
