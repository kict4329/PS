#include <iostream>
#include <ctime>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	
	int n;
	cin >> n;

	for (int i = 1; i < 10; i++)
	{
		cout << n << " * " << i << " = " << 2 * i << "\n";
	}
	return 0;
}