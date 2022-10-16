#include <bits/stdc++.h>
using namespace std;

class Node{
public:
    int val;
    Node *next;
    Node(int value){
        val = value;
        next = NULL;
    }
};

class SingleLL{
public:
    Node *head;
    int length;
    SingleLL(){
        head = NULL;
        length = 0;
    }
    void insertNode(int pos, int value);
    void deleteNode(int pos);
    void append(int value);
    void printList();
    int search(int searchItem);
};

void SingleLL::deleteNode(int pos){

    if(head == NULL){
        cout << "linked list empty!\n";
        return;
    }
    if(pos >= length){
        cout << "'pos' is out of range\n";
        return;
    }
    
    Node* curr = head;
    Node* temp;

    if(pos == 0){
        temp = head;
        head = head->next;
        delete temp;
        length--;
        return;
    }

    // traverse until curr points to the Node 
    // preceeding the node to be deleted
    for(int i = 0; i < pos-1; i++){
        curr = curr->next;
    }
    
    temp = curr->next;
    curr->next = temp->next;
        
    length--;
    delete temp;
}

// inserts a Node at the end of the linked list
void SingleLL::append(int value){
    // Create the new Node.
    Node* newNode = new Node(value);
  
    // Assign to head
    if (head == NULL) {
        head = newNode;
        return;
    }
  
    // Traverse till end of list
    Node* temp = head;
    while (temp->next != NULL) {
  
        // Update temp
        temp = temp->next;
    }
  
    // Insert at the last.
    temp->next = newNode;

    length++;
}

void SingleLL::insertNode(int pos, int value){

    // Create the new Node.
    Node* newNode = new Node(value);

    //when the linked list is empty
    if(length == 0 and pos == 0){
        head = newNode;
        length++;
        return;
    }
    //when the position to be inserted is greater 
    //than the length of linked list
    if(pos > length){
        cout << "'pos' out of bounds\n";
        return;
    }
    
    Node* ptr = head;

    for(int i = 0; i < pos-1; i++){
        ptr = ptr->next;
    }
    //if pos == 0
    if(ptr == head){
        newNode->next = head;
        head = newNode;
    }
    else{
        newNode->next = ptr->next;
        ptr->next = newNode;
    }
    
    length++;
}

void SingleLL::printList()
{
    Node* temp = head;
  
    // Check for empty list.
    if (head == NULL) {
        cout << "List empty" << endl;
        return;
    }
  
    // Traverse the list.
    cout << "linked list: length=" << length << endl;
    while (temp != NULL) {
        cout << temp->val << "->";
        temp = temp->next;
    }
    cout << "\n\n";
}

// time complexity O(n)
// returns the index of the Node with value equal to searchItem
// otherwise returns -1
int SingleLL::search(int searchItem){
  
    // Traverse till end of list
    Node* temp = head;
    int indx = 0;

    while (temp != NULL) {

        if(temp->val == searchItem){
            return indx;
        }
        // Update temp
        temp = temp->next;
        indx++;
    }
    return -1;
}

int main(){
    SingleLL list = SingleLL();

    list.insertNode(0,19);
    list.printList();
    list.insertNode(0,18);
    list.printList();
    list.insertNode(0,17);
    list.printList();
    list.insertNode(0,16);
    list.printList();
    list.insertNode(4,9);
    list.printList();
    list.insertNode(4,45);
    list.printList();
    list.insertNode(2,4);
    list.printList();
    list.insertNode(100,5);
    list.printList();

    list.append(1);
    list.append(11);
    list.printList();

    list.deleteNode(0);
    list.printList();
    list.deleteNode(2);
    list.printList();
    list.deleteNode(list.length-1);
    list.printList();
    list.deleteNode(list.length-2);
    list.printList();
    list.deleteNode(1);
    list.printList();

    int item = 1;
    int index = list.search(item);
    if(index == -1) cout << item << " not found\n";
    else cout << item << " found at index " << index << endl;

}