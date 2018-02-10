#ifndef STACK_H
#define STACK_H

#include<vector>
using namespace std;

template<typename T>
class Stack{
	vector<T> v;

	public:
		Stack(int init_size=10){
			v.reserve(init_size);
		}

		void push(T data){
			v.push_back(data);
		}

		void pop(){
			v.pop_back();
		}
		T top() const{
			int i = v.size() - 1;
			return v[i];
		}
		bool isEmpty() const{
			return v.size()==0;
		}

};


#endif

