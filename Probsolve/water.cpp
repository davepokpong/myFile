#include <bits/stdc++.h>

using namespace std;

int day[1002] = {0};
int dif[1002] = {0};

int main(){
    int n, i, water, res=0;

    cin >> n;
    for (i=0; i<n; i++){
        cin >> water;
        day[i+1] = water;
    }
    /*
    cout << "-------water-------" << "\n";
    for (i=1; i<n; i++){
        dif[i]=day[i+1]-day[i];
        cout << dif[i] << " ";
    }
    cout << "\n";
    //cout << "-------diff-------" << "\n";*/
    for (i=1; i<=1002; i++){
        dif[i] = day[i-1]-day[i];
        if (dif[i]<=10) dif[i]=0;
        if (dif[i]>70) dif[i]=70;
        dif[i] = dif[i]*10;
    }
    /*
    cout << "-------power-------" << "\n";
    for (i=1; i<n+1; i++){
        cout << dif[i] << " ";
    }
    cout << "\n" << "-------------------" << "\n";
    */

    for (i=1; i<n+1; i++){
        res += dif[i];
    }

    cout << res << "\n";
}