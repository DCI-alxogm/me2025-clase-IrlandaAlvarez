Algoritmo Derivadas_Finitas_Usuario
	
	Definir fi,fi1,fi_1,e,atras,adelante,centrada,erroratras,erroradelante,errorcentrada Como Real
	Definir xi,xi_1,xi1 Como Real
	
	Escribir "Ingrese el valor de xi"
	Leer xi
	Escribir "Ingrese el valor de xi+1"
	Leer xi1
	Escribir "Ingrese el valor de xi-1"
	Leer xi_1
	Escribir "Ingrese el valor de la función de xi"
	Leer fi
	Escribir "Ingrese el valor de la función de xi+1"
	Leer fi1
	Escribir "Ingrese el valor de la función de xi-1"
	Leer fi_1
	Escribir "Ingrese el valor del error relativo"
	Leer e
	
	//Derivadas funcionales
	adelante=(fi1 - fi)/(xi1 -xi)
	atras=(fi -fi_1)/(xi1-xi_1)
	centrada=(fi1 - fi_1)/(xi1 - xi_1)
	
	//Errores
	erroradelante=(e-adelante)/e
	erroratras=(e-atras)/e
	errorcentrada=(e-centrada)/e
	
	//Resultados
	Escribir "Derivada aproximada hacia adelante ",adelante
	Escribir "Error hacia adelante ",erroradelante
	Escribir "Derivada aproximada hacia atrás ",atras
	Escribir "Error hacia atrás ",erroratras
	Escribir "Derivada aproximada centrada ",centrada
	Escribir "Error centrado",errorcentrada
	
	
FinAlgoritmo
