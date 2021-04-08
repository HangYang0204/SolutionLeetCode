#include <iostream>
#include <string>

struct node{
    int data;
    struct node* next;
};

class LinkedList{
    private:
    node* head;
    node* tail;
    public:
    LinkedList(){
        head = NULL;
        tail = NULL;
    }
    void addNode(int n){
        node* tmp = new node;//dynamic memory allocation 
        tmp->data = n;
        tmp->next = NULL;
        if(head == NULL){
            head = tmp;
            tail = tmp;
        }
        else{
            tail->next = tmp;
            tail = tail->next;
        }

    }
    void addhead(int n){
        node* p = new node;
        p->data = n;
        p->next = head;
        head = p;
    }

    void insert(node* a, int d){
        node* p = new node;
        p->data = d;
        p->next = a->next;
        a->next = p;
    }

    void delnode(node* prenode){
        //i can only delete the following node
        node* del;
        del = prenode->next;
        prenode->next = del->next;
        delete del;
    }

    node* gethead(){
        return head;
    }

    static void display(node* head){
        if(head == NULL){
            std::cout << "NULL" << std::endl;
        }
        else{
            std::cout << head->data << std::endl;
            display(head->next);
        }
    }
    static void concatnate(node* a, node* b){
        if(a != NULL && b != NULL){
            if(a->next == NULL){
                a->next = b;
            }
            else{
                concatnate(a->next,b);
            }
        } 
        else{
            std::cout << "Either a or b is null\n";
        }
    }

};
 


int main(){
    // int x = 47;
    // int* p = &x;
    // std::cout << p << "\n" << *p << "\t";
    // std::cout << &x << "\n" << x << "\t";
    LinkedList a;
    a.addNode(1);
    a.addNode(2);
    LinkedList::display(a.gethead()); //class call for static methods
    // LinkedList b;
    // b.addNode(3);
    // LinkedList::concatnate(a.gethead(),b.gethead());
    // LinkedList::display(a.gethead());
    a.addhead(5);
    std::cout<< "I added new head: " << a.gethead()->data << std::endl;
    a.insert(a.gethead()->next,10);
    LinkedList::display(a.gethead()); 
    a.delnode(a.gethead()->next);
    LinkedList::display(a.gethead());
    return 0;

}