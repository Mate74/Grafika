#include "matrix.h"
#include "math.h"
int main(int argc, char* argv[])
{
	float a[3][3] = {
        { 1.0f, -2.0f,  3.0f},
        { 5.0f, -3.0f,  0.0f},
        {-2.0f,  1.0f, -4.0f}
    };
	float b[3][3];
	float c[3][3];
	float d[3][3];
	float e[3][3];
	float f[3][3];
	float g[3][3];
	float h[3][3];
	float i[3][3];
	float p[3];
	p[0]=4.0f;
	p[1]=7.0f;
	p[2]=-2.0f;
	float tp[3];
    init_zero_matrix(b);
    b[1][1] =  8.0f;
    b[2][0] = -3.0f;
    b[2][2] =  5.0f;
	printf("Matrix a:\n");
    print_matrix(a);
	printf("Matrix b:\n");
    print_matrix(b);
    printf("Matrixok osszege:\n");
    add_matrices(c, a, b);
    print_matrix(c);
	printf("Egyseg matrix:\n");
	init_identity_matrix(d);
	print_matrix(d);
	printf("Matrix szorzasa skalarral:\n");
	multiply_matrix_with_skalar(e,a, 1000.0);
	print_matrix(e);
	printf("Matrixok szorzatanak eredmenye:\n");
	 multiply_matrices(f,a,c);
	 print_matrix(f);
	 printf("Transzformalt pont:\n");
	 transform_point(tp,a,p);
	 print_vektor(tp);
	printf("Eltolas:\n");
	shift(g,a);
	print_matrix(g);
	printf("Elforgatas:\n");
	rotate(h,a);
	print_matrix(h);
	printf("Skalazas:\n");
	scale(i,a);
	print_matrix(i);
	return 0;
}

