#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int n, m;
vector<int> adj[1001]; // �ε��� 1���� Ž��
bool c[1001] = { false };

void dfs(int s)
{
	if (c[s] == true)
		return; // �̹� �湮�� �༮�̶��
	else
	{
		c[s] = true;

		for (unsigned int i = 0; i < adj[s].size(); i++)
		{
			dfs(adj[s][i]);
		}
	}
}

int main()
{
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int u, v;

		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
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

	return 0;
}