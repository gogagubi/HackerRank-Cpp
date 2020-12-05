#include <iostream>
#include <vector>
#include "../model_tree/Node.cpp"

using namespace std;

class Solution {
public:
    void inOrder(Node *root) {
        vector<Node*> stack;
        Node* curr = root;

        while(curr != nullptr || stack.size() > 0){
            while(curr != nullptr){
                stack.push_back(curr);
                curr = curr->left;
            }

            curr = stack.back();
            stack.pop_back();
            cout << curr->data << " ";
            curr = curr->right;
        }
    }
};


int main() {

    if (true) {
        Solution *s = new Solution();
        Node *root = new Node();
        root->setTree(1, NULL, 2, NULL, 5, 3, 6, NULL, 4);

        cout << "Result: ";
        s->inOrder(root);
        cout << endl;
    }

    return 0;
}