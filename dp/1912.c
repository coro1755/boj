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
	int ans = a[0];
	for (int i = 1; i < n; i++)
	{
		d[i] = max(d[i - 1] + a[i], a[i]);
		ans = max(ans, d[i]);
	}

	printf("%d", ans);

	delete[] a;
	delete[] d;
	return 0;
}

int max(int a, int b)
{
	return a > b ? a : b;
}
