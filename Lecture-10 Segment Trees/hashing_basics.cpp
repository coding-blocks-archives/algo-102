#include<iostream>
#include<unordered_map>
#include<map>
using namespace std;



int main(){

	map<string,int> price;

	//Insertion
	price["Mango"] = 100;
	price["Mango"] += 20;
	price["Apple"] = 20;

	price.insert(make_pair("Guava",60));
	
	pair<string,int> p("Papaya",90);
	price.insert(p);

	//Search - 2 ways
	cout<<price["Mango"]<<endl;

	//Count returns 0 or 1
	if(price.count("Kiwi")){
		cout<<price["Kiwi"]<<endl;
	}
	else{
		cout<<"Kiwi not found"<<endl;
	}
	//Removal
	price.erase("Guava");

	//Using the Find fn - returns an iterator to pair
	auto it = price.find("Guava");
	if(it==price.end()){
		cout<<"Guava not present";
	}
	else{
		cout<<it->first<<endl;
		cout<<it->second<<endl;
	}

	//Print all the elements in the map
	// Iterators
	cout<<endl;
	for(auto it = price.begin();it!=price.end();it++){
		cout<<it->first<<", "<<it->second<<endl;
	}


	// For Each Loop
	for(auto p:price){
		cout<<p.first<<" ,"<<p.second<<endl;
	}

	return 0;
}