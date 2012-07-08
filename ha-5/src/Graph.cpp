/**
 * Datenstrukturen SS2012 - Hausaufgabe 5
 * // Graph.cpp
 *
 * @author Nepomuk Frädrich 247041 <nepf@informatik.tu-chemnitz.de>
 */

Graph::Graph(int n, int m)
{
	this->n = 0;
	this->matrix = NULL;
	this->nodes = NULL;

	if (n <= 0)
	{
		nep::dbg(__FILE__, __LINE__, "Kann keinen Graphen mit kleiner gleich 0 Knoten erzeugen", nep::DBG_ERROR);
		return;
	}

	this->n = n;
	this->m = m;

	// Adjazenten Matrix initialisieren - start
	//
	this->matrix = new int* [this->n];
	for( int i = 0; i < this->n ; i++)
	{
		this->matrix[i] = new int[this->n];
		for(int j = 0; j < this->n;j++)
		{
			this->matrix[i][j] = 9999;
		}
	}
	//
	// Adjazenten Matrix initialisieren - ende

	// Graphknoten initialisieren - start
	//
	node* _nodes = new node[this->n];
	for(int c = 0;  c < this->n; c++)
	{
		_nodes[c].id = c+1;
	}
	this->nodes = _nodes;
	//
	// Graphknoten initialisieren - ende
};

Graph::~Graph()
{
	for (int i = 0; i < this->n; i++)
	{
		delete[] this->matrix[i];
	}
	delete[] this->matrix;

	for(int c = 0;  c < this->n; c++)
	{
		delete &this->nodes[c];
	}
	delete this->nodes;
};

void Graph::print()
{
	for(int i = 0; i < this->n; i++)
	{
		//printf("(%i) ", this->nodes[i].id);
	}
};

void Graph::setEdge(int start, int end, int weight)
{
	printf("\nSetze Kante von %i nach %i mit Gewicht %i", start, end, weight);
	this->matrix[start][end] = weight;
}



void Graph::printAdjMatrix()
{
	for(int i = 0; i < this->n; i++)
	{
		for(int j = 0; j < this->n; j++)
		{
			printf("%4i ", this->matrix[i][j]);
		}
		printf("\n");
	}
};
