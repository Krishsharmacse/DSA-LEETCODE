/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        set<ListNode*>sets;
        ListNode *curr=head;
        while(curr!=NULL){
            if(sets.contains(curr)){
                return true;
            }
            else{

                sets.insert(curr);
                curr=curr->next;
              
            }
        }

          return false;
    }
};