/*
 * @lc app=leetcode id=141 lang=cpp
 *
 * [141] Linked List Cycle
 */

// @lc code=start
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
        if(head == nullptr){
            return false;
        }

        ListNode* curr = head;
        ListNode* ncurr = head->next;
        while(curr != ncurr){
            if(ncurr == nullptr || ncurr->next == nullptr){
                return false;
            }
            curr = curr->next;//1 step
            ncurr = ncurr->next->next;//2 step 
        }
        return true; //if they meet, cyclic 
        
    }
};
// @lc code=end

