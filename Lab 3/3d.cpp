#include <iostream>
#include <vector>
#include <string>

struct pushCommand {
    int push_pos;
    int push_value;
};

void insert(std::vector<pushCommand> &heap, pushCommand p) {
    heap.push_back(p);
    int i = heap.size() - 1;
    while (i > 0 && heap[i].push_value < heap[(i - 1) / 2].push_value) {
        std::swap(heap[i], heap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

void remove_min(std::vector<pushCommand> &h) {
    std::swap(h[0], h[h.size() - 1]);
    h.pop_back();
    int i = 0;
    int j;
    while (true) {
        j = i;
        if (2 * i + 1 < h.size() && h[j].push_value > h[2 * i + 1].push_value)
            j = 2 * i + 1;
        if (2 * i + 2 < h.size() && h[j].push_value > h[2 * i + 2].push_value)
            j = 2 * i + 2;
        if (i == j)
            break;
        std::swap(h[i], h[j]);
        i = j;
    }
}


void build_heap(std::vector<pushCommand> &heap, int i) {
    while (heap[i].push_value < heap[(i - 1) / 2].push_value) {
        std::swap(heap[i], heap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

int main() {
    freopen("priorityqueue.in", "r", stdin);
    freopen("priorityqueue.out", "w", stdout);
    std::string command;
    int i, j, k;
    pushCommand number;
    std::vector<pushCommand> arr;
    i = 0;
    k = 0;
    int a, b;
    while (std::cin >> command) {

        i++;
        if (command[0] == 'p') {
            std::cin >> a;
            number.push_value = a;
            number.push_pos = i;
            insert(arr, number);
        }
        if (command[0] == 'd') {
            j = 0;
            std::cin >> a >> b;
            while (arr[j].push_pos != a)
                j++;
            arr[j].push_value = b;
            build_heap(arr, j);
        }
        if (command[0] == 'e') {
            k++;
            if (arr.size() > 0) {
                std::cout << arr[0].push_value << std::endl;
                remove_min(arr);
            } else
                std::cout << "*" << std::endl;
        }
    }
    return 0;
}