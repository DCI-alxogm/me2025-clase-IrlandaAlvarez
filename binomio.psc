Algoritmo binomio
	Definir a, b, c, x1, x2, xi1, xi2, discr Como Real
	Definir opcion Como Cadena
	Repetir
		Escribir 'Ingrese a: '
		Leer a
		Escribir 'Ingrese b: '
		Leer b
		Escribir 'Ingrese c: '
		Leer c
		Si a=0 Entonces
			Si b<>0 Entonces
				x1 <- -c/b
				Escribir 'x1 = ', x1
			SiNo
				Escribir 'Solucion trivial'
			FinSi
		SiNo
			discr <- b*b-4*a*c
			Si discr>=0 Entonces
				x1 <- (-b+raiz(discr))/(2*a)
				x2 <- (-b-raiz(discr))/(2*a)
				Escribir 'x1 = ', x1
				Escribir 'x2 = ', x2
			SiNo
				x1 <- -b/(2*a)
				xi1 <- raiz(abs(discr))/(2*a)
				x2 <- x1
				xi2 <- -xi1
				Escribir 'x1 = ', x1, ' + ', xi1, 'i'
				Escribir 'x2 = ', x2, ' ', xi2, 'i'
			FinSi
		FinSi
		Escribir '¿Desea realizar otra operacion? (S/N): '
		Leer opcion
	Hasta Que opcion='N' O opcion='n'
FinAlgoritmo
