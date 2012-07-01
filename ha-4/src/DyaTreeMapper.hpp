/**
 * Datenstrukturen SS2012 - Hausaufgabe 4
 * // DyaTreeMapper.hpp
 *
 * @author Nepomuk Frädrich 247041 <nepf@informatik.tu-chemnitz.de>
 */

#ifndef DYATREEMAPPER_H
#define DYATREEMAPPER_H

class DyaTreeMapper {

private:
	static DyaTreeNode* createPart(char*, int, int);
	static int findOpIndex(char*, int, int);
	static int str2int(char*, int, int);

public:
	static DyaTreeNode* create(char*);

	static void simplify(DyaTreeNode*);
};

#endif