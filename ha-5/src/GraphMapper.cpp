/**
 * Datenstrukturen SS2012 - Hausaufgabe 5
 * // GraphMapper.cpp
 *
 * @author Nepomuk Frädrich 247041 <nepf@informatik.tu-chemnitz.de>
 */


Graph* GraphMapper::readFile(char* filename)
{
	std::ifstream datei;
	datei.open(filename, std::ios_base::in);

	if (!datei)
	{
		std::cerr << "\nDie Datei " << filename << " konnte nicht geoeffnet werden.\n" << std::endl;
		return 0;
	} else {

		int curr_int;
		int int_count = 0;
		//bool adj_finish = false;
		int tmp_int_count = 0;

		int N = -1, M = -1;

		Graph* G;

		int tmp_start, tmp_end, tmp_weight;

		while(datei >> curr_int)
		{
			if (int_count >= 2)
			{
				// Adjazentsangaben oder Anfragedaten
				if ((int_count - 2) <= M*3)
				{
					// Kanten einlsen

					if (tmp_int_count == 0)
					{
						tmp_start = curr_int;
					} else if (tmp_int_count == 1) {

						tmp_end = curr_int;
					} else if (tmp_int_count == 2) {

						tmp_weight = curr_int;

						// alle drei Angaben erhalten, jetzt kann die Kante vollständig gesetzt werden
						G->setEdge(tmp_start, tmp_end, tmp_weight);
						tmp_int_count = -1; // minus 1 da, er gleich wieder ++ gemacht wird
					}
					tmp_int_count++;
				} else {

					// test Kosten-Abfragen einlesen

					// TODO!
				}
			} else {

				// N und M Angaben
				if (int_count == 0)
				{
					N = curr_int;
				} else if (int_count == 1) {

					M = curr_int;
				}

				if (N > -1 && M > -1)
				{
					std::cout <<"N: " << N << "; M: " << M << std::endl;
					G = new Graph(N, M);
				}
			}
			int_count++;
		}

		datei.close();

		return G;
	}
};