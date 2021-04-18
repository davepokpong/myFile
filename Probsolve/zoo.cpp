#include <bits/stdc++.h>

using namespace std;

int bird[1001][1001];

int main(){
    int r, c, b, t, i, j, k;
    int sum=0, res=0;
    cin >> r >> c >> b >> t;
    for (i = 0; i < r; i++){
        for (j = 0; j < c; j++){
            cin >> bird[i][j];
        }
    }

    int n = b/t;
    int water = b;
    for (i = 0; i < r; i++){
        for (j = 0; j < c; j++){
            sum += bird[i][j];
        }
        if (sum%n>0) sum=sum/n+1;
        else sum=sum/n;
        res += sum;
        sum = 0;
    }

    // for (i = 0; i < r; i++){
    //     for (j = 0; j < c; j++){
    //         cout << bird[i][j] << "  ";
    //         if (j == c - 1) cout << "\n";
    //     }
    // } print matrix

    cout << res << "\n";
}