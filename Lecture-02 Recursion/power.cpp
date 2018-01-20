#include<iostream>
using namespace std;

//Complexity is O(N)
int power(int a,int n){
	return n==0?1:a*power(a,n-1);
}

//Optimise !
int fastPower(int a,int n){
	if(n==0){
		return 1;
	}
	int a1 = fastPower(a,n/2);
	a1 *= a1;
	return (n&1)?a*a1:a1;
}







int main(){
	cout<<power(5,3)<<endl;
	cout<<fastPower(3,5)<<endl;
	return 0;
}