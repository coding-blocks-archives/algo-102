#include<iostream>
using namespace std;

void findSubseq(char *in,char *out,int i,int j){
		if(in[i]=='\0'){
			out[j] = '\0';
			cout<<out<<endl;
			return;
 		}
 		//Rec Case
 		//Inc the ith char
 		out[j] = in[i];
 		findSubseq(in,out,i+1,j+1);

 		//Exc the ith char
 		findSubseq(in,out,i+1,j);
}

int main(){

	char a[] = "abc";
	char out[100];
	findSubseq(a,out,0,0);

	return 0;
}