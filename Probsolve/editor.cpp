#include <bits/stdc++.h>

using namespace std;

list <string> sen;
list <string>::iterator pos, tmp;

int main(){
    int n, i;
    string word;
    char op;

    pos = sen.end();   
    cin >> n;
    for (i=0; i<n; i++){
        cin >> op;
        if (op == 'i'){
            cin >> word;
            sen.insert(pos, word);
        }
        if (op == 'l'){
            if (pos == sen.begin()) continue;
            pos--;
        }
        if (op == 'r'){
            if (pos == sen.end()) continue;
            pos++;
        }
        if (op == 'b'){
            if (pos == sen.begin()) continue;
            tmp = pos;
            tmp--;
            sen.erase(tmp);
        }
        if (op == 'd'){
            if (pos == sen.end()) continue;
            tmp = pos;
            pos++;
            sen.erase(tmp);
        }
    }

    for (pos=sen.begin() ;pos!=sen.end(); pos++){
        cout << *pos << "\n";
    }

}