#include<iostream>
#include<queue>
#include<cstring>
using namespace std;

class Person(){
public:	
	int age;
	string name;

	Person(){

	}
	Person(string n,int a){
		age = a;
		name = n;
	}

}

int main(){
	
	//priority_queue<int,vector<int>,greater<int> > h;

	//Min Heap
	priority_queue<int,vector<int>,greater<int> > h;

	int n;
	cin>>n;

	cout<<"Enter n numbers ";
	for(int i=0;i<n;i++){
		int temp;
		cin>>temp;
		h.push(temp);
	}

	while(!h.empty()){
		cout<<h.top()<<",";
		h.pop();
	}


	return 0;
}