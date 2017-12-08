#include<iostream>
using namespace std;

int fib(int n){
		if(n==0||n==1){
			return n;
		}
		int ans;
		int f1 = fib(n-1);
		int f2 = fib(n-2);
		return f1+f2;
}

int main(){
		
	cout<<fib(5)<<endl;

	return 0;
}