#include<iostream>
using namespace std;


void replacePi(char a[],int i=0){
		//Think about base case
		if(a[i+1]=='\0'||a[i]=='\0'){
			return;
		}
		//Rec Case
		if(a[i]=='p'&&a[i+1]=='i'){

				int j = i + 2;
				while(a[j]!='\0'){
					j++;
				}
				//Shift 
				while(j>=i+2){
					a[j+2] = a[j];
					j--;
				}
				a[i] = '3';
				a[i+1] = '.';
				a[i+2] = '1';
				a[i+3] = '4';
				return replacePi(a,i+4);
		}
		else{
			return replacePi(a,i+1);
		}

}

int main(){

	char a[100] = "abcpiyhpiphpi";
	cout<<a<<endl;
	replacePi(a);
	cout<<a<<endl;


}
