#include <iostream>
using namespace std;

int main()
{
	int K , N;
	scanf("%d %d", &N, &K);
	int d[201][201] = { 0, };
	for (int i = 0; i <= N; i++)
	{
		d[1][i] = 1;
		d[2][i] = i + 1;
	}

	for (int i = 3; i <= K; i++)
	{
		for (int j = 0; j <= N; j++)
		{
			for (int k = 0; k <= j; k++)
			{
				d[i][j] += d[i - 1][k];
				d[i][j] %= 1000000000;
			}
		}
	}
	printf("%d", d[K][N]);
	return 0;
}
