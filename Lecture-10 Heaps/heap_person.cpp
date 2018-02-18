#include<iostream>
#include<queue>
#include<cstring>
using namespace std;

class Person{
public:	
	int age;
	string name;

	Person(){

	}
	Person(string n,int a){
		age = a;
		name = n;
	}
	void print(){
		cout<<"Name : "<<name<<endl;
		cout<<"Age :"<<age<<endl<<endl;
	}
};

class PersonCompare{
	public:
		bool operator()(Person p1,Person p2){
			//cout<<"Learning Functor "<<s;
			//cout<<p1.name<<" is more clever than "<<p2.name<<endl;
			//return p1.name<p2.name;
			return p1.age>p2.age;
		}

};

int main(){
	
	

	//Min Heap
	priority_queue<Person,vector<Person>,PersonCompare> h;



	Person p1("Modi",65);
	Person p2("Kejru",45);
	Person p3("Pappu",48);

	PersonCompare pc;
	//pc("at Coding Blocks");
	//pc(p2,p1);

	
	h.push(p1);
	h.push(p2);
	h.push(p3);

	
	while(!h.empty()){
		Person p = h.top();
		p.print();
		h.pop();
	}

	return 0;
}