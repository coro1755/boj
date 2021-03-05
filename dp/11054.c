#include <iostream>
using namespace std;

int max(int a, int b);

int main()
{
	int n = 0;
	scanf("%d", &n);
	int * a = new int[n];
	int * d1 = new int[n];
	int * d2 = new int[n];
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}

	for (int i = 0; i < n; i++)
	{
		d1[i] = 1;
		for (int j = 0; j < i; j++)
		{
			if (a[i] > a[j])
			{
				d1[i] = max(d1[i], d1[j] + 1);
			}
		}
	}
	for (int i = n - 1; i >= 0; i--)
	{
		d2[i] = 1;
		for (int j = n - 1; j > i; j--)
		{
			if (a[i] > a[j])
			{
				d2[i] = max(d2[i], d2[j] + 1);
			}
		}
	}
	int ans = d1[0] + d2[0] - 1;
	for (int i = 1; i < n; i++)
	{
		ans = max(ans, d1[i] + d2[i] - 1);
	}
	printf("%d", ans);

	delete[] a;
	delete[] d1;
	delete[] d2;
	return 0;
}

int max(int a, int b)
{
	return a > b ? a : b;
}
