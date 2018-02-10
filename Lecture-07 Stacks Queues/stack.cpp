#include<iostream>
#include "stack.h"
#include "stack.h"
using namespace std;


int main(){

	Stack<float> s;
	float b = 65.5;

	s.push(1+b);
	s.push(2+b);
	s.push(3+b);
	s.push(4+b);
	s.push(5+b);


	while(!s.isEmpty()){
		cout<<s.top()<<endl;
		s.pop();
	}
	 
	return 0;
}