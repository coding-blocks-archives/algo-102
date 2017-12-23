#include<iostream>
using namespace std;

void fun(int &z){
	z++;
}

int main(){

	int x = 10;
	
	cout<< &x <<endl;

	int *y = &x;
	cout<< y <<endl;
	cout<< &y <<endl;

	cout<< *y <<endl;
	cout<< *(&y) <<endl;

	

	return 0;
}