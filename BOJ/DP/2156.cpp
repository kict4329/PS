#include <iostream>
#include <algorithm>

using namespace std;

int n;
int dp[10001][3] = { 0, };
int p[10001];

int main()
{
	/*cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> p[i];
	}

	for (int i = 1; i <= n; i++)
	{
		if (i == 1)
		{
			dp[i][0] = 0;
			dp[i][1] = p[i];
			dp[i][2] = 0;
		}

		else
		{
			dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);
			dp[i][0] = max(dp[i][0], dp[i - 1][2]);
			dp[i][1] = dp[i - 1][0] + p[i];
			dp[i][2] = dp[i - 1][1] + p[i];
		}
	}

	int Max = 0;
	Max = max(dp[n][0], dp[n][1]);
	Max = max(Max, dp[n][2]);

	cout << Max;*/
	cout << p[0];
	return 0;
}