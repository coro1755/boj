#include <iostream>
using namespace std;

int min(int a, int b);

int main()
{
	int n = 0;
	scanf("%d", &n);
	int * d = new int[n + 1];
	d[0] = 0;
	for (int i = 1; i < n + 1; i++)
	{
		d[i] = i;
		for (int j = 2; j*j <= i; j++)
		{
			d[i] = min(d[i], d[i - j * j] + 1);
		}
	}

	printf("%d", d[n]);

	delete[] d;
	return 0;
}

int min(int a, int b)
{
	return a < b ? a : b;
}
