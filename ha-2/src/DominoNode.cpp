
class DominoNode
{
	public:
		DominoStein* info;
		DominoNode* next;
		
		DominoNode()
		{};
		
		DominoNode(DominoStein* stein)
		{
			this->info = stein;
		};


		DominoNode(int leftEye, int rightEye)
		{
			DominoStein* info = new DominoStein();
			
			info->setLeftEye(leftEye);
			info->setRightEye(rightEye);
			
			this->next = NULL;
			this->info = info;
		};
};
