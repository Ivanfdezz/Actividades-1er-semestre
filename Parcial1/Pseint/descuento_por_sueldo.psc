Algoritmo descuento_por_sueldo
	Definir sueldo Como Entero
	Escribir "Por favor ingrese su sueldo"
	leer sueldo
	si sueldo <= 1000 Entonces
		descuento = sueldo * 0.10
	SiNo
		si sueldo <= 2000
			descuento = 1000 * 0.10 + (sueldo - 1000) *0.05
		SiNo
			descuento = 1000 * 0.10 + 1000 * 0.5 + (sueldo - 2000) * 0.03
		FinSi
		
	FinSi
	
	sueldo_neto = sueldo - descuento
	Escribir "Su descuento es de:", descuento
	Escribir "Su sueldo es de:", sueldo_neto
FinAlgoritmo
