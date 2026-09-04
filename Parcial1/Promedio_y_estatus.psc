Algoritmo Promedio_y_estatus
	Definir cal1,cal2,cal3 Como Entero
	Escribir "Ingrese las calificaciones de sus tres parciales por favor."
	leer cal1,cal2,cal3
	sumasdepromedios = cal1+cal2+cal3
	promedio = sumasdepromedios/3
	si promedio >= 6 Entonces
		Escribir "Felicidades, has aprobado."
	SiNo
		Escribir "Lo siento, has reprobado"
		
			
		FinSi
	
	
FinAlgoritmo
