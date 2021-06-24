#include <iostream>
#include <vector>

int main() {
    freopen("isheap.in", "r", stdin);
    int n;
    std::cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        std::cin >> arr[i];
    bool flag = true;
    for (int i = 0; i < n; i++) {
        if (flag == false)
            break;
        else if (arr[i] < arr[(i - 1) / 2])
            flag = false;

    }
    freopen("isheap.out", "w", stdout);
    if (flag)
        std::cout << "YES";
    else
        std::cout << "NO";
    return 0;
}