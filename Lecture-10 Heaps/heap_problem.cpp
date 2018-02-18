#include<iostream>
#include<cstdio>
#include<queue>
#include<vector>
using namespace std;

void print(priority_queue<int,vector<int>,greater<int> > pq){
	while(!pq.empty()){
		cout<<pq.top()<<" ,";
		pq.pop();
	}
	cout<<endl;
}

int main(){

	int no;
	//cout<<EOF<<endl;
	int k = 3;
	priority_queue<int,vector<int>,greater<int> > pq;

	int cs = 0;

	while(scanf("%d",&no)!=EOF){

		cout<<no<<endl;
		if(no==-1){
			//Print the heap
			print(pq);
		
		}
		else if(cs<k){
			pq.push(no);
			cs++;
		}

		else{
			if(no>pq.top()){
				pq.pop();
				pq.push(no);
			}
		}
	}


	return 0;
}