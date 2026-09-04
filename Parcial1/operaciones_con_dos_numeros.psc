Algoritmo operaciones_con_dos_numeros
	Definir num1, num2 Como Entero
	Escribir "Escriba dos numeros por favor"
	Leer num1, num2
	si num1 = num2 Entonces
		operacion = num1 * num2
	SiNo
		si num1 > num2 Entonces
			operacion = num1 - num2
		SiNo
			operacion = num1 + num2
		FinSi
		
	FinSi
	
	Escribir "Su resultado final es:", operacion
FinAlgoritmo
