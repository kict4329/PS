#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

int k, v, e;
int RED = 1, BLUE = -1;

vector<string> ans;
vector<int> adj[20001];
bool c[20001];
int colors[20001];

bool isBipartite()
{
	for (int i = 1; i < v; i++)
	{
		int curColor = colors[i];

		for (int j = 0; j < adj[i].size(); j++)
		{
			if (curColor == colors[adj[i][j]])
				return false;
		}
	}
	return true;
}

void dfs(int s, int color)
{
	if (c[s])
		return;
	else
	{
		c[s] = true;
		colors[s] = color;

		for (unsigned int i = 0; i < adj[s].size(); i++)
		{
			dfs(adj[s][i], -color);
		}
	}
}

int main()
{
	cin >> k;

	for (int i = 0; i < k; i++)
	{
		cin >> v >> e;

		for (int j = 0; j < e; j++)
		{
			int a, b;
			cin >> a >> b;
			adj[a].push_back(b);
			adj[b].push_back(a);
		}

		for (int j = 1; j <= v; j++)
		{
			if (!c[j])
				dfs(j, RED);
		}

		if (isBipartite())
			cout << "YES" << "\n";
		else
			cout << "NO" << "\n";

		memset(c, false, sizeof(c));
		memset(adj, 0, sizeof(adj));
		memset(colors, 0, sizeof(colors));
	}

	return 0;
}