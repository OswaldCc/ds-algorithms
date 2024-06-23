/*a singly linked list with a tail, will give constant time performance 
for the ..first, ..last functions apart from deleteLast which requires a doubly 
linked list.*/
#include <iostream>
using namespace std;
class Node{
	public:
		int data;
		Node* next;
		Node(){
			data=0;
			next=NULL;
		}
		Node(int data){
			this->data=data;
			this->next=NULL;
			
		}
};

class LinkedList{
	public:
		Node* head;
		Node* tail;
		
		LinkedList(){
			head=NULL;
			tail=NULL;
		}
		void insertNode(int);
		void getAll();
		void insertFirst(int);
		void getFirst();
		void insertLast(int);
		void getLast();
		void deleteFirst();
};

/* the dynamic functions: insertFirst, getFirst, insertLast, getLast,
and deleteFirst all run in constant time */ 
//we need a doubly linkedlist for deleteLast to run in constant time.
void LinkedList::insertNode(int data){
	Node* newNode= new Node(data);
	if(head==NULL){
		head=newNode;
		tail=newNode;
		return;
	}
	Node* temp= head;
	while(temp->next!=NULL){
		temp=temp->next;
	}
	temp->next=newNode;
	tail=newNode;
}
void LinkedList::getAll(){
	if(head==NULL){
		cout<<"as null as it gets "<<endl;
		return;
	}
	Node* temp= head;
	while(temp!=NULL){
		cout<<temp->data<<" ";
		temp=temp->next;
	}
	cout<<endl;
}
void LinkedList::insertFirst(int data){
	Node* firstNode= new Node(data);
	if(head==NULL){
		head=firstNode;
		tail=firstNode;
		return;
	}
	Node* initialFirst;
	initialFirst=head;
	firstNode->next=initialFirst;
	head=firstNode;	
}
void LinkedList::getFirst(){
	if(head==NULL){
		cout<<"lol, empty"<<endl;
	}
	Node* firstNode=head;
	cout<<firstNode->data<<" "<<endl;
}
void LinkedList::insertLast(int data){
	Node* newLastNode=new Node(data);
	if(head==NULL){
		head=newLastNode;
		tail=newLastNode;
		return;
	}
	Node* initialLast;
	initialLast=tail;
	initialLast->next=newLastNode;
	tail=newLastNode;
}
void LinkedList::getLast(){
	if(head==NULL){
		cout<<"lol as empty as it gets"<<endl;
		return;
	}
	Node* lastNode;
	lastNode=tail;
	cout<<lastNode->data<<" "<<endl;
}
void LinkedList::deleteFirst(){
	if(head==NULL){
		cout<<"No nodes to delete"<<endl;
		return;
	}
	Node* initialFirst;
	initialFirst=head;
	head=initialFirst->next;
	delete initialFirst;	
}
int main(){
	LinkedList list;
	list.insertNode(2);
	list.insertLast(3);
	list.insertFirst(1);
	cout<<"All after insert first: 1 2 3"<<endl;
	list.getAll();
    cout<<"Last only, should be 3"<<endl;
	list.getLast();
    cout<<"First only, should be 1"<<endl;
	list.getFirst();
    cout<<"deleting first, result:2 3"<<endl;
	list.deleteFirst();
	list.getAll();
}