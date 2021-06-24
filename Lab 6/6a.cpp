#include <iostream>
#include <vector>
using namespace std;

int hash_f(int num) {
    return num % 10000001;
}

void push(vector<vector <int>> &a, int key, int num){
    for(int i = 0; i < a[key].size(); i++){
        if(a[key][i] == num){
            return ;
        }
    }
    a[key].push_back(num);
}

void del(vector<vector <int>> &a, int key, int num){
    for(int i = 0; i < a[key].size(); i++)
        if(a[key][i] == num) {
            a[key].erase(a[key].begin() + i);
            break;
        }
}

bool isInSet(vector<vector <int>> &a, int key, int num){
    bool flag = false;
    for(int i = 0; i < a[key].size(); i++)
        if(a[key][i] == num) {
            flag = true;
            break;
        }
    return flag;
}

int main(){
    freopen("set.in", "r",stdin);
    freopen("set.out", "w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<vector <int>> mySet(10000001);
    string command;
    int num, key;
    bool flag;
    while(cin >> command >> num){
        key = hash_f(abs(num));

        if(command == "insert") {
            push(mySet, key, num);
        }

        else if(command == "delete"){
            del(mySet, key, num);
        }

        else {
            flag = isInSet(mySet, key, num);
            if(flag)
                cout << "true" << endl;
            else
                cout << "false" << endl;
        }
    }

    return 0;
}
