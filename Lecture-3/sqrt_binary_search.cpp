#include<iostream>
using namespace std;

float squareRoot(int n,int p){

	int s = 0;
	int e = n;
	int ans = 0;

	while(s<=e){
		int mid = (s+e)/2;

		if(mid*mid==n){
			return mid;
		}
		else if(mid*mid <n){
			ans = mid;
			s = mid + 1;
		}
		else{
			e = mid - 1;
		}

	}
	//Precision
	float nans = ans;
	float inc = 0.1;

	for(int place=1;place<=p;place++){
	
		while(nans*nans <=n){
			nans += inc;
		}
		nans -= inc;
		inc = inc/10;
	}
	return nans;

}

int main(){

	int n;
	cin>>n;

	cout<<squareRoot(n,4)<<endl;

	return 0;
}