#include <iostream>
using namespace std;

int max(int a, int b);

int main()
{
	int T = 0;
	scanf("%d", &T);
	while (T--)
	{
		int n = 0;
		scanf("%d", &n);
		int **sticker = new int*[2];
		int **d = new int*[2];
		for (int i = 0; i < 2; i++)
		{
			sticker[i] = new int[n + 1];
			d[i] = new int[n + 1];
		}

		for (int i = 1; i < n + 1; i++)
		{
			scanf("%d", &sticker[0][i]);
		}
		for (int i = 1; i < n + 1; i++)
		{
			scanf("%d", &sticker[1][i]);
		}
		d[0][0] = 0;
		d[1][0] = 0;
		d[0][1] = sticker[0][1];
		d[1][1] = sticker[1][1];
		
		for (int i = 2; i < n + 1; i++)
		{
			d[0][i] = sticker[0][i] + max(d[1][i - 1], d[1][i - 2]);
			d[1][i] = sticker[1][i] + max(d[0][i - 1], d[0][i - 2]);
		}

		printf("%d\n", max(d[0][n], d[1][n]));

		for (int i = 0; i < 2; i++)
		{
			delete[] sticker[i];
			delete[] d[i];
		}
		delete[] sticker;
		delete[] d;
	}
	return 0;
}

int max(int a, int b)
{
	return a > b ? a : b;
}
