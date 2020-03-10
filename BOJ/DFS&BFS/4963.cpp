#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;

int w, h;

int map[51][51];
bool visited[51][51];

int dx[] = { -1,0,1,1,1,0,-1,-1 };
int dy[] = { -1,-1,-1,0,1,1,1,0 };

vector<int> ans;

typedef struct Node
{
	int x, y;

	Node(int a, int b) :
		x(a), y(b) {	};
}Node;

void bfs(Node start);
bool isInside(Node node);

int main()
{
	while (1)
	{
		memset(map, 0, sizeof(map));
		memset(visited, false, sizeof(visited));

		cin >> w >> h;

		if (w == 0 && h == 0)
			break;
		
		for (int i = 1; i <= h; i++)
		{
			for (int j = 1; j <= w; j++)
				cin >> map[i][j];
		}

		int cnt = 0;

		for (int i = 1; i <= h; i++)
		{
			for (int j = 1; j <= w; j++)
			{
				if (!visited[i][j] && map[i][j])
				{
					bfs(Node(i, j));
					++cnt;
				}
			}
		}

		ans.push_back(cnt);
	}

	for (unsigned int i = 0; i < ans.size(); i++)
		cout << ans[i] << "\n";

	return 0;
}

void bfs(Node start)
{
	queue<Node> q;

	q.push(start);
	visited[start.x][start.y] = true;

	while (!q.empty())
	{
		Node cur = q.front();
		q.pop();

		for (int i = 0; i < 8; i++)
		{
			Node next(cur.x + dx[i], cur.y + dy[i]);

			if (map[next.x][next.y] && isInside(next) && !visited[next.x][next.y])
			{
				q.push(next);
				visited[next.x][next.y] = true;
			}
		}
	}
}

bool isInside(Node node)
{
	return ((node.x > 0 && node.x < h + 1) && (node.y > 0 && node.y < w + 1));
}