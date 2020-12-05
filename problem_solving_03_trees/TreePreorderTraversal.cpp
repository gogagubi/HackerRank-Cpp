#include <iostream>
#include <vector>
#include "../model_tree/Node.cpp"

using namespace std;

class Solution {
public:
    void preOrder(Node *root) {
        vector<Node *> stack;
        stack.push_back(root);

        while (stack.size() > 0) {
            Node *curr = stack.back();
            stack.pop_back();

            cout << curr->data << " ";
            if (curr->right != nullptr) stack.push_back(curr->right);
            if (curr->left != nullptr) stack.push_back(curr->left);
        }
    }
};


int main() {

    if (true) {
        Solution *s = new Solution();
        Node *root = new Node();
        root->setTree(1, NULL, 2, NULL, 5, 3, 6, NULL, 4);

        cout << "Result: ";
        s->preOrder(root);
        cout << endl;
    }

    return 0;
}