#include <iostream>
#include <queue>
#include <cstring>
#include <vector>

using namespace std;

int t, n;

vector<int> adj[1001];
bool c[1001];

void dfs(int s);

int main()
{
	cin >> t;

	for (int i = 0; i < t; i++)
	{
		cin >> n;

		/*for (int j = 0; j < 1001; j++)
			adj[j].clear();
		memset(c, false, sizeof(c));*/

		for (int j = 1; j <= n; j++)
		{
			int a;
			cin >> a;
			adj[j].push_back(a);
			adj[a].push_back(j);
		}
		
		int cnt = 0;

		for (int i = 1; i <= n; i++)
		{
			if (!c[i])
			{
				dfs(i);
				++cnt;
			}
		}
		cout << cnt << "\n";

		memset(adj, 0, sizeof(adj));
		memset(c, false, sizeof(c));
	}

	return 0;
}

void dfs(int s)
{
	if (c[s])
		return;
	else
	{
		c[s] = true;

		for (unsigned int i = 0; i < adj[s].size(); i++)
		{
			int next = adj[s][i];

			dfs(next);
		}
	}
}