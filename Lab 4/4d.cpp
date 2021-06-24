#include <iostream>
#include <vector>
using namespace std;
int main() {
    freopen("postfix.in", "r", stdin);
    freopen("postfix.out", "w", stdout);
    vector<int> stack;
    int num;
    int a, b;
    stack.clear();
    char command;
    while(cin >> command) {
            if (command>='0' && command<='9'){
                stack.push_back(int(command) - 48);
            } else {
                a = stack[stack.size()-1];
                stack.pop_back();
                b = stack[stack.size()-1];
                stack.pop_back();
                if(command == '+')
                    stack.push_back(a+b);
                else if(command == '-')
                    stack.push_back(b - a);
                else
                    stack.push_back(a*b);
            }
    }
    cout << stack[0];
    return 0;
}