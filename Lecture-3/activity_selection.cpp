#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

/*class Pair{
	int startTime;
	int endTime;
}*/
bool compare(pair<int,int> p1,pair<int,int> p2){

	return p1.second < p2.second;
}

int activitySelection(vector<pair<int,int> > &v,int n){

	sort(v.begin(),v.end(),compare);

	int fin = v[0].second;
	int ans =1;
	
	for(int i=1;i<n;i++){
		
		if(v[i].first >= fin){
			ans++;
			fin = v[i].second;
		}
	}
	return ans;
}

int main(){
	int t;
	cin>>t;
	int n;
	vector<pair<int,int> > v;

	while(t--){
		cin>>n;
		for(int i=0;i<n;i++){
			int s,e;
			cin>>s>>e;
			v.push_back(make_pair(s,e));
		}
		int ans = activitySelection(v,n);
		cout<<ans<<endl;
		v.clear();
	}

}


