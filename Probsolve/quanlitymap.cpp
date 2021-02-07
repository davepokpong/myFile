#include <bits/stdc++.h>

using namespace std;

char area[31][31];
bool visited[31][31];
int n, m, c=0, star=0, dollar=0, excellent=0, good=0;

void init(int n, int m){
    char ground;
    int i, j;
    for (i=0; i<n; i++){
        for (j=0; j<m; j++){
            cin >> ground;
            visited[i][j] = false;
            area[i][j] = ground;
        }
    }
}

void dfs(int x, int y){
    visited[x][y] = true;
    if (area[x][y]=='*') star++;
    if (area[x][y]=='$') dollar++;
    c++;

    if (x>0 && area[x-1][y]!='#' && !visited[x-1][y]) dfs(x-1, y);
    if (x<n-1 && area[x+1][y]!='#' && !visited[x+1][y]) dfs(x+1, y); 
    if (y>0 && area[x][y-1]!='#' && !visited[x][y-1]) dfs(x, y-1);
    if (y<m-1 && area[x][y+1]!='#' && !visited[x][y+1]) dfs(x, y+1);
}

int main(){
    int i, j;
    cin >> n >> m;
    init(n, m);

    for (i=0; i<n; i++){
        for (j=0; j<m; j++){
            if (!visited[i][j] && area[i][j]!='#') dfs(i, j);
            if (dollar>0 && star>0){ //excellent
                excellent+=c;
            }else if(dollar>0 || star>0){
                good+=c;
            }
            //cout << "---- " << excellent << " " << good << "\n";
            dollar=0; star=0; c=0;
        }
    }

    cout << excellent << " " << good << "\n";
}