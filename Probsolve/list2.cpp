#include <bits/stdc++.h>

using namespace std;

int main(){
    list<long long> list1;
    list<long long>::iterator pos;
    long long n, i, num;
    char op;

    cin >> n;
    for (i=0; i<n; i++){
        //cout << "hellooooo" << "\n";
        cin >> op >> num;
        //cout << op;
        if (op == 'I')
            list1.push_front(num);
        else if (op == 'A'){
            list1.push_back(num);
        }else{
            if (num > list1.size())
                continue;
            pos = list1.begin();
            advance(pos, num-1);
            list1.erase(pos);
        }
    }
    
    for (pos=list1.begin(); pos!=list1.end(); pos++){
        cout << *pos << "\n";
    }
}