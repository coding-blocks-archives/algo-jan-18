#include<iostream>
#include<stack>
using namespace std;

void print(stack<int> s){
	while(!s.empty()){
		cout<<s.top();
		s.pop();
	}
}
void insertAtBottom(stack<int> &s,int data){
	//Base Case
	if(s.empty()){
		s.push(data);
		return;
	}
	//Otherwise !
	int element = s.top();
	s.pop();
	insertAtBottom(s,data);
	s.push(element);
}
void reverse(stack<int> &s){
	//Base Case
	if(s.empty()){
		return;
	}
	//Otherwise !
	int tp = s.top();
	s.pop();
	reverse(s);
	insertAtBottom(s,tp);
}

int main(){

	stack<int> s;

	s.push(1);
	s.push(2);
	s.push(3);
	s.push(4);
	s.push(5);

	print(s);
	cout<<endl;
	reverse(s);
	print(s);

	return 0;
}