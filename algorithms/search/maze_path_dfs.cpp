#include<iostream>
#include<vector>
#include<string>

using namespace std;

int n, m;
vector<string>maze;
vector<vector<bool>>visited;

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

bool dfs(int x, int y) {
	if (x == n - 1 && y == m - 1) {
		return true;
	}

	visited[x][y] = true;

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx >= 0 && nx < n &&
			ny >= 0 && ny < m &&
			maze[nx][ny] != '#' &&
			!visited[nx][ny])
		{
			if (dfs(nx, ny))
			{
				return true;
			}
		}
	}
	return false;
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		maze.push_back(s);
	}
	visited.resize(n, vector<bool>(m, false));

	if (dfs(0, 0)) {
		cout << "Yes";
	}
	else {
		cout << "No";
	}

	return 0;
}