#include <stdio.h>
#include <math.h>

float calculate_magnetic_field(float m, float theta)
{
	float r, Br, Bt, Bp, B;
	m = 1;
	printf("Ingresa theta ");
	scanf("%f",&theta);
	printf("Ingresa r ");
	scanf("%f",&r);
	Br = (m*sin(theta)) / pow(r,3);
	Bt = (2*m*cos(theta)) / pow(r,3);
	Bp = 0;
	B = sqrt( pow(Br,2) + pow(Bt,2) + pow(Bp,2) );
	return B;
}

void polar_to_cartesian(float theta, float r, float *xptr, float *yptr)
{
	float x, y;
	x = r * pow(sin(theta),2) * cos(theta);
	y = r * pow(sin(theta),3);
	*xptr = x;
	*yptr = y;
}

int main()
{
	float theta, r, x, y, r1;
	r1 = .2;
	for(theta = 0; theta <= 6.28; theta += 1)
	{
		r = r1 * pow( sin(theta), 2);
		polar_to_cartesian(theta,r1,&x,&y);
		printf("theta = %f\nr = %f\nX = %f\nY = %f\n\n",theta,r,x,y);
	}
	return 0;
}
