#include<bits/stdc++.h>
using namespace std;

class Graph{
	
	list<int> *l;
	int V;
public:
	Graph(int V){
		this->V = V;
		l  = new list<int>[V];
	}
	void addEdge(int u,int v){
		l[u].push_back(v);
		l[v].push_back(u);
	}
	//Ghum k aao
	int dfsHelper(int node,bool *visited){
		visited[node] = true;
		cout<<node<<",";
		int ans = 1;
		for(int neighbour:l[node]){
			if(!visited[neighbour]){
				int nsize = dfsHelper(neighbour,visited);
				ans += nsize;
			}
		}
		return ans;

	}
	//Function Returns no of different astranaut pairs
	int dfs(){
			bool *visited = new bool[V]{0};
			int  ans = V*(V-1)/2;

			for(int i=0;i<V;i++){
				if(!visited[i]){
					int component_size = dfsHelper(i,visited);
					ans -= component_size*(component_size-1)/2;
					cout<<endl;
				}
			}
			return ans;
	}



};

int main(){

	Graph g(5);
	g.addEdge(0,1);
	g.addEdge(2,3);
	g.addEdge(0,4);
	cout<<g.dfs()<<endl;

};