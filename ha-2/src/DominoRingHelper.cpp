
class DominoRingHelper
{
	public:
	
		bool isUnusedItemInList(DominoListe * dlist)
		{
			DominoNode* tmp = dlist->getHead();
			
			while(tmp)
			{
				if (!tmp->info->isUsed)
				{
					return true;
				}
				tmp = tmp->next;
			}
			return false;
		}
		
		void findRingsInList(DominoListe* dlist)
		{
			DominoNode* tmp0 = dlist->getHead();
			DominoNode* tmp = dlist->getHead()->next;
			
			DominoNode* myhead = dlist->getHead();
			
			
			DominoRingLists* liste = new DominoRingLists();
			DominoRing* ring;
			
			while(tmp0)
			{
				if (tmp0->info->isUsed)
				{
					liste->addRing(ring);
					ring = 0;
					tmp0 = tmp0->next;
					std::cout << std::endl;
					
					ring = new DominoRing();
					
					continue;
				}
				
				myhead = tmp0;
			
				/**///std::cout << "I0:";
				myhead->info->printInfo(0);
				ring->addStone(myhead->info);
				myhead->info->isUsed = 1;
				
				tmp = tmp0->next;
				
				while (tmp)
				{
					/**///std::cout << std::endl << "L:";
					/**///dlist->printList(0);
					/**///std::cout << std::endl << "T:";
					/**///mp->info->printInfo(0);
					/**///std::cout << std::endl << "M:";
					/**///tmp->info->printInfo(0);
					
					/**///std::cout << std::endl;
					
					if (tmp->info->isUsed == 0)
					{
						if(myhead->info->getRightEye() == tmp->info->getLeftEye())
						{
							/**///std::cout << "I1:";
							tmp->info->printInfo(0);
							ring->addStone(tmp->info);
							tmp->info->isUsed = 1;
							myhead = tmp;
							tmp = dlist->getHead();
							/**///std::cout << "reset head 1" << std::endl;
							/**///continue;
						} else if (myhead->info->getRightEye() == tmp->info->getRightEye()) {
							
							tmp->info->switchEyes();
							/**///std::cout << "I2:";
							tmp->info->printInfo(0);
							ring->addStone(tmp->info);
							tmp->info->isUsed = 1;
							myhead = tmp;
							tmp = dlist->getHead();
							/**///std::cout << "reset head 2" << std::endl;
						} else {
							
							tmp = tmp->next;
						}
					} else {
						
						tmp = tmp->next;
					}
				}
				tmp0 = tmp0->next;
			}
		};
};

