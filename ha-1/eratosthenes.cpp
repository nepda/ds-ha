

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
    for(int i = 2; i <= M; i++)
    {
	printf("\nerat[%i]: %i, %i", i, erat[i], marked[i]);
    }

    printf("\nEs wurden %i zellen markiert", mark_count);

    // testoutput - ende
}




