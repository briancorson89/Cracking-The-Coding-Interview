//
//  main.cpp
//  CTCILinkedListImplementation
//
//  Created by Brian Corson on 6/23/16.
//
//  Entire Implementation for chapter 2
#include <iostream>

using namespace std;

//Struct for each Node of the linked list
struct Node{
    int data;//component to hold data
    Node* next;//component to point to the next node
};

class LinkedList{//a collection of Nodes
public:
    Node* head;//points to head of the list
    Node* tail;//points to tail of the list
    LinkedList();//Constructor
    ~LinkedList();//Destructor
    void insert(int value);//function to create a node
    void display();//display the list
    void removeDuplicates(Node* head);//Question 2.1
    void kthToLastDisplay(Node* head, int index);//Question 2.2
private:
    int nodeCounter;//for question 2.2
};

LinkedList::LinkedList(){
    nodeCounter = 0;
    this->head = nullptr;//construct an empty list
}

LinkedList::~LinkedList(){
    Node* current = head;//point to the front of the list
    
    while (current != 0){//while list has content
        //delete node one by one
        Node* next = current->next;
        delete current;
        current = next;
    }
    head = nullptr;//until list is empty
}

void LinkedList::insert(int value){
    if (head == NULL){//for empty list
        head = new Node();//create a node
        tail = head;//tail and head points to only node
        head->next = nullptr;//next is null pointer
        head->data = value;//data component in node struct given value
        nodeCounter++;
    }
    else{
        tail->next = new Node();//create a node
        tail = tail->next;//tail points to newly created node
        tail->data = value;//give node value
        tail->next = nullptr;//create null pointer
        nodeCounter++;
    }
}

void LinkedList::display(){
    Node* temp;
    if (head == NULL){//display for an empty list
        cout << "This is an Empty List. Node Count:" << nodeCounter << endl;
        return;
    }
    temp = head;//temp emcompasses head node
    while (temp != NULL){//for all nodes in list
        cout << temp->data << "->";//display data in temp node
        temp = temp->next;//temp emcompasses next node
    }
    cout <<"null. Node count:" << nodeCounter << endl;//print null node
}

//  Question 2.1 -- Write code to remove duplicates from an unsorted linked list
void LinkedList::removeDuplicates(Node* head){
    if (head == NULL){
        return;
    }
    //runner technique
    Node* current = head;//points to current node
    Node* runner;//runs through the rest of list to compare duplicates
    
    while (current != NULL){
        runner = current;//current and runner pointer begin at same nodes
        
        while (runner->next){//current points at one node while runner goes through the rest of the list
            if (current->data == runner->next->data){//if current and runner node data
                Node* temp = runner->next;//temp emcompases duplicate node
                runner->next = runner->next->next;//temp is no longer pointed to in the lsit
                delete temp;//delete node
                nodeCounter--;
            }
            else{
                runner = runner->next;//move to next node if not the same
            }
        }
        current = current->next;//current moves to the next node
    }
}
//Question 2.2 -- Implement an argument to find the kth to last element of the list
void LinkedList::kthToLastDisplay(Node* head, int index){
    Node* current = head;
    if(index > nodeCounter || nodeCounter == 0){
        cout << "List is not long enough for function to succeed" << endl;
        return;
    }
    int count = 1;
    cout << "KthToLastDisplay(" << index << "):";
    while(current){
        if(count >= index){
            cout << current->data << "->";
        }
        current = current->next;
        count++;
    }
    cout << "null. Node Count:" << nodeCounter - index + 1 << endl;
}
int main(int argc, const char * argv[]) {
    LinkedList* myList = new LinkedList();
    myList->display();//Expect: This is an Empty List. Node Count:0
    myList->kthToLastDisplay(myList->head, 1);//Expect: List is not long enough for function to succeed
    myList->insert(1);
    myList->insert(1);
    myList->insert(2);
    myList->insert(1);
    myList->insert(12);
    myList->insert(11);
    myList->insert(100);
    myList->insert(2);
    myList->display();//1->1->2->1->12->11->100->2->null. Node count:8
    myList->kthToLastDisplay(myList->head, 5);//Expect: KthToLastDisplay(5):12->11->100->2->null. Node Count:4
    myList->removeDuplicates(myList->head);
    myList->display();//Expect: 1->2->12->11->100->null. Node count:5
    delete myList;
    return 0;
}
/* Output:
 This is an Empty List. Node Count:0
 List is not long enough for function to succeed
 1->1->2->1->12->11->100->2->null. Node count:8
 KthToLastDisplay(5):12->11->100->2->null. Node Count:4
 1->2->12->11->100->null. Node count:5
 */













