#include <iostream>
#include <vector>

using namespace std;

struct MyElem {
    string key;
    string value;
    struct MyElem* next;
    struct MyElem* prev;
    struct MyElem* Queue;
};

class List {
    MyElem* list;
public:
    List() {
        list = new MyElem();
        list->Queue = nullptr;
    }
    void insert(const string& key, const string& value, MyElem *head) {
        MyElem *new_elem = exists(key);
        if (exists(key) == nullptr) {
            new_elem = new MyElem;
            new_elem->key = key;
            new_elem->value = value;
            new_elem->Queue = list->Queue;
            list->Queue = new_elem;
            MyElem *Tail = head->prev;
            Tail->next = new_elem;
            head->prev = new_elem;
            new_elem->next = head;
            new_elem->prev = Tail;
        } else
            new_elem->value = value;
    }
    void del(const string& key) {
        MyElem *current_element = list;
        while (current_element->Queue != nullptr) {
            if (current_element->Queue->key == key) {
                MyElem *to_delete = current_element->Queue;
                current_element->Queue = current_element->Queue->Queue;
                MyElem *prev_element = to_delete->prev, *NextNode = to_delete->next;
                to_delete->prev->next = NextNode;
                to_delete->next->prev = prev_element;
                delete to_delete;
                return;
            } else
                current_element = current_element->Queue;
        }
    }
    MyElem* exists(const string& key) {
        MyElem *cur_elem = list;
        while (cur_elem->Queue != nullptr) {
            if (cur_elem->Queue->key == key)
                return cur_elem->Queue;
            cur_elem = cur_elem->Queue;
        }
        return nullptr;
    }
};

class LinkedMap
{
    vector <List> linked_map;
    MyElem *head;
    static int GetElement(const string& key) {
        int hash_value = 0;
        for(int i = 0; i < key.size(); i++){
            hash_value += key[i]*(i+61);
        }
        return abs(hash_value % 1000001);
    }
public:
    LinkedMap() {
        linked_map.resize(1000001);
        head = new MyElem;
        head->prev = head->next = head;
    }
    void insert(const string& key, const string& value) {
        linked_map[GetElement(key)].insert(key, value, head);
    }
    void del(const string& key) {
        linked_map[GetElement(key)].del(key);
    }
    string get(const string& key) {
        MyElem *result = linked_map[GetElement(key)].exists(key);
        if (result == nullptr)
            return "none";
        else
            return result->value;
    }
    string next(const string& K)
    {
        MyElem *result = linked_map[GetElement(K)].exists(K);
        if (result == nullptr || result->next == head)
            return "none";
        else
            return result->next->value;
    }
    string prev(const string& key)
    {
        MyElem *result = linked_map[GetElement(key)].exists(key);
        if (result == nullptr || result->prev == head) {
            return "none";
        }
        else {
            return result->prev->value;
        }
    }
};

int main() {
    freopen("linkedmap.in", "r", stdin);
    freopen("linkedmap.out", "w", stdout);
    string key;
    string value;
    string command;
    LinkedMap my_map;
    while(cin >> command) {
        if (command == "put") {
            cin >> key >> value;
            my_map.insert(key, value);
        } else if (command == "delete") {
            cin >> key;
            my_map.del(key);
        } else if (command == "get") {
            cin >> key;
            cout << my_map.get(key) << endl;
        } else if (command == "next") {
            cin >> key;
            cout << my_map.next(key) << endl;
        } else if (command == "prev") {
            cin >> key;
            cout << my_map.prev(key) << endl;
        }
    }
    return 0;
}