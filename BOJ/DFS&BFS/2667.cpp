#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

int n;

int town[26][26];
int visited[26][26];
int cnt = 1;

int dx[] = { 0,1,0,-1 };
int dy[] = { -1,0,1,0 };

vector<int> ans;

typedef struct Node
{
	int x; // 몇번째 열인지, 가로좌표
	int y; // 몇번째 행인지, 세로좌표

	Node(int a, int b)
		: x(a), y(b)
	{	};

}Node;

bool isInside(Node node)
{
	int x = node.x;
	int y = node.y;
	return ((node.x >= 0 && node.x < n + 1) && (node.y >= 0 && node.y < n + 1));
}

void bfs(Node start)
{
	int aptcnt = 1;

	queue<Node> q;

	q.push(start);
	visited[start.x][start.y] = true;

	while (!q.empty())
	{
		Node cur = q.front();
		visited[cur.x][cur.y] = true;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			Node next = Node(cur.x + dx[i], cur.y + dy[i]);
			if (town[next.x][next.y] && isInside(next) && !visited[next.x][next.y])
			{
				++aptcnt;
				q.push(next);
				visited[next.x][next.y] = cnt;
			}
		}
	}
	ans.push_back(aptcnt);
}

int main()
{
	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		string a = "";
		cin >> a;
		for (int j = 1; j <= n; j++)
		{
			town[i][j] = a[j - 1] - '0';
		}
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (town[i][j] && !visited[i][j])
			{
				bfs(Node(i, j));
				++cnt;
			}
		}
	}

	cout << cnt - 1 << "\n";

	sort(ans.begin(), ans.end());

	for (int i = 0; i < ans.size(); i++)
		cout << ans[i] << "\n";

	return 0;
}