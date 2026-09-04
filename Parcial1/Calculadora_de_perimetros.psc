Algoritmo Calculadora_de_perimetros
	Escribir 'Calculadora de perimetros'
	Definir eleccion Como Entero
	Definir medida Como real
	Definir Perimetro Como Real
	Definir radio Como Real
	Escribir 'Elija una de las siguientes'

	Escribir '1. Cuadrado'
	Escribir '2. Triangulo equilátero'
	Escribir '3. Círculo'
	Leer eleccion
	Segun eleccion Hacer
		1:
			Escribir "Indique la medida de un lado del cuadrado"
			Leer medida 
			Perimetro = medida * 4
			Escribir "Su perimetro es:", Perimetro
		2:
			Escribir "Indique la medida de un lado del triangulo"
			leer medida
			Perimetro = medida * 3
			Escribir "Su perimetro es:", Perimetro
		3:
			Escribir "Indique el radio de su circulo"
			Leer radio
			Perimetro = 2 * PI * radio
			Escribir "Su perimetro es:", Perimetro
		De Otro Modo:
			Escribir "Error: Opcion no valida, intente nuevamente."
	Fin Segun
	

FinAlgoritmo
