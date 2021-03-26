// C++ program for the above approach
#include <iostream>
#include <cstdlib>
#include <array>
#include <tuple>
#include <bits/stdc++.h>
using namespace std;

class Matrix{
public:

	int LinearIndx(int i,int j);

	int InverseIdx(int i, int n);

};

	int LinearIndx(int i, int j){
		int index = (i * (i - 1)) / 2 + j - 1;
		return index;
	}

	tuple<int, int> InverseIdx(int m, int n){
		int currentind=0;
			for(int i=0; i<n; i++){
				for(int j=0;j<n; j++){
					if(i >= j){
						currentind++;
						if(currentind==m){
							return make_tuple(i,j);
						}
				}
				}
			}
			return make_tuple(0,0);
	}

// Driver Code
int main()
{
	// Size of row or column
	// of square matrix
	int array[]={8,32,128};
	for(auto &N : array){
	int A[N][N];
	int total=N * (N + 1)/2;
	int B[total];
	int C[N][N];
	int i, j;
	int m=0;

	    for (i = 0; i < N; i++)
	    {
	        for (j = 0; j < N; j++)
	        {
	            if (i < j)
	            {
									A[i][j]=0;
	                //cout << "0" << " ";
	            }
	            else
							A[i][j]=rand()%1000;
	            //cout << A[i][j] << " ";
	        }
	        //cout << endl;
					//cout << endl;
	    }




			for (i = 1; i <= N; i++)
	    {
	        for (j = 1; j <= N; j++)
	        {
	            if (i >= j)
	            {

								B[LinearIndx(i,j)]=A[i][j];
	            	//cout << B[LinearIndx(i,j)] << " ";
	        }

	    }
}
			for(int m = 0; m<=total; m++){
				tie(i, j) = InverseIdx(m,N);
				C[i][j]=B[m];
				//cout<< C[i][j]<<" ";
			}


			int D[20];
			int count=0;
					for(int i=0; i<N;i++){
						for(int j=0; j<N;j++){
							D[LinearIndx(i,j)]=A[i][j];
							cout<<D[LinearIndx(i,j)]<<" ";
							cout<<"["<<i<<","<<j<<"]"<<endl;
							if((sizeof(D)/sizeof(D[0]))==20){
								break;
							}
						}

					}

			}
			return 0;
			}
