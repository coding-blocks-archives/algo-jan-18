#include<iostream>
#include<unordered_map>
using namespace std;

class node{
public:
	const char data;
	unordered_map<char,node*> m;
	bool isTerminal;
	node(char d):data(d),isTerminal(false){}
};

class Trie{
	node*root;
public:
	Trie(){
		root = new node('\0');
	}
	void addWord(char *w){

		node*temp =root;
		for(int i=0;w[i]!='\0';i++){
			char ch = w[i];
			if(temp->m.count(ch)){
				temp = temp->m[ch];
			}
			else{
				node*child = new node(ch);
				temp->m[ch] = child;
				temp = child;
			}

		}
		temp->isTerminal = true;
	}

	bool searchWord(char *w){
		node*temp = root;
		for(int i=0;w[i]!='\0';i++){
			char ch = w[i];

			if(temp->m.count(ch)){
				temp = temp->m[ch];
			}
			else{
				return false;
			}

		}
		return temp->isTerminal;
	}
};

int main(){

	char words[][10] = {"a","apple","ape","code","no","not","news","name"};
	Trie t;
	for(int i=0;i<8;i++){
		t.addWord(words[i]);
	}

	char w[10];
	cin>>w;
	if(t.searchWord(w)){
		cout<<"Word found !";
	}
	else{
		cout<<"Not found !";
	}


	return 0;
}