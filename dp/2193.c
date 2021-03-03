#include <iostream>
using namespace std;


int main()
{
	int n = 0;
	scanf("%d", &n);
	long long *d = new long long[n + 1];
	d[1] = 1;
	d[2] = 1;
	for (int i = 3; i < n + 1; i++)
	{
		d[i] = d[i - 1] + d[i - 2];
	}
	printf("%lld", d[n]);
	delete[] d;
	return 0;
}

