#include<iostream>
using namespace std;


// Finding Permuations of a String

void printPermuation(char *input,int i){
	if(input[i]=='\0'){
		cout<<input<<endl;
		return;
	}
	//Rec Case
	for(int j=i;input[j]!='\0';j++){
		//Top Down
		swap(input[i],input[j]);
		
		printPermuation(input,i+1);
		//Bottom Up
		//Backtracking
		swap(input[i],input[j]);
	}	

}

int main(){
	char input[100];
	cin>>input;

	printPermuation(input,0);

	return 0;
}