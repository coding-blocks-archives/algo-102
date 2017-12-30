#include<bits/stdc++.h>
using namespace std;

class Graph{
	int V;
	unordered_map<int,list<pair<int,int> > > m;
public:
	Graph(int v){
		V = v;
	}
	//Weighted Graph
	void addEdge(int u,int v,int wt,bool bidir=true){
		m[u].push_back(make_pair(v,wt));
		if(bidir){
			m[v].push_back(make_pair(u,wt));
		}
	}
	int dfsHelper(int node,int *cnt,bool *visited,int &ans){

		visited[node] = true;
		cnt[node] = 1;

		for(auto np:m[node]){
			int neigbour = np.first;
			
			if(!visited[neigbour]){
				cnt[node] += dfsHelper(neigbour,cnt,visited,ans);
				int x = cnt[neigbour];
				int y = V - cnt[neigbour];
				ans += 2*min(x,y)*(np.second);
			}
		}

		return cnt[node];

	}

	int dfs(int src){
		int *cnt = new int[V+1]{0};
		bool *visited = new bool[V+1]{0};
		int ans = 0;
		dfsHelper(src,cnt,visited,ans);
		return ans;
	}

};


int main(){

	Graph g(4);
	g.addEdge(1,2,3);
	g.addEdge(2,3,2);
	g.addEdge(3,4,2);

	cout<<g.dfs(1)<<endl;


return 0;
}