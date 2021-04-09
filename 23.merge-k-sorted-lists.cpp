/*
 * @lc app=leetcode id=23 lang=cpp
 *
 * [23] Merge k Sorted Lists
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        //we push all head in min Heap
        //the following defines min heap with ListNode memember. 
        //lamab & decltype
        auto comp = [](ListNode* t1, ListNode* t2){return t1->val > t2->val;};
        priority_queue<ListNode*, vector<ListNode*>,decltype(comp)> pq(comp);//min heap, by default priority_queue<int> is max HEAP
        for(ListNode* list : lists){
            if(list != nullptr){
                pq.push(list);
            }   
        }
        
        ListNode* res = new ListNode();
        ListNode* curr = res; //res point to every heap top node
        while(!pq.empty()){
            //start from the first head at the heap top
            ListNode* top = pq.top();
            pq.pop();
            curr->next = top;//curr -> top
            curr = curr->next; //top
            if(top->next != nullptr){ //next in the heap top list not null, add it and 
            //let the heap to sort it
                pq.push(top->next);
            }
            
        }
        return res->next;
    }
};
// @lc code=end

