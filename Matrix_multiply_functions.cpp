#include <stdio>
void EnterData(int A[][10], int B[][10], int r1, int c1, int r2, int c2)
{
	int i, j;
	printf("\nEnter elements of matrix 1:\n");
	for(i = 0; i < r1; ++i)
	{
		for(j = 0; j < c1; ++j)
		{
			cin >> A[i][j];
		}
	}
	printf("\nEnter elements of matrix 2:\n");
	for(i = 0; i < r2; ++i)
	{
		for(j = 0; j < c2; ++j)
		{
			cin >> B[i][j];
		}
	}
}
void MultiplyMatrices(int A[][10], int B[][10], int C[][10], int r1, int c1, int r2, int c2)
{
	int i, j, k;
	for(i = 0; i < r1; ++i)
	{
		for(j = 0; j < c2; ++j)
		{
			C[i][j] = 0;
			for(k=0; k<c1; ++k)
			{
				C[i][j] += A[i][k] * B[k][j];
			}
		}
	}
}
void Display(int C[][10], int r1, int c2)
{
	int i, j;
	printf("\nMultiplication Matrix:\n");
	for(i = 0; i < r1; ++i)
	{
		for(j = 0; j < c2; ++j)
		{
			printf("%d ",C[i][j]);
		}
		printf("\n");
	}
}

int main()
{
	int A[10][10], B[10][10], C[10][10], r1, c1, r2, c2, i, j, k;
	printf("Enter rows and column for first matrix: ");
	scanf("%d,%d",&r1,&c1);
	printf("Enter rows and column for second matrix: ");
	scanf("%d,%d",&r2,&c2);
	while (c1 != r2)
	{
		printf("Matrices canot be multiplied!\n");
		printf("Enter rows and column for first matrix: ");
	    scanf("%d,%d",&r1,&c1);
	    printf("Enter rows and column for second matrix: ");
	    scanf("%d,%d",&r2,&c2);
	}
        EnterData(A, B, r1, c1, r2, c2);
        MultiplyMatrices(A, B, C, r1, c1, r2, c2);
        Display(C, r1, c2);
	return 0;
}


