#include<iostream>
using namespace std;

char keypad[][10] = {"","","ABC","DEF","GHI","JKL","MNO","PQRS","TUV","WXYZ"};


void phoneKeypad(char *in,int i,char *out,int j){
	//Base Case
	if(in[i]=='\0'){
		out[j] = '\0';
		cout<<out<<endl;
		return;
	}
	//Recursive Case ?
	char ch = in[i];
	int digit = ch - '0';

	if(digit==1||digit==0){
		phoneKeypad(in,i+1,out,j);
		return;
	}

	for(int k=0;keypad[digit][k]!='\0';k++){
		out[j] = keypad[digit][k];
		phoneKeypad(in,i+1,out,j+1);
	}
}

int main(){

	char in[100];
	cin>>in;
	char out[100];
	phoneKeypad(in,0,out,0);


	return 0;
}