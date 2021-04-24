#include <bits/stdc++.h>

using namespace std;

double matrix[21][21], res[21][21];

int main(){
    int n, m, i, j, k, ans_a, ans_b;
    double num, ans;

    cin >> n >> m;
    for(i=1; i<=n; i++){
        for(j=1; j<=m; j++){
            cin >> matrix[i][j];
        }
    }

    for(i=1; i<=n; i++){
        for(j=1; j<=m; j++){
            num = 0;
            for(k=1; k<=n; k++){
                num += abs(matrix[i][j]-matrix[k][j]);
            }
            for(k=1; k<=m; k++){
                num += abs(matrix[i][j]-matrix[i][k]);
            }
            res[i][j] = num/(n+m-2);
        }
    }

    ans = res[1][1];
    for(i=1; i<=n; i++){
        for(j=1; j<=m; j++){
            if(ans>res[i][j]) {
                ans=res[i][j];
                ans_a = i;
                ans_b = j;
            }
        }
    }

    cout << matrix[ans_a][ans_b] << "\n";
}