#include <iostream>
#include <string>
#include <deque>

using namespace std;

class TreeNode {
    deque<int> values;

public:
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}

    void setTree() {
        deque<TreeNode *> nodes;

        val = values.back();
        values.pop_back();

        nodes.push_front(this);

        while (!values.empty()) {
            int size = nodes.size();
            for (int i = 0; i < size; i++) {
                TreeNode *node = nodes.back();
                nodes.pop_back();

                if (node != nullptr) {
                    if (!values.empty()) {
                        int leftValue = values.back();
                        node->left = leftValue != 0 ? new TreeNode(leftValue) : nullptr;
                        values.pop_back();
                        nodes.push_front(node->left);
                    }

                    if (!values.empty()) {
                        int rightValue = values.back();
                        node->right = rightValue != 0 ? new TreeNode(rightValue) : nullptr;
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

        deque<TreeNode *> nodes;
        nodes.push_front(this);

        while (!nodes.empty()) {
            int size = nodes.size();

            for (int i = 0; i < size; i++) {
                TreeNode *current = nodes.back();

                result.append(to_string(current->val));
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