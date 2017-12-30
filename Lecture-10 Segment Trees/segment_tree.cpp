#include<iostream>
using namespace std;

int lazy[10000] = {0};

void buildTree(int *a,int *tree,int index,int s,int e){
	if(s>e){
		return;
	}
	if(s==e){
		tree[index] = a[s];
		return;
	}
	//Rec Case
	int mid = (s+e)/2;
	buildTree(a,tree,2*index,s,mid);
	buildTree(a,tree,2*index+1,mid+1,e);
	tree[index] = min(tree[2*index],tree[2*index+1]);
	return;
}

int query(int *tree,int index,int s,int e,int qs,int qe){
		//Complete Overlap
		if(s>=qs && e<=qe){
			return tree[index];
		}

		//No Overlap
		if(qe<s || qs>e){
			return INT_MAX;
		}
		//Partial Overlap
		int mid = (s+e)/2;
		int left = query(tree,2*index,s,mid,qs,qe);
		int right = query(tree,2*index+1,mid+1,e,qs,qe);
		return min(left,right);
}

//Update Node
void updateNode(int *tree,int index,int s,int e,int i,int inc){
		//Out of Bounds
		if(i<s ||i>e){
			return;
		}
		//Leaf Node
		if(s==e){
			tree[index] += inc;
			return;
		}
		//Rec Case
		int mid = (s+e)/2;
		updateNode(tree,2*index,s,mid,i,inc);
		updateNode(tree,2*index+1,mid+1,e,i,inc);
		tree[index] = min(tree[2*index],tree[2*index+1]);
		return;
}
//Update Range 
void updateRange(int *tree,int index,int s,int e,int rs,int re,int inc){
		//Out of Bounds
		if(re<s || rs>e){
			return;
		}
		//Leaf nodes
		if(s==e){
			tree[index] += inc;
			return;
		}

		//Rec Case
		int mid = (s+e)/2;
		updateRange(tree,2*index,s,mid,rs,re,inc);
		updateRange(tree,2*index+1,mid+1,e,rs,re,inc);
		tree[index] = min(tree[2*index],tree[2*index+1]);
		return;

}
void updateRangeLazy(int *tree,int index,int s,int e,int rs,int re,int inc){
		//Check for the lazy value, resolve 
		if(lazy[index]!=0){

				tree[index] += lazy[index];
				if(s!=e){
					lazy[2*index] += lazy[index];
					lazy[2*index+1] += lazy[index];
				}
				lazy[index] = 0;
		}
		//Out of Bounds
		if(re<s || rs>e){
			return;
		}

		//Complete Overlap
		if(s>=rs && e<=re){
				tree[index] += inc;
				if(s!=e){
					lazy[2*index] += inc;
					lazy[2*index+1] += inc;
				}
		return;
		}

		//Partial Overlap
		int mid = (s+e)/2;
		updateRangeLazy(tree,2*index,s,mid,rs,re,inc);
		updateRangeLazy(tree,2*index+1,mid+1,e,rs,re,inc);
		tree[index] = min(tree[2*index],tree[2*index+1]);
		return;
}

int queryLazy(int *tree,int index,int s,int e,int qs,int qe){
		if(lazy[index]!=0){

				tree[index] += lazy[index];
				if(s!=e){
					lazy[2*index] += lazy[index];
					lazy[2*index+1] += lazy[index];
				}
				lazy[index] = 0;
		}
		
		//Complete Overlap
		if(s>=qs && e<=qe){
			return tree[index];
		}

		//No Overlap
		if(qe<s || qs>e){
			return INT_MAX;
		}
		//Partial Overlap
		int mid = (s+e)/2;
		int left = queryLazy(tree,2*index,s,mid,qs,qe);
		int right = queryLazy(tree,2*index+1,mid+1,e,qs,qe);
		return min(left,right);	
}



int main(){
	int a[] = {2,-3,1,0,5};
	int n = sizeof(a)/sizeof(int);

	int *tree = new int[4*n+1];
	buildTree(a,tree,1,0,n-1);

	/*for(int i=1;i<=9;i++){
		cout<<tree[i]<<" ";
	}*/
	int qs,qe;
	cin>>qs>>qe;
	//updateNode(tree,1,0,n-1,1,10);
	//updateRange(tree,1,0,n-1,1,3,10);
	
	//cout<<query(tree,1,0,n-1,qs,qe)<<endl;ṭ

	updateRangeLazy(tree,1,0,n-1,0,4,5);
	updateRangeLazy(tree,1,0,n-1,0,2,10);
	cout<<queryLazy(tree,1,0,n-1,qs,qe);ṭ		
	return 0;

}