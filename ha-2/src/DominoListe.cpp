
class DominoListe
{
	private:
		DominoNode* head;
		DominoNode* last;

		int laenge;
	
	public:
		DominoListe()
		{
			this->head = NULL;
			this->last = this->head;
		};
		
		DominoNode* getHead()
		{
			return this->head;
		};

		void setLength(int length)
		{
			this->laenge = length;
		};
		
		int getLength(int length)
		{
			return this->laenge;
		};

		void addStone(int leftEye, int rightEye)
		{
			DominoNode* tmp = new DominoNode(leftEye, rightEye);

			if (this->head == NULL)
			{
				//debug//std::cout << "insert at head" << std::endl;
				this->head = tmp;
				this->last = this->head;
			} else {
				
				//debug//std::cout << "insert at tail" << std::endl;
				// DominoNode* ende = this->head;
				
				this->last->next = tmp;
				this->last = tmp;
				
				//debug//std::cout << "tmp: " << this->last->info->getLeftEye() << ", " << this->last->info->getRightEye() << std::endl;				
			}
		};
		
		void readFromFile(char filename[])
		{
			std::ifstream datei;
			datei.open(filename, std::ios_base::in);
			
			if (!datei)
			{
				std::cerr << "Die Datei " << filename << " konnte nicht geoeffnet werden" << std::endl;
				// DominoListe* dlist = new DominoListe();
				return;
			} else {

				// DominoListe* dlist = new DominoListe();

				int currInt;
				int line = 0;
				int lastInt;

				int c = 0;
				while(datei >> currInt)
				{
					if (line == 0)
					{
						this->setLength(currInt);
					} else {
						
						if (0 == c)
						{
							lastInt = currInt;
							++c;
						} else {
							
							//debug//std::cout << "insert: " << lastInt << ", " << currInt << std::endl;
							this->addStone(lastInt, currInt);
							c = 0;
						}
						
					}
					++line;
				}
				
				datei.close();
				
				//return dlist;
			}
		};
		
		void printList(int endl = 1)
		{
			DominoNode* tmp = this->head;
			int c=0;
			while (tmp)
			{
				tmp->info->printInfo(0);
				tmp = tmp->next;
				++c;
			}
			if (endl) std::cout << std::endl;
		};
};
