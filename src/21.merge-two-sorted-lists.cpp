/*
 * @lc app=leetcode id=21 lang=cpp
 *
 * [21] Merge Two Sorted Lists
 */

// @lc code=start
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        /*
        1. Create a head node and a curr pointer point to it
        2. Compare l1 and l2 until one of them is null
        3. Curr will always point to the smaller one and move curr to it
        4. If l1 pr l2 reached the end, point curr to the remaining one.
        5. Return head->next
        */
        ListNode* head = new ListNode(0);
        //head->next = (l1->val < l2->val)? l1: l2;
        ListNode* curr = head;
        while(l1 && l2){
           if(l1->val < l2->val){
               curr->next = l1;
               l1 = l1->next;
           }else{
               curr->next = l2;
               l2 = l2->next;
           }
           curr = curr->next;
       }
       curr->next = (l1 != nullptr) ? l1 : l2;
       return head->next;

    }   
};
// @lc code=end

