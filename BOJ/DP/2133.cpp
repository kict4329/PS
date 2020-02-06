#include <iostream>

using namespace std;

int n;
int dp[31];

int main()
{
	cin >> n;
	dp[0] = 1;
	for (int i = 1; i <= n; i++)
	{
		if (i == 1)
			dp[i] = 0;
		else if (i == 2)
			dp[2] = 3;
		else if (i % 2 == 0)
			dp[i] = dp[i - 2] * (dp[2] + 1) - dp[i - 4];
	}

	cout << dp[n];

	return 0;
}