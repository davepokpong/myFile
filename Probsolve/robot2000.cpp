#include <bits/stdc++.h>

using namespace std;

char s[1010];

int moon(char c){

    if(c == 'W') return 3;
    if(c == 'S') return 2;
    if(c == 'E') return 1;
    if(c == 'N') return 0;
}

int main(){

    int i, j, yaw=0, c;

    cin >> s;
    for(i=0; i<strlen(s); i++){

        if (s[i] == 'Z'){
            cout << "Z";
            yaw = 0;
        }else{
            c = moon(s[i])-yaw;

            if(c < 0)
                c += 4;

            for(j=0; j<c; j++){
               cout << "R";
            }

            yaw = moon(s[i]);
            cout << "F";
        }
    }

    cout << "\n";
}