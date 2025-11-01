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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        ListNode* dummy = new ListNode(-1);
        ListNode* ans = dummy,*temp=head;
        unordered_set<int> numSet;
        for(auto n : nums){
            numSet.insert(n);
        }

        while(temp){
            int x = temp->val;
            temp = temp->next;

            if(numSet.find(x) ==numSet.end()){
                ListNode* newN = new ListNode(x);
                ans->next = newN;
                ans = newN; 
            }
        }

        delete head;
        return dummy->next;
    }
};