Algoritmo par_impar
	Definir numero Como Entero
	Definir cont Como Cadena
	Repetir
		Escribir 'Coloca un número entero: '
		Leer numero
		Si numero MOD 2=0 Entonces
			Escribir 'El número ', numero, ' es par'
		SiNo
			Escribir 'El número ', numero, ' es impar'
		FinSi
		Escribir '¿Quieres ingresar otro número? (S=si / N=no): '
		Leer cont
	Hasta Que cont<>'S' Y cont<>'s'
	Escribir 'Programa finalizado.'
FinAlgoritmo
