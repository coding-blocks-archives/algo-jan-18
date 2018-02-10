#include<iostream>
#include "queue.h"
using namespace std;


int main(){

	Queue q;

	for(int i=1;i<=6;i++){
		q.push(i);
	}
	q.pop();
	q.pop();
	q.push(7);

	while(!q.empty()){
		cout<<q.front()<<" ";
		q.pop();
	}

	return 0;
}