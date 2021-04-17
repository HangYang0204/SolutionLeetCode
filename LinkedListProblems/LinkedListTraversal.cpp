#include<iostream>
#include<vector>
using std::vector;

class ListNode{
public:
    int val;
    ListNode* next;
    ListNode() : val(0),next(nullptr) {};
    ListNode(int val) : val(val),next(nullptr) {};
    //ListNode(int val, ListNode* next) : val(val),next(next) {}; 
    ListNode(int val, ListNode* next){
        //using this pointer
        this->val = val;
        this->next = next;
    }
};

void ListTraversal(ListNode* root){
    //this will print out LinkedList from root to end
    ListNode* curr = root;
    while(curr != nullptr){
        std::cout << "|" << curr->val ;
        curr = curr->next;
    }
    std::cout << "|" << std::endl;
}

ListNode* ReverseLinkedList(ListNode* root){
    //this will return the reversed list root
    ListNode* curr = root;
    ListNode* prev; 
    /*
    null -> a -> b -> c 
    ----------------------------------------
    prev = null | curr = a | post = b
    ----------------------------------------
        curr->next = prev; 
    null <- a  b->c
    2 updates to move forward
        prev = curr; 
        curr = curr->next;
    ----------------------------------------
    prev = a | curr = b | post = b another copy.
    ----------------------------------------    
    */
    while(curr != nullptr){
        ListNode* post = curr->next; //perserve the next info
        curr->next = prev;
        prev = curr;
        curr = post;
    }
    //after the loop curr == nullptr and perv become the new root
    return prev;
}
//driver
int main(){
    ListNode* d = new ListNode(6);
    ListNode* c = new ListNode(5,d);
    ListNode* b = new ListNode(7,c);
    ListNode* a = new ListNode(2,b);
    ListNode* root = new ListNode(1,a);
    //1->2->7->5->6
    ListTraversal(root);
    ListNode* newroot = ReverseLinkedList(root);
    ListTraversal(newroot);
}