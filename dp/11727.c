#include <iostream>
using namespace std;


int main()
{
	int n = 0;
	scanf("%d", &n);
	int* tile = new int[n + 1];
	tile[1] = 1;
	tile[2] = 3;
	for (int i = 3; i <= n; i++)
	{
		tile[i] = (tile[i - 1] + 2 * tile[i - 2]) % 10007;
	}
	printf("%d", tile[n]);
	delete[] tile;
}

