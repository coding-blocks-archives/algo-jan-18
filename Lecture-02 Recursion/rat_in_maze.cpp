#include<iostream>
using namespace std;

bool ratInMaze(char maze[10][10],int sol[][10],int i,int j,int m,int n){
	if(i==m && j==n){
		sol[i][j] = 1;
		//Print the Path
		for(int x=0;x<=m;x++){
			for(int y=0;y<=n;y++){
				cout<<sol[x][y]<<" ";
			}
			cout<<endl;
		}
		cout<<endl;

		return true;
	}
	// Rec Case
	if(i>m || j>n){
		return false;
	}

	if(maze[i][j]=='X'){
		return false;
	}

	//Assumption 
	sol[i][j] = 1;

	bool rightSuccess = ratInMaze(maze,sol,i+1,j,m,n);
	bool downSuccess = ratInMaze(maze,sol,i,j+1,m,n);


	sol[i][j] = 0;

	if(rightSuccess||downSuccess){
		return true;
	}
	return false;
}

int main(){

	char maze[10][10] = {
						"0000",
						"00X0",
						"000X",
						"0X00",
						};

	int soln[10][10] = {0};	
	bool ans = ratInMaze(maze,soln,0,0,3,3);
	if(ans==false){
		cout<<"NO path exists !";
	}

	return 0;
}