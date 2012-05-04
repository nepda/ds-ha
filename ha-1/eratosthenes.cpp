#include <stdio.h>


#define N 36


void markMultiples(int i);

int erat[N], marked[N], mark_count = 0;

int main () {


    int n=2;

    while (n <= N)
    // eratosthenes feld mit 2..N befüllen UND alle als unmarkiert markieren
    {
	marked[n] = -1;
	erat[n] = n;
	n++;
    }


    for(int x = 2; x <= N; x++)
    {
	for(int c = x; c <= N; c++)
	{
	    if (marked[c] == -1)
	    {
		markMultiples(c);
		break;
	    }
	}
    }

    for(int i = 0; i <= N; i++)
    {
	printf("\nerat[%i]: %i, %i", i, erat[i], marked[i]);
    }

    printf("\nEs wurden %i zellen markiert", mark_count);

    printf("\n\n.bye.");
    return 0;
}


void markMultiples(int y)
{
    for(int c = y*y; c <= N; c += y)
    {
	printf("X");
	mark_count += 1;
	marked[c] = 1;
    }
}





