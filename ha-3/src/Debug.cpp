/**
 * Datenstrukturen SS2012 - Hausaufgabe 3
 * // Debug.cpp
 *
 *
 * @author Nepomuk Frädrich 247041 <nepf@informatik.tu-chemnitz.de>
 */

class iArray {
	private:
		struct node {
			node* next;
			int index;
			int info;
		};

		node* head;
		node* last;

	public:

		iArray()
		{
			this->head = NULL;
			this->last = this->head;
		};

		void push(int value)
		{
			node* tmp;
			tmp->info = value;
			tmp->next = 0;
			tmp->index = this->last->index+1;
			this->last->next = tmp;
			this->last = tmp;
		};

		int set(int index, int value)
		{
			if (this->last->index < index)
			{
				node* tmp;
				tmp->info = value;
				tmp->next = 0;
				tmp->index = index;
			}
		};

		int get(int index)
		{
			node* tmp = this->head;

			while (tmp->index != index)
			{
				tmp = tmp->next;
			}

			if (tmp->index == index)
			{
				return tmp->info;
			}
		};


};