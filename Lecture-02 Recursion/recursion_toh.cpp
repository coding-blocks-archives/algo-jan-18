#include<iostream>
using namespace std;

void toh(int n,char src,char help,char dest){
	if(n==0){
		return;
	}
	toh(n-1,src,dest,help);
	cout<<"Move disk "<<n<<" from "<<src<<" to "<<dest<<endl;
	toh(n-1,help,src,dest);
}

int steps(int n){
	if(n==0){
		return 0;	
	}
	return 2*steps(n-1) + 1;
}
//Optimise
int fastSteps(int n){
	return (1<<n) - 1;
}

int main(){

	int n;
	cin>>n;
	//toh(n,'A','B','C');
	cout<<steps(n)<<endl;


	return 0;
}