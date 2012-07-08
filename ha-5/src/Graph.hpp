/**
 * Datenstrukturen SS2012 - Hausaufgabe 5
 * // Graph.hpp
 *
 * @author Nepomuk Frädrich 247041 <nepf@informatik.tu-chemnitz.de>
 */

class Graph {

private:
	int** matrix;
	int n;
	int m;

	struct node { // Knoten des Graphs
      int id;
    };

    node* nodes;

public:
	Graph(int, int);
	~Graph();
	void setEdge(int, int, int);
	void delEdge(int, int);
	bool getEdge(int, int);

	void print();
	void printAdjMatrix();
};