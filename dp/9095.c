#include <iostream>
using namespace std;


int main()
{
	int T = 0;
	scanf("%d", &T);
	while (T--)
	{
		int n = 0;
		scanf("%d", &n);
		int* a = new int[n + 1];
		a[1] = 1;
		a[2] = 2;
		a[3] = 4;
		for (int i = 4; i <= n; i++)
		{
			a[i] = (a[i - 1] + a[i - 2] + a[i - 3]) % 10007;
		}
		printf("%d\n", a[n]);
		delete[] a;
	}

	return 0;
}

