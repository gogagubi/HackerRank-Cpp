#include <iostream>
#include <vector>
#include "../model_tree/Node.cpp"

using namespace std;

class Solution {
public:
    void postOrder(Node *root) {
        vector<Node*> stack;
        stack.push_back(root);

        while(stack.size() > 0){
            Node* curr = stack.back();

            if(curr->left == nullptr && curr->right == nullptr){
                stack.pop_back();
                cout << curr->data << " ";
            }
            else{
                if(curr->right != nullptr) {
                    stack.push_back(curr->right);
                    curr->right = nullptr;
                }

                if(curr->left != nullptr) {
                    stack.push_back(curr->left);
                    curr->left = nullptr;
                }
            }
        }
    }
};


int main() {

    if (true) {
        Solution *s = new Solution();
        Node *root = new Node();
        root->setTree(1, NULL, 2, NULL, 5, 3, 6, NULL, 4);

        cout << "Result: ";
        s->postOrder(root);
        cout << endl;
    }

    return 0;
}