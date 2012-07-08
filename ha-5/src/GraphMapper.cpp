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
		//bool adj_started = false;
		//int tmp_int_count = 0;

		int N = -1, M = -1;

		Graph* G;

		while(datei >> curr_int)
		{
			if (int_count >= 2)
			{
				// Adjazentsangaben oder Anfragedaten
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