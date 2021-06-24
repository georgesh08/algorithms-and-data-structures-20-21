#include <iostream>
#include <vector>

using namespace std;

struct MyMap {
    string key;
    string value;
};

int hash_func(string key) {
    long long int sum = 0;
    for(int i = 0; i < key.length(); ++i)
        sum += (int)key[i]*(i+123);
    return sum % 10000001;
}

void insert(vector<vector<MyMap>> &a, int pos, string key, string value) {
    for (int i = 0; i < a[pos].size(); i++) {
        if (a[pos][i].key == key) {
            a[pos][i].value = value;
            return ;
        }
    }
    MyMap elem;
    elem.key = key;
    elem.value = value;
    a[pos].push_back(elem);
}

void get(vector<vector<MyMap>> &a, int pos, string key) {
    bool exists = false;
    int i = 0;
    for (i = 0; i < a[pos].size(); i++) {
        if (a[pos][i].key == key) {
            exists = true;
            break;
        }
    }
    if (exists)
        cout << a[pos][i].value << endl;
    else
        cout << "none" << endl;
}

void del(vector<vector<MyMap>> &a, int pos, string key){
    for(int i = 0; i < a[pos].size(); i++){
        if(a[pos][i].key == key){
            a[pos].erase(a[pos].begin() + i);
            break;
        }
    }
}

int main() {
    freopen("map.in", "r", stdin);
    freopen("map.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<vector<MyMap>> a(10000001);
    string key, val, command;
    int hash_pos;
    while (cin >> command >> key) {
        hash_pos = abs(hash_func(key));
        if(command == "put") {
            cin >> val;
            insert(a, hash_pos, key, val);
        }
        else if(command == "delete")
            del(a, hash_pos, key);
        else
            get(a, hash_pos, key);

    }

    return 0;
}