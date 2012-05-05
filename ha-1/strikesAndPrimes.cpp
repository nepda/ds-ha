

void strikesAndPrimes (int sieb_groesse, int &strikes_count, int &prime_count)
{
    int sieb[sieb_groesse];
    int strikes[sieb_groesse];

    strikes_count = 0;
    prime_count = 0;
    
    for(int k = 2; k <= sieb_groesse; k++)
    {
	sieb[k] = k;
	strikes[k] = -1;
    }

    for(int i = 2; i <= sieb_groesse; i++)
    {
	for(int j = i; j <= sieb_groesse; j++)
	{
	    if (strikes[j] == -1)
	    {
		// mark multiples;

		for(int l = j*j; l < sieb_groesse; l += j)
		{
		    ++strikes_count;
		    strikes[l] = 1;
		}

		break;
	    }
	}
    }

    for(int m = 2; m <= sieb_groesse; m++)
    {
	if (strikes[m] == -1)
	{
	    ++prime_count;
	}
    }
}
