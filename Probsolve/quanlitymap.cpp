#include <bits/stdc++.h>

using namespace std;

char area[31][31];
bool visited[31][31];

void init(){
    int n, m, i, k, ground;
    cin >> n >> m;

    for (i=0; i<n; i++){
        for (j=0; j<m; j++){
            cin >> ground;
            visited[i][j] = false;
            area[i][j] = ground;
        }
    }
}


int main(){


}