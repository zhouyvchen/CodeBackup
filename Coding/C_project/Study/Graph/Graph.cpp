#include <stdio.h>
#include <stdlib.h>

#define INF 30000  // 定义∞
#define MAXV 100   // 最大顶点个数

// 定义顶点类型
typedef char InfoType;

typedef struct {
    int no;         // 顶点编号
    InfoType info;  // 顶点其他信息
} VertexType;       // 顶点类型

// 定义边节点类型
typedef struct ANode {
    int adjvex;             // 该边的邻接点编号
    struct ANode* nextarc;  // 指向下一条边的指针
    int weight;  // 该边的相关信息，如权值（用整型表示）
} ArcNode;       // 边节点类型

// 定义邻接表头节点类型
typedef struct Vnode {
    InfoType info;      // 顶点其他信息
    ArcNode* firstarc;  // 指向第一条边
} VNode;                // 邻接表头节点类型

// 定义邻接表类型
typedef struct {
    VNode adjlist[MAXV];  // 邻接表头节点数组
    int n, e;             // 图中顶点数n和边数e
} AdjGraph;

// 创建图的邻接表
void CreateAdj(AdjGraph* G, int A[MAXV][MAXV], int n, int e) {
    G->n = n;  // 设置图的顶点数
    G->e = e;  // 设置图的边数

    // 初始化所有顶点的第一条边为NULL
    for (int i = 0; i < n; i++) {
        G->adjlist[i].firstarc = NULL;
    }

    // 根据邻接矩阵创建邻接表
    for (int i = 0; i < n; i++) {
        for (int j = n - 1; j >= 0; j--) {
            // 如果存在边
            if (A[i][j] != INF) {
                // 创建新的边节点
                ArcNode* arcNode = (ArcNode*)malloc(sizeof(ArcNode));
                arcNode->adjvex = j;        // 设置邻接点编号
                arcNode->weight = A[i][j];  // 设置权值
                arcNode->nextarc =
                    G->adjlist[i].firstarc;  // 将新节点插入到链表的头部
                G->adjlist[i].firstarc = arcNode;  // 更新头节点的第一条边
            }
        }
    }
}

// 输出邻接表G
void DispAdj(AdjGraph* G) {
    printf("邻接表：\n");
    // 遍历所有顶点
    for (int i = 0; i < G->n; i++) {
        ArcNode* arcNode = G->adjlist[i].firstarc;  // 获取顶点的第一条边
        printf("顶点 %d:", i);
        // 遍历顶点的所有边
        while (arcNode != NULL) {
            printf(" -> %d (%d)", arcNode->adjvex,
                   arcNode->weight);     // 打印邻接点编号和权值
            arcNode = arcNode->nextarc;  // 转到下一条边
        }
        printf("\n");
    }
}

int main() {
    AdjGraph G;                       // 创建邻接表
    int adjacencyMatrix[MAXV][MAXV];  // 创建邻接矩阵
    int n, e;                         // 顶点数和边数

    printf("请输入顶点数：");
    scanf("%d", &n);  // 读取顶点数
    printf("请输入边数：");
    scanf("%d", &e);  // 读取边数

    printf("请输入邻接矩阵（用INF表示无穷大）：\n");
    // 读取邻接矩阵
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &adjacencyMatrix[i][j]);
        }
    }

    CreateAdj(&G, adjacencyMatrix, n, e);  // 根据邻接矩阵创建邻接表
    DispAdj(&G);                           // 打印邻接表

    return 0;
}
