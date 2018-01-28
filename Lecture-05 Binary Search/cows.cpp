#include<iostream>
using namespace std;

bool canPlace(int c,int n,int *x,int D){

	int cow = 1; //0 th stall
	int last_stall = x[0];

	for(int i=1;i<n;i++){
		int current_stall = x[i];
		if(current_stall-last_stall>=D){
			cow++;
			last_stall = current_stall;
		}
		if(cow==c){
			return true;
		}
	}
	return false;
}

int binarySearch(int c,int n,int *x){

	int s = 0;
	int e = x[n-1];
	int ans = -1;

	while(s<=e){
		int mid = (s+e)/2;

		if(canPlace(c,n,x,mid)){
			ans = mid;
			s = mid + 1;
		}
		else{
			e = mid - 1;
		}
	}
	return ans;
}


int main(){
	int cows = 3;
	int stalls = 5;
	int x[] = {1,2,4,8,9};

	cout<<binarySearch(cows,stalls,x)<<endl;

	return 0;
}