#include <iostream>
using namespace std;

int min(int a, int b);

int main()
{
	int x = 0;
	scanf("%d", &x);
	int* make_one = new int[x+1];
	make_one[0] = 0;
	make_one[1] = 0;
	for (int i = 2; i <= x; i++)
	{
		make_one[i] = make_one[i - 1] + 1;
		if (i % 2 == 0)
			make_one[i] = min(make_one[i], make_one[i / 2] + 1);
		if (i % 3 == 0)
			make_one[i] = min(make_one[i], make_one[i / 3] + 1);
	}
	printf("%d", make_one[x]);
	delete[] make_one;
	return 0;
}

int min(int a, int b)
{
	return (a < b ? a : b);
}
