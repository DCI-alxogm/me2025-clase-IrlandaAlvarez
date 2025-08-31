Algoritmo Ago_26_serie_Taylor
	Definir op, nmax, n, fact, factr, residuo Como Entero
	Definir x, h, x0, f, valorreal, xi, error Como Real
	n <- 0
	fact <- 1
	Escribir 'Escoge qué función quieres aproximar'
	Escribir '1. e^x, 2. sen(x), 3. cos(x), 4. arctan(x), 5. ln(1+x)'
	Leer op
	Escribir 'Ingresa el punto en el que deseas calcular el valor de tu función'
	Leer x
	Escribir 'Ingresa tu valor de h'
	Leer h
	x0 <- x-h
	xi <- (x+x0)/2
	Escribir 'Ingresa el número de aproximaciones que deseas'
	Leer nmax
	Según op Hacer
		1:
			valorreal <- exp(x) // e^x
			Mientras n<nmax Hacer
				Si n=0 Entonces
					f <- exp(x0)
					r <- exp(xi)*h
				SiNo
					f <- f+(exp(x0)*h^n)/factorial[n]
					r <- (exp(xi)*h^(n+1))/factorial[n+1]
				FinSi
				error <- valorreal-f
				Escribir f, r, error
				n <- n+1
			FinMientras
		2:
			valorreal <- sen(x) // sen(x)
			Mientras n<nmax Hacer
				residuo <- n MOD 4
				Según residuo Hacer
					0:
						Si n=0 Entonces
							f <- sen(x0)
							r <- cos(xi)*h
						SiNo
							f <- f+(sen(x0)*h^n)/factorial[n]
							r <- (cos(xi)*h^(n+1))/factorial[n+1]
						FinSi
					1:
						f <- f+(cos(x0)*h^n)/factorial[n]
						r <- (-sen(xi)*h^(n+1))/factorial[n+1]
					2:
						f <- f+(-sen(x0)*h^n)/factorial[n]
						r <- (-cos(xi)*h^(n+1))/factorial[n+1]
					3:
						f <- f+(-cos(x0)*h^n)/factorial[n]
						r <- (sen(xi)*h^(n+1))/factorial[n+1]
				FinSegún
				error <- valorreal-f
				Escribir f, r, error
				n <- n+1
			FinMientras
		3:
			valorreal <- cos(x) // cos(x)
			Mientras n<nmax Hacer
				residuo <- n MOD 4
				Según residuo Hacer
					0:
						Si n=0 Entonces
							f <- cos(x0)
							r <- -sen(xi)*h
						SiNo
							f <- f+(cos(x0)*h^n)/factorial[n]
							r <- (-sen(xi)*h^(n+1))/factorial[n+1]
						FinSi
					1:
						f <- f+(-sen(x0)*h^n)/factorial[n]
						r <- (-cos(xi)*h^(n+1))/factorial[n+1]
					2:
						f <- f+(-cos(x0)*h^n)/factorial[n]
						r <- (sen(xi)*h^(n+1))/factorial[n+1]
					3:
						f <- f+(sen(x0)*h^n)/factorial[n]
						r <- (cos(xi)*h^(n+1))/factorial[n+1]
				FinSegún
				error <- valorreal-f
				Escribir f, r, error
				n <- n+1
			FinMientras
		4:
			valorreal <- atan(x) // arctan(x)
			Mientras n<nmax Hacer
				Según n Hacer
					0:
						f <- atan(x0)
						r <- (1/(1+xi^2))*h
					1:
						f <- f+((1/(1+x0^2))*h)/factorial[1]
						r <- ((-2*xi)/(1+xi^2)^2)*(h^2)/factorial[2]
					2:
						f <- f+(((-2*x0)/(1+x0^2)^2)*h^2)/factorial[2]
						r <- ((6*xi^2-2)/(1+xi^2)^3)*(h^3)/factorial[3]
					3:
						f <- f+(((6*x0^2-2)/(1+x0^2)^3)*h^3)/factorial[3]
						r <- ((-24*xi^3+24*xi)/(1+xi^2)^4)*(h^4)/factorial[4]
				FinSegún
				error <- valorreal-f
				Escribir f, r, error
				n <- n+1
			FinMientras
		5:
			valorreal <- ln(1+x) // ln(1+x)
			Si x0<=-1 Entonces
				Escribir 'Función no definida'
			SiNo
				Mientras n<nmax Hacer
					Si n=0 Entonces
						f <- ln(1+x0)
						r <- (1/(1+xi))*h
					SiNo
						f <- f+(((-1)^(n+1))*(h^n))/(n)
						r <- (((-1)^(n+2))*(h^(n+1)))/(n+1)
					FinSi
					error <- valorreal-f
					Escribir f, r, error
					n <- n+1
				FinMientras
			FinSi
		De Otro Modo:
			Escribir 'Opción no válida'
	FinSegún
FinAlgoritmo

//Funcion factorial
Funcion f <- factorial(n)
    Definir f, i Como Entero
    f <- 1
    Para i <- 1 Hasta n Con Paso 1 Hacer
        f <- f * i
    FinPara
FinFuncion

