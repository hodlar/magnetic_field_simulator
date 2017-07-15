#include <stdio.h>
#include <math.h>

float calculate_magnetic_field(float m, float theta)
{
	float B;
	return B;
}

int main()
{

	float m, theta, r, Br, Bt, Bp, B;
	m = 1;
	printf("Ingresa theta ");
	scanf("%f",&theta);
	printf("Ingresa r ");
	scanf("%f",&r);
	Br = (m*sin(theta)) / pow(r,3);
	Bt = (2*m*cos(theta)) / pow(r,3);
	Bp = 0;
	B = sqrt( pow(Br,2) + pow(Bt,2) + pow(Bp,2) );
	printf("Br = %f\n Bt = %f\n Bp = %f\n B = %f",Br,Bt,Bp,B);
	return 0;
}
