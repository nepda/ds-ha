
/**
 * Sieb des Eratosthenes - ohne Rückgabe
 *
 * Beispiel:
 * <code>
 * int sieb_groesse = 36;
 * int erat[sieb_groesse], marked[sieb_groesse];
 * 
 * eratosthenes(sieb_groesse, erat, marked);
 *
 * // jetzt sieht das so aus:
 * // erat[2] = 2; marked[2] = -1 // Prim.
 * // erat[3] = 3; marked[3] = -1 // Prim.
 * // erat[4] = 4; marked[4] = 1  // keine Prim.
 * // erat[5] = 5; marked[5] = -1 // Prim.
 * // erat[6] = 6; marked[6] = 1  // keine Prim.
 * // ...
 * </code>
 *
 * @param int M die Größe des Eratosthenes Feldes
 * @param int* erat ein integer-Feld von 0..M mit index hier werden alle Zahlen von 2..M gespeichert.
 * @param int* marked ein integer-Feld von 0..M her werden alle Streichungen gespeichert.
 * @return void
 * @see strikesAndPrimes ermittelt die Anzahl der Streichungen und Primzahlen von 2..M
 */
void eratosthenes (int M, int* erat, int* marked)
{

    /**
     * @var int erat das Feld aller natürlichen Zahlen ab 2 bis M
     * @var int marked Markierungegn bzw. Streichungen bezügliche erat bei marked, gilt eine -1 als unmarkiert und eine 1 als markiert.
     */
//    int erat[M], marked[M];

    // erat und marked initialisieren
    for(int k = 2; k <= M; k++)
    {
	erat[k] = k; // key = value
	marked[k] = -1; // alle Felder sind vorerst unmarkiert
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
		for(int l = c*c; l < M; l += c)
		{
		    marked[l] = 1;
		}
		break; // breche diese (innere) Schleife ab
	    }
	}
    }
}

