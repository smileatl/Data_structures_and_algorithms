#include <iostream>
using namespace std;

#define MAXSIZE 100

//边表的定义
struct ArcNode {
	int adjvex;
	int weight;
	ArcNode* nextarc;
};

//顶点表的定义
struct VNode {
	int data; 
	ArcNode* firstarc;
};

//图的定义
struct ALGraph {
	VNode vexs[MAXSIZE];
	int vexnum, arcnum;
};

//邻接表的LocateVex函数
int LocateVex(ALGraph& G, const char& v) {
	for (int i = 0; i < G.vexnum; i++) {
		if (G.vexs[i].data == v) {
			return i;
		}
	}
	return -1;
}

//创建无向图算法
void CreatUDG(ALGraph& G) {
	cout << "info" << endl;
	cin >> G.vexnum >> G.arcnum;
	for (int i = 0; i < G.vexnum; i++) {
		cin >> G.vexs[i].data;
		G.vexs[i].firstarc = nullptr;
	}
	for (int j = 0; j < G.arcnum; j++) {
		cout << "input info about arc" << endl;
		char a, b;
		int w;
		cin >> a >> b >> w;
		int i = LocateVex(G, a);
		int j = LocateVex(G, b);
		ArcNode* p = new ArcNode;
		p->adjvex = j;
		p->weight = w;
		p->nextarc = G.vexs[i].firstarc;
		G.vexs[i].firstarc = p;

		ArcNode* q = new ArcNode;
		q->adjvex = i;
		q->weight = w;
		q->nextarc = G.vexs[j].firstarc;
		G.vexs[j].firstarc = q;
	}
}

//深度优先遍历算法DFS
int visited[MAXSIZE] = {};
void DFS_AL(ALGraph& G, int v) {
	//访问v代表的顶点
	cout << G.vexs[v].data << endl;
	//访问之后，顶点标记为1
	visited[v] = 1;
	//访问该顶点之后的边结点
	ArcNode* p = G.vexs[v].firstarc;
	while (p != nullptr) {
		int i = p->adjvex;
		if (visited[i] == 0) {
			DFS_AL(G, i);
		}
		p = p->nextarc;
	}
}

//广度优先遍历算法BFS
void BFS(ALGraph G, int v) {

}

int main()
{
	

	system("pause");
	return 0;
}