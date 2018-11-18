#include <stdio.h>
#include <math.h>
#include "iostream"
#include "fstream"
using namespace std;


// declarar variables
float c=0.2;
float g=10.0;
float m=0.2;
float tiempo_total=3.0;
int n_tiempo=5000;
float instante_t=tiempo_total/(n_tiempo-1);


void leapfrog_ode(float beta, float velocidad_inicial, char *nombre_archivo)
{
	// crear vectores
	float x[n_tiempo];
	float y[n_tiempo];
	float xdot;
	float ydot;
	float vx[n_tiempo];
	float vy[n_tiempo];
	float vxdot;
	float vydot;

	ofstream archivo_salida(nombre_archivo);

	// valores iniciales
	x[0] = 0.0;
	vx[0] = velocidad_inicial*cos(beta);
	y[0] = 0.0;
	vy[0] = velocidad_inicial*sin(beta);

	// Avanzar las velocidades medio instante de tiempo
	vxdot = -vx[0]*c/m*( vx[0]*vx[0] + vy[0]*vy[0] ) /sqrt(vx[0]*vx[0] + vy[0]*vy[0]);
	vydot = -g -vy[0]*c/m*( vx[0]*vx[0] + vy[0]*vy[0] ) /sqrt(vx[0]*vx[0] + vy[0]*vy[0]);
	vx[0] = vx[0] + 0.5*instante_t*vxdot;
	vy[0] = vy[0] + 0.5*instante_t*vydot;

	int i;
	for (i = 0; i < n_tiempo-1; ++i)
	{
		// En la posicion i de los arreglos estan las coordenadas
		// x,y en el instante i y las velocidades vx,vy en el instante
		// i+1/2

		// avanzar las posiciones
		xdot = vx[i];
		ydot = vy[i];
		x[i+1] = x[i] + instante_t*xdot;
		y[i+1] = y[i] + instante_t*ydot;


		// avanzar las velocidades
		vxdot = -vx[i]*c/m*( vx[i]*vx[i] + vy[i]*vy[i] ) /sqrt(vx[i]*vx[i] + vy[i]*vy[i]);
		vydot = -g -vy[i]*c/m*( vx[i]*vx[i] + vy[i]*vy[i] ) /sqrt(vx[i]*vx[i] + vy[i]*vy[i]);
		vx[i+1] = vx[i] + instante_t*vxdot;
		vy[i+1] = vy[i] + instante_t*vydot;

		if (y[i]>=0.0)
		{
			// imprimir datos
			archivo_salida << x[i] << " " << y[i] << " " << vx[i] << " " << vy[i] << "\n";
		}
		
	}

}


int main()
{
	
	
	float Betas[1];
	Betas[0] = (2*3.14159)*(45.0);

