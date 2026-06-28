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
    struct compare{
    bool operator()(ListNode* a, ListNode* b){
        return a->val > b->val;
    }
};
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, compare> heap;
        int k = lists.size();
        for(int i = 0;i<k;i++){
            if(lists[i]!=nullptr){
                heap.push(lists[i]);
            }

        }
        ListNode* dummy = new ListNode(-1);
        ListNode* temp = dummy;
        while(!heap.empty()){
            ListNode* head = heap.top();
            heap.pop();
            temp->next = head;
            temp = temp->next;
            if(head->next!=nullptr){
            heap.push(head->next);}
        }
        return dummy->next;
        
    }
};
