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

	d[0] = a[0];
	d[1] = a[0] + a[1];
	d[2] = max(a[0] + a[2], a[1] + a[2]);

	for (int i = 3; i < n; i++)
	{
		d[i] = max(d[i - 2] + a[i], d[i - 3] + a[i - 1] + a[i]);
	}

	printf("%d", d[n - 1]);

	delete[] a;
	delete[] d;
	return 0;
}

int max(int a, int b)
{
	return a > b ? a : b;
}
