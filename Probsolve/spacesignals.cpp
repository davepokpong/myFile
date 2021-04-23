#include <bits/stdc++.h>

using namespace std;

char s[21], t[200001];

int main(){
    cin >> s;   
    cin >> t;

    int i, now=0, n=0;
    for (i=0; i<strlen(t); i++){
        if(t[i]==s[now]){
            now++;
            if (now==strlen(s)){
                now=0;
                n++;
            }
        }
    }

    cout << n << "\n";
}