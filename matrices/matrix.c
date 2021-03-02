#include "matrix.h"

#include <stdio.h>
#include <math.h>

void init_zero_matrix(float matrix[3][3])
{
    int i;
    int j;

    for (i = 0; i < 3; ++i) {
        for (j = 0; j < 3; ++j) {
            matrix[i][j] = 0.0;
        }
    }
}

void print_matrix( float matrix[3][3])
{
    int i;
    int j;

    for (i = 0; i < 3; ++i) {
        for (j = 0; j < 3; ++j) {
            printf("%4.4f ", matrix[i][j]);
        }
        printf("\n");
    }
}
void print_vektor( float vektor[3])
{
    int j;
        for (j = 0; j < 3; ++j) 
		{
            printf("%f ", vektor[j]);
        }
        printf("\n");
}
void add_matrices(float result[3][3],float a[3][3],float b[3][3])
{
    int i;
    int j;
    for (i = 0; i < 3; ++i) 
	{
        for (j = 0; j < 3; ++j) 
		{
            result[i][j] = a[i][j] + b[i][j];
        }
    }
}
void init_identity_matrix(float matrix[3][3])
{
    int i;
    int j;

    for (i = 0; i < 3; ++i) 
	{
        for (j = 0; j < 3; ++j)
		{
			if(i ==j)
			{
				 matrix[i][j] = 1.0;
			}else
			{
				matrix[i][j] = 0.0;
			}
        }
    }
}
void multiply_matrix_with_skalar(float result[3][3],float matrix[3][3], float skalar)
{
	int i;
    int j;
	    for (i = 0; i < 3; ++i)
		{
			for (j = 0; j < 3; ++j)
			{
				result[i][j] =matrix[i][j] *skalar;
			}
		}
}
void multiply_matrices(float result[3][3],float matrix_a[3][3],float matrix_b[3][3]){
	int i;
	int sum=0;
	int x=0;
	int y=0;
	for(i=0;i<3;i++)
	{
		int n=0;
		int j=0;
		while(n<3)
		{
			sum=sum+(matrix_a[i][j]*matrix_b[j][n]);
			if(j==2)
			{
				result[x][y]=sum;
				if(y==2)
				{
					x++;
					y=0;
				}else
				{
					y++;
				}
				n++;
				sum=0;
				j=-1;
			}
			j++;
		}
	}
}
void transform_point(float result[3],float matrix[3][3],float point[3]){
	int i;
	int j;
	int sum=0;
	for(i=0;i<3;i++)
	{
			for(j=0;j<3;j++)
			{
				sum=sum+(matrix[i][j]*point[j]);
			}
			result[i]=sum;
			sum=0;
	}
}
void shift(float result[3][3],float matrix[3][3])
{
		float transform[3][3] = {
        { 1.0f, 0.0f,  3.0f},
        { 0.0f, 1.0f,  2.0f},
        {0.0f,  0.0f, 1.0f}
    };
	int i;
	int sum=0;
	int x=0;
	int y=0;
	for(i=0;i<3;i++)
	{
		int n=0;
		int j=0;
		while(n<3)
		{
			sum=sum+(matrix[i][j]*transform[j][n]);
			if(j==2)
			{
				result[x][y]=sum;
				if(y==2)
				{
					x++;
					y=0;
				}else
				{
					y++;
				}
				n++;
				sum=0;
				j=-1;
			}
			j++;
		}
	}
}
void rotate(float result[3][3],float matrix[3][3])
{
		float transform[3][3] = {
		{cos(M_PI/6), -sin(M_PI/6),  0.0f},
        { sin(M_PI/6), cos(M_PI/6),  0.0f},
        {0.0f,  0.0f, 1.0f}
    };
	int i;
	int sum=0;
	int x=0;
	int y=0;
	for(i=0;i<3;i++)
	{
		int n=0;
		int j=0;
		while(n<3)
		{
			sum=sum+(matrix[i][j]*transform[j][n]);
			if(j==2)
			{
				result[x][y]=sum;
				if(y==2)
				{
					x++;
					y=0;
				}else
				{
					y++;
				}
				n++;
				sum=0;
				j=-1;
			}
			j++;
		}
	}
}
void scale (float result[3][3],float matrix[3][3])
{
		float transform[3][3] = {
        { 3.0f, 0.0f,  0.0f},
        { 0.0f, 5.0f,  0.0f},
        {0.0f,  0.0f, 1.0f}
    };
	int i;
	int sum=0;
	int x=0;
	int y=0;
	for(i=0;i<3;i++)
	{
		int n=0;
		int j=0;
		while(n<3)
		{
			sum=sum+(matrix[i][j]*transform[j][n]);
			if(j==2)
			{
				result[x][y]=sum;
				if(y==2)
				{
					x++;
					y=0;
				}else
				{
					y++;
				}
				n++;
				sum=0;
				j=-1;
			}
			j++;
		}
	}
}
