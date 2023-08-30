#include <iostream>
using namespace std;

class Node{
public:
    int Value;
    Node* next;
};

//Display the List of Circular linked list
void DisplayList(Node** last) {
    //if list is emtpy just return
    if(*last == NULL) {
        return;
    }
    //Point to the first node of list
    Node* current = (*last)->next;
    do{
        cout<<current->Value<<" ";
        current = current->next;
    }while(current != (*last)->next);
}


//function to add a node to an empty list
void InsertInEmtpy(Node** last, int value) {
    if(*last != NULL) {
        return;
    }

    //prepare a new node
    Node* newnode = new Node();
    newnode->Value = value;
    *last = newnode;
    //link it to ourself since it is circular, I think
    (*last)->next = newnode;
}

//Function to insert a Node at the beginnig of a list
void InsertAtBegin(Node** Prev, int value) {
    if(*Prev == NULL) {
        return InsertInEmtpy(Prev, value);
    }

    //Prepare a new node
    Node* newnode = new Node();
    newnode->Value = value; //add value to new node
    newnode->next = (*Prev)->next;
    (*Prev)->next = newnode;

}

//function to insert a Node at the End of list
void InsertAtEnd(Node** prev, int value) {
    if(*prev == NULL) {
        return InsertInEmtpy(prev, value);
    }

    //Prepare a new Node
    Node* newnode = new Node();
    newnode->Value = value;
    newnode->next = (*prev)->next;
    (*prev)->next = newnode;
    *prev = newnode;
}

//Function to insert a node after a specific node
void insertAfter(Node** last, int value, int Target) {
    if(*last == NULL) {
        return;
    }

    //find target
    Node* current = (*last)->next;
    while(current != *last && current->Value != Target) {
        current = current->next;
    }

    //if target is found
    if(current != *last) {
        //Prepare new Node
        Node* newnode = new Node();
        newnode->Value = value;

        newnode->next = current->next;
        current->next = newnode;

        if(current == *last) {
            *last = newnode;
        }
    }


}

//Delete a specific node
void DeleteNode(Node** last, int TargetNode) {
   //check if list is empty
    if(*last == NULL) {
        return;
    }

    //find target
    Node* current = (*last)->next;
    Node* prev = *last;
    while(current != *last && current->Value != TargetNode) {
        prev = current;
        current = current->next;
    }

    //if target node is found, delete it
    if(current != *last) {
        prev->next = current->next;

        if(current == *last) {
            *last = prev;
        }
        //delete node
        delete current;
    }
}

//function to print the list in reverse order
void reverse(Node** last) {
    //the base case
    if(*last == NULL) {
        return;
    }

    Node* prev = NULL;
    Node* current = (*last)->next;
    Node* NEXT;

    do {
        NEXT = current->next;
        current->next = prev;
        prev = current;
        current = NEXT;
    }while(current != (*last)->next);


    *last = prev;


    current = (*last)->next;
    do {
        cout<<current->Value<<" ";
        current = current->next;
    }while(current != (*last)->next);
    cout<<endl;
}

int main()
{

    Node* last = NULL;
    //Insert at Empty list
    InsertInEmtpy(&last,1);
    //Insert at Beginning of List
    InsertAtBegin(&last, 0);
    //Insert at the end of list
    InsertAtEnd(&last, 3);
    InsertAtEnd(&last, 4);
    InsertAtEnd(&last, 5);
    //Insert After given node in the list
    insertAfter(&last, 2,1);
    //Delete a node in the list
    DeleteNode(&last, 5);



    //Display the list
    DisplayList(&last);
    //Display in reverse
    cout<<" "<<endl;
    cout<<"Reverse of the Circular linked list:"<<endl;
    reverse(&last);
    return 0;
}
