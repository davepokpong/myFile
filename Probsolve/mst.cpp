#include <bits/stdc++.h>

using namespace std;

vector< pair < int, pair < int, int > > > graph;
vector< pair < int, pair < int, int > > >::iterator it1;
map<pair<int,int>,int> chk;
int parent[100001];

void init(int n){
    int i;
    for(i=1; i<n+1; i++)
        parent[i] = -1;
}

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
    int n, m, cost=0;
    cin >> n >> m;
    int i;

    for(i=1; i<n+1; i++){
        parent[i] = -1;
    }

    int a, b, c, d;
    for(i=0; i<m; i++){
        cin >> a >> b >> c >> d;
        graph.push_back(make_pair(c,make_pair(a,b)));
        chk[make_pair(a, b)] = d;
        if (d==1) u(a, b);
    }

    sort(graph.begin(), graph.end());

    for(it1=graph.begin(); it1!=graph.end(); it1++){
        if(find(it1->second.first) != find(it1->second.second)){
            cost += it1->first;
            u(it1->second.first, it1->second.second);
        }
    }

    cout << cost << '\n';
}