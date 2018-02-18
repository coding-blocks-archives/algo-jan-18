#include<iostream>
#include<queue>
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

node* buildTree(){

	//cout<<"Enter data";
	int d;
	cin>>d;

	if(d==-1){
		return NULL;
	}

	node* n = new node(d);
	n->left = buildTree();
	n->right = buildTree();

	return n;
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
	root = buildTree();
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
void levelOrderBuild(node*&root){

	cout<<"Enter Root Data"<<endl;
	int d;
	cin>>d;

	root  = new node(d);
	queue<node*> q;
	q.push(root);

	while(!q.empty()){
		node* n = q.front();
		q.pop();

		int c1,c2;
		cout<<"Enter children of "<<n->data<<endl;
		cin>>c1>>c2;
		if(c1!=-1){
			n->left = new node(c1);
			q.push(n->left);
		}
		if(c2!=-1){
			n->right = new node(c2);
			q.push(n->right);
		}
	}
}

int replaceWithSum(node *root){
	if(root==NULL){
		return 0;
	}

	int lsum = replaceWithSum(root->left);
	int rsum = replaceWithSum(root->right);
	root->data += lsum + rsum;
	return root->data;
}
//Leaving leaves
int replaceWithChildrenSum(node *root){
	if(root==NULL){
		return 0;
	}
	if(root->left==NULL && root->right==NULL){
		return root->data;
	}

	int lsum = replaceWithChildrenSum(root->left);
	int rsum = replaceWithChildrenSum(root->right);
	int temp = root->data;
	root->data = lsum + rsum;
	return root->data+temp;
}
//MaxSubsetSum - Include either node or its child in the sum
class Pair{
public:
	int inc;
	int exc;
};

Pair maxSubsetSum(node*root){
	Pair p;
	if(root==NULL){
		p.inc = p.exc = 0;
		return p;
	}

	//Post order
	Pair L = maxSubsetSum(root->left);
	Pair R = maxSubsetSum(root->right);

	p.inc = root->data + L.exc + R.exc;
	p.exc = max(L.inc,L.exc) + max(R.inc,R.exc);
	return p;
}

int diameter(node*root){
	if(root==NULL){
		return 0;
	}
	int op1 = height(root->left) + height(root->right);
	int ld = diameter(root->left);
	int rd = diameter(root->right);
	return max(op1,max(ld,rd));
}

class HDPair{
public:
	int height;
	int diameter;
};
//Complexity O(n)
HDPair fastDiameter(node *root){
	HDPair p;
	if(root==NULL){
		p.height = p.diameter = 0;
		return p;
	}

	HDPair Left = fastDiameter(root->left);
	HDPair Right = fastDiameter(root->right);

	p.height = max(Left.height,Right.height) + 1;


	int op1 = Left.height  + Right.height;
	int ld = Left.diameter;
	int rd = Right.diameter;

	p.diameter = max(op1,max(ld,rd));
	return p;
}


int main(){
	node* root = NULL;
	//cin>>root;
	levelOrderBuild(root);

	cout<<endl;
	printTree(root);
	cout<<endl;
	printInorder(root);
	cout<<endl;
	printPostorder(root);
	cout<<endl;
	cout<<"Height of tree is "<<height(root)<<endl;
	
	cout<<"Nodes at level k are ";
	printAtLevelK(root,3);
	cout<<endl;
	//cout<<root;
	
	levelOrderPrint(root);
	//replaceWithChildrenSum(root);
	cout<<endl;
	levelOrderPrint(root);	

	Pair ans = maxSubsetSum(root);

	cout<<"Maxisum Subset Sum "<<max(ans.inc,ans.exc)<<endl;

	return 0;
}