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
x = np.linspace(-25.0, 25.0, n)
y = np.linspace(-25.0, 25.0, n)
x,y = np.meshgrid(x,y)

I = np.array( [ 0, 35.0/100.0*nt, 70.0/100.0*nt ,-1 ] ).astype(int)

fig_ff = plt.figure(figsize=(10,10))
fig_fa = plt.figure(figsize=(10,10))
fig_fp = plt.figure(figsize=(10,10))

for i in range(len(I)):
	ii = I[i] # instante a graficar

	ax_ff = fig_ff.add_subplot(2,2,i+1, projection='3d')
	ax_fa = fig_fa.add_subplot(2,2,i+1, projection='3d')
	ax_fp = fig_fp.add_subplot(2,2,i+1, projection='3d')

	ax_ff.plot_surface(x,y,arreglo_calcita(ff, ii, n))
	ax_fa.plot_surface(x,y,arreglo_calcita(fa, ii, n))
	ax_fp.plot_surface(x,y,arreglo_calcita(fp, ii, n))


	ax_ff.set_title("Indice de tiempo " + str(ii))
	ax_fa.set_title("Indice de tiempo " + str(ii))
	ax_fp.set_title("Indice de tiempo " + str(ii))


	ax_ff.set_zlim([0,100])
	ax_fa.set_zlim([0,100])
	ax_fp.set_zlim([0,100])

fig_ff.savefig('ff.png')
fig_fa.savefig('fa.png')
fig_fp.savefig('fp.png')

