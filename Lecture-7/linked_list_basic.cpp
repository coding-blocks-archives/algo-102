#include<iostream>
using namespace std;

class node{
public:
	int data;
	node*next;

	node(int d){
		data = d;
		next = NULL;
	}
};

void insertAtHead(node *&head,int d){

	node*n = new node(d);
	n->next = head;
	head = n;
}
void readList(node *&head){
	int data;
	cin>>data;
	
	while(data!=-1){
		insertAtHead(head,data);
		cin>>data;
	}

}
void addAtTail(node *&head,int d){

	if(head==NULL){
		head = new node(d);
		return;
	}
	//Travel till the last node
	node* temp = head;
	while(temp->next!=NULL){
		temp = temp->next;
	}
	temp->next = new node(d);
	return;
}
int length(node *head){
	int len = 0;
	while(head!=NULL){
		len++;
		head = head->next;
	}
	return len;
}
void reverse(node *&head){

	node*prev = NULL;
	node*current =head;

	while(current!=NULL){
		node* N = current->next;
		current->next = prev;

		prev = current;
		current = N;
	}
	head = prev;
}

node* reverseRec(node *head){
	if(head==NULL||head->next==NULL){
		return head;
	}

	node* cHead = reverseRec(head->next);
	/*node* temp = cHead;
	while(temp->next!=NULL){
		temp = temp->next;
	}
	temp->next = head;
	*/
	head->next->next = head;
	head->next = NULL;
	return cHead;
}

void print(node *head){

	while(head!=NULL){
		cout<<head->data<<"->";
		head = head->next;
	}

	cout<<endl;
}
node* midPoint(node *head){
	node*slow = head;
	node*fast = head->next;

	while(fast!=NULL && fast->next!=NULL){
		fast = fast->next->next;
		slow = slow->next;
	}
	return slow;
}
//Recursive Fn to Merge 2 Sorted Linked Lists
node*merge(node *a,node *b){
	if(a==NULL){
		return b;
	}
	else if(b==NULL){
		return a;
	}

	node* c;
	if(a->data < b->data){
		c = a;
		c->next = merge(a->next,b);
	}
	else{
		c = b;
		c->next = merge(a,b->next);
	}
	return c;
}
//Sort an Unsorted Linked List using Merge Sort
node* mergeSort(node *head){
	
	if(head==NULL||head->next==NULL){
		return head;
	}
	//Rec Case
	node *mid = midPoint(head);
	node * a = head;
	node* b = mid->next;
	mid->next = NULL;

	a = mergeSort(a);
	b = mergeSort(b);

	return merge(a,b);
}

void insertInMiddle(node*&head,int d,int p){


}
void deleteNode(node*&head,int p){


}
void deleteList(node *&head){


}
node* findElementRec(node *head){

	
}

istream& operator>>(istream&is,node*&head){
	readList(head);
	return is;
}
ostream& operator<<(ostream&os,node*head){
	print(head);
	return os;
}

int main(){
	node*head = NULL;
	node*head2 = NULL;

	cin>>head;
	cout<<head;
	head = mergeSort(head);
	cout<<head;
	/*
	cin>>head>>head2;
	
	cout<<head<<head2;

	reverse(head);
	head2 = reverseRec(head2);

	cout<<head<<head2<<endl;
	//cout<<midPoint(head)->data<<endl;
	head = merge(head,head2);
	cout<<head<<endl;
	*/

	return 0;
}