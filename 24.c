#include <stdio.h>
#include <stdlib.h>

#define MAX 100

struct Queue {
    int items[MAX];
    int front;
    int rear;
};

struct Queue* createQueue() {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->front = -1;
    queue->rear = -1;
    return queue;
}

int isEmpty(struct Queue* queue) {
    return queue->front == -1;
}

void enqueue(struct Queue* queue, int value) {
    if (queue->rear == MAX - 1)
        printf("Queue is full\n");
    else {
        if (queue->front == -1)
            queue->front = 0;
        queue->rear++;
        queue->items[queue->rear] = value;
    }
}

int dequeue(struct Queue* queue) {
    int value;
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
        return -1;
    } else {
        value = queue->items[queue->front];
        queue->front++;
        if (queue->front > queue->rear) {
            queue->front = queue->rear = -1;
        }
        return value;
    }
}

void DFS(int graph[MAX][MAX], int visited[MAX], int start, int vertices) {
    int i;

    printf("%d ", start);
    visited[start] = 1;

    for (i = 0; i < vertices; i++) {
        if (!visited[i] && graph[start][i] == 1)
            DFS(graph, visited, i, vertices);
    }
}

void BFS(int graph[MAX][MAX], int visited[MAX], int start, int vertices) {
    struct Queue* queue = createQueue();

    visited[start] = 1;
    printf("%d ", start);
    enqueue(queue, start);

    while (!isEmpty(queue)) {
        int current = dequeue(queue);

        for (int i = 0; i < vertices; i++) {
            if (!visited[i] && graph[current][i] == 1) {
                visited[i] = 1;
                printf("%d ", i);
                enqueue(queue, i);
            }
        }
    }
}

int main() {
    int graph[MAX][MAX], visited[MAX];
    int vertices, edges, i, j;

    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);

    for (i = 0; i < vertices; i++) {
        visited[i] = 0;
        for (j = 0; j < vertices; j++)
            graph[i][j] = 0;
    }

    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    printf("Enter the edges (in the format 'source destination'): \n");
    for (i = 0; i < edges; i++) {
        int source, destination;
        scanf("%d %d", &source, &destination);
        graph[source][destination] = 1;
        // Directed Graph
        // graph[destination][source] = 1;
    }

    printf("\nDFS Traversal: ");
    for (i = 0; i < vertices; i++) {
        if (!visited[i])
            DFS(graph, visited, i, vertices);
    }

    for (i = 0; i < vertices; i++)
        visited[i] = 0;

    printf("\nBFS Traversal: ");
    for (i = 0; i < vertices; i++) {
        if (!visited[i])
            BFS(graph, visited, i, vertices);
    }

    return 0;
}
