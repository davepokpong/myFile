#include <bits/stdc++.h>
using namespace std;

list <int> q;

vector <int> graph[1000];

int degree[1000];
int visited[1000];


void addNode(int a , int b) {
    graph[a].push_back(b);
    graph[b].push_back(a);

    degree[a]++;
    degree[b]++;
}
// queue
void BFS(int start) {
    int current,next;
    q.push_back(start);
    while (!q.empty()) {
        current = q.front();
        q.pop_front();
        visited[current] = 1;
        printf("node: %d\n"  , current);
        for (int i=0 ; i<degree[current] ; i++) {
            next = graph[current][i];
            if (!visited[next]) {
                q.push_back(next);
            }
        }

    }
}

void DFS(int src) {
    int next;
    visited[src] = 1;
    printf("node: %d\n" , src);
    for (int i=0 ; i<degree[src] ; i++) {
        next = graph[src][i];
        if (!visited[next]) {
            DFS(next);
        }
    }
}

int main() {

    addNode(1,2);
    addNode(1,3);
    addNode(1,4);
    addNode(3,5);
    addNode(4,6);
    addNode(5,7);
    addNode(5,8);
    addNode(6,9);
    BFS(1);
    printf("\n");
    for (int i=0 ; i<1000 ; i++) {
        visited[i] = 0;
    }
    DFS(1);
} 