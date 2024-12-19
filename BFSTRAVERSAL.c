#include<stdio.h>
#define MAX 5

void dfs(int adj[][MAX], int visited[], int start) {
    int stack[MAX], top= -1, i;
    for (int k = 0; k < MAX; k++)
        visited[k] = 0;


    stack[++top] = start;
    visited[start] = 1;

    printf("BFS Traversal: ");
    while (top!=-1) {
        start = stack[top--];
        printf("%d->", start);


        for (i = 0; i < MAX; i++) {
            if (adj[start][i] && visited[i] == 0) {
                stack[++top] = i;
                visited[i] = 1;
            }
        }
    }
    printf("NULL\n");
}

int main() {
    int visited[MAX] = {0};
    int adj[MAX][MAX], i, j;
    int start;

    printf("\nEnter the adjacency matrix (5x5)To find DFS:\n");
    for (i = 0; i < MAX; i++)
        for (j = 0; j < MAX; j++)
            scanf("%d", &adj[i][j]);
    printf("Enter starting element 0-4:\n");
    scanf("%d",&start);
    dfs(adj, visited, start);
    return 0;
}
