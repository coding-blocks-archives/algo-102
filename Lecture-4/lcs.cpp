#include<iostream>
#include<cstring>ṭ
using namespace std;

//Convert into top-down DP
int lcs(char *s1,char *s2,int i,int j){
	if(i==0||j==0){
		return 0;
	}

	//Otherwise - Check for the last char !
	if(s1[i-1]==s2[j-1]){	
		return 1 + lcs(s1,s2,i-1,j-1);
	}

	else{
		
		
		 int op1 = lcs(s1,s2,i-1,j);
		 int op2 = lcs(s1,s2,i,j-1);
		 return max(op1,op2);
	}
	

}

int lcsBottomUp(char *s1,char *s2,int l1,int l2){

		int dp[100][100] = {0};

		for(int i=0;i<=l1;i++){
			for(int j=0;j<=l2;j++){
				if(i==0||j==0){
					dp[i][j] = 0;
				}
				else{
					if(s1[i-1]==s2[j-1]){
						dp[i][j] = 1 + dp[i-1][j-1];
					}
					else{
						dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
					}

				}

			}
			
		}
		return dp[l1][l2];ṭ


}

int main(){
	char s1[100] = "apple";
	char s2[100] = "apen";
	int i = strlen(s1);
	int j = strlen(s2);
	cout<<lcs(s1,s2,i,j);
	cout<<lcsBottomUp(s1,s2,i,j)<<endl;

	return 0;
}