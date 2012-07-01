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
	node* tmp = this->head;
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

void exprStack::push(char data)
{
	this->i++;
	node* tmp = new node();
	tmp->data = data;
	tmp->i = this->i;
	tmp->next = head;

	if (!this->isEmpty())
	head->prev = tmp;

	head = tmp;
};

char exprStack::pop()
{
	if (!this->isEmpty())
	{
		char data;
		data = head->data;

		node* tmp = head;

		head = head->next;
		head->prev = 0;

		delete tmp;

		return data;
	}
	return 0;
};

char exprStack::dequeue()
{
	if (!this->isEmpty())
	{
		node* tmp = this->head;
		while (tmp->next)
		{
			tmp = tmp->next;
		}
		return tmp->data;
	}

	return 0;
};

void exprStack::lookInside()
{
	node* tmp = this->head;

	while (tmp->next)
	{
		printf("%c.%i", tmp->data, tmp->i);

		tmp = tmp->next;
	}
	printf("%c.%i", tmp->data, tmp->i);
};

void exprStack::lookInsideQueue()
{
	node* tail = this->head;

	while (tail->next)
	{
		tail = tail->next;
	}

	while (tail->prev)
	{
		//printf("%c.%i", tail->data, tail->i);
		printf("%c", tail->data);
		tail = tail->prev;
	}
	//printf("%c.%i", tail->data, tail->i);
	printf("%c", tail->data);
};

int exprStack::length()
{
	node* tmp = this->head;
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
	char* str = new char[this->length()];
	node* tmp = this->head;

	int i = 0;

	while (tmp)
	{
		str[i] = tmp->data;
		tmp = tmp->next;
		i++;
	}
	printf("DBG: toString(): %s\n", str);

	return str;
};


char* exprStack::toQueueString()
{
	char* str = new char[this->length()];

	node* tmp = this->head;

	while (tmp->next)
	{
		tmp = tmp->next;
	}

	// tmp ist jetzt ende

	int i = 0;

	//printf("DBG: tmp->data: %c", tmp->data);

	while (tmp)
	{
		str[i] = tmp->data;
		tmp = tmp->prev;
		i++;
	}
	//printf("DBG: toQueueString(): %s\n", str);

	return str;
};


