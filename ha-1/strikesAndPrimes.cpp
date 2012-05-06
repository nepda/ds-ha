
/**
 * Ermittelt die Anzahl der Streichungen und Primzahlen nach Eratosthenes
 *
 * Doppelte Streichungen werden doppelt gezählt.
 *
 * @param int sieb_groesse N, von 2..N die Feldgröße
 * @param int &strikes_count hier wird die Anzahl der Streichungen gespeichert
 * @param int &prime_count hier wird die Anzahl der Primzahlen gespeichert
 * @return void
 */
void strikesAndPrimes (int sieb_groesse, int &strikes_count, int &prime_count)
{
    // Sieb-Feld und Markierungsfeld deklarieren
    long unsigned int sieb[sieb_groesse]; // index gleich value
    long int strikes[sieb_groesse]; // unmarkiert: -1, markiert: 1

    // Zähler initialisieren
    strikes_count = 0;
    prime_count = 0;
    
    // Siebfeld und Markierungsfeld initialisieren
    for(int k = 2; k <= sieb_groesse; k++)
    {
	sieb[k] = k;
	strikes[k] = -1;
    }

    // printf("kein Problem mit init.\n");

    // jede Zelle in Siebfeld ab 2
    for(int i = 2; i <= sieb_groesse; i++)
    {
	// ab aktueller Zelle (i) alle weiteren Zellen (j)
	for(int j = i; j <= sieb_groesse; j++)
	{
	    // wenn aktuelle Zelle j unmarkiert ist
	    if (strikes[j] == -1)
	    {
		// alle vielfachen von Zellen l ab dem Quadrat der aktuellen Primzahl j
		for(int l = j*j; l < sieb_groesse; l += j)
		{
		    strikes_count++;
		    strikes[l] = 1; // markieren
		}
		break;
	    }
	}
    }

    // gehe Markierungsfeld durch umd Primzahlen zu zählen
    for(int m = 2; m <= sieb_groesse; m++)
    {
	// printf("strikes[%i] = %i\n", m, strikes[m]);
	if (strikes[m] == -1)
	{
	    prime_count++;
	}
    }
    
    prime_count--;
    strikes_count--;
    /*
    --prime_count; // da mit 0 angefangen wurde, müssen beide Counter dekrementiert werden
    
    ++strikes_count;
    if (strikes_count > 0)
        --strikes_count;

*/

}

