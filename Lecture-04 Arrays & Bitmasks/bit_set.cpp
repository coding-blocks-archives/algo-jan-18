#include<iostream>
using namespace std ;

int findSetBits(int n){
	int ans = 0;

	while(n>0){
		ans++;
		int p = n&(-n);
		n = n - p;
	}
	return ans;
}


int main(){
	int n;
	cin>>n;
	cout<<findSetBits(n)<<endl;

	return 0;
}