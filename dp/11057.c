#include <iostream>
#define LIMIT 10007
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

	for (int i = 0; i < 10; i++)
	{
		d[1][i] = 1;
	}

	for (int i = 2; i < n + 1; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			d[i][j] = 0;
			for (int k = 0; k <= j; k++)
			{
				d[i][j] += d[i - 1][j - k];
				d[i][j] %= LIMIT;
			}
		}
	}
	int ans = 0;
	for (int i = 0; i < 10; i++)
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

