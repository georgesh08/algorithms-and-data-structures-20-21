#include <iostream>
using namespace std;

int main(){
    int n;
    freopen("sortland.in","r",stdin);
    cin >> n;
    double arr[n];
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    double b[n];
    for(int i = 0; i <= n; i++)
        b[i] = arr[i];
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n - i - 1; j++)
            if(arr[j] > arr[j+1])
                swap(arr[j], arr[j+1]);
    freopen("sortland.out", "w", stdout);
    for(int i = 0; i < n; i++)
        if(arr[0] == b[i])
            cout << i + 1 << " ";
    for(int i = 0; i < n; i++)
        if(arr[n/2] == b[i])
            cout << i + 1 << " ";
    for(int i = 0; i < n; i++)
        if(arr[n-1] == b[i])
            cout << i + 1;
    return 0;
}