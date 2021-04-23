#include <bits/stdc++.h>

using namespace std;

int a[101];
int b[101];
int c[101];

int main(){
    int n, m, i, x, y, z;
    int level=1;

    cin >> n >> m;
    for (i=1; i<n; i++){
        cin >> a[i] >> b[i] >> c[i];
    }

    for (i=1; i<=m; i++){
        cin >> x >> y >> z;
        
        if (a[level]<=x) a[level]=-1;
        if (b[level]<=y) b[level]=-1;
        if (c[level]<=z) c[level]=-1;

        if (a[level]==-1 && b[level]==-1 && c[level]==-1) {
            level++;
            if(level==n) break;
        }
    }

    cout << level << "\n";
}