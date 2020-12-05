#include <iostream>
#include <string>
#include <deque>

using namespace std;

class Node {
    deque<int> values;

public:
    int data;
    Node *left;
    Node *right;

    Node() : data(0), left(nullptr), right(nullptr) {}

    Node(int x) : data(x), left(nullptr), right(nullptr) {}

    Node(int x, Node *left, Node *right) : data(x), left(left), right(right) {}

    void setTree() {
        deque<Node *> nodes;

        data = values.back();
        values.pop_back();

        nodes.push_front(this);

        while (!values.empty()) {
            int size = nodes.size();
            for (int i = 0; i < size; i++) {
                Node *node = nodes.back();
                nodes.pop_back();

                if (node != nullptr) {
                    if (!values.empty()) {
                        int leftValue = values.back();
                        node->left = leftValue != 0 ? new Node(leftValue) : nullptr;
                        values.pop_back();
                        nodes.push_front(node->left);
                    }

                    if (!values.empty()) {
                        int rightValue = values.back();
                        node->right = rightValue != 0 ? new Node(rightValue) : nullptr;
                        values.pop_back();
                        nodes.push_front(node->right);
                    }
                }
            }
        }
    }

    template<typename ... Args>
    void setTree(int arg, const Args &...args) {
        values.push_front(arg);
        setTree(args...);
    }

    string show() {
        string result;

        deque<Node *> nodes;
        nodes.push_front(this);

        while (!nodes.empty()) {
            int size = nodes.size();

            for (int i = 0; i < size; i++) {
                Node *current = nodes.back();

                result.append(to_string(current->data));
                if (i != size - 1) {
                    result.append(",");
                }
                nodes.pop_back();

                if (current->left != nullptr) {
                    nodes.push_front(current->left);
                }
                if (current->right != nullptr) {
                    nodes.push_front(current->right);
                }
            }

            result.append("\n");
        }

        return result;
    }


};