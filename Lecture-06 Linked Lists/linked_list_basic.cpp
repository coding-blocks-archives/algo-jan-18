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
	~node(){
		if(next!=NULL){
			delete next;
		}
	}
};


/*
class LinkedList{
	node*head;
public:
	//Functions here

};
*/
//Passing head using reference variable
void insertAtHead(node*&head,int data){

	if(head==NULL){
		head = new node(data);
		return;
	}
	else{
		node *n = new node(data);
		n->next = head;
		head = n;
	}
}
void insertAtTail(node*&head,int data){

	if(head==NULL){
		head = new node(data);
	}
	else{
		node*temp = head;
		while(temp->next!=NULL){
			temp = temp->next;
		}
		temp->next = new node(data);
	}
}
int length(node *head){
	int len=0;
	while(head){
		len++;
		head = head->next;
	}
	return len;
}

void insertInMiddle(node*&head,int data,int p){

	if(p==0){
		insertAtHead(head,data);
		return;
	}
	else if(p>=length(head)){
		insertAtTail(head,data);
		return;
	}
	else{
		node*temp = head;
		int jump = 1;
		
		while(jump<=p-1){
			temp = temp->next;
			jump++;
		}
		node*n =  new node(data);
		n->next = temp->next;
		temp->next = n;
	}
	return;
}

void print(node *head){
	while(head!=NULL){
		cout<<head->data<<"->";
		head = head->next;
	}
	cout<<endl;
}

ostream& operator<<(ostream &os,node*head){
	print(head);
	return os;
}
istream& operator>>(istream&is, node*&head){

	int d;
	is>>d;
	while(d!=-1){
		insertAtTail(head,d);
		is>>d;
	}
	return is;
}

node* search(node*head,int key){
	if(head==NULL){
		return NULL;
	}
	if(head->data==key){
		return head;
	}
	return search(head->next,key);
}
//Iteratively Reverse A linked List
void reverse(node *&head){
	node* current = head;
	node* N;
	node* prev = NULL;

	while(current!=NULL){
		//Save the next node
		N = current->next;
		//Update the current node 
		current->next = prev;

		//Shift Prev and Current
		prev = current;
		current = N;
	}

	head = prev;
}

bool detectCycle(node*head){

	node*slow = head;
	node*fast = head;
	int ans = false;

	while(fast!=NULL && fast->next!=NULL){
		fast = fast->next->next;
		slow = slow->next;

		if(slow==fast){
			ans = true;
			break;
		}

	}
	slow = head;
	while(slow!=fast){
		slow = slow->next;
		fast = fast->next;
	}
	cout<<"Loop starts at "<<slow->data;
	//3. Break the loop 


	return ans;
}

node* midPoint(node*head){
	//Homework !
	node * slow = head;
	node * fast = head->next;

	while(fast!=NULL && fast->next!=NULL){
		fast = fast->next->next;
		slow = slow->next;
	}
	return slow;

}

node* getTail(node*head){
		while(head->next!=NULL){
			head = head->next;
		}
		return head;
}

node* reverseRec(node*head){
	if(head->next==NULL){
		return head;
	}

	node* sHead = reverseRec(head->next);
	/*node* temp = sHead;
	while(temp->next!=NULL){
		temp = temp->next;
	}*/
	node * temp = head->next;
	temp->next = head;
	head->next = NULL;
	return sHead;

}

node* merge(node*a,node*b){
	if(a==NULL){
		return b;
	}
	else if(b==NULL){
		return a;
	}

	//Otherwise !
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

node* mergeSort(node *head){
	if(head==NULL||head->next==NULL){
		return head;
	}

	//Rec Case
	node *mid = midPoint(head);
	node *a = head;
	node *b = mid->next;
	mid->next = NULL;

	//Sort the two halves
	a = mergeSort(a);
	b = mergeSort(b);

	return merge(a,b);

}

int main(){	
	node*head = NULL;
	node*head1 = NULL;
	cin>>head;
	head = mergeSort(head);
	cout<<head;
	/*
	insertAtHead(head,4);
	insertAtHead(head,2);
	insertAtHead(head,1);

	insertInMiddle(head,3,2);
	*/
	/*
	cin>>head;
	cin>>head1;

	cout<<head;
	cout<<head1;

	head = merge(head,head1);

	cout<<head;
	*/

	//head = reverseRec(head);
	//cout<<head;

	//Create Cycle
	/*
	node*tail = getTail(head);
	tail->next = head->next->next->next;
	//cout<<head;

	if(detectCycle(head)){
		//cout<<"Loop is present ";
	}
	else{
		cout<<"Loop is not present";
		cout<<head;
	}
	//cout<<midPoint(head)->data<<endl;

	*/
	delete head;

	return 0;	
}