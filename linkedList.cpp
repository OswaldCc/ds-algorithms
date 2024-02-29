#include <iostream>
using namespace std;

class Node{
public:
	int data;
	Node* next;	// this means next is a pointer of type node
	
	//default conctructor(creates new Node objects with default values)
	Node(){
		data=0;
		next=NULL;
	} 
	//parametized constructor(this one is used when you want to create a node object with a specific data value provided
	  Node(int data) 
    { 
        this->data = data; 
        this->next = NULL; 
    } 
};
/* the role of this class is to manage the overall structure of the linked list such as insertion and deletion.
it does not need to handle the individual data elements directly.by
not dealing stores within each node, the ll class becomes more generic and flexible,
it can be used to mange linked lists containing any type of data, not just a specific type.

*/
class LinkedList{
	Node* head;
	public:
		LinkedList(){
			//points to the first node in the linked list.
			// throught the head pointer you can access and manipulate the nodes in thbe linked list
			head=NULL;
		}
		void insertNode(int);
		void printList();		
		
	
};

void LinkedList::insertNode(int data){
	Node* newNode= new Node(data);/*new creates a pointer, but this pointer belongs to the previous node. when i create a new node the pointer is there but
	that value of the pointer will be assigned to the next node so as we can point to it*/
	
	if(head == NULL){
		head=newNode;
		return;
	}
	Node* temp =head;// this initializes pointer temp of type Node and sets it to the head pointer, to traverse the node from the beginning
	
	//traverse till the end of the list
	/*this loop works because if you for example instatiate a new instance of linked 
	list and add more than just the head, it means that that instance has for example two
	instances of class node. hence if there is a next pointer in the same instance of list we 
	will find it(the pointer is automatically created when you instantiate a new instance of class node. this will also
	make the last item in the linked list have a bnull pointer because no new instance of node has been created
	 hence we are able to traverse through that one instance. the temp varable will point to the last node.remember 
	that the last node is characterised by its pointer being null. the last line is just an append
	*/
	while(temp->next != NULL){//we are referring to the next variable of the next node instance
		temp= temp->next;//The loop's goal is to find the last node in the linked list. The last node is characterized by having its next pointer set to NULL
		
	}
	// we update the next pointer to point to the next node of class Node
	//here we are just updating the last pointer but remember that when new node is created the data variable already exists
	temp->next=newNode;
	
}
void LinkedList::printList(){
	Node* temp = head;
	if(head==NULL){
		cout<<"List is empty"<<endl;
		return;
	}
	while(temp!=NULL){
		cout<<temp->data<<" ";
		temp=temp->next;
	}
}

int main(){
	LinkedList list;
	list.insertNode(1);
    list.insertNode(2); 
    list.insertNode(3); 
    list.insertNode(4); 
    list.printList();
}