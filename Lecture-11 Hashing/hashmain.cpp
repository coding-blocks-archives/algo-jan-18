#include<iostream>
#include "hashtable.h"
using namespace std;


int main(){
	Hashtable<int> h;

	h.insert("Mango",100);
	h.insert("Apple",120);
	h.insert("Guava",80);
	h.insert("Banana",60);
	h.insert("Lit-chi",90);
	
	h["Orange"] = 30;
	h["Mango"] = 95;

	cout<<h["Mango"]<<endl;

	string f;
	cin>>f;

	int *price  = h.search(f);
	if(price==NULL){
		cout<<"Out of stock !";
	}
	else{
		cout<<"Price is "<<*price<<endl;
	}
	h.print();
	return 0;
}