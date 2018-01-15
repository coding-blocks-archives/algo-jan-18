#include<iostream>
using namespace std;

void fun(int &z){
	z++;
}

int main(){

	int x = 10;
	//Y and x are same bucket, y is a reference variable
	int &y = x;

	y++;
	x++;
	fun(y);

	cout<<x<<endl;
	cout<<y<<endl;
	//cout<<z<<endl;

}