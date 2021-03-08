#include <iostream>
using namespace std;

int max(int a, int b);

int main()
{
	int N = 0;
	scanf("%d", &N);
	int *p = new int[N + 1];
	int *d = new int[N + 1];
	p[0] = 0;
	for (int i = 1; i <= N; i++)
	{
		scanf("%d", &p[i]);
	}
	d[0] = 0;
	for (int i = 1; i <= N; i++)
	{
		d[i] = p[i];
		for (int j = 0; j <= i / 2; j++)
		{
			d[i] = max(d[i], d[i - j] + p[j]);
		}
	}

	printf("%d", d[N]);
	delete[] p;
	delete[] d;
	return 0;
}

int max(int a, int b)
{
	return a > b ? a : b;;
}
