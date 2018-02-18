#ifndef HEAP_H
#define HEAP_H 
#include<vector>
using namespace std;

class Heap{

	vector<int> v;
	bool minHeap;
	
	bool cmp(int a,int b){
		if(minHeap)
			return a<b;
		else
			return a>b;
	}
	void heapify(int i){

		int left =2*i;
		int right = 2*i + 1;

		int min_i = i;
		
		if(left<v.size() && cmp(v[left],v[i])){
			min_i = left;
		}
		if(right<v.size() && cmp(v[right],v[min_i])){
			min_i = right;
		}

		if(i!=min_i){
			swap(v[i],v[min_i]);
			heapify(min_i);
		}

	}
public:
	Heap(int ds=100,bool flag=true){
		minHeap = flag;
		v.reserve(ds);
		v.push_back(-1);
	}

	void push(int data){
		v.push_back(data);
		int i = v.size()-1;
		int p = i/2;
		while(i>1 && cmp(v[i],v[p]))
		{
			swap(v[i],v[p]);
			i = p;
			p = p/2;
		}
	}
	bool isEmpty(){
		return v.size()==1;
	}
	int front(){
		return v[1];
	}
	void pop(){
		//Swap first and last
		int last = v.size()-1;
		swap(v[1],v[last]);

		v.pop_back();

		//Heapify
		heapify(1); 
	}



};
#endif