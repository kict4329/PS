#include <iostream>

using namespace std;

int n;
int dp[1001] = { 0, };
int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		if (i == 1)
			dp[1] = 1;
		else if (i == 2)
			dp[2] = 3;
		else
			dp[i] = (dp[i - 1] + dp[i - 2] * 2)%10007;
	}

	cout << dp[n];

	return 0;
}