#include <bits/stdc++.h>
using namespace std;

vector <int> graph[50001];

int degree[50001];
int visited[50001];

struct node {
    int name;
    int deep;
};

list <node> q;
int shortpath=999999;

void BFS(int start, int dist) {
    node current, next_node;
    int next;

    q.push_back({start, 0});
    while (!q.empty()) {
        current = q.front();
        q.pop_front();
        visited[current.name] = 1;

        if (current.name==dist){
            if (current.deep < shortpath) {
                shortpath = current.deep;
            }
        }

        for (int i=0; i<degree[current.name]; i++){
            next = graph[current.name][i];
            next_node = {next, current.deep+1};
            if (!visited[next]){
                q.push_back(next_node);
            }
        }

    }
}

int main(){
    int n, m, s, t;
    
    cin >> n >> m >> s >> t;
    for (int i=0; i<n; i++){
        degree[i] = 0;
    }

    for (int i=0; i<m; i++){
        int u, v, color;
        cin >> u >> v >> color;

        graph[u].push_back(v);
        graph[v].push_back(u);
        degree[u]++;
        degree[v]++;
    }

    BFS(s, t);
    printf("%d\n", shortpath);

} 