#include <iostream>
#include <string>
#include "MyList.h"

using namespace std;

int main() {
    int n;
    cin >> n;

    MyList<int>* lists = new MyList<int>[n];

    int q;
    cin >> q;

    for (int i = 0; i < q; i++) {
        string op;
        cin >> op;

        if (op == "push_back") {
            int list_idx, value;
            cin >> list_idx >> value;
            lists[list_idx].push_back(value);
        } else if (op == "pop_back") {
            int list_idx;
            cin >> list_idx;
            lists[list_idx].pop_back();
        } else if (op == "push_front") {
            int list_idx, value;
            cin >> list_idx >> value;
            lists[list_idx].push_front(value);
        } else if (op == "pop_front") {
            int list_idx;
            cin >> list_idx;
            lists[list_idx].pop_front();
        } else if (op == "insert") {
            int list_idx, index, value;
            cin >> list_idx >> index >> value;
            lists[list_idx].insert(index, value);
        } else if (op == "erase") {
            int list_idx, index;
            cin >> list_idx >> index;
            lists[list_idx].erase(index);
        } else if (op == "size") {
            int list_idx;
            cin >> list_idx;
            cout << lists[list_idx].size() << endl;
        } else if (op == "empty") {
            int list_idx;
            cin >> list_idx;
            cout << (lists[list_idx].empty() ? "true" : "false") << endl;
        } else if (op == "clear") {
            int list_idx;
            cin >> list_idx;
            lists[list_idx].clear();
        } else if (op == "front") {
            int list_idx;
            cin >> list_idx;
            cout << lists[list_idx].front() << endl;
        } else if (op == "back") {
            int list_idx;
            cin >> list_idx;
            cout << lists[list_idx].back() << endl;
        } else if (op == "link") {
            int list_idx1, list_idx2;
            cin >> list_idx1 >> list_idx2;
            lists[list_idx1].link(lists[list_idx2]);
        } else if (op == "cut") {
            int list_idx, index;
            cin >> list_idx >> index;
            MyList<int> temp = lists[list_idx].cut(index);
            // Store the cut list somewhere or replace an existing list
            int target_idx;
            cin >> target_idx;
            lists[target_idx] = temp;
        } else if (op == "print") {
            int list_idx;
            cin >> list_idx;
            MyList<int> temp(lists[list_idx]);
            bool first = true;
            while (!temp.empty()) {
                if (!first) cout << " ";
                cout << temp.front();
                temp.pop_front();
                first = false;
            }
            cout << endl;
        }
    }

    delete[] lists;
    return 0;
}
