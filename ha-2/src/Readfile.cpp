#ifndef READFILE_CPP
#define READFILE_CPP

Readfile::Readfile()
{
	
};

Readfile::Readfile(char* filename[])
{
	std::ifstream datei;
	datei.open(filename, std::ios_base::in);
};

Readfile::~Readfile()
{
	
};

#endif
