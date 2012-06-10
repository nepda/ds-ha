
class DominoStein {
	
	private:
		int leftEye;
		int rightEye;

		
	public:
	
		int isUsed;
	
		DominoStein()
		{
			this->isUsed = 0;
		};
	
		void setLeftEye(int left)
		{
			this->leftEye = left;
		};
		
		int getLeftEye()
		{
			return this->leftEye;
		};
		
		
		void setRightEye(int right)
		{
			this->rightEye = right;
		};
		
		int getRightEye()
		{
			return this->rightEye;
		};
		
		void printInfo(int endl = 1)
		{
			//std::cout << "cout ist ein arschloch" << this->getLeftEye() << std::endl;
			std::cout << "[" << getLeftEye() << ":" << getRightEye() << /* ":" << isUsed <<*/ "]";
			
			if (endl) std::cout << std::endl;
		};
		
		void switchEyes()
		{
			int tmp = this->getLeftEye();
			this->leftEye = this->rightEye;
			this->rightEye = tmp;
		};
};
