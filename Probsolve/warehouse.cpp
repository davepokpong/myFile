#include <bits/stdc++.h>

using namespace std;

int parent[100001];

int find(int n){
    if(parent[n] == -1) return n;
    
    int res = find(parent[n]);
    parent[n] = res;
    return  res; 
}

void u(int a, int b){
    int f = find(a);
    int s = find(b);
    if(f == s) return;
    parent[f] = s;
}

int main(){
    int i, n, m, k, cost=0;
    cin >> n >> m >> k;

    for(i=1; i<n+1; i++){
        parent[i] = -1;
    }

    int a, b;
    for(i=0; i<m; i++){
        cin >> a >> b;
        u(a, b);
    }

    for (i=0; i<k; i++){
        cin >> a >> b;
        if (find(a)!=find(b)) cout << "0" << "\n";
        else cout << "1" << "\n";
    }

}