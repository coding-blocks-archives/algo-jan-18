#include<iostream>
#include<cstring>
using namespace std;


int main(){

	char a[100000];
	cin.getline(a,100000);
	char *ptr = strtok(a," ,+");
	while(ptr!=NULL){
		cout<<ptr<<endl;
		ptr = strtok(NULL," ,+");
	}


	return 0;
}