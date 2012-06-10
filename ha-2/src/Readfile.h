#ifndef READFILE_H
#define READFILE_H

class Readfile {

	private:
		std::ifstream datei;
		
	public:
		Readfile();
		Readfile(char* filename[]);
		~Readfile();
};

#include "Readfile.cpp"
#endif
