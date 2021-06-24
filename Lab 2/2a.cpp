#include <iostream>
using namespace std;

void merge(int a[], int l, int m, int r){
    int n1 = m - l + 1;
    int n2 = r - m;
    int i = 0, j = 0, k = l;
    int left[n1],right[n2];
    for(int i = 0; i < n1; i++)
        left[i] = a[l + i];
    for(int j = 0; j < n2; j++)
        right[j] = a[m + 1 + j];
    while(i < n1 && j < n2){
        if(left[i] <= right[j]){
            a[k] = left[i];
            i++;
        }
        else{
            a[k] = right[j];
            j++;
        }
        k++;
    }
    while(i < n1){
        a[k] = left[i];
        i++;
        k++;
    }
    while(j < n2){
        a[k] = right[j];
        k++;
        j++;
    }
}


void sort(int a[], int left, int right){
    if (left < right){
        int middle = left + (right - left) / 2;
        sort(a, left, middle);
        sort(a, middle+1, right);
        merge(a, left, middle, right);
    }
}


int main(){
    int n;
    freopen("sort.in", "r", stdin);
    cin >> n;
    int arr[n];

    for(int i = 0; i < n; i++)
        cin >> arr[i];

    sort(arr , 0 , n-1);

    freopen("sort.out", "w", stdout);
    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";

    return 0;
}