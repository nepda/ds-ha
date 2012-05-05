


void markMultiples(int y, int M, int * marked, int &mark_count)
{
    for(int c = y*y; c < M; c += y)
    {
	printf("x%i", mark_count);
        mark_count = mark_count + 1;
	if (marked[c] == -1)
	    marked[c] = 1;
	else
	    marked[c] = marked[c] + 1;
    }
}
