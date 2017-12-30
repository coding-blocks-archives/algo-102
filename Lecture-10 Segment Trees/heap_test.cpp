#include<iostream>
#include "heap.h"
using namespace std;


int main(){

	Heap h(false);
	int a[] = {1,5,3,2,6,8,7};
	int n = sizeof(a)/sizeof(int);

	for(int i=0;i<n;i++){
		h.push(a[i]);
	}
	//i= 0;
	while(!h.empty()){
		//a[i] = h.top(); i++;
		cout<<h.top()<<" ";
		h.pop();
	}

	return 0;
}