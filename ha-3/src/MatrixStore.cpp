/**
 * Datenstrukturen SS2012 - Hausaufgabe 3
 * // MatrixStore.cpp
 * 
 * 
 * @author Nepomuk Frädrich 247041 <nepf@informatik.tu-chemnitz.de>
 */
 
class MatrixStore {
	
	private:
		MatrixNode* head;
		
		int rows; // Zeilen
		int cols; // Spalten
		
	public:
	
		MatrixStore(int rows, int cols)
		{
			/*debug*///std::cout << "MatrixStore::MatrixStore(int "<<rows<<", int "<<cols<<")" << std::endl;
			this->rows = rows;
			this->cols = cols;
			
			this->head = new MatrixNode(0, 0);
			
			MatrixNode* prev = head;

			for (int i = 0; i < rows; i++)
			{
				for(int j = 0; j < cols; j++)
				{
					if (i == 0 && j == 0) continue;
					
					MatrixNode* tmp = new MatrixNode(i, j); // MatrixNode->isSet ist vorerst immer false!
					prev->next = tmp;
					prev = tmp;
				}
			}
		};
		
		MatrixNode* getIndex(int row, int col)
		{
			MatrixNode* tmp = this->head;
		
			/*debug*///std::cout << "MatrixStore::getIndex(int " << row << ", int " << col << ") - start" << std::endl;
				
			while (tmp)
			{
				if (tmp->col == col &&
					tmp->row == row)
				{
					/*debug*///std::cout << "MatrixStore::getIndex(int " << row << ", int " << col << ") - tmp->value: " << tmp->value << "; tmp->row:" << tmp->row << "; tmp->col: " << tmp->col << std::endl;
					/*debug*///std::cout << "MatrixStore::getIndex(int " << row << ", int " << col << ") - end" << std::endl;
					return tmp;
				}
				tmp = tmp->next;
			}
			return 0;
		};
		
		void set(int row, int col, int value)
		{
			/*debug*///std::cout << "MatrixStore::set(row: " << row << ", col:" << col << ", value:" << value << ") " << std::endl;
			MatrixNode* tmp = this->getIndex(row, col);
			
			tmp->value = value;
			tmp->isSet = true;
		};
		
		int getRowCount()
		{
			return this->rows;
		};
		
		int getColumnCount()
		{
			return this->cols;
		};
};
