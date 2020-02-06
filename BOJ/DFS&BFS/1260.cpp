#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int n, m, v;
int adj[1001][1001];
bool c[1001];

void dfs(int v)
{
	if (c[v])
		return;
	else
	{
		c[v] = true;
		cout << v << " ";
		for (int i = 1; i <= n; i++)
		{
			if (adj[v][i] && !c[i])
			{
				dfs(i);
			}
				
			else
				continue;
		}
	}
}

void bfs(int v)
{
	memset(c, false, sizeof(c));
	queue<int> q;
	q.push(v);
	c[v] = true;
	while (!q.empty())
	{
		int cur = q.front();
		q.pop();
		cout << cur << " ";

		for (int i = 1; i <= n; i++)
		{
			if (adj[cur][i])
			{
				if (!c[i])
				{
					c[i] = true;
					q.push(i);
				}
			}
		}
	}
	cout << "\n";
}

int main()
{
	cin >> n >> m >> v;
	for (int i = 1; i <= m; i++)
	{
		int a, b;
		cin >> a >> b;
		adj[a][b] = 1;
		adj[b][a] = 1;
	}

	dfs(v);
	cout << "\n";
	bfs(v);
	return 0;
}