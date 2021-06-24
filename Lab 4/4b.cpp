#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    freopen("queue.in", "r", stdin);
    freopen("queue.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int m, x, i;
    cin >> m;
    char command;
    i = 0;
    vector<int> arr;
    while(i < m){
        i++;
        cin >> command;
        if(command == '+') {
            cin >> x;
            arr.push_back(x);
        }
        if(command == '-') {
            reverse(arr.begin(), arr.end());
            cout << arr[arr.size()-1] << endl;
            arr.pop_back();
            reverse(arr.begin(), arr.end());
        }
    }

    return 0;
}