#include <iostream>
using namespace std;

/* in a doubly linked list, delete last will happen in constant time*/
class Node{
	public:
		int data;
		Node* next;
		Node* prev;
		
		Node(){
			data=0;
			next=NULL;
			prev=NULL;
		}
		Node(int data){
			this->data=data;
			this->next=NULL;
			this->prev=NULL;
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
		void insertNode(int);//equivalent to insertLast
		void insertFirst(int);
		void getFirst();
		void getLast();
		void getAll();
		void deleteFirst();
		void deleteLast();		
};

void LinkedList::insertNode(int data){
	Node* lastNode = new Node(data);
	if(head==NULL){
		head=lastNode;
		tail=lastNode;
		return;
	}
	Node* initialLastNode=tail;
	initialLastNode->next=lastNode;
	lastNode->prev=initialLastNode;
	tail=lastNode;	
}

void LinkedList::getAll(){
	if(head==NULL){
		cout<<"sorry bro, nothing to print";
		return;
	}
	Node* temp = head;
	while(temp!=NULL){
		cout<<temp->data<<" ";
		temp=temp->next;
	}
}
void LinkedList::insertFirst(int data){
	Node* newFirstNode = new Node(data);
	if(head==NULL){
		head=newFirstNode;
		tail=newFirstNode;
		return;
	}
	Node* initialFirstNode=head;
	newFirstNode->next=initialFirstNode;
	initialFirstNode->prev=newFirstNode;
	head=newFirstNode;	
}
void LinkedList::getFirst(){
	if(head==NULL){
		cout<<"lol, nothing in this list";
		return;
	}
	Node* firstNode=head;
	cout<<firstNode->data<<" ";
}
int main(){
	LinkedList list;
	cout<<"All Nodes:"<<" ";
	list.insertNode(2);
	list.insertNode(3);
	list.insertNode(4);
	list.insertFirst(1);
	list.getAll();
	cout<<endl;
	cout<<"First Node:"<<" ";
	list.getFirst();
}