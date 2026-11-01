#include <stdio.h>
#include <string.h>

int a[10][10], visited[10], n;
char files[10][30];

void BFS(int start)
{
    int q[10], front = 0, rear = 0, i;
    for(i = 0; i < n; i++)
        visited[i] = 0;

    q[rear++] = start;
    visited[start] = 1;

    printf("\nBFS: ");
    while(front < rear)
    {
        int v = q[front++];
        printf("%s ", files[v]);

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
    printf("%s ", files[v]);

    for(i = 0; i < n; i++)
        if(a[v][i] && !visited[i])
            DFS(i);
}

int main()
{
    int i, j, start, found = 0;
    char search[30];

    printf("Enter number of files/folders: ");
    scanf("%d", &n);

    printf("Enter file/folder names:\n");
    for(i = 0; i < n; i++)
        scanf("%s", files[i]);

    printf("Enter adjacency matrix:\n");
    for(i = 0; i < n; i++)
        for(j = 0; j < n; j++)
            scanf("%d", &a[i][j]);

    printf("Enter starting node (0 to %d): ", n-1);
    scanf("%d", &start);

    BFS(start);

    for(i = 0; i < n; i++)
        visited[i] = 0;

    printf("\nDFS: ");
    DFS(start);

    printf("\nEnter file to search: ");
    scanf("%s", search);

    for(i = 0; i < n; i++)
        if(strcmp(files[i], search) == 0)
        {
            found = 1;
            break;
        }

    if(found)
        printf("File Found!");
    else
        printf("File Not Found!");

    return 0;
}
