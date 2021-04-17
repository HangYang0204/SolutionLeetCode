## (Singly)Linked List Problems
Linked list is a sequence of connected Node type. Node type/class contains a data member and Node pointer member point to the address of next Node. 

## Traversal a Linked List from the head/root
The head/root is the entrance of a LinkedList, no Node point to it. We should loop through the Linked list from the root until reaching the last Node pointing to a null pointer(nullptr). very much like how we tranversal a array or container excpet Linked List does not have lentgh defined.
```c++
    Node* curr = root;
    while(curr != nullptr){
        cout << curr->val << endl;
        curr = curr->next;
    }
```

## The common implementation
From the definition, normally we building a LinkedList creating Node class, the Node class would have a data member and a Node* member point to the next Node(address). Below is an example to build a Linked list 
a - > b -> c -> nullptr where a is the root/head.
```c++
    class Node{
        int data;
        Node* next;
        Node(): data(0),next(nullptr){};
        Node(int data, Node* next): data(data),next(next){};
    };
    void main(){
        Node* c = new Node(3);
        Node* b = new Node(2,c);
        Node* a = new Node(1,b);

    }
```
## Reverse a Linked List
For a given Linked list A -> B -> C -> D -> NULL we want to have a function to reverse it making the list look like D -> C -> B -> A -> NULL having D as the new root, the input would be root A and desired return would be the new root D. 

We need to have a function to print out the list data from root to end. this can be easily achived by using Linked List traversal. Set a Node* curr variable to loop through the list starting from root until it reaches the end ``` curr == nullptr ```

To reverse the list, we need to have prev Node info and next Node info, so that we can allow ```curr->next = prev``` and then move forward ```prev = curr; curr = next``` __import__ here next Node is vital for this idea to work, you need this info to move forward. 

```c++
    Node* curr = root;
    Node* prev; //an empty Node point to NULL 
    while(curr != nullptr){
        Node* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev; 
```
After the loop curr will become NULL and since prev point to curr, prev is the end of the list. 
