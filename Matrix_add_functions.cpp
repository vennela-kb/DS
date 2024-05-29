#include<iostream> 
using namespace std; 
 
int add(int A[][10], int B[][10], int C[][10], int m, int n)  
{  

	int i, j;  
    for (i = 0; i < m; i++)  
    {
    	
	    for (j = 0; j < n; j++)  
            { C[i][j] = A[i][j] + B[i][j]; }
    }
}  
  
int main()  
{  
    int A[10][10], B[10][10],C[10][10]; 
    int i,j,m,n;
	 cout<<"Enter number of rows: ";
	 cin>>m;
	 cout<<"Enter number of columns: ";
	 cin>>n;
	 
	 cout<<"Enter elements of Matrix A:"<<endl;
	 for(i=0;i<m;i++)
	 {
	 	for(j=0;j<n;j++)
	 	{ cin>>A[i][j]; }
     }
	  
	 cout<<"Enter elements of Matrix B:"<<endl;
	 for(i=0;i<m;i++)
	 {
	 	for(j=0;j<n;j++)
	 	{ cin>>B[i][j]; }
     }
	 
	 add(A,B,C,m,n); 
    
    cout << "Result matrix is " << endl;  
    for (i = 0; i < m; i++)  
    {  
        for (j = 0; j < n; j++)  
          { cout << C[i][j] << " "; }
        cout << endl; 
    }  
  
    return 0;  
}  
  
