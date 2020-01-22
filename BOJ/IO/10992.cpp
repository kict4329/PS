#include <iostream>

using namespace std;

int main()
{
	int n;
	cin >> n;

	for (int i = 1; i < n; i++)
	{
		for (int j = i; j < n; j++)
		{
			cout << " ";
		}
		for (int j = 1; j <= 2 * i - 1; j++)
		{
			if (j == 1 || j == 2 * i - 1)
				cout << "*";
			else
				cout << " ";
		}
		cout << endl;
	}
	for (int j = 1; j <= 2 * n - 1; j++)
	{
		cout << "*";
	}
	return 0;
}