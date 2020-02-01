#include <iostream>

using namespace std;

int n, k;
int dp[201][201];

int main()
{
	cin >> n >> k;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= k; j++)
		{
			if (j == 1)
				dp[i][j] = 1;
			else if (i == 1)
				dp[i][j] = j;
			else
				dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % 1000000000;
		}
	}

	cout << dp[n][k];

	return 0;
}