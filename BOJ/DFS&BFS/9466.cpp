#include <iostream>
#include <cstring>

using namespace std;

int t, n;
int cnt;

int team[100001];
bool c[100001];
bool done[100001];

void dfs(int s)
{
	c[s] = true;

	int next = team[s];

	if (!c[next])
	{
		dfs(next);
	}

	else if (!done[next])
	{
		for (int i = next; i != s; i = team[i])
			++cnt;
		++cnt;
	}

	done[s] = true;

}

int main()
{
	cin >> t;

	for (int i = 0; i < t; i++)
	{
		memset(team, 0, sizeof(team));
		memset(c, false, sizeof(c));
		memset(done, false, sizeof(done));
	
		cin >> n;

		cnt = 0;

		for (int j = 1; j < n + 1; j++)
			cin >> team[j];

		for(int j=1;j<n+1;j++)
		{ 
			if (!c[j])
				dfs(j);
		}

		cout << n - cnt << "\n";
	}

	return 0;
}