#include<iostream>
using namespace std;

void fun(int &z){
	z++;
}

int main(){

	int x = 10;
	int &y = x;
	x++;
	y++;
	fun(y);

	cout<<x<<endl;
	cout<<y<<endl;

	return 0;
}