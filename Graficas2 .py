#!/usr/bin/env python
# coding: utf-8

# In[ ]:


import numpy as np
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D

lista_archivos = list(np.genfromtxt("ode.txt", dtype=str))
print(" Realizando graficas de los archivos \n", lista_archivos, "\n"*3)


ode1 = np.genfromtxt(lista_archivos[4])
x = ode1[:,0]
y = ode1[:,1]
vx = ode1[:,2]
vy = ode1[:,3]

plt.figure()
plt.plot(x,y)
plt.savefig("proyectil_a_45.png")

# Grafica de todas las trayectorias
plt.figure()
for archivo in lista_archivos:
	ode = np.genfromtxt(archivo)
	x = ode[:,0]
	y = ode[:,1]
	vx = ode[:,2]
	vy = ode[:,3]

	plt.plot(x, y, label=archivo[:-4])
plt.legend()
plt.savefig("proyectiles.png")




def arreglo_calcita(C, nt, n):
	# tomar una fila del arreglo y devolverla como una maitrz
	calcita = np.reshape(C[nt,:], (n,n))
	return calcita

ff = np.genfromtxt("pde_ff.txt")
fa = np.genfromtxt("pde_fa.txt")
fp = np.genfromtxt("pde_fp.txt")

nt = np.size(ff,0) # numero de pasos de tiempo
n = int(np.size(ff,1)**0.5) # numero de nodos

