#include <iostream>
using namespace std;

int binsearch1(int a[], int key, int n) {
    int l = -1;
    int r = n;
    int m;
    while(l < r-1){
        m = (l + r)/2;
        if (a[m] >= key)
            r = m;
        else l = m;
    }
    if(a[r] == key)
        return r+1;
    else return -1;
}

int binsearch2(int a[],int key, int n){
    int l = -1;
    int r = n;
    int m;
    while(l < r-1){
        m = (l + r)/2;
        if (a[m] <= key)
            l = m;
        else r = m;
    }
    if(a[l] == key)
        return l+1;
    else return -1;

}

int main(){
    int n , k, x, bs1, bs2,p;
    freopen("binsearch.in", "r", stdin);
    cin >> n;
    int a[n];
    for(int i = 0; i < n;i++)
        cin >> a[i];
    cin >> k;
    freopen("binsearch.out", "w", stdout);
    for(int i = 0; i < k; i++){
        cin >> x;
        bs1 = binsearch1(a, x, n);
        bs2 = binsearch2(a, x, n);
        cout << bs1 << " " << bs2 << endl;
    }
    return 0;
}