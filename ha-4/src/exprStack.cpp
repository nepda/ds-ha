/**
 * Datenstrukturen SS2012 - Hausaufgabe 4
 * // exprStack.cpp
 *
 * @author Nepomuk Frädrich 247041 <nepf@informatik.tu-chemnitz.de>
 */


exprStack::exprStack()
{
	this->head = 0;
};


exprStack::~exprStack()
{
	exprStackNode* tmp = this->head;
	while (tmp)
	{
		head = head->next;
		delete tmp;
		tmp = head;
	};
};


bool exprStack::isEmpty()
{
	/*debug*///printf("bool exprStack::isEmpty()\n");
	return (this->head == 0);
};

void exprStack::push(char* data)
{
	exprStackNode* temp = new exprStackNode();
	temp->data = data;
	temp->next = head;
	head = temp;
};

void exprStack::push(char* data, int start, int end)
{
	printf("exprStack::push(char* '%s', int %i, int %i)\n", data, start, end);
	char* str = new char[end-start];

	int c = 0;

	for (int i = start; i < end; i++)
	{
		// /*debug*///printf("exprStack::push(char* '%s', int %i, int %i) str[%i] = data[%i]\n", data, start, end);
		str[c] = data[i];
		c++;
	}
	str[c] = '\0';

	/*debug*///printf("exprStack::push(char* '%s', int %i, int %i), str: %s\n", data, start, end, str);
	this->push(str);
};

void exprStack::push(char data)
{
	printf("exprStack::push(char '%c')\n", data);
	char str[1];

	str[0] = data;
	str[1] = '\0';

	this->push(str);
};

char* exprStack::pop()
{
	if (!this->isEmpty())
	{
		exprStackNode* temp = head;
		char* data = head->data;
		head = head->next;
		delete temp;
		return data;
	}
	return 0;
};


int exprStack::length()
{
	exprStackNode* tmp = this->head;
	int i = 0;

	while (tmp)
	{
		i++;
		tmp = tmp->next;
	};
	return i;
};

char* exprStack::toString()
{
	exprStackNode* tmp = this->head;


	while (tmp)
	{
		printf("%s", tmp->getData());
		tmp = tmp->next;
	}

	return 0;


	int stack_size = this->length();

	char* str[stack_size];

	int len = 0;

	int i = 0;

	while (tmp)
	{
		str[i] = tmp->getData();

		len += nep::strlen(str[i]);

		tmp = tmp->next;
		i++;
	}
	/*debug*///printf("DBG: toString(), len: %i\n", len);

	char* value = new char[len];

	int j = 0;
	int u;

	for (int k = 0; k < stack_size; k++)
	{
		u = nep::strlen(str[k]);
		for(int c = 0; c < u; c++)
		{
			value[j] = str[k][c];
			j++;
		}
	}

	return value;
};


char* exprStack::toQueueString()
{
	/*debug*///printf("_&$_%s::%s::%i\n", __FILE__, __func__, __LINE__);

	exprStackNode* tmp = this->head;

	while (tmp->next)
	{
		tmp = tmp->next;
	}
	//tmp = tmp->prev;

	//printf("Ende Datum: %s", tmp->getData());

	 // tmp ist jetzt ende


	/*debug*///printf("_&$_%s::%s::%i\n", __FILE__, __func__, __LINE__);

	int stack_size = this->length();

	char* str[stack_size];



	int len = 0;

	int i = 0;


	while (tmp)
	{

		/*debug*///printf("_&$_%s::%s::%i\n", __FILE__, __func__, __LINE__);

		str[i] = tmp->getData();

		len += nep::strlen(str[i]);

		tmp = tmp->prev;
		i++;

	}

	/*debug*///printf("_&$_%s::%s::%i\n", __FILE__, __func__, __LINE__);

	char* val = 0;

	/*debug*///printf("_&$_%s::%s::%i\n", __FILE__, __func__, __LINE__);

	val = new char[len];


	/*debug*///printf("_&$_%s::%s::%i\n", __FILE__, __func__, __LINE__);


	int j = 0;
	int u;


	/*debug*///printf("_&$_%s::%s::%i\n", __FILE__, __func__, __LINE__);


	for (int k = 0; k < stack_size; k++)
	{

		/*debug*///printf("_&$_%s::%s::%i\n", __FILE__, __func__, __LINE__);

		u = nep::strlen(str[k]);
		for(int c = 0; c < u; c++)
		{
			val[j] = str[k][c];
			j++;
		}
	}

	val[j] = '\0';

	/*debug*///printf("_&$_%s::%s::%i\n", __FILE__, __func__, __LINE__);
	//return 0;



	return val;
};



void exprStack::print()
{
	exprStackNode* tmp = this->head;

	printf("\n------STACK VIEW-------\n");

	while (tmp)
	{
		printf("[%s] ", tmp->getData());
		tmp = tmp->next;
	}
	printf("\n-----------------------\n");

};

