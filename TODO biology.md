// DNA
// TODO: see if to separate the dna part of magickscience to msci_dna.a in order to protect it from adding it to GitHub unwantedly
// TODO: see which functions of molecule change now that bit_molecule is being used and add those functions to normal_molecule, being the ones of molecule class pure-virtual
// TODO: load and free genes in ram
// TODO: warn if the DNA is composed by an non-divisible per 3 number of nitrogenous bases
// TODO: see which enumeration systems exists for genes and use one inside dna class
// TODO: save() function to store .dna files. new_genes should be stored as another member-variable in order to optimize how to save the file without asking to new_genes all the time
// TODO: if the pointers of rapidxml have to be deleted or not
// TODO: maybe the dna should load with a buffer and with multi-threading
// TODO: compression algorithm maybe using zlib for dna files
// TODO: see if it's possible to support to write numbers with bytes
// TODO: add the two dna strings (male and female), and add H- or M- to the operator[] of the dna class as a prefix to select the chain
// TODO: change the include of gene.hpp of normal_molecule.hpp to a general one for molecules
// TODO: .genoma files
// TODO: .dna files can be full or can be compressed (by saying only their respective gen number, without the sequence)
// TODO: fingerprint of dna files to avoid creation of false files
// TODO: dna.cpp: rapidxml shouldn't be aliased as namespace (maybe other files too)
// TODO: dna.cpp: see which is the best method to travel rapidxml, if to use file<> of rapidxml of if to use the actual fstream (maybe other files too)
// TODO: .mcd (mythical creature dna) file (it goes inside another program, not this library)

// ANIMAL AND VEGETABLE
// TODO: .life_sample files

// BIOCHEMISTRY
// TODO: protein class, with special format to store and load it
// TODO: molecule::is_biochemical()
// TODO: Store the proteins only one time, and to calculate a lot of them use that unique instead for the data purpose. For movement modeling, with one instance is enough, and use position coordinates and rotation coordinates to store the data of each protein
