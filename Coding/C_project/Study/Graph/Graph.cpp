#include <stdio.h>
#include <stdlib.h>

#define INF 30000  // 定义∞
#define MAXV 100   // 最大顶点个数

typedef char InfoType;

typedef struct {
    int no;         // 顶点编号
    InfoType info;  // 顶点其他信息
} VertexType;       // 顶点类型

typedef struct ANode {
    int adjvex;             // 该边的邻接点编号
    struct ANode* nextarc;  // 指向下一条边的指针
    int weight;  // 该边的相关信息，如权值（用整型表示）
} ArcNode;       // 边节点类型

typedef struct Vnode {
    InfoType info;      // 顶点其他信息
    ArcNode* firstarc;  // 指向第一条边
} VNode;                // 邻接表头节点类型

typedef struct {
    VNode adjlist[MAXV];  // 邻接表头节点数组
    int n, e;             // 图中顶点数n和边数e
} AdjGraph;

// 创建图的邻接表
void CreateAdj(AdjGraph* G, int A[MAXV][MAXV], int n, int e) {
    G->n = n;
    G->e = e;

    for (int i = 0; i < n; i++) {
        G->adjlist[i].firstarc = NULL;
    }

    for (int i = 0; i < n; i++) {
        for (int j = n - 1; j >= 0; j--) {
            if (A[i][j] != INF) {
                ArcNode* arcNode = (ArcNode*)malloc(sizeof(ArcNode));
                arcNode->adjvex = j;
                arcNode->weight = A[i][j];
                arcNode->nextarc = G->adjlist[i].firstarc;
                G->adjlist[i].firstarc = arcNode;
            }
        }
    }
}

// 输出邻接表G
void DispAdj(AdjGraph* G) {
    printf("邻接表：\n");
    for (int i = 0; i < G->n; i++) {
        ArcNode* arcNode = G->adjlist[i].firstarc;
        printf("顶点 %d:", i);
        while (arcNode != NULL) {
            printf(" -> %d (%d)", arcNode->adjvex, arcNode->weight);
            arcNode = arcNode->nextarc;
        }
        printf("\n");
    }
}

int main() {
    AdjGraph G;
    int adjacencyMatrix[MAXV][MAXV];
    int n, e;

    printf("请输入顶点数：");
    scanf("%d", &n);
    printf("请输入边数：");
    scanf("%d", &e);

    printf("请输入邻接矩阵（用INF表示无穷大）：\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &adjacencyMatrix[i][j]);
        }
    }

    CreateAdj(&G, adjacencyMatrix, n, e);
    DispAdj(&G);

    return 0;
}
