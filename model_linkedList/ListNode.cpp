#include <iostream>
#include <deque>

using namespace std;

class ListNode {
private:
    deque<int> values;

public:
    ListNode *next;
    int val;

    ListNode(int x) {
        this->val = x;
        this->next = nullptr;
    }

    void setValues() {
        this->val = values.back();
        values.pop_back();
        ListNode *tmp = this;

        while (values.size() > 0) {
            tmp->next = new ListNode(values.back());
            values.pop_back();
            tmp = tmp->next;
        }

    }

    template<typename ... Args>
    void setValues(int arg, const Args &...args) {
        values.push_front(arg);
        setValues(args...);
    }

    void addLast(ListNode *node) {
        ListNode *tmp = this;
        while (tmp != nullptr && tmp->next != nullptr) {
            tmp = tmp->next;
        }

        tmp->next = node;
    }

    string show() {
        string builder;

        ListNode *node = this;
        while (node != nullptr) {
            builder.append(to_string(node->val));
            if (node->next != nullptr) {
                builder.append("->");
            }
            node = node->next;
        }

        return builder;
    }

    int size() {
        ListNode *node = this;
        int s = 0;
        while (node != nullptr) {
            s++;
            node = node->next;
        }

        return s;
    }
};