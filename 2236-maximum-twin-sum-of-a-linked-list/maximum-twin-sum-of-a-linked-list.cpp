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
    int pairSum(ListNode* head) {
        vector<int>arr;
        while(head!=NULL){

            arr.push_back(head->val);
            head =head->next;
        }
        int i =0;
        int j = arr.size()-1;
        int mx=INT_MIN;
        while(i<j){
            int candidate=arr[i]+arr[j];
             mx=max(candidate,mx);
             i++;
             j--;
        }
       return mx; 
    }
};