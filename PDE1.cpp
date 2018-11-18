#include <stdio.h>
#include <math.h>
#include "iostream"
#include "fstream"
using namespace std;



int main()
{
	// indices en los recorridos
	int i;
	int j;
	int k;
	int ti;
	float xij;
	float yij;

	int n=128; // numero de puntos

	// En cordenadas polares guardo la distancia desde el centro del dominio
	// hasta cada punto
	float coordenadas_polares[n][n];
	for (i = 0; i < n; ++i)
	{
		for (j = 0; j < n; ++j)
		{
			xij = 50.0*(float)(i-n/2)/n;
			yij = 50.0*(float)(j-n/2)/n;
			coordenadas_polares[i][j] = sqrt(xij*xij + yij*yij);
		}

	}


	
}
