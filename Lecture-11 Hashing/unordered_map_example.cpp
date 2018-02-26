#include<iostream>
#include<unordered_map>
#include<map>
#include<cstring>
using namespace std;


int main(){

	unordered_map<string,int> h;

	//Insert
	h.insert(make_pair("Mango",100));

	pair<string,int> p;
	p.first = "Apple";
	p.second = 20;

	h.insert(p);

	h["Litchi"] = 90;

	//Search - 2 ways
	if(h.count("Litchi")){
		cout<<"Litchi exists at price"<<h["Litchi"];
	}

	//using the find function
	unordered_map<string,int>::iterator it = h.find("Mango");
	//auto it = h.find("Mango");
	cout<<"Mango price "<<it->second<<endl;

	//Delete
	h.erase("Mango");
	h.erase("Mango");
	//h.erase(it);


	for(auto fp:h){
		cout<<fp.first<<endl;
		cout<<fp.second;
	}

	for(auto it = h.begin();it!=h.end();it++){
		cout<<it->first<<endl;
		cout<<it->second<<endl;
	}

	return 0;
}