#include <iostream>
using namespace std;

int main()
{
	int n = 0;
	scanf("%d", &n);
	int * d = new int[n + 1];
	d[0] = 1;
	d[1] = 0;
	for (int i = 2; i < n + 1; i++)
	{
		d[i] = 0;

		if (i % 2 == 0)
		{
			d[i] += d[i - 2] * 3;
			for (int j = 4; j <= i; j += 2)
			{
				d[i] += d[i - j] * 2;
			}
		}
	}

	printf("%d", d[n]);

	delete[] d;
	return 0;
}
