#include <iostream>
#define LIMIT 1000000000
using namespace std;


int main()
{
	int n = 0;
	scanf("%d", &n);
	int **d = new int*[n + 1];
	for (int i = 0; i < n + 1; i++)
	{
		d[i] = new int[10];
	}

	d[1][0] = 0;
	for (int i = 1; i < 10; i++)
	{
		d[1][i] = 1;
	}

	for (int i = 2; i <= n; i++)
	{
		d[i][0] = d[i - 1][1];
		d[i][9] = d[i - 1][8];

		for (int j = 1; j <= 8; j++)
		{
			d[i][j] = (d[i - 1][j - 1] + d[i - 1][j + 1]) % LIMIT;
		}
	}
	int ans = 0;
	for (int i = 0; i <= 9; i++)
	{
		ans += d[n][i];
		ans %= LIMIT;
	}
	printf("%d", ans);

	for (int i = 0; i < n + 1; i++)
	{
		delete[] d[i];
	}
	delete[] d;
	return 0;
}

