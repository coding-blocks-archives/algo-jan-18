#include<bits/stdc++.h>
using namespace std;

class Graph{
	
	list<pair<int,int> > *l;
	int V;
public:
	Graph(int V){
		this->V = V;
		l  = new list<pair<int,int> >[V];
	}
	void addEdge(int u,int v,int wt){
		l[u].push_back(make_pair(v,wt));
		l[v].push_back(make_pair(u,wt));
	}
	int dfsHelper(int u,bool *visited,int &ans){
		visited[u] = true;
		int subtree_size = 1;

		for(auto neighbour:l[u]){
			int v = neighbour.first;
			int w = neighbour.second;

			if(!visited[v]){
				int v_size = dfsHelper(v,visited,ans);
				subtree_size += v_size;
				ans += 2*min(v_size,V-v_size)*w;
			}
		}
		
		//cout<<subtree_size<<endl;
		return subtree_size;
	}
	//Function Returns no of different astranaut pairs
	int dfs(){
		bool *visited = new bool[V]{0};
		int ans = 0;
		dfsHelper(0,visited,ans);
		return ans;
	}
};

int main(){

	Graph g(4);
	g.addEdge(0,1,3);
	g.addEdge(1,2,2);
	g.addEdge(2,3,2);
	cout<<g.dfs()<<endl;
};