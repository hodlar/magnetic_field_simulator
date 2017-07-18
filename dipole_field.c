#include <stdio.h>
#include <math.h>

#define HALF_PI 3.1416
#define THETA_STEP .3
#define R_STEP .2
#define R_MAX 2

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

void polar_to_cartesian(double theta, double r, double *xptr, double *yptr)
{
	double x, y;
	x = r * pow(sin(theta),2) * cos(theta);
	y = r * pow(sin(theta),3);
	*xptr = x;
	*yptr = y;
}

int main()
{
	double theta, r, x, y, r1, Br, Bt, Bx, By, B, orientation, m, field_limit;
	m = 1;
	//Calculate magnetic dipole field lines
	for(r1 = R_STEP; r1 < R_MAX; r1 += R_STEP)
	{
		printf("R = %f\n",r1);
		for(theta = 0; theta <= HALF_PI; theta += THETA_STEP)
		{
			r = r1 * pow( sin(theta), 2);
			polar_to_cartesian(theta,r1,&x,&y);
			//printf("lineas de campo\n");
			//printf("theta = %f\nr = %f\nX = %f\nY = %f\n\n",theta,r,x,y);
		}

		//Calculate magnetic field vectors
		for(field_limit = THETA_STEP; r1*sin(field_limit) < .7 && field_limit < HALF_PI; field_limit += THETA_STEP){}
		for(theta = field_limit; theta < HALF_PI - field_limit; theta+= THETA_STEP)
		{
			Br = (2 * m * cos(theta)) / pow(r1,3);
			Bt = (m * sin(theta)) / pow(r1,3);
			Bx = Br * cos(theta) - Bt * sin(theta);
			By = Br * sin(theta) + Bt * cos(theta);
			B = sqrt(pow(Bx,2) + pow(By,2));
			orientation = atan2(By,Bx);
			//printf("theta = %f Br = %f Bt = %f      ",theta,Br,Bt);
			//printf("theta = %f   Bx = %f   By = %f \n",theta,Bx,By);
			printf("B = %f    orientation = %f \n",B,orientation);
		}
		printf("\n");
	}
	

	return 0;
}
