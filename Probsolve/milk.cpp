#include <bits/stdc++.h>

using namespace std;

int parent[100001];

int find(int n){
    if(parent[n] == -1) return n;
    
    int res = find(parent[n]);
    parent[n] = res;
    return  res; 
}

void u(int a, int b){
    int f = find(a);
    int s = find(b);
    if(f == s) return;
    parent[f] = s;
}

int main(){
    int n, q, i, a, b;
    char op;    

    scanf("%d %d", &n, &q);

    for(i=1; i<n+1; i++){
        parent[i] = -1;
    }

    for (i=0; i<q; i++){
        scanf(" %c", &op);
        if (op=='q'){
            scanf("%d %d", &a, &b);
            if (find(a)!=find(b)) cout << "no" << "\n";
            else cout << "yes" << "\n";
        }
        else {
            scanf("%d %d", &a, &b);
            u(a, b);
        }
    }
}

/*
5 10
q 1 2
c 1 3
q 3 2
c 3 2
q 1 2
q 4 5
c 4 2
q 4 1
c 1 4
q 5 1
*/