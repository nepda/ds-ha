/**
 * Datenstrukturen SS2012 - Hausaufgabe 4
 * // exprStack.cpp
 *
 * @author Nepomuk Frädrich 247041 <nepf@informatik.tu-chemnitz.de>
 */


exprStack::exprStack()
{
	this->i = 0;
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
	return (head == 0);
};

void exprStack::push(char* data)
{
	printf("exprStack::push(char* '%s')\n", data);
	this->i++;
	exprStackNode* tmp = new exprStackNode();
	tmp->setData(data);
	tmp->i = this->i;
	tmp->next = head;

	if (!this->isEmpty())
	head->prev = tmp;

	head = tmp;
};

void exprStack::push(char* data, int start, int end)
{
	printf("exprStack::push(char* '%s', int %i, int %i)\n", data, start, end);
	char* str = new char[end-start];

	int c = 0;

	for (int i = start; i < end; i++)
	{
		// printf("exprStack::push(char* '%s', int %i, int %i) str[%i] = data[%i]\n", data, start, end);
		str[c] = data[i];
		c++;
	}

	printf("exprStack::push(char* '%s', int %i, int %i), str: %s\n", data, start, end, str);
	this->push(str);
};

void exprStack::push(char data)
{
	printf("exprStack::push(char '%c')\n", data);
	this->i++;
	exprStackNode* tmp = new exprStackNode();
	tmp->setData(data);
	tmp->i = this->i;
	tmp->next = head;

	if (!this->isEmpty())
	head->prev = tmp;

	head = tmp;
};

char* exprStack::pop()
{
	if (!this->isEmpty())
	{
		char* data;
		data = head->getData();

		exprStackNode* tmp = head;

		head = head->next;
		head->prev = 0;

		delete tmp;

		return data;
	}
	return 0;
};

char* exprStack::dequeue()
{
	if (!this->isEmpty())
	{
		exprStackNode* tmp = this->head;
		while (tmp->next)
		{
			tmp = tmp->next;
		}
		return tmp->getData();
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
	printf("DBG: toString(), len: %i\n", len);

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
	exprStackNode* tmp = this->head;

	while (tmp->next)
	{
		tmp = tmp->next;
	} // tmp ist jetzt ende


	int stack_size = this->length();

	char* str[stack_size];

	int len = 0;

	int i = 0;

	while (tmp)
	{
		str[i] = tmp->getData();

		len += nep::strlen(str[i]);

		tmp = tmp->prev;
		i++;
	}
	printf("DBG: toStringQueue(), len: %i\n", len);

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



