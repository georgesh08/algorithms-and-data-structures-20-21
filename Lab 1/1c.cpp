#include <iostream>
using namespace std;

int main(){
    int i,j,h,w;
    freopen("turtle.in", "r", stdin);
    cin >> h >> w;
    int a[h][w];

    for(i = 0; i < h; i++)
        for(j = 0; j < w; j++)
            cin >> a[i][j];

    for(i = h-2; i >= 0; i--)
        a[i][0] = a[i+1][0] + a[i][0];

    for(j = 1; j < w; j++)
        a[h-1][j] = a[h-1][j-1] + a[h-1][j];

    for(i = h-2; i >= 0; i--)
        for(j = 1; j < w; j++)
            a[i][j] = max(a[i][j-1], a[i+1][j]) + a[i][j];

    freopen("turtle.out", "w", stdout);
    cout << a[0][w-1];
    return 0;
}