/**
 * Datenstrukturen SS2012 - Hausaufgabe 3
 * // MatrixNode.cpp
 * 
 * 
 * @author Nepomuk Frädrich 247041 <nepf@informatik.tu-chemnitz.de>
 */
 
class MatrixNode {
	
	public:
		MatrixNode* next;
		int value;
		bool isSet;
		int row;
		int col;
		
		MatrixNode(int row, int col)
		{
			/*debug*///std::cout << "MatrixNode::MatrixNode(int " << row << ", int " << col << ")" << std::endl;
			this->row = row;
			this->col = col;
			this->isSet = false;
			this->next = 0;
		};
};
