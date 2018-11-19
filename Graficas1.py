#!/usr/bin/env python
# coding: utf-8

# In[ ]:


import numpy as np
import matplotlib.pyplot as plt

ode1 = np.genfromtxt("proyectil_a_45.txt")
x = ode1[:,0]
y = ode1[:,1]
vx = ode1[:,2]
vy = ode1[:,3]

plt.figure()
plt.plot(x)
plt.plot(y)
plt.savefig("proyectil_a_45.png")

