#include <bits/stdc++.h>

using namespace std;

char arr[1010][1010]; 
int table[1010][1010];
bool visited[1010][1010];

bool dfs(int i , int j, int n, int m) {
    visited[i][j] = true;
    bool bon=false;

    if (i==n) return true;
    if (table[i+1][j] == 1 && !visited[i+1][j]) 
        bon |= dfs(i+1, j, n, m);
    if (table[i-1][j] == 1 && !visited[i-1][j])
        bon |= dfs(i-1, j, n, m);
    if (table[i][j+1] == 1 && !visited[i][j+1]) 
        bon |= dfs(i, j+1, n, m);
    if (table[i][j-1] == 1 && !visited[i][j-1]) 
        bon |= dfs(i, j-1, n, m);

    return bon;
}

int main() {
    int n, m;
    cin >> n >> m;
    bool franky=false;

    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            cin >> arr[i][j];
        }
    }
    for (int i=2; i<=n; i++) {
        for (int j=2; j<=m; j++) {
            if (arr[i][j] == '.' && arr[i-1][j] == '.' && arr[i][j-1] == '.' && arr[i-1][j-1] == '.')
                table[i][j] = 1;
            else table[i][j] = 0;
        }
    }

    for (int i=1; i<=m; i++) {
        if (table[2][i] == 1) {
            franky |= dfs(2, i, n, m);
        }
    }

    if (franky) cout << "yes" << "\n";
    else cout << "no" << "\n";
}