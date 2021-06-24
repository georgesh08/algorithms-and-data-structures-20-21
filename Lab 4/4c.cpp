#include <iostream>
#include <vector>

int main() {
    freopen("brackets.in", "r", stdin);
    freopen("brackets.out", "w", stdout);
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::string str;
    bool flag;
    std::vector<char> arr;
    while (std::cin >> str) {
        flag = true;
        arr.clear();
        for (int i = 0; i < str.length(); i++) {
            if (str[i] == '(' || str[i] == '[') {
                arr.push_back(str[i]);
            } else if (arr.size() != 0) {
                if ((str[i] == ']' && arr[arr.size() - 1] == '[') || (str[i] == ')' && arr[arr.size() - 1] == '(')) {
                    arr.pop_back();
                    continue;
                }
                if ((str[i] == ']' && arr[arr.size() - 1] == '(') || (str[i] == ')' && arr[arr.size() - 1] == '[')) {
                    flag = false;
                    break;
                }
            } else flag = false;
        }
        if (flag && (arr.size() == 0))
            std::cout << "YES" << std::endl;
        else
            std::cout << "NO" << std::endl;

    }

    return 0;
}