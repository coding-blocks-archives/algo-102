#include<iostream>
using namespace std;

void generateMatrix(int a[][100],int R,int C){

	int val=1;
	for(int i=0;i<R;i++){
		for(int j=0;j<C;j++){
			a[i][j] = val;
			val++;
			cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}

}

void spiralPrint(int a[][100],int R,int C){

	int sr = 0,sc = 0,er = R-1,ec = C-1;

	while(sr<=er  && sc <=ec){
		//Print the start row
		for(int i=sc;i<=ec;i++){
			cout<<a[sr][i]<<" ";
		}
		sr++;

		//Print the endcol
		for(int i=sr;i<=er;i++){
			cout<<a[i][ec]<<" ";
		}
		ec--;

		//Bottom row
		if(er>sr){
		for(int i=ec;i>=sc;i--){
			cout<<a[er][i]<<" ";
			}
			er--;
		}

		//Start Col
		if(sc<ec){
		for(int i=er;i>=sr;i--){
			cout<<a[i][sc]<<" ";
			}
			sc++;
		}
	}

}

int main(){

	int a[100][100];
	int R,C;
	cin>>R>>C;
	generateMatrix(a,R,C);
	cout<<endl;
	spiralPrint(a,R,C);

return 0;
}