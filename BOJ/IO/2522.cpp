#include <iostream>

using namespace std;

int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= 2 * n - 1; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			int k = i;
			if (i > n)
				k = 2 * n - i;

			if (j >= n - k + 1)
				cout << "*";
			else
				cout << " ";
		}
		cout << "\n";
	}

	return 0;
}