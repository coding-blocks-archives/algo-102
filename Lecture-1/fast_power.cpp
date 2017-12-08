#include<iostream>
using namespace std;

int power(int x,int n){
		if(n==0){
			return 1;
		}
		//Otherwise
		int smallPower = power(x,n/2);
		if(n&1){
				return x*smallPower*smallPower;
		}
		return smallPower*smallPower;

}

int inc(int n){
	if(n==0){
		return;
	}
	inc(n-1);
	cout<<n<<" ";
}
void dec(int n){
	if(n==0){
		return;
	}
	cout<<n<<",";
	dec(n-1);
}


int main(){
	cout<<power(5,4)<<endl;ṭ	
	
	return 0;
}