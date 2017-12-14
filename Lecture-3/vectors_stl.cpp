#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool compare(int a,int b){
	//cout<<"Compareing "<<a<<" and "<<b<<endl;
	return a>b;
}

int main(){

	//Vectors - Resizable Arrays in C++
	// Expand on demand 

	vector<int> v;
	v.reserve(100);

	for(int i=0;i<=5;i++){
		v.push_back(i*i);
	}
	//v[i] += 5
	//v.pop_back()

	//Print the elements
	//Resize - size,value-init
	v.resize(15,11);


	sort(v.begin(),v.end(),compare);


	for(int i=0;i<v.size();i++){
		cout<<v[i]<<endl;
	}


	cout<<v.capacity()<<endl;
	cout<<v.max_size()<<endl;







}