#ifndef MOLECULE_HPP_INCLUDED
#define MOLECULE_HPP_INCLUDED

namespace chemistry
{
	class molecule
	{
		public:
			molecule();
			virtual int get_ionic_charge() = 0;
			void print();
            virtual void print_image_2d() = 0;
            virtual void print_image_3d() = 0;
            //virtual c_canvas_t get_image_2d() = 0;
            //virtual GLObject get_image_3d() = 0;
            virtual bool is_ion() = 0;
            virtual bool is_anion() = 0;
            virtual bool is_cation() = 0;
            virtual bool is_neutral() = 0;
	};
}

#endif // MOLECULE_HPP_INCLUDED
