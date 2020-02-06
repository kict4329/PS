#include <iostream>

using namespace std;

int t;

int main()
{
	cin >> t;

	for (int i = 1; i <= t; i++)
	{
		int n;
		cin >> n;
		int dp[101] = { 1,1,1,1,2,2, };
		for (int j = 6; j <= n; j++)
		{
			dp[j] = dp[j - 1] + dp[j - 5];
		}
		cout << dp[n] << "\n";
	}

	
	return 0;
}