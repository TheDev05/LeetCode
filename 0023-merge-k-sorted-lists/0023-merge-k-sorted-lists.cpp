/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& num) {
        
    if(num.empty())
        return NULL;
        
    std::multiset<std::pair<int, ListNode *>> inox;
    
    for(auto i: num)
        if(i)
          inox.insert({i->val, i});
        
    ListNode *prev = NULL, *newHead = NULL;
    while (inox.size())
    {
        auto it = inox.begin();
        ListNode *temp = it->second;
        int val = it->first;

        inox.erase(it);

        if (prev)
            prev->next = temp;
        prev = temp;

        if (newHead == NULL)
            newHead = prev;

        if (temp->next)
            inox.insert({temp->next->val, temp->next});
    }
        
    return newHead;
    }
};