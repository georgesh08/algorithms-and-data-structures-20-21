#include <iostream>
#include <vector>
using namespace std;

void remove_min(vector<int> &h) {
    swap(h[0], h[h.size() - 1]);
    h.pop_back();
    int i = 0;
    int j;
    while (true) {
        j = i;
        if (2 * i + 1 < h.size() && h[j] > h[2 * i + 1])
            j = 2 * i + 1;
        if (2 * i + 2 < h.size() && h[j] > h[2 * i + 2])
            j = 2 * i + 2;
        if (i == j)
            break;
        swap(h[i], h[j]);
        i = j;
    }
}

int get_min(vector<int> h) {
    return h[0];
}

void insert(vector<int> &h, int x){
    h.push_back(x);
    int i = h.size()-1;
    while(i > 0 && h[i] < h[(i-1)/2]){
        swap(h[i], h[(i-1)/2]);
        i = (i-1)/2;
    }

}

int main(){
    int n;
    freopen("sort.in", "r", stdin);
    cin >> n;
    vector<int> a(n),res(n), h;
    for(int i = 0; i < n;i++)
        cin >> a[i];

    for(int i = 0; i < n;i++) {
        insert(h, a[i]);
    }

    for(int i = 0; i < n;i++) {
        res[i] = get_min(h);
        remove_min(h);
    }

    freopen("sort.out", "w", stdout);
    for(int i = 0; i < n;i++)
        cout << res[i] << " ";

    return 0;
}