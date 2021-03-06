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
		long long d[101];
		d[0] = 1;
		d[1] = 1;
		d[2] = 1;
		d[3] = 2;
		d[4] = 2;
		for (int i = 5; i < n; i++)
		{
			d[i] = d[i - 1] + d[i - 5];
		}

		printf("%lld\n", d[n - 1]);
	}
	return 0;
}
