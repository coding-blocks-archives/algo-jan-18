#include<iostream>
#include<queue>
#include<cmath>
using namespace std;

class node{

public:
	int data;
	node*left;
	node*right;
	
	node(int d){
		data = d;
		left = NULL;
		right = NULL;
	}
};
node* insertInBST(node*root,int data){
	if(root==NULL){
		root = new node(data);
		return root;
	}
	else if(data <= root->data){
		root->left = insertInBST(root->left,data);
	}
	else{
		root->right = insertInBST(root->right,data);
	}
	return root;
}

node* buildBST(){
	int d;
	cin>>d;

	node*root=NULL;
	while(d!=-1){
		root = insertInBST(root,d);
		cin>>d;
	}
	return root;
}
void printTree(node*root){
	if(root==NULL){
		return;
	}
	//Print  root,left and right
	cout<<root->data<<", ";
	printTree(root->left);
	printTree(root->right);
}
void printInorder(node*root){
	if(root==NULL){
		return;
	}
	printInorder(root->left);
	cout<<root->data<<", ";
	printInorder(root->right);
}	
void printPostorder(node*root){
	if(root==NULL){
		return;
	}
	printPostorder(root->left);
	printPostorder(root->right);
	cout<<root->data<<", ";
}

int height(node *root){
	if(root==NULL){
		return 0;
	}
	int h1 = height(root->left);
	int h2 = height(root->right);
	return max(h1,h2) + 1;
}
void printAtLevelK(node *root,int k){
	if(root==NULL){
		return;
	}
	if(k==1){
		cout<<root->data<<" ,";
		return;
	}
	printAtLevelK(root->left,k-1);
	printAtLevelK(root->right,k-1);
	return;
}
void printAllLevels(node*root){

	int level;
	int h = height(root);
	for(level=1;level<=h;level++){
		printAtLevelK(root,level);
		cout<<endl;
	}
	return;
}
istream& operator>>(istream&is,node*&root){
	root = buildBST();
	return is;
}

ostream& operator<<(ostream&os,node*root){
	printAllLevels(root);
	return os;
}

void levelOrderPrint(node*root){
	queue<node*> q;
	q.push(root);
	q.push(NULL);

	while(!q.empty()){
		node* n = q.front();
		if(n==NULL){
			cout<<endl;
			q.pop();
			if(!q.empty()){
				q.push(NULL);
			}
		}
		else{
			q.pop();
			cout<<n->data<<" ";

			if(n->left){
				q.push(n->left);
			}
			if(n->right){
				q.push(n->right);
			}
		}
	}
}

node* arrayToBST(int *a,int s,int e){
	if(s>e){
		return NULL;
	}
	//Rec Case
	int mid = (s+e)/2;
	node* root = new node(a[mid]);
	root->left = arrayToBST(a,s,mid-1);
	root->right = arrayToBST(a,mid+1,e);
	return root;
}

//Build a Binary Tree from Pre-Order and Inorder
int index=0;
node* buildBinaryTree(int *in,int *pre,int s,int e,int n){
	if(s>e){
		return NULL;
	}
	if(index==n){
		return NULL;
	}
	node*root = new node(pre[index]);
	int i = -1;
	for(int j=s;j<=e;j++){
		if(in[j]==pre[index]){
			i = j;
			break;
		}
	}
	index++;
	//Rec Case
	root->left = buildBinaryTree(in,pre,s,i-1,n);
	root->right =buildBinaryTree(in,pre,i+1,e,n);
	return root; 
}

//Check for Height Balanced Tree
bool isHeightBalanced(node*root){
	if(root==NULL){
		return true;
	}
	int h1 = height(root->left);
	int h2 = height(root->right);

	if(abs(h1-h2)<=1 && isHeightBalanced(root->left) && isHeightBalanced(root->right)){
		return true;
	}
	return false;
}

class Pair{
public:
	int height;
	bool balance;
};

Pair isHeightBalancedFast(node*root){
	Pair p;
	if(root==NULL){
		p.height = 0;
		p.balance = true;
		return p;
	}
	Pair left = isHeightBalancedFast(root->left);
	Pair right = isHeightBalancedFast(root->right);

	p.height = max(left.height,right.height) + 1;
	p.balance = (abs(left.height-right.height)<=1) &&left.balance&&right.balance;

	return p;

}

class LinkedList{
public:
	node*head;
	node*tail;
};

LinkedList tree2LL(node*root){
	LinkedList l;
	if(root==NULL){
		l.head=l.tail=NULL;
		return l;
	}
	//Leaf Node
	if(root->left==NULL && root->right==NULL){
		l.head = l.tail = root;
		return l;
	}
	else if(root->left!=NULL && root->right==NULL){
		LinkedList leftLL = tree2LL(root->left);
		leftLL.tail->right = root;

		l.head = leftLL.head;
		l.tail = root;
	}
	else if(root->left==NULL && root->right!=NULL){
		LinkedList rightLL = tree2LL(root->right);
		root->right = rightLL.head;

		l.head = root;
		l.tail = rightLL.tail;
	}
	else{
		LinkedList leftLL = tree2LL(root->left);
		LinkedList rightLL = tree2LL(root->right);

		leftLL.tail->right = root;
		root->right = rightLL.head;

		l.head  = leftLL.head;
		l.tail = rightLL.tail;
	}
	return l;
}

int main(){
	//node* root = buildBST();
	int p[] = {8,3,1,6,4,7,10,14,13};
	int a[] = {1,3,4,6,7,8,10,13,14};
	
	node* root = buildBinaryTree(a,p,0,8,9);//arrayToBST(a,0,9);
		
	LinkedList l = tree2LL(root);
	node*temp = l.head;
	while(temp!=NULL){
		cout<<temp->data<<" ->";
		temp = temp->right;
	}
	/*if(isHeightBalancedFast(root).balance
		){
		cout<<"Badia hai";
	}
	else{
		cout<<"Not so Badia!";
	}
	cout<<endl;
	printTree(root);
	cout<<endl;
	printInorder(root);
	cout<<endl;
	printPostorder(root);
	cout<<endl;
	levelOrderPrint(root);
	*/

	return 0;
}