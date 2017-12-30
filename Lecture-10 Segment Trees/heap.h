#ifndef HEAP_H
#define HEAP_H

#include<vector>
using namespace std;

class Heap{
		vector<int> v;
		bool minH;
	
	bool comp(int a,int b){
		if(minH){
				return a<b;
		}
		else{
			return a>b;
		}
	}
	void heapify(int idx){

		int left = 2*idx;
		int right = 2*idx + 1;
		int min_idx = idx;

		if(left<v.size() && comp(v[left],v[idx])){
			min_idx = left;
		}
		if(right<v.size() && comp(v[right],v[min_idx])){
			min_idx = right;
		}

		if(idx!=min_idx){
			swap(v[idx],v[min_idx]);
			heapify(min_idx);
		}
	}

public:
	 Heap(bool x=true){
	 	v.reserve(100);
	 	minH = x;
	 	v.push_back(-1);
	 }

	 void push(int data){
	 		v.push_back(data);
	 		int index = v.size()-1;
	 		int parent = index/2;
	 		
	 		while(index > 1 && comp(v[index],v[parent])){
	 				swap(v[index],v[parent]);
	 				index = parent;
	 				parent = parent/2;
	 		}
	 }
	 int top(){
	 	return v[1];
	 }

	 void pop(){
	 	int last = v.size() - 1;
	 	swap(v[1],v[last]);
	 	v.pop_back();
	 	heapify(1);
	 }
	 bool empty(){
	 	return v.size()==1;
	 }

};
#endif