


class DominoRing
{
	private:
		DominoNode* head;
		DominoNode* last;

	public:
	
		DominoRing()
		{
			this->head = 0;
			this->last = head;
		};

		void addStone(DominoStein* stein)
		{
			DominoNode* node = new DominoNode(stein);
			
			node->info->printInfo();

			if (this->head == 0)
			{
				std::cout << "insert at head" << std::endl;
				this->head = node;
				this->head->next = this->head;
				this->last = this->head;
			} else {
				
				std::cout << "insert at tail" << std::endl;
				node->next = head;
				last->next = node;
				last = node;
			}
		};
		
		void printRing()
		{
			DominoNode* curr = head;
			while (curr != last)
			{
				curr->info->printInfo();
			}
		};
};
