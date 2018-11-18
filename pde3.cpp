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


	// A partir de las coordenadas polares asignar valores de temperatura
	// a la varilla y a la calcita
	float t_calcita = 0.0;
	float t_varilla = 100.0;

	float Calcita_ff[2][n][n]; // el presente se guarda en [0][][] y el futuro en [1][][]
	float Calcita_fa[2][n][n]; // el presente se guarda en [0][][] y el futuro en [1][][]
	float Calcita_fp[2][n][n]; // el presente se guarda en [0][][] y el futuro en [1][][]

	for (k = 0; k < 2; ++k)
	{ // recorrer las dos posiciones de presente y futuro en calcita
		for (i = 0; i < n; ++i)
		{
			for (j = 0; j < n; ++j)
			{ // asignar temperatura de calcita o varilla dependiendo de la posicion del nodo
				if (coordenadas_polares[i][j]>5.0)
				{
					Calcita_ff[k][i][j] = t_calcita;
				}else if (coordenadas_polares[i][j]<=5.0)
				{
					Calcita_ff[k][i][j] = t_varilla;
					Calcita_fa[k][i][j] = t_varilla;
					Calcita_fp[k][i][j] = t_varilla;
				}

			}
		}
	}
	
