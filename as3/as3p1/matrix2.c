#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

/*FUNCTION=================================================================
*  Funtion Name : Matrix_Input
*  Description  : Input the element of matrix
==========================================================================*/
void matrixInput(int *p_arr, int row, int col)
{
	int row_index, col_index; // loop variable

	for (row_index = 0; row_index < row; row_index++)
	{
		for (col_index = 0; col_index < col; col_index++)
		{
			printf("a[%d][%d] =  ", row_index, col_index);
			scanf("%d", (p_arr + row_index * row + col_index));
		}
	}
}

/*FUNCTION=================================================================
*  Funtion Name : Matrix_Print
*  Description  : Print the matrix to the terminal
==========================================================================*/
void matrixPrint(int *p_arr, int row, int col)
{
	int row_index, col_index; // Loop variable

	for (row_index = 0; row_index < row; row_index++)
	{
		for (col_index = 0; col_index < col; col_index++)
		{
			printf("%d   ", *(p_arr + row_index * row + col_index));
		}
		printf("\n");
	}
}

/*FUNCTION================================================================
*  Funtion Name : Multiply
*  Description  : Calculate the Multiple of two matrices
=========================================================================*/
void Multiply(int *p_arrA, int *p_arrB, int row, int col, int general, int *p_arrmul)
{

	int row_index = 0; // loop variable to count row of matrix
	int col_index = 0; // loop variable to count colums of matrix
	int index = 0;	   // loop variable to count index of Multiply matrix

	for (row_index = 0; row_index < row; row_index++)
	{
		for (col_index = 0; col_index < col; col_index++)
		{
			// value of one element in Multi matrix
			int matrix_element = 0;

			for (index = 0; index < general; index++)
			{
				matrix_element += *(p_arrA + row_index * row + index) * *(p_arrB + index * row + col_index);
			}

			// element in row i col j of arr_M
			*(p_arrmul + row_index * row + col_index) = matrix_element;
		}
	}
}


/*FUNCTION===============================================================
*  Funtion Name : check_AB
*  Description  : check the multiplication condition of Matrix A and B
*  return true/false
========================================================================*/
bool check(int col, int row)
{
	if (col == row)
	{
		return 1;
	}

	else
	{
		return 0;
	}
}

/*======================================================================
*  Funtion Name : show_Output
*  Description  : check and show output of program
========================================================================*/
void Output(int *p_arrA, int *p_arrB, int rowA, int colA, int rowB, int colB)
{
	bool mul_AB, mul_BA;

	/*check each calculation condition*/
	mul_AB = check(colA, rowB);
	mul_BA = check(rowA, colB);

	int *p_arrmul = NULL; // Multiply of matrices

	/*printf the result of conditions*/

	if (mul_AB == 1)
	{
		printf("Matrix A and Matrix B can multi together \n");
	}
	else
	{
		printf("Matrix A and matriX B can not multi together \n");
	}

	if (mul_BA == 1)
	{
		printf("Matrix B and Matrix A can multi together \n");
	}
	else
	{
		printf("Matrix B and Matrix A can not multi together \n ");
	}

	/*Print the matrix A and matrix B*/
	printf("\n----- Matrix A : -----\n");
	matrixPrint(p_arrA, rowA, colA);

	printf("\n----- Matrix B -----\n");
	matrixPrint(p_arrB, rowB, colB);


	printf("\nMatrix A * Matrix B:\n");
	if (mul_AB == 1)
	{
		p_arrmul = (int *)malloc(rowA * colB * sizeof(int));
		Multiply(p_arrA, p_arrB, rowA, colB, colA, p_arrmul);
		matrixPrint(p_arrmul, rowA, colB);
		free(p_arrmul);
	}
	else
	{
		printf("N/A\n");
	}

	printf("\nMatrix B * Matrix A:\n");
	if (mul_BA == 1)
	{

		p_arrmul = (int *)malloc(rowB * colA * sizeof(int));
		Multiply(p_arrB, p_arrA, rowB, colA, colB, p_arrmul);
		matrixPrint(p_arrmul, rowB, colA);
		free(p_arrmul);
	}
	else
	{
		printf("N/A\n");
	}
}

int main()
{
	int *pArrA = NULL; // Matrix A
	int *pArrB = NULL; // Matrix B
	
	
	int rowA , colA ; // row and colums of matrix A
	int rowB , colB ; // row and colums of matrix B
	
	
	/*Matrix A -- Input row and col*/
	printf("-----Input the information of Matrix A-----\n");
	printf("Row of matrix A : ");
	scanf("%d",&rowA );
	printf("Col of matrix A : ");
	scanf("%d",&colA );
	
	/* dyamic allocation for matrix A */
	pArrA = (int*)malloc( rowA*colA*sizeof(int) );
	
	
	matrixInput(pArrA , rowA , colA );
	
	/*Matrix B -- Input row and col*/
	printf("-----Input the information of Matrix B-----\n");
	printf("Row of matrix B : ");
	scanf("%d",&rowB );
	printf("Col of matrix B : ");
	scanf("%d",&colB );
	
	/* dyamic allocation for matrix B */
	pArrB = (int*)malloc( rowB*colB*sizeof(int) );
	
	matrixInput(pArrB , rowB , colB );
	 
	Output(pArrA , pArrB, rowA, colA, rowB, colB);
	
	/* Free Matrix A and Matrix B */
	free( pArrA );
	free( pArrB );
	
	return 0;
}
