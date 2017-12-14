#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool compare(string a,string b){
		if(a.length()!=b.length()){
			return a.length()<b.length();
		}
		else{
			return a>b;
		}
}

int main(){

	//Vectors - Resizable Arrays in C++
	// Expand on demand 

	//vector<string> vs;
	string s[] = {"apple","ape","mango"};

	vector<string> vs;
	for(int i=0;i<3;i++){
		vs.push_back(s[i]);
	}

	sort(vs.begin(),vs.end(),compare);
	
	for(int i=0;i<3;i++){
		cout<<vs[i]<<endl;
	}


return 0;

}