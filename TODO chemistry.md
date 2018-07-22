// MSCIENCE MOLECULES VISUALIZER
// TODO: .msm file extension (abbreviation of Mscience Molecule)
// TODO: support proteins (check if possible for all proteins first)

// MSCIENCE CHEMISTRY CREATOR
// TODO: Chemistry Creator program for creating molecules with .sm extension

// ATOMS
// TODO: 3D graphical functions: get_image_3d(),get_molecular_geometry_angle(const atom&) finish two angles
// TODO: atom::get_molecular_geometry_angle() needs good the square_antipristamic and tricapped_trigonal_prismatic values
// TODO: 2D graphical functions: get_image_2d(),get_detailed_image_2d()
// TODO: finish atom::get_atomic_color() using an enum for all colors
// TODO: review all electrical classes, atom::get_lone_pairs() among others
// TODO: finish normal_atom::get_electronic_configuration()
// TODO: create the first isotope class
// TODO: create all common isotopes of chemistry
// TODO: create_atom() should detect ions and isotopes (and more of the nomenclature, if it exists)
// TODO: class atomic_group
// TODO: function atom::is_chiral()
// TODO: is_factible(), is_valence_full(), get_valence_number() should work for atomic_group_b(), lanthanides and actinides
// TODO: finish some properties of some atoms (like radioactive)
// TODO: what's speed of sound of atoms
// TODO: what's half-life and unit to represent it
// TODO: create triple_point and melting_point (maybe point classes)
// TODO: ordering for atoms

// DETAILED ATOMS
// TODO: finish detailed atoms
// TODO: finish electron_cloud object
// TODO: electron cloud functions: get_electron_cloud(),print_electron_cloud()

// DOCUMENTATION OF ATOMS
// TODO: document that is_atom_specimen() is always used instead of get_z() or get_symbol() to test for the specimen, cause for isotopes the string symbol can change
// TODO: document the nomenclature of the cas number
// TODO: document that the unfinished atoms doesn't have their values actually calculated. Document which values and atoms aren't completed
// TODO: document that normal_atom template-class isn't an abstract class because it's not intended to be used directly

// MOLECULES
// TODO: implement the bond_length inside atomic_bond class
// TODO: 3D display
// TODO: 2D display of molecules by printing inside 2D a 3D molecule
// TODO: molecule::has_functional_group(functional_group)
// TODO: molecule::get_dipole()
// TODO: molecule::is_polar() and molecule::is_apolar()
// TODO: are_isomers(), are_conformational_isomers(), are_enantiomers()
// TODO: are_miscible(), are_inmiscible()
// TODO: molecule::is_cyclical() and molecule::is_acyclical()
// TODO: is_eter(), and all the others of those functions
// TODO: molecule::get_formula(),molecule::print(),operator << of molecule
// TODO: operator == and operator != of molecule
// TODO: ether, carboxilic_acid, and all the other molecule subclasses of normal_molecule in order to have the same clarity as with units length, mass, etc.
// TODO: normal_molecule.cpp: rapidxml shouldn't be aliased as namespace
// TODO: normal_molecule.cpp: see which is the best method to travel rapidxml, if to use file<> of rapidxml of if to use the actual fstream
// TODO: ordering for molecules
// TODO: .msm should have <atom> with nick attribute to abbreviate special atoms

// REGEX OF MOLECULE NAMES
//(((([0-9]+-)|([0-9]+,[0-9]+-di))((meth)|(eth)|(prop)|(but)|(pent)|(hex)|(hept)|(oct)|(non)|(dec))yl-)*((([0-9]+-)|([0-9]+,[0-9]+-di))((meth)|(eth)|(prop)|(but)|(pent)|(hex)|(hept)|(oct)|(non)|(dec))yl)|((([0-9]+-)|([0-9]+,[0-9]+-di))((meth)|(eth)|(prop)|(but)|(pent)|(hex)|(hept)|(oct)|(non)|(dec))yl)?)((meth)|(eth)|(prop)|(but)|(pent)|(hex)|(hept)|(oct)|(non)|(dec))((ane)|(anol))
// prefixes of names: (([0-9]+-)|([0-9]+,[0-9]+-di))
// radical names: ((meth)|(eth)|(prop)|(but)|(pent)|(hex)|(hept)|(oct)|(non)|(dec))
// compound type: ((ane)|(anol))
// regex structure: (${radical_regex_with_hyphen}*${radical_regex}|${radical_regex}?)${radical_names}${compound_types}
// add the conformations: \(((E)|(Z))\)
// TODO: search all the basic IUPAC rules
// TODO: search the general document of IUPAC that doesn't includes something more
// TODO: search if they're libraries that handle IUPAC names
// TODO: function for veryfing the name (the basic one)
// TODO: function for generating the prefix based on a number
// TODO: function for generating the prefix of the form n,...,n-<prefix>
// TODO: function for generating the radical based on a number
// TODO: support the n- names of compound type
// TODO: array (or function) of compound types
// TODO: support the translation
// TODO: use regex replacement inside the constructor of molecules to get the data to create the molecule (if possible with bool)

// CHEMICAL REACTIONS
// TODO: Finish basic member-functions of the class
// TODO: Reaction is_safe() member-function, related to T change, entropy change, etc.
// TODO: Add all toxicology knowledge inside chemical_reaction and molecule, in order to know if a reaction is safe or not

// UNFINISHED ATOMS
// TODO: Nh (atoms_iiia.hpp), Fl (atoms_iva.hpp), Mc (atoms_va.hpp), Lv (atoms_via.hpp), At y Ts (atoms_viia.hpp), He and the other noble gases (atoms_viiia.hpp), Y (atoms_iiib.hpp), all ivb (atoms_ivb.hpp), all vb (atoms_vb.hpp), all vib (atoms_vib.hpp),
// TODO: Mn doesn´t documents  covalent radius dual spin
