
class ringNode 
{
	public:
		ringNode* next;
		DominoRing* info;
};

class DominoRingLists
{
	private:		
		ringNode* head;
		ringNode* last;
		
	public:
		
		DominoRingLists()
		{
			head = NULL;
			last = head;
		};
		
		void addRing(DominoRing* ring)
		{
			ringNode* tmp = new ringNode();
			tmp->next = 0;
			tmp->info = ring;

			if (head)
			{
				last->next = tmp;
				last = tmp;
			} else {
				head = tmp;
				last = head;
			}
		};
};
