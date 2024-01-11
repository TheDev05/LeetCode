/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
    Node *temp = head;

    std::map<Node *, Node *> data;
    while (temp)
    {
        Node *inox = new Node(temp->val);
        data[temp] = inox;
        temp = temp->next;
    }

    temp = head;

    while (temp)
    {
        Node *root = data[temp];
        Node *next = data[temp->next];
        Node *random = data[temp->random];

        root->next = next;
        root->random = random;

        temp = temp->next;
    }
        
    return data[head];
    }
};