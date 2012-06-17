/**
 * Datenstrukturen SS2012 - Hausaufgabe 3
 * // Matrix.cpp
 * 
 * 
 * @author Nepomuk Frädrich 247041 <nepf@informatik.tu-chemnitz.de>
 */
 
#include "MatrixNode.cpp"
#include "MatrixStore.cpp"

class Matrix {
	
	private:
		MatrixStore* storage; // echte Matrix
		
		int* values;
		
		void printInt4(int i)
		{
			if (i < -99)
			{ // 4 Zeichen
				std::cout << i;
				return;
			}
			if (i < -9)
			{ // 3 Zeichen
				std::cout << " " << i;
				return;
			}
			if (i < 0)
			{ // 2 Zeichen
				std::cout << "  " << i;
				return;
			}
			if (i < 10)
			{ // 1 Zeichen
				std::cout << "   " << i;
				return;
			}			
			if (i < 100)
			{ // 2 Zeichen
				std::cout << "  " << i;
				return;
			}

			// 3 Zeichen
			std::cout << " " << i;
			return;
		}
		
	public:
	
		Matrix (int rows, int cols)
		{
			this->storage = new MatrixStore(rows, cols);
			
			/*debug*//*test*///this->storage->set(0, 0, 898);
			/*debug*//*test*///this->storage->set(2, 19, 0);
			
		};
		
		void set(int* a)
		{			
			/*debug*///std::cout << "Matrix::set(int* a)" << std::endl;
			int max_col = this->storage->getColumnCount();
			int max_row = this->storage->getLineCount();
			
			
			int max_item = max_col*max_row;
			
			/*debug*///std::cout << "Matrix::set(int* a)::max_item = " << max_item << "; " << std::endl;
			/*debug*///std::cout << "Matrix::set(int* a)::max_col = " << max_col << "; " << std::endl;
			
			int line = 0;
			int col = 0;
			
			for(int i = 0; i < max_item; i++)
			{
				if (col >= max_col)
				{
					line++;
					col = 0;
				}
				
				this->storage->set(line, col, a[i]);
				
				col++;
			}
			
		};
		
		void out ()
		{
			int rows = this->storage->getLineCount();
			int cols = this->storage->getColumnCount();
			
			MatrixNode* node;
			
			int k;
			
			std::cout << "    ";
			for (k = 0; k < cols; k++)
			{
				std::cout << " ";
				this->printInt4(k);
			}
			std::cout << std::endl;
			
			
			
			std::cout << "     +";
			for (k = 0; k < cols; k++)
			{
				std::cout << "----+";
			}
			std::cout << std::endl;


			
			
			for (int i = 0; i < rows; i++)
			{
				this->printInt4(i);
				std::cout << " |";
				for (int j = 0; j < cols; j++)
				{
					node = storage->getIndex(i, j);
					
					/*debug*///std::cout << "row: " << i << ", col: " << j;
					
					int val = node->value;
					
					if (node->isSet)
					{
						/*debug*/this->printInt4(val);
					} else {
						
						/*debug*/std::cout << "  F ";
					}
					
					std::cout << "|";					
					
					
					/*debug*///std::cout << std::endl;					
				}
				
				std::cout << std::endl;
			}
			
			std::cout << "     +";
			for (k = 0; k < cols; k++)
			{
				std::cout << "----+";
			}
			std::cout << std::endl;
		}
		
		void trp ()
		{
			int cols = this->storage->getColumnCount();
			int rows = this->storage->getLineCount();
			
			//        MatrixStore::MatrixStore(int rows, int cols)
			MatrixStore* neu = new MatrixStore(cols, rows);
			
			MatrixNode* node;
			
			for (int i = 0; i < rows; i++)
			{
				for(int j = 0; j < cols; j++)
				{
					node = this->storage->getIndex(i, j);
					neu->set(j, i, node->value);
				}
			}
			delete this->storage;
			this->storage = neu;
		};
		
		void add(Matrix &m)
		{
			
		}
		
		void mul(Matrix &m)
		{
			
		};
		
		bool sym()
		{
			
		};
};
