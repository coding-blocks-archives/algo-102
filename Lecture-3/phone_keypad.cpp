#include<iostream>
#include<cstring>
using namespace std;

string keypad[] = {"","","ABC","DEF","GHI","JKL","MNO","PQRS","TUV","WXYZ"};

void phoneKeyPadStrings(char *in,char *out,int i=0,int j=0){
	if(in[i]=='\0'){
		out[j]='\0';
		cout<<out<<endl;
		return;
	}
	//Otherwise ?

	int digit = in[i]-'0';
	for(int k=0;k<keypad[digit].length();k++){
		char ch = keypad[digit][k];
		out[j] = ch;
		phoneKeyPadStrings(in,out,i+1,j+1);
	}

	return;
}


int main(){

	char in[100],out[100];
	cin>>in;

	phoneKeyPadStrings(in,out);


	return 0;
}