#include <iostream>
#include <vector>
using namespace std;

class stack
{
	vector<int> stk;
	int top;
	int ms;
public:
	stack(int s=8){
		top=0;
		ms=s;
		stk.reserve(ms);
	}
	~stack();
	
	void push(int data){
		stk.push_back(data);
		//top+=1;
	}
	void pop(){
		stk.pop_back();
	}
	int topValue(){
		return stk[stk.size()-1];
	}
	bool isEmpty(){
		return stk.size()==0;
	}
};
int main(){
	stack obj;

	obj.push(1);
	obj.push(2);
	obj.push(3);
	obj.push(4);
	cout<<obj.topValue()<<"\n";
	obj.pop();
	while(!obj.isEmpty()){
		cout<<obj.topValue()<<"\n";
		obj.pop();
	}

	return 0;
}