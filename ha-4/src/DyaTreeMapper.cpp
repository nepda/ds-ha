/**
 * Datenstrukturen SS2012 - Hausaufgabe 4
 * // DyaTreeMapper.cpp
 *
 * @author Nepomuk Frädrich 247041 <nepf@informatik.tu-chemnitz.de>
 */

DyaTreeMapper::DyaTreeMapper()
{};

DyaTreeMapper::DyaTreeMapper(char* input)
{
	this->readFromString(input);
};

DyaTree* DyaTreeMapper::readFromString(char* input)
{
	int length = 0;

	while (input[length] != '\0')
	{
		length++;
	}


	std::cout << "input laengee: " << length << std::endl;

	return new DyaTree();
};