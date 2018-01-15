#include<iostream>
using namespace std;


//ComplexNo
// Constructor, Copy Constructor, Copy Assignment 
// Operator Overloading
// c1 + c2;
// cout << c1;  a + ib
// cin>> c1;  a,b
// c1*c2;
// !c1;
// c['r']
// c['i'];


class ComplexNo{
	int r;
	int i;

public:
	ComplexNo(){
		r = 0;
		i = 0;
	}
	ComplexNo(int r,int i){
		this->r = r;
		this->i = i;
	}
	ComplexNo(const ComplexNo &c){
		r = c.r;
		i = c.i;
	}
	void operator=(const ComplexNo &c){
		r = c.r;
		i = c.i;
	}
	void print() const{
		if(i>=0){
			cout<<r<<" + "<<i<<"i"<<endl;
		}
		else{
			cout<<r<<" - "<<-1*i<<"i"<<endl;
		}
	}
	void operator+(const ComplexNo &c){
		r += c.r;
		i += c.i;
	}

	int operator[](char x){
		if(x=='r'){
			return r;
		}
		else{
			return i;
		}
	}
	void setValues(int r,int i){
		this->r  = r;
		this->i = i;
	}

	~ComplexNo(){

	}
};

istream& operator>>(istream &xyz,ComplexNo &c){
	int a,b;
	cin>>a>>b;
	c.setValues(a,b);
	return xyz;
}

ostream& operator<<(ostream &abc,ComplexNo &c){
	c.print();
	return abc;
}

int main(){
	ComplexNo c1,c2;
	cin>>c1>>c2;

	//c1 + c2;

	//Cascading of operators
	cout<<c1<<c2;

	cout<<c1['r'];
	

	return 0;
}