#include<iostream>
#include<unordered_map>
#include<list>
#include<queue>
using namespace std;

template<typename T>
class Graph{

	unordered_map<T,list<T> > m;
public:
	int V;

	void addEdge(T src,T dest,bool bidir = true){
		
		m[src].push_back(dest);
		if(bidir){
			m[dest].push_back(src);
		}
	}
	void printAdjList(){
		for(auto p:m){
			cout<<p.first<<"->";
			for(auto node:p.second){
				cout<<node<<",";
			}
			cout<<endl;
		}
	}
	void dfsHelper(T node,unordered_map<T,bool> &visited,int &ans){

		cout<<node<<" ";
		visited[node] = true;
		ans++;

		for(auto neighbour:m[node]){
			if(!visited[neighbour]){
				dfsHelper(neighbour,visited,ans);
			}
		}
		return;
	}

	int dfs(int n){
		unordered_map<T,bool> visited;
		
		int finalAns = n*(n-1)/2;

		for(auto p:m){
			if(!visited[p.first]){
				int ans = 0;
				dfsHelper(p.first,visited,ans);
				cout<<endl;
				finalAns -= (ans)*(ans-1)/2;
			}
		}
		return finalAns;
	}




	//Iterative Traversal of Graph - Breadth First Search
	void bfs(T src,T dest){
		queue<T> q;
		unordered_map<T,bool> visited;
		unordered_map<T,int> dist;
		unordered_map<T,T> parent;

		q.push(src);
		visited[src] = true;
		dist[src] = 0;
		parent[src] = src;

		while(!q.empty()){
			T f = q.front();
			q.pop();
			cout<<f<<" ";

			for(auto neigbour:m[f]){
				if(!visited[neigbour]){
					dist[neigbour] = dist[f] + 1;
					parent[neigbour] = f;
					q.push(neigbour);
					visited[neigbour] = true;
				}
			}
		}

		//Distances
		for(auto p:m){
			cout<<p.first<<"--> "<<dist[p.first]<<endl;
		}
		//Path Print
		T temp = dest;
		while(parent[temp]!= temp){
			cout<<temp<<"<--";
			temp = parent[temp];
		}
		cout<<src<<endl;

	return;
	}

};

int main(){
	Graph<int> g;
	g.addEdge(0,1);
	g.addEdge(0,4);
	g.addEdge(2,3);

	cout<<g.dfs(5)<<endl;

return 0;
}