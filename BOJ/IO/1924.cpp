#include <iostream>
#include <vector>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	
	int x, y;
	cin >> x >> y;

	int days = -1;

	for (int i = 1; i < x; i++)
	{
		if (i == 2)
			days += 28;
		else if (i == 4 || i == 6 || i == 9 || i == 11)
			days += 30;
		else
			days += 31;
	}
	days += y;

	if (days % 7 == 0)
		cout << "MON";
	else if (days % 7 == 1)
		cout << "TUE";
	else if (days % 7 == 2)
		cout << "WED";
	else if (days % 7 == 3)
		cout << "THU";
	else if (days % 7 == 4)
		cout << "FRI";
	else if (days % 7 == 5)
		cout << "SAT";
	else
		cout << "SUN";

	return 0;
}