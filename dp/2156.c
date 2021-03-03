#include <iostream>
using namespace std;

int max(int a, int b, int c);

int main()
{
	int n = 0;
	scanf("%d", &n);
	int *juice = new int[n + 1];
	int *d = new int[n + 1];
	for (int i = 1; i < n + 1; i++)
	{
		scanf("%d", &juice[i]);
	}
	d[0] = 0;
	d[1] = juice[1];
	d[2] = juice[1] + juice[2];
	for (int i = 3; i < n + 1; i++)
	{
		d[i] = max(d[i - 1], d[i - 2] + juice[i], d[i - 3] + juice[i] + juice[i - 1]);
	}
	printf("%d", d[n]);
	delete[] juice;
	delete[] d;
	return 0;
}

int max(int a, int b, int c)
{
	int tmp = a;
	tmp = tmp > b ? tmp : b;
	tmp = tmp > c ? tmp : c;
	return tmp;
}