#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <fstream>
using namespace std;

class cell {
public:
	int id, wall, visited, from;

	cell() { visited = 0; from = -1; }

};

void DFS(vector<cell> &maze, int n, int start, int end);
void BFS(vector<cell> &maze, int n, int start, int end);

int main() {
	int n = 30;
	vector<cell> maze(n*n);
	ifstream in("maze.txt");

	for (int i = 0; i < n*n; i++) {
		maze[i].id = i;
		in >> maze[i].wall;
		cout << maze[i].wall << endl;
	}
	for (int i = 0; i < n*n; i++) {
		cout << maze[i].id << " " << maze[i].wall << endl;
	}

	DFS(maze, n, 0, n*n - 1);

	for (int i = 0; i < n*n; i++) {
		maze[i].visited = 0;
		maze[i].from = -1;
	}
	
	BFS(maze, n, 0, n*n - 1);
	getchar();
	getchar();
	return 0;
}

void DFS(vector<cell> &maze, int n, int start, int end) {

	int a = start;
	stack<cell> v;
	
	v.push(maze[start]);
	v.top();
	

	do {
		int from = 0;

		v.top();

		if (maze[a].wall % 2 < 1) {
			v.push(maze[a]);
			maze[a].visited = 1;
			maze[a + n].from = a;
			a = a + n;
		}
		else if (maze[a].wall % 4 < 2) {
			v.push(maze[a]);
			maze[a].visited = 1;
			maze[a + 1].from = a;
			a = a + 1;
		}
		else if (maze[a].wall % 8 < 4) {
			v.push(maze[a]);
			maze[a].visited = 1;
			maze[a - n].from = a;
			a = a - n;
		}
		else if (maze[a].wall % 16 < 8) {
			v.push(maze[a]);
			maze[a].visited = 1;
			maze[a - 1].from = a;
			a = a - 1;
		}
		cout << maze[a].id << endl;

	} while (a != end);
	
	do {
		cell x = v.top();
		v.pop();
		cout << "id: " << x.id << endl;
	} while (v.size() != 0);
}

void BFS(vector<cell> &maze, int n, int start, int end) {
	int a = start;
	queue<cell> v;

	v.push(maze[start]);
	v.front();


	do {
		int from = 0;

		v.front();

		if (maze[a].wall % 2 < 1) {
			v.push(maze[a]);
			maze[a].visited = 1;
			maze[a + n].from = a;
			a = a + n;
		}
		else if (maze[a].wall % 4 < 2) {
			v.push(maze[a]);
			maze[a].visited = 1;
			maze[a + 1].from = a;
			a = a + 1;
		}
		else if (maze[a].wall % 8 < 4) {
			v.push(maze[a]);
			maze[a].visited = 1;
			maze[a - n].from = a;
			a = a - n;
		}
		else if (maze[a].wall % 16 < 8) {
			v.push(maze[a]);
			maze[a].visited = 1;
			maze[a - 1].from = a;
			a = a - 1;
		}
		cout << maze[a].id << endl;

	} while (a != end);

	do {
		cell x = v.front();
		v.front();
		cout << "id: " << x.id << endl;
	} while (v.size() != 0);
}