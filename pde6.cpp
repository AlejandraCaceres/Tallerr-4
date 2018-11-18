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

				if (i==0 || j==0 || i==n-1 || j==n-1)
				{ // asignar temperatura fija en los bordes
					Calcita_ff[k][i][j] = 10.0;
					Calcita_fa[k][i][j] = 10.0;
					Calcita_fp[k][i][j] = 10.0;
				}
			}
		}
		
	}


	float v=1.62/(820.0*2710.0); // v=k/(Cp*p) [SI]
	float difx=(50.0/n)/100; // diferencial de x [m]
	float dift=0.05*difx*difx/v; // diferencial de tiempo
	float t_final = 3600*24; // tiempo final
	int nt = t_final/dift; // pasos de tiempo
	
	cout << "\nCalculando " << nt << " pasos de tiempo para problema de difusion de calor en Calcita\n\n";
	cout << "\n" << v*dift/(difx*difx) << "\n";

	k = 0;
	nt=100;
	for (ti = 0; ti < nt; ++ti) // recorrido en el tiempo
	{ 
		for (i = 0; i < n; ++i) // recorridos en el espacio
		{
			for (j = 0; j < n; ++j)
			{ // asignar temperatura de calcita o varilla dependiendo de la posicion del nodo
				if (i!=0 && i!=n-1 && j!=0 && j!=n-1) // nodos fuera de los bordes
				{
					if (Calcita_ff[k][i][j] != t_varilla)
					{// es un nodo de calcita

						// sumar el termino del pasado
						Calcita_ff[k+1][i][j] = Calcita_ff[k][i][j]*(1.0-4.0*v*dift/(difx*difx)); 

						// sumar el termino de los vecinos en el pasado
						Calcita_ff[k+1][i][j] = Calcita_ff[k+1][i][j] + (v*dift/(difx*difx)) * ( Calcita_ff[k][i+1][j] + Calcita_ff[k][i-1][j] + Calcita_ff[k][i][j+1] + Calcita_ff[k][i][j-1]);


						// sumar el termino del pasado
						Calcita_fa[k+1][i][j] = Calcita_fa[k][i][j]*(1.0-4.0*v*dift/(difx*difx)); 

						// sumar el termino de los vecinos en el pasado
						Calcita_fa[k+1][i][j] = Calcita_fa[k+1][i][j] + (v*dift/(difx*difx)) * ( Calcita_fa[k][i+1][j] + Calcita_fa[k][i-1][j] + Calcita_fa[k][i][j+1] + Calcita_fa[k][i][j-1]);


						// sumar el termino del pasado
						Calcita_fp[k+1][i][j] = Calcita_fp[k][i][j]*(1.0-4.0*v*dift/(difx*difx)); 

						// sumar el termino de los vecinos en el pasado
						Calcita_fp[k+1][i][j] = Calcita_fp[k+1][i][j] + (v*dift/(difx*difx)) * ( Calcita_fp[k][i+1][j] + Calcita_fp[k][i-1][j] + Calcita_fp[k][i][j+1] + Calcita_fp[k][i][j-1]);

					}
				}

				// condiciones de frontera
				if (i==0) // nodos de arriba
				{
					Calcita_ff[k+1][i][j] = 10.0;

					Calcita_fa[k+1][i][j] = Calcita
