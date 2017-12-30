#include<iostream>
#include<queue>
using namespace std;

class Person{
public:
	int money;
	string name;
	
	Person(){

	}

	Person(int m,string n){
		name  = n;
		money = m;
	}
	bool operator()(Person a,Person b){
		//cout<<"Having fun at "+venue<<endl;
		return a.money<b.money;
	}
	
};

ostream& operator<<(ostream&os,Person &p){
	os<<p.name<<endl;
	os<<p.money<<endl;
	return os;
}

//Operator Overloading
class PersonCompare{
public:	
	bool operator()(Person a,Person b){
		//cout<<"Having fun at "+venue<<endl;
		return a.money<b.money;
	}

};


int main(){
	//Inbuild STL

	//Max Heap
	priority_queue<int> hMax;

	//Min Heap
	priority_queue<int, vector<int>, greater<int> > hMin;

	//Custom Objects Priority Queue
	Person p1(100,"Agrim");
	Person p2(200,"Aspira");
	Person p3(10,"Anuj");
	Person p4(250,"Arjun");


	priority_queue<Person, vector<Person>, Person > h;
	h.push(p1);
	h.push(p2);
	h.push(p3);
	h.push(p4);

	while(!h.empty()){
		Person pi = h.top();
		cout<<pi<<endl;
		h.pop();
	}


	


	//PersonCompare p;
	//p("Coding Blocks"); //Functor - Object behaving as a function

	/*
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
	*/

	return 0;



}