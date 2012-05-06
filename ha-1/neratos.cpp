

void eratos (int n)
{

    int a[n];

    for (int i = 2; i <= (n/2); i++)
    {
	if (a[i] == true)
	{
	    for (int j = 2*i; j <= n; j += i)
	    {
		a[j] = false;
	    }
	}
    }
}

int main ()
{}
