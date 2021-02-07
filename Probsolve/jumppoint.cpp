#include <bits/stdc++.h>

using namespace std;

int x[1010], y[1010], layer[1010];
bool visited[1010];
vector<int> node[1010];
queue<int> q;


void bfs(int index){
    layer[index] = 0;
    visited[index] = true;

    q.push(index);
    while (!q.empty()){
        int tmp = q.front();
        q.pop();

        for (auto it=node[tmp].begin(); it!=node[tmp].end(); it++){
            if(visited[*it] == false){
                layer[*it] = layer[tmp] + 1;
                q.push(*it);
                visited[*it] = true;
            }
        }
        /*
        for (int i=0; i<node[tmp].size(); i++){
            node[tmp][i]
        }*/
        
    }

}

int main(){
    int n, r, r_sq;
    cin >> n >> r;

    for (int i=0; i<n; i++){
        int xx, yy;
        cin >> xx >> yy;
        x[i+1] = xx;
        y[i+1] = yy;
    }
    x[n+1] = 100;
    y[n+1] = 100;

    for (int i=0; i<=n+1; i++){
        for (int j=i+1; j<=n+1; j++){
            r_sq = pow(x[i]-x[j],2) + pow(y[i]-y[j],2);
            if (r_sq <= pow(r,2)){
                node[i].push_back(j);
                node[j].push_back(i);
            }   
        }
    }

    bfs(0);
    if (visited[n+1]==false) cout << -1;
    else cout << layer[n+1] << "\n";
}