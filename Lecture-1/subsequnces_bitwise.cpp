#include<iostream>
using namespace std;

void filterChars(int no,char *a){

	int i=0;
	
	while(no>0){
		if(no&1){
			cout<<a[i];
		}
		i++;
		no = no>>1;
	}

}

void print_subsequences(char *a,int L){

		for(int no=0;no< (1<<L);no++){
			filterChars(no,a);
			cout<<endl;
		}

}


int main(){

	//filterChars(5,"abc");
	print_subsequences("abc",3);
	return 0;
}