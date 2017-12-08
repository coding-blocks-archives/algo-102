#include<bits/stdc++.h>
using namespace std;

set<string> s;

void printPermutation(char *a,int i){
	
	if(a[i]=='\0'){
		//cout<<a<<endl;
		string temp = a;
		s.insert(temp);
		return;
	}
	//Place 1 char at front and call for remaining part
	for(int j=i;a[j]!='\0';j++){
		swap(a[i],a[j]);
		printPermutation(a,i+1);
		//Restore - Backtracking
		swap(a[i],a[j]);
	}
	return;
}

int main(){
	
	char a[100];
	cin>>a;
	printPermutation(a,0);

	//Iterate Over Set and Print - Iterators
	for(auto ptr = s.begin();ptr!=s.end();ptr++){
		cout<< (*ptr) <<", ";
	}

	// Using For Each Loop
	for(string p:s){
		cout<<p<<endl;
	}

	return 0;
}