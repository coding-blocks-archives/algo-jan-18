/* Implement a Vector Class */
/* with the following operations 
	1. Push Back - Add element at end (Automatically Doubling of Memory)
	2. Pop - Remove element frome end
	3. [] operator - find element at ith index
	4. v + v1 - append two vectors
*/
#include<iostream>
using namespace std;

class Vector{
	int * arr;
	int ms;
	int cs;

public:
	Vector(int def_size=4){
		ms = def_size;
		cs = 0;
		arr = new int[ms];
	}
	Vector(Vector &v){
	    
	    cs = 0;
	    ms = v.ms;
	    arr = new int[ms];
	    
	    for(int i=0;i<v.size();i++){
	        push_back(v[i]);
	    }
	    
	    
	}
	int size(){
	    return cs;
	}
	void push_back(int data){
		if(cs==ms){
			//Doubling Later
			int *oldArr = arr;
			int oldCs = cs;
			
			ms *= 2;
			arr = new int[ms];
			for(int i=0;i<oldCs;i++){
			    arr[i] = oldArr[i];
			}
		}
		arr[cs] = data;
		cs++;
	}
	void pop_back(){
		if(cs>0){
			cs--;
		}
	}
	void print() const{
		for(int i=0;i<cs;i++){
			cout<<arr[i]<<",";
		}
		cout<<endl;
	}
	int getMaxSize(){
	    return ms;
	}
	int& operator[](int i){
		return arr[i];
	}
	~Vector(){
		if(arr!=NULL){
			delete [] arr;
			arr = NULL;
		}
	}
};
// Add +, !, ~ Destructor

ostream& operator<<(ostream&os, const Vector&v){
		v.print();
		return os;
}

int main(){

	Vector v1;
	v1.push_back(1);
	v1.push_back(5);
	v1.push_back(10);
	v1.push_back(7);
	v1.push_back(8);
	v1.push_back(11);
	

	Vector v2=v1;
	//v1.pop_back();
	v1[0] = 100;
	cout<<v1<<endl;
	cout<<v2<<endl;
	cout<<v1.getMaxSize()<<endl;
	
	//cout<<v1<<v2<<endl;

	return 0;
}

