#include<iostream>
#include<algorithm>
using namespace std;

bool compare(int a,int b){
	cout<<"Compare "<<a<<" and "<<b;
	return a>b;
}
	
int main(){

	int a[] = {1,5,4,3,2,8,9};
	int n = sizeof(a)/sizeof(int);

	sort(a,a+n,compare);

	for(int i=0;i<n;i++){
		cout<<a[i]<<" ";
	}

	return 0;
}