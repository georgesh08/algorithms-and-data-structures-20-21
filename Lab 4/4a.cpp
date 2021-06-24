#include <iostream>
#include <vector>
using namespace std;

int main(){
    freopen("stack.in", "r", stdin);
    freopen("stack.out", "w", stdout);
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
            cout << arr[arr.size()-1] << endl;
            arr.pop_back();
        }
    }

    return 0;
}