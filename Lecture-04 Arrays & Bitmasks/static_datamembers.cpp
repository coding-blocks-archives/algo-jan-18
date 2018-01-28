#include<iostream>
using namespace std;


//Static Variables
int fun(){
	static int i =0;
	i++;

	return i;
}

int main(){
	cout<<fun()<<endl;
	cout<<fun()<<endl;
	cout<<fun()<<endl;
	cout<<fun()<<endl;
	cout<<fun()<<endl;

}