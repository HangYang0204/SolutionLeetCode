#include<iostream>
#include<vector>

using std::vector;
using std::cout;

class ListNode{
public:
    int val;
    ListNode* next;
    ListNode() : val(0),next(nullptr) {};
    ListNode(int val) : val(val), next(nullptr) {};
    ListNode(int val,ListNode* next) : val(val), next(next) {};
};


ListNode* MergeLists(ListNode* l1, ListNode* l2){
    ListNode* result;
    if(!l1 && !l2) return result;
    if(!l1 || !l2) result = !l1? l2 : l1;
    else{
        if(l1->val < l2->val){
            result = l1;
            result->next = MergeLists(l1->next,l2);
        } else {
            result = l2;
            result->next = MergeLists(l1,l2->next);
        }
    }
    return result;
}

void PrintList(ListNode* head){
    if(head == nullptr) cout << "empty list node";
    else{
        ListNode* curr = head;
        while(curr){
            cout << curr->val << " ";
            curr = curr->next;
        }
    }
}

int main(){
    //l1: 1->3->5->6->11 
    //l2: 4->6->8->12->15->19
    ListNode* l14 = new ListNode(11);
    ListNode* l13 = new ListNode(6,l14);
    ListNode* l12 = new ListNode(5,l13);
    ListNode* l11 = new ListNode(3,l12);
    ListNode* l1  = new ListNode(1,l11);
    
    ListNode* l25 = new ListNode(19);
    ListNode* l24 = new ListNode(15,l25);
    ListNode* l23 = new ListNode(12,l24);
    ListNode* l22 = new ListNode(8,l23);
    ListNode* l21 = new ListNode(6,l22);
    ListNode* l2  = new ListNode(4,l21);

    PrintList(MergeLists(l1,l2));
    delete l14,l13,l12,l11,l1,l25,l24,l23,l22,l21,12;

}