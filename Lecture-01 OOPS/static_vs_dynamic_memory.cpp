#include<iostream>
using namespace std;

int *createArr(){
	int *a = new int[100];
	for(int i=0;i<=10;i++){
		a[i] = i;
	}

	return a;
}

int main(){
	
	int *x = createArr();
	
	for(int i=0;i<=10;i++){
		cout<<x[i]<<","<<endl;
	}
	delete [] x;
return 0;
}