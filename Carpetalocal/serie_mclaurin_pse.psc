Algoritmo serie_mclaurin
	// La variable ea se iguala a 50 para darle un valor grande y asegurar que el ciclo entre la primera vez
	Definir x, ea, ess, valact, valtant, termino, valorReal Como Real
	Definir n, i Como Entero
	ea <- 50
	Escribir 'Por favor ingrese el valor de x: '
	Leer x
	Escribir 'Ingrese el porcentaje de error deseado: '
	Leer ess
	// Si aun existen valores posibles de error se sigue preguntando por n
	Mientras ea>ess Hacer
		Escribir 'Ingrese el numero de terminos a usar: '
		Leer n
		valact <- 1
		termino <- 1
		Para i<-1 Hasta n Con Paso 1 Hacer
			// La función ^ calcula potencias, primero va la base y luego el exponente
			// La función Factorial(i) devuelve i! (factorial)
			termino <- (x^i)/Factorial[i]
			// Esto actualiza la aproximación
			valact <- valact+termino
		FinPara
		// La función Abs, es absoluto, solo dara errores positivos
		valorReal <- Exp(x)
		ea <- Abs((valorReal-valact)/valorReal)*100
		Escribir 'Con n=', n, ' aproximacion=', valact, ' error=', ea
		Si ea<=ess Entonces
			Escribir 'El numero de terminos es correcto para el error deseado'
		SiNo
			Escribir 'Aun no se alcanza el error, intenta con mas terminos'
		FinSi
	FinMientras
FinAlgoritmo
// Ya que no existe una función para el factorial, tuve que crear esta para que pudiera ejecutarla y esta parte la tengo que quitar al momento de hacer el diagrama
// porque no me deja realizarlo ya que no acepta funciones fuera del proceso
Funcion f=Factorial(num)
	Definir f, j Como Entero
	f=1
	Para j=1 Hasta num Con Paso 1 Hacer
		f= f * j
	FinPara
FinFuncion
