#include <bits/stdc++.h>

using namespace std;

int all[1204];

int main(){
    int n, i;
    cin >> n;
    for (i=0; i<4*n; i++){
        cin >> all[i];
    }
    int max1=0, max1_idx;
    for (i=0; i<n; i++){
        if (all[i]>max1){
            max1 = all[i];
            max1_idx = i;
        } 
    }
    int max2=0, max2_idx;
    for (i=n; i<2*n; i++){
        if (all[i]>max2){
            max2 = all[i];
            max2_idx = i;
        } 
    }
    int max3=0, max3_idx;
    for (i=2*n; i<3*n; i++){
        if (all[i]>max3){
            max3 = all[i];
            max3_idx = i;        
        } 
    }
    int max4=0, max4_idx;
    for (i=3*n; i<4*n; i++){
        if (all[i]>max4){
            max4 = all[i];
            max4_idx = i;
        } 
    }
    int ching1, ching2, ching1_idx, ching2_idx, lose1, lose2, lose1_idx, lose2_idx;
    if(max1>max2) {
        ching1 = max1;
        ching1_idx = max1_idx;
        lose1 = max2;
        lose1_idx = max2_idx;
    }else{
        ching1 = max2;
        ching1_idx = max2_idx;
        lose1 = max1;
        lose1_idx = max1_idx;
    }

    if(max3>max4) {
        ching2 = max3;
        ching2_idx = max3_idx;
        lose2 = max4;
        lose2_idx = max4_idx;
    }else{
        ching2 = max4;
        ching2_idx = max4_idx;
        lose2 = max3;
        lose2_idx = max3_idx;
    }

    int champ, champ_idx, longchamp, longchamp_idx;
    if (ching1>ching2){
        champ = ching1;
        champ_idx = ching1_idx;
        longchamp = ching2;
        longchamp_idx = ching2_idx;
    }else{
        champ = ching2;
        champ_idx = ching2_idx;
        longchamp = ching1;
        longchamp_idx = ching1_idx;
    }

    cout << champ_idx+1 << " " << longchamp_idx+1 << " " << lose1_idx+1 << " " << lose2_idx+1 << "\n";
}