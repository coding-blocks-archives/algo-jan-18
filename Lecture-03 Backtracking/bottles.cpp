#include<iostream>
using namespace std;

int bottles(int *a,int i,int j,int day){
	if(i>j){
		return 0;
	}
	int op1 = a[i]*day + bottles(a,i+1,j,day+1);
	int op2 = a[j]*day + bottles(a,i,j-1,day+1);
	return max(op1,op2);

}

int main(){

	return 0;
}