#include<iostream>
using namespace std;

int f(int *a,int i,int j){
	if(i>j){
		return 0;
	}

	int op1 = a[i] + min(f(a,i+1,j-1),f(a,i+2,j));
	int op2 = a[j] + min(f(a,i,j-2),f(a,i+1,j-1));
	return max(op1,op2);
}

int main(){

	int a[] = {3,16,7,4,15,8,20,10};
	cout<<f(a,0,7)<<endl;	


	return 0;
}