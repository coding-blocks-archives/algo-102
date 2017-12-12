#include<iostream>
#include<cmath>
using namespace std;

bool isSafe(int mat[9][9],int i,int j,int no,int N){
	//Check for row and col
	for(int x=0;x<N;x++){
		if(mat[x][j]==no||mat[i][x]==no){
			return false;
		}
	}
	//Check for SubGrid
	int rn = sqrt(N);
	int sx = (i/rn)*rn;
	int sy = (j/rn)*rn;

	for(int x=sx;x<sx+rn;x++){
		for(int y=sy;y<sy+rn;y++){
			if(mat[x][y]==no){
				return false;
			}
		}
	}
	return true;

}

bool solveSudoku(int mat[9][9],int i,int j,int N){
	if(i==N){
		//Print the Matrix
		for(int i=0;i<N;i++){
			for(int j=0;j<N;j++){
				cout<<mat[i][j]<<" ";
			}
			cout<<endl;
		} 

		return true;
	}
	if(j==N){
		return solveSudoku(mat,i+1,0,N);
	}

	if(mat[i][j]!=0){
		//Skip the blue cell
		return solveSudoku(mat,i,j+1,N);
	}
	//Otherwise - Try all possible options at white cell
	for(int no=1;no<=N;no++){
		if(isSafe(mat,i,j,no,N)){
			mat[i][j] = no;

			bool solveHua = solveSudoku(mat,i,j+1,N);
			if(solveHua==true){
				return true;
			}


		}
	}
	//Finally 
	mat[i][j] = 0;
	return false;

}


int main(){	

		int mat[9][9] =
        {{5,3,0,0,7,0,0,0,0},
        {6,0,0,1,9,5,0,0,0},
        {0,9,8,0,0,0,0,6,0},
        {8,0,0,0,6,0,0,0,3},
        {4,0,0,8,0,3,0,0,1},
        {7,0,0,0,2,0,0,0,6},
        {0,6,0,0,0,0,2,8,0},
        {0,0,0,4,1,9,0,0,5},
        {0,0,0,0,8,0,0,7,9}};

        solveSudoku(mat,0,0,9);



        return 0;
}