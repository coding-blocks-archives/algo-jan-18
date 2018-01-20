#include<iostream>
using namespace std;

bool lt[30] = {0};
bool rt[30] = {0};
bool col[30] = {0};

int ans = 0;
void nqueenways(int i,int n,int board[10][10]){
	//Base Case
	if(i==n){
		ans++;
		//Print the board
		for(int x=0;x<n;x++){
			for(int y=0;y<n;y++){
				cout<<board[x][y]<<" ";
			}
			cout<<endl;
		}
		cout<<endl;
		return;
	}
	//Rec Case
	// Try to the place in queen in all possible positions in the current row
	for(int c=0;c<n;c++){
		//Place at i,c
		if(!col[c] && !lt[i-c+n-1] &&!rt[i+c]){
			col[c] = lt[i-c+n-1] = rt[i+c] =board[i][c]=1;
			nqueenways(i+1,n,board);
			
			//Backtracking !
			board[i][c] = 0;
			col[c] = lt[i-c+n-1] = rt[i+c] =board[i][c]=0;
		}
	}
}


int main(){

	int n;
	cin>>n;
	int board[10][10] = {0};
	nqueenways(0,n,board);

	cout<<ans<<endl;
	return 0;
}