#include <iostream>
using namespace std;

#define MAXSIZE 10

//图的定义
struct AMGraph {
	char vexs[MAXSIZE];
	int arcs[MAXSIZE][MAXSIZE];
	int vexnum, arcnum;
};

int LocateVex(AMGraph& G, const char& e) {
	for (int i = 0; i < G.vexnum; i++) {
		if (G.vexs[i] = e) {
			return i;
		}
	}
	return -1;
}

//创建无向图
void CreatUDN(AMGraph& G) {
	cout << "input num" << endl;
	cin >> G.arcnum >> G.arcnum;

	cout << "input vexs" << endl;
	for (int i = 0; i < G.vexnum; i++) {
		cin >> G.vexs[i];
	}
	for (int i = 0; i < G.arcnum; i++) {
		for (int j = 0; j < G.arcnum; i++) {
			G.arcs[i][j] = INT32_MAX;
		}
	}
	for (int k = 0; k < G.arcnum; k++) {
		int i, j, weight;
		char a, b;
		cin >> a >> b >> weight;
		i = LocateVex(G, a);
		j = LocateVex(G, b);
		G.arcs[i][j] = G.arcs[j][i] = weight;
	}
}

//深度优先遍历算法DFS
int visited[MAXSIZE] = {};
void DFS_AM(AMGraph& G, int v) {
	cout << G.vexs[v];
	visited[v] = 1;
	for (int w = 0; w < G.vexnum; w++) {
		if ((G.arcs[v][w] != 0 && visited[w] == 0)) {
			DFS_AM(G, w);
		}
	}
}

//广度优先遍历算法BFS
void BFS_AM(AMGraph& G) {
	for (int v = 0; v < G.vexnum; v++) {
		for (int w = 0; w < G.vexnum; w++) {
			if ((G.arcs[v][w] != 0 && visited[w] == 0)) {
				cout << G.vexs[w];
				visited[w] = 1;
			}
		}
	}
}

int main()
{


	system("pause");
	return 0;
}