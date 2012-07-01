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

	public:
		DyaTreeMapper();
		DyaTreeMapper(char*);

		DyaTree* readFromString(char*);
		DyaTree* parsePartString(char*, int, int);
};

#endif