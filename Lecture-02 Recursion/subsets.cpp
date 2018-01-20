#include<iostream>
#include<set>
#include<cstring>
using namespace std;

//Subset Generation using Recursion
void subsets(char *in,char *out,int i,int j,set<string> & myS){
	if(in[i]=='\0'){
		out[j] = '\0';
		string s(out);
		myS.insert(s);
		cout<<out<<endl;
		return;
	}

	//Rec Case 
	//1. Inc 
		out[j] = in[i];
		subsets(in,out,i+1,j+1,myS);
	//2. Exc 
		subsets(in,out,i+1,j,myS);
}


int main(){

	char in[100] = "aaabc";
	char out[100];

	set<string> mySet;
	subsets(in,out,0,0,mySet);

	//Print the mySet using for-each loop
	for(string s:mySet){
		cout<<s<<","<<endl;
	}


	return 0;
}