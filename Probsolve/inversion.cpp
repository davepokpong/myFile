#include <bits/stdc++.h>

using namespace std;

long long arr[100100];
long long temp[100100];
long long _mergeSort(long long left, long long right);
long long merge(long long left, long long mid, long long right);
 
long long _mergeSort(long long left, long long right){
    long long mid, inv_count = 0;
    
    if (right > left){
        mid = (right + left) / 2;
        inv_count += _mergeSort(left, mid);
        inv_count += _mergeSort(mid + 1, right);
        inv_count += merge(left, mid + 1, right);
    }
    return inv_count;
}

long long merge(long long left, long long mid, long long right){
    long long i, j, k;
    long long inv_count = 0;
 
    i = left; 
    j = mid; 
    k = left; 

    while ((i <= mid - 1) && (j <= right)) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        }
        else {
            temp[k++] = arr[j++];
            inv_count = inv_count + (mid - i);
        }
    }
 
    while (i <= mid - 1)
        temp[k++] = arr[i++];

    while (j <= right)
        temp[k++] = arr[j++];

    for (i = left; i <= right; i++)
        arr[i] = temp[i];
 
    return inv_count;
}

int main() { 
    long long n;

    cin >> n;
    for (long long i=0; i<n; i++) 
        cin >> arr[i];
    
    long long right = n;
    long long left = 0;
    cout << _mergeSort(left, right-1) << "\n"; 
}