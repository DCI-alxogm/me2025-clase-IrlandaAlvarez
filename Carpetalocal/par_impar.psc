Algoritmo par_impar
	Definir numero Como Entero
	Definir cont Como Cadena
	Repetir
		Escribir 'Coloca un n�mero entero: '
		Leer numero
		Si numero MOD 2=0 Entonces
			Escribir 'El n�mero ', numero, ' es par'
		SiNo
			Escribir 'El n�mero ', numero, ' es impar'
		FinSi
		Escribir '�Quieres ingresar otro n�mero? (S=si / N=no): '
		Leer cont
	Hasta Que cont<>'S' Y cont<>'s'
	Escribir 'Programa finalizado.'
FinAlgoritmo
