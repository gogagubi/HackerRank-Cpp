#include <iostream>
#include <vector>
#include "../model_linkedList/Node.cpp"

using namespace std;

class Solution {
public:
    bool has_cycle(Node *head) {
        Node *slow = head;
        Node *fast = head;

        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast) {
                return true;
            }
        }

        return false;
    }
};


int main() {

    if (true) {
        Solution *o = new Solution();
        Node *node = new Node(0);
        node->setValues(1, 2, 3);
        node->next->next->next = node->next->next;
        cout << "Result: " << o->has_cycle(node) << endl;
    }

    return 0;
}