Algoritmo Derivadas_Finitas_Valores
	// x=0.5
	Definir f0, f05, f1, e, atras, adelante, centrada, erroratras, erroradelante, errorcentrada Como Real
	Definir xi, xi_1, xi1 Como Real
	// El xi_1 es el xi-1 y el xi1 es xi+1
	f0 <- 1.2
	f05 <- 0.925
	f1 <- 0.2
	e <- -0.925
	xi <- 0.5
	xi1 <- 1
	xi_1 <- 0
	// Derivadas funcionales
	adelante <- (f1-f05)/(xi1-xi)
	atras <- (f05-f0)/(xi1-xi_1)
	centrada <- (f1-f0)/(xi1-xi_1)
	// Errores
	erroradelante <- (e-adelante)/e
	erroratras <- (e-atras)/e
	errorcentrada <- (e-centrada)/e
	// Resultados
	Escribir 'Derivada aproximada hacia adelante ', adelante
	Escribir 'Error hacia adelante ', erroradelante
	Escribir 'Derivada aproximada hacia atrás ', atras
	Escribir 'Error hacia atrás ', erroratras
	Escribir 'Derivada aproximada centrada ', centrada
	Escribir 'Error centrado', errorcentrada
FinAlgoritmo
