#include<iostream>
#include<cstring>
using namespace std;

int main(){


		string s ="abcdef";
		int L = s.length();

		for(int i=0;i<L;i++){
			
			for(int j=i;j<L;j++){
					
					for(int k=i;k<=j;k++){
						cout<<s[k];
					}
					cout<<endl;
			}
		}

	

return 0;
}