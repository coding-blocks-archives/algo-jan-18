#include<bits/stdc++.h>
using namespace std;

bool comp(pair<int,int> a1,pair<int,int> a2){
	return a1.second < a2.second;
}

int countActivities(vector<pair<int,int> > v){
	// Sort based upon end time
	sort(v.begin(),v.end(),comp);

	//Pick the Pick first activity
	int finish = v[0].second;
	int count = 1;

	for(int i=1;i<v.size();i++){

		int current_start = v[i].first;
		if(current_start>=finish){
			count++;
			finish = v[i].second;
		}	
	}
	return count;
}

int main(){

	int t;
	cin>>t;

	vector<pair<int,int> > v;

	while(t--){
		int n;
		cin>>n;
		v.clear();
		int s,e;
		for(int i=0;i<n;i++){
			cin>>s>>e;
			v.push_back(make_pair(s,e));
		}
		cout<<countActivities(v);
	}
}