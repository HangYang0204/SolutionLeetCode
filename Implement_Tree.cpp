
#include<iostream>

typedef struct node{
    int data;
    struct node* next;
}* ptrnode;

class LinkedList{
private:
    ptrnode head;
    ptrnode curr; //current node
    ptrnode temp; //temp node for implementing methods
public:
    LinkedList(){
        head = NULL;
        curr = NULL;
        temp = NULL;
    } //constructor

    void AppendNode(int Ndata){
        ptrnode n = new node;//dynamic memory allocation expression
        n->data = Ndata;
        n->next = NULL;
        if(head == NULL){
            head = n;
        }
        else{
            curr = head;
            while(curr->next != NULL){
                curr = curr->next;
            }
            curr->next = n;
        }
    }

    void NodePrint(){
        if(head == NULL){
            std::cout << "The List is Empty!" << std::endl;
        }
        else{
            curr = head;
            while(curr != NULL){
                std::cout << curr->data << std::endl;
                curr = curr->next;
            }
        }
    }

    void DelNode(int delData){
        ptrnode p = NULL;
        curr = head;
        temp = head;
        while(curr != NULL && curr->data != delData){
            temp = curr;
            curr = curr->next;
        }
        if(curr == NULL){
            std::cout << "Node not eixit in List\n" << std::endl;
            delete p;
        }
        else{
            p = curr;
            curr = curr->next;
            temp->next = curr;
            if(p == head){
                head = head->next;
                temp = NULL;
            }
            delete p; //the node pointer
        }

    }
};
int main(){ 
    LinkedList L;
    L.AppendNode(10);
    L.AppendNode(12);
    L.AppendNode(5);
    L.NodePrint();
    L.DelNode(5);
    L.NodePrint();
    std::cout << "hello world" << std::endl;
    return 0;
} 
