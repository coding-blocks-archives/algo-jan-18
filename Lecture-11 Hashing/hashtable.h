#ifndef HASHTABLE_H
#define HASHTABLE_H
#include<cstring>
using namespace std;

template<typename T>
class Hashtable;

template<typename T>
class node{
	string key;
	T value;
	node*next;
public:
	node(string k,T v){
		key = k;
		value = v;
		next = NULL;
	}
	~node(){
		if(next!=NULL){
			delete next;
		}
	}

	friend class Hashtable<T>;

};


template<typename T>
class Hashtable{

	int ts;
	int cs;
	node<T>** table;

	int hashFn(string key){
		int ans = 0;
		int p = 1;

		for(int i=0;i<key.length();i++){
			ans += p*key[i];
			p = p*37;
			p %= ts;
			ans %= ts;
		}
		return ans;
	}

	void rehash(){

		node<T>**oldTable = table;
		table = new node<T>*[2*ts+1];
		int oldTs =ts;
		ts = 2*ts+1;

		for(int i=0;i<ts;i++){
			table[i] = NULL;
		}
		cs = 0;

		for(int i=0;i<oldTs;i++){
			node<T>*temp = oldTable[i];

			if(temp!=NULL){
				while(temp!=NULL){
					insert(temp->key,temp->value);
					temp = temp->next;
				}
				delete oldTable[i];
			}	
		}
		delete [] oldTable;
	}

public:
	Hashtable(int ts=7){
		this->ts = ts;
		cs = 0;
		table = new node<T>*[ts];
		
		//Init all head pointers with NULL
		for(int i=0;i<ts;i++){
			table[i] = NULL;
		}
	}

	void insert(string key,T value){
		int i = hashFn(key);

		node<T>* n = new node<T>(key,value);
		n->next = table[i];
		table[i] = n;

		cs += 1;
		//Later On...
		float load_factor = cs/(1.0*ts); 
		float threshold = 0.70;
		if(load_factor>threshold){
			cout<<"load factor :"<<load_factor<<endl;
			rehash();
		}
	}

	T* search(string key){
		int i = hashFn(key);

		node<T> *temp = table[i];
		while(temp!=NULL && temp->key!=key){
			temp = temp->next;
		}
		if(temp==NULL){
			return NULL;
		}
		return &(temp->value);
	}
	void erase(string key){
		// 1. Search
		// 2. Delete that node(IF EXISTS) from linked list (table[i])
		// 3. Cs--

	}
	T& operator[](string key){

		T* vptr = search(key);
		if(vptr==NULL){
			T garbage;
			insert(key,garbage);
			vptr = search(key);
			return (*vptr);
		}
		else{
			return (*vptr);
		}

	}
	void print(){

		for(int i=0;i<ts;i++){
			node<T>* temp = table[i];
			cout<<"Bucket "<<i<<" = ";

			while(temp!=NULL){
				cout<<temp->key<<"->";
				temp = temp->next;
			}
			cout<<endl;
		}
	}

};
#endif