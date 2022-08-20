#include <iostream>

using namespace std;

#define MAX_N 10
int N, E;
int graph[MAX_N][MAX_N];
bool visited[MAX_N];

void dfs(int);

int main()
{
	cin >> N >> E;

	// allocate visited, graph to false
	for (int i = 0; i < MAX_N; i++)
	{
		visited[i] = 0;
		for (int j = 0; j < MAX_N; j++)
		{
			graph[i][j] = 0;
		}
	}

	// 
	int u, v;
	for (int i = 0; i < E; i++)
	{
		cin >> u >> v;
		graph[u][v] = graph[v][u] = 1;
	}
	dfs(0);
	
	return 0;
}

void dfs(int node)
{
	visited[node] = true;
	cout << node << ' ';

	for (int next = 0; next < N; next++)
	{
		if (!visited[next] && graph[node][next])
		{
			dfs(next); // recursion
		}
	}
}
