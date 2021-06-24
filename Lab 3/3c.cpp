#include <iostream>
#include <vector>

int main(){
    freopen("radixsort.in", "r", stdin);
    int n, m , k;
    std::cin >> n >> m >> k;
    std::string str , tmp;
    std::vector<std::string> arr, res;

    for(int i = 0; i < n; i++){
        std::cin >> str;
        arr.push_back(str);
    }

    for(int i = 0; i < k; i++) {
        for (char j = 'a'; j <= 'z'; j++)
            for (int p = 0; p < n; p++) {
                tmp = arr[p];
                if (tmp[m - i - 1] == j)
                    res.push_back(tmp);
            }
        arr = res;
        res.clear();
    }
    freopen("radixsort.out", "w", stdout);
    for(int i = 0; i < n; i++)
        std::cout << arr[i] << std::endl;
    return 0;
}