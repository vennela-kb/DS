#include<iostream>
using namespace std;
int main()
{
	int i,j,a[4][4],order;
	float det=0;
	cout<<"Enter the order of matrix:";
	cin>>order;
	cout<<"Enter elements of matrix:\n";
	for(i=0;i<order;++i)
	 {
	 	for(j=0;j<order;++j)
	 	  {  cin>>a[i][j];  }
	 }
	cout<<"MATRIX:\n";
	for(i=0;i<order;++i)
	 {
	 	for(j=0;j<order;++j)
	 	  {  cout<<a[i][j]<<"  ";  }
	 	cout<<endl;
	 }
	for(i=0;i<order;++i)
	   {  det=det+(a[0][i]*(a[1][(i+1)%3]*a[2][(i+2)%3]-a[1][(i+2)%3]*a[2][(i+1)%3]));  }
	cout<<"Determinant of Matrix= "<<det<<endl;
	
	cout<<"INVERSE MATRIX:\n";
	for(i=0;i<order;++i)
	 {
	 	for(j=0;j<order;++j)
	 	{  cout<<((a[(j+1)%3][(i+1)%3]*a[(j+2)%3][(i+2)%3])-(a[(j+1)%3][(i+2)%3]*a[(j+2)%3][(i+1)%3]))/det<<"  ";  }
	 	cout<<endl;
	 }
}

