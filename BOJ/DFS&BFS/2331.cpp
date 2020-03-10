#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int a, p;
int visited[300000];

void dfs(int a);

int main()
{
	cin >> a >> p;

	dfs(a);

	int ans = 0;

	for (int i = 1; i < 300000; i++)
	{
		if (visited[i] == 1)
			++ans;
	}

	cout << ans << "\n";

	return 0;
}

void dfs(int n)
{
	++visited[n];

	if (visited[n] == 3)
		return;

	int next = 0;

	while (n > 0)
	{
		next += (int)(pow(n % 10, p));
		n /= 10;
	}
	
	dfs(next);
}