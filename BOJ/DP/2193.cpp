#include <iostream>
#include <vector>

using namespace std;

vector<vector<long long>> dp;

int main()
{
	int n;
	cin >> n;

	for (int i = 0; i <= n; i++)
	{
		vector<long long> temp;
		if (i == 0)
		{
			temp.push_back(0);
			temp.push_back(0);
			temp.push_back(0);
			dp.push_back(temp);
		}

		else if (i == 1)
		{
			temp.push_back(0);
			temp.push_back(1);
			temp.push_back(temp[0] + temp[1]);
			dp.push_back(temp);
		}

		else
		{
			temp.push_back(dp[i - 1][0] + dp[i - 1][1]);
			temp.push_back(dp[i - 1][0]);
			temp.push_back(temp[0] + temp[1]);
			dp.push_back(temp);
			/*dp[i].push_back(dp[i - 1][0] + dp[i - 1][1]);
			dp[i].push_back(dp[i - 1][0]);
			dp[i].push_back(dp[i][0] + dp[i][1]);*/
		}
	}
	cout << dp[n][2];

	return 0;
}