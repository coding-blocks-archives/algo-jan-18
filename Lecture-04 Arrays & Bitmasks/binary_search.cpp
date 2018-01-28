#include<iostream>
using namespace std;

int binarySearch(int *a,int n,int key){

	int s = 0;
	int e = n-1;

	while(s<=e){
		int mid = (s+e)/2;
		if(a[mid]==key){
			return mid;
		}
		else if(a[mid]>key){
			e = mid - 1;
		}
		else{
			s = mid + 1;
		}
	}
	return -1;
}


int lowerSearch(int *a,int n,int key){

	int s = 0;
	int e = n-1;
	int ans = -1;

	while(s<=e){
		int mid = (s+e)/2;
		
		if(a[mid]==key){
			ans = mid;
			e = mid - 1;
		}
		else if(a[mid]>key){
			e = mid - 1;
		}
		else{
			s = mid + 1;
		}
	}
	return ans;
}

int sqRoot(int n){
	int s = 0;
	int e = n ;
	
	int ans;

	while(s<=e){
		int m = (s+e)/2;

		if(m*m==n){
			return m;
		}
		else if(m*m < n){
			ans = m;
			s = m + 1;
		}
		else{
			e  = m -1;
		}
	}
	return ans;
}

int main(){

	int a[] = {1,2,2,2,2,2,2,2,2,3,14,15,16,70};
	int n = sizeof(a)/sizeof(int);

	//cout<<binarySearch(a,n,16)<<endl;
	//cout<<lowerSearch(a,n,2)<<endl;

	cout<<sqRoot(25);

	return 0;
}