#include<iostream>
#include<stack>
using namespace std;


int main(){

	stack<float> s;
	float b = 65.5;

	s.push(1+b);
	s.push(2+b);
	s.push(3+b);
	s.push(4+b);
	s.push(5+b);


	while(!s.empty()){
		cout<<s.top()<<endl;
		s.pop();
	}
	 
	return 0;



}