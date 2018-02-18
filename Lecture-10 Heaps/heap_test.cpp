#include<iostream>
#include "heap.h"
using namespace std;



int main(){

	Heap h(100,false);
	int n;
	cin>>n;

	cout<<"Enter n numbers ";
	for(int i=0;i<n;i++){
		int temp;
		cin>>temp;
		h.push(temp);
	}

	while(!h.isEmpty()){
		cout<<h.front()<<",";
		h.pop();
	}

	return 0;
}