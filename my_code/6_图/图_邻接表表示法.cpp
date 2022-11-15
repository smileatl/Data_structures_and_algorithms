#include <iostream>
using namespace std;

#define MAXSIZE 100

//�߱�Ķ���
struct ArcNode {
	int adjvex;
	int weight;
	ArcNode* nextarc;
};

//�����Ķ���
struct VNode {
	int data; 
	ArcNode* firstarc;
};

//ͼ�Ķ���
struct ALGraph {
	VNode vexs[MAXSIZE];
	int vexnum, arcnum;
};

//�ڽӱ��LocateVex����
int LocateVex(ALGraph& G, const char& v) {
	for (int i = 0; i < G.vexnum; i++) {
		if (G.vexs[i].data == v) {
			return i;
		}
	}
	return -1;
}

//��������ͼ�㷨
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

//������ȱ����㷨DFS
int visited[MAXSIZE] = {};
void DFS_AL(ALGraph& G, int v) {
	//����v����Ķ���
	cout << G.vexs[v].data << endl;
	//����֮�󣬶�����Ϊ1
	visited[v] = 1;
	//���ʸö���֮��ı߽��
	ArcNode* p = G.vexs[v].firstarc;
	while (p != nullptr) {
		int i = p->adjvex;
		if (visited[i] == 0) {
			DFS_AL(G, i);
		}
		p = p->nextarc;
	}
}

//������ȱ����㷨BFS
void BFS(ALGraph G, int v) {

}

int main()
{
	

	system("pause");
	return 0;
}