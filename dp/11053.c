#include <iostream>
using namespace std;

int max(int a, int b);

int main()
{
	int n = 0;
	scanf("%d", &n);
	int * a = new int[n];
	int * d = new int[n];
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		d[i] = 1;
		for (int j = 0; j < i; j++)
		{
			if (a[i] > a[j])
			{
				d[i] = max(d[i], d[j] + 1);
			}
		}
		sum = max(sum, d[i]);
	}
	printf("%d", sum);

	delete[] a;
	delete[] d;
	return 0;
}

int max(int a, int b)
{
	return a > b ? a : b;
}
