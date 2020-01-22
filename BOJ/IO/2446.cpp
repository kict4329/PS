#include <iostream>

using namespace std;

int main(void)
{
	int n;
	cin >> n;

	for (int i = 1; i <= 2 * n - 1; ++i)
	{
		for (int j = 1; j < 2 * n; j++)
		{
			int k = i;
			if (i > n)
				k = 2 * n - i;

			/*if (j <= k - 1 || 2 * n - k + 1 <= j)
				cout << " ";
			else
				cout << "*";*/
			if (j > k - 1 && 2 * n - k + 1 > j)
				cout << "*";
			else if (j <= k - 1)
				cout << " ";
		}
		cout << "\n";
	}

	return 0;
}