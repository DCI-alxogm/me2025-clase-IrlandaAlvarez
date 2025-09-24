import numpy as np 
f1 = lambda x: np.sin(10*x) - np.cos(3*x)
f2 = lambda x: np.exp(-x) - x
f3 = lambda x: x**10 - 1
f4 = lambda x: x**3 - 5*(x**2) - 7*x - 3

import scipy as sp
#Bisección
r1 = sp.optimize.root_scalar(f1, method='bisect', bracket=[3,5])

#Newton
r2_1 = sp.optimize.root_scalar(f2, method='newton', x0=0)
r2_2 = sp.optimize.root_scalar(f2, method='newton', x0=0.5)
r2_3 = sp.optimize.root_scalar(f3, method='newton', x0=0)
r2_4 = sp.optimize.root_scalar(f3, method='newton', x0=4)
#Secante 
r3_1 = sp.optimize.root_scalar(f2, method='secant', x0=0)  
r3_2 = sp.optimize.root_scalar(f2, method='secant', x0=0.5) 
r3_3 = sp.optimize.root_scalar(f3, method='secant', x0=0)  
r3_4 = sp.optimize.root_scalar(f3, method='secant', x0=4)  

# Imprimir todos los resultados
print(f"r1 (f1, bisección [3,5]): Raíz = {r1.root:.6f}, Iteraciones = {r1.iterations}, Convergió = {r1.converged}")
print(f"r2_1 (f2, Newton x0=0): Raíz = {r2_1.root:.6f}, Iteraciones = {r2_1.iterations}, Convergió = {r2_1.converged}")
print(f"r2_2 (f2, Newton x0=0.5): Raíz = {r2_2.root:.6f}, Iteraciones = {r2_2.iterations}, Convergió = {r2_2.converged}")
print(f"r2_3 (f3, Newton x0=0): Raíz = {r2_3.root:.6f}, Iteraciones = {r2_3.iterations}, Convergió = {r2_3.converged}")
print(f"r2_4 (f3, Newton x0=4): Raíz = {r2_4.root:.6f}, Iteraciones = {r2_4.iterations}, Convergió = {r2_4.converged}")
print(f"r3_1 (f2, simula secante x0=0): Raíz = {r3_1.root:.6f}, Iteraciones = {r3_1.iterations}, Convergió = {r3_1.converged}")
print(f"r3_2 (f2, simula secante x0=0.5): Raíz = {r3_2.root:.6f}, Iteraciones = {r3_2.iterations}, Convergió = {r3_2.converged}")
print(f"r3_3 (f3, simula secante x0=0): Raíz = {r3_3.root:.6f}, Iteraciones = {r3_3.iterations}, Convergió = {r3_3.converged}")
print(f"r3_4 (f3, simula secante x0=4): Raíz = {r3_4.root:.6f}, Iteraciones = {r3_4.iterations}, Convergió = {r3_4.converged}")

