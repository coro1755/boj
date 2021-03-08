#include <iostream>
#define MOD 1000000
using namespace std;

int main()
{
	int a[5001] = { 0, };
	int N = 1;
	while (scanf("%1d", &a[N]) == 1)
	{
		N++;
	}
	int *d = new int[N];
	d[0] = 1;
	if (a[1] != 0)
		d[1] = 1;
	else
		d[1] = 0;
	for (int i = 2; i < N; i++)
	{
		d[i] = 0;
		if (a[i] > 0)
		{
			d[i] = (d[i] + d[i - 1]) % MOD;
		}
		int tmp = 10 * a[i - 1] + a[i];
		if (tmp >= 10 && tmp <= 26)
		{
			d[i] = (d[i] + d[i - 2]) % MOD;
		}
	}
	printf("%d", d[N - 1]);

	delete[] d;
	return 0;
}
