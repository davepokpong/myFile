#include <bits/stdc++.h>

using namespace std;

int R[100001];
vector<pair<int,int>> graph[100001];

int main(){
    int n, m, l, a, b, r;
    
    for (int i=1; i<=n; i++){
        cin >> R[n];
    }

    for (int i=0; i<m; i++){
        cin >> a >> b >> r;

        graph[a].push_back(make_pair(b, r));
        graph[b].push_back(make_pair(a, r));
    }

    
}