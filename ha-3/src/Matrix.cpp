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

		int getRowCount()
		{
			return this->storage->getRowCount();
		};

		int getColCount()
		{
			return this->storage->getColumnCount();
		};

		int getIndex(int i, int j)
		{
			return this->storage->getIndex(i, j)->value;
		};

		void setIndex(int i, int j, int value)
		{
			this->storage->set(i, j, value);
		};

		void set(int* a)
		{
			/*debug*///std::cout << "Matrix::set(int* a)" << std::endl;
			int max_col = this->getColCount();
			int max_row = this->getRowCount();


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
			int rows = this->getRowCount();
			int cols = this->getColCount();

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
					node = this->storage->getIndex(i, j);

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
			int cols = this->getColCount();
			int rows = this->getRowCount();

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

		Matrix* trpReturn ()
		{
			int cols = this->getColCount();
			int rows = this->getRowCount();

			//        MatrixStore::MatrixStore(int rows, int cols)
			Matrix* neu = new Matrix(cols, rows);

			MatrixNode* node;

			for (int i = 0; i < rows; i++)
			{
				for(int j = 0; j < cols; j++)
				{
					node = this->storage->getIndex(i, j);
					neu->setIndex(j, i, node->value);
				}
			}


			return neu;
		};

		void add(Matrix &m)
		{
			int cols = this->getColCount();
			int rows = this->getRowCount();

			if (cols != m.getColCount())
			{
				/*debug*/std::cout << "Matrix::add(Matrix &m) Spaltenanzahl stimmt nicht überein, abbruch" << std::endl;
				return;
			}

			if (rows != m.getRowCount())
			{
				/*debug*/std::cout << "Matrix::add(Matrix &m) Zeilenanzahl stimmt nicht überein, abbruch" << std::endl;
				return;
			}


			for (int i = 0; i < rows; i++)
			{
				for(int j = 0; j < cols; j++)
				{
					this->setIndex(i, j, this->getIndex(i,j)+m.getIndex(i,j));
				}
			}
			return;
		}

		Matrix* mul(Matrix &m)
		{
			int cols = this->getColCount();
			int rows = this->getRowCount();

			int m_cols = m.getColCount();
			//int m_rows = m.getRowCount();


			int n_rows = rows;
			int n_cols = m_cols;

			/*debug*///std::cout << "Multiplikation: A[" << rows << "x" << cols << "] mal B["<< m_rows <<"x"<< m_cols<< "]" << std::endl;
			/*debug*///std::cout << "ergibt neue Ma: C[" << n_rows << "x" << n_cols << "]" << std::endl;



			if (cols != m.getRowCount())
			{
				/*debug*///std::cout << "Matrix::mul(Matrix &m): cols != rows, abbruch" << std::endl;
				return NULL;
			}

			if (rows != m.getColCount())
			{
				/*debug*///std::cout << "Matrix::mul(Matrix &m): rows != cols, abbruch" << std::endl;
				return NULL;
			}



			Matrix* multi = new Matrix(n_rows, n_cols);

			int n_val, k;

			for (int i = 0; i < n_rows; i++)
			{
				for(int j = 0; j < n_cols; j++)
				{
					/*debug*///std::cout << "[" << i << "," << j << "] * [" << j << ", "<< i <<"] ";

					n_val = 0;

					for (k = 0; k < m.getRowCount(); k++)
					{
						/*debug*///std::cout << " + A["<<i<<","<<k<<"] * B["<<k<<","<<j<<"]:";

						/*debug*///std::cout << this->getIndex(i, k) << " * " << m.getIndex(k, j);
						n_val += this->getIndex(i, k) * m.getIndex(k, j);
					}

					multi->setIndex(i, j, n_val);

					std::cout << std::endl;
				}
			}
			return multi;
		};

		bool sym()
		{

			Matrix* transponierteMatrix = this->trpReturn();

			int t_rows = transponierteMatrix->getRowCount();
			int t_cols = transponierteMatrix->getColCount();

			int rows = this->getRowCount();
			int cols = this->getColCount();

			if (t_rows != rows || t_cols != cols)
			{
				return false;
			}

			int t_val, val;

			for (int i = 0; i < rows; i++)
			{
				for (int j = 0; j < cols; j++)
				{
					t_val = transponierteMatrix->getIndex(i, j);
					val = this->getIndex(i, j);

					if (t_val != val)
					{
						return false;
					}
				}
			}
			return true;
		};

		bool orth()
		{

			int rows = this->getRowCount();
			int cols = this->getColCount();

			if (rows != cols)
			{
				return false;
			}

			// TODO

			return false;
		};
};
