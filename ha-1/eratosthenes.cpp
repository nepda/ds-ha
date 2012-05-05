#include <stdio.h>

// frei wählbares Maximum N:
#define N 36


void markMultiples(int i, int M, int* marked, int &mark_count);
void eratosthenes(int);


void eratosthenes (int M)
{

    /**
     * @var int erat das Feld aller natürlichen Zahlen ab 2 bis M
     * @var int marked Markierungegn bzw. Streichungen bezügliche erat
     *       bei marked, gilt eine -1 als unmarkiert und eine 1 als markiert.
     */
    int erat[M], marked[M];

    /**
     * @var int mark_count zählt alle Streichungen bzw. Markierungen
     */
    int mark_count = -1;

    int n=2; // mit Zahl 2 beginnend

    // 1. Schreibe mit Zahl 2 beginnend alle folgenden natürlichen Zahlen
    // bis zu einem frei wählbaren Maximalwert M auf.
    while (n <= M)
    // eratosthenes feld mit 2..M befüllen UND alle als unmarkiert markieren
    {
	marked[n] = -1; // zunächst sind alle Zahlen unmarkiert
	erat[n] = n; // alle folgenden nat. Zahlen
	n++;
    }


    // gehe jede Zelle in Feld erat durch ( ab 2 )
    for(int x = 2; x <= M; x++)
    {
	// gehe ab dieser Zelle alle weiteren Zellen durch
	for(int c = x; c <= M; c++)
	{
	    // und finde die erste unmarkierte Zelle
	    if (marked[c] == -1)
	    {
		// markiere alle vielfachen dieser Zahl
		markMultiples(c, M, marked, mark_count);
		break; // breche diese (innere) Schleife ab
	    }
	}
    }

    // testoutput - start
    for(int i = 0; i <= M; i++)
    {
	printf("\nerat[%i]: %i, %i", i, erat[i], marked[i]);
    }

    printf("\nEs wurden %i zellen markiert", mark_count);

    printf("\n\n.bye.");
    // testoutput - ende
}


void markMultiples(int y, int M, int * marked, int &mark_count)
{
    for(int c = y*y; c <= M; c += y)
    {
	printf("x%i", mark_count);
	mark_count = mark_count + 1;
	marked[c] = 1;
    }
}

int main ()
{
    eratosthenes(2315);
    return 0;
}



