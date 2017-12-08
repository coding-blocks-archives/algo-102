#include<iostream>
using namespace std;

int main(){

	float p = 1;
	//Prob of having different birthday
	int num = 365;
	int den = 365;
	int no_of_people = 0;

	while(p>=0.5){
		p = p*(num/(1.0*den));
		ṭnum--;
		no_of_people++;
		cout<<"Prob is "<<p<<" and "<<no_of_people<<endl;
	}

return 0;
}