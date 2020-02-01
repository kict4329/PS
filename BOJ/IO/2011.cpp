#include <iostream>
#include <string>

using namespace std;

int n;
int dp[5001];
string password;

int main()
{
	cin >> password;
	int size = password.size();
	dp[0] = 1;
	for (int i = 1; i <= size; i++)
	{
		if (i == 1)
			dp[i] = 1;
		else
		{
			if ((password[i - 1] - '0') == 0)
			{
				if (((password[i - 2] - '0') * 10 + (password[i - 1] - '0')) < 27 && 9 < ((password[i - 2] - '0') * 10 + (password[i - 1] - '0')))
					dp[i] = dp[i - 2];
				else
					break;
			}
			else if (((password[i - 2] - '0') * 10 + (password[i - 1] - '0')) < 27 && 9 < ((password[i - 2] - '0') * 10 + (password[i - 1] - '0')))
				dp[i] = (dp[i - 2] + dp[i - 1]) % 1000000;
			else if (((password[i - 2] - '0') * 10 + (password[i - 1] - '0')) == 0)
			{
				break;
			}
			else
				dp[i] = dp[i - 1];
		}
	}

	if (password[0] == '0')
		cout << "0";
	else
		cout << dp[size];

	for (int i = 1; i <= size; i++)
	{
		cout << dp[i] << " ";
	}
	
	return 0;
}