#include <stdio.h>

int a[10][10], visited[10], n;

void BFS(int start)
{
    int q[10], front = 0, rear = 0, i;
    for(i = 0; i < n; i++)
        visited[i] = 0;

    q[rear++] = start;
    visited[start] = 1;

    printf("BFS: ");
    while(front < rear)
    {
        int v = q[front++];
        printf("%d ", v);

        for(i = 0; i < n; i++)
            if(a[v][i] && !visited[i])
            {
                q[rear++] = i;
                visited[i] = 1;
            }
    }
}

void DFS(int v)
{
    int i;
    visited[v] = 1;
    printf("%d ", v);

    for(i = 0; i < n; i++)
        if(a[v][i] && !visited[i])
            DFS(i);
}

int main()
{
    int i, j, start;

    printf("Enter number of folders: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for(i = 0; i < n; i++)
        for(j = 0; j < n; j++)
            scanf("%d", &a[i][j]);

    printf("Enter starting folder: ");
    scanf("%d", &start);

    BFS(start);

    for(i = 0; i < n; i++)
        visited[i] = 0;

    printf("\nDFS: ");
    DFS(start);

    return 0;
}
