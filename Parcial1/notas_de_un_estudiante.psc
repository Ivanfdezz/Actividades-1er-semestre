Algoritmo notas_de_un_estudiante
	Definir contador Como entero
	Definir calificaciones Como Entero
	Definir desaprobadas Como entero
	Definir aprobadas Como entero
	Definir calificacion_actual Como Real
	definir suma_total Como Real
	Definir suma_aprobadas Como Real
	Definir suma_desaprobadas Como Real
	definir promedio_general Como Real
	Definir promedio_aprobadas Como Real
	definir promedio_desaprobadas Como Real
	contador = 0
	aprobadas = 0
	desaprobadas = 0
	suma_total = 0
	suma_aprobadas = 0
	suma_desaprobadas = 0
	Escribir "¿Cuántas calificaciones desea ingresar?"
	Leer calificaciones
	Escribir "Escriba sus calificaciones"
	si calificaciones > 0 entonces
		Mientras contador < calificaciones Hacer
		leer calificacion_actual
		si calificacion_actual >= 6 Entonces
			aprobadas = aprobadas + 1
			suma_aprobadas = suma_aprobadas + calificacion_actual
			suma_total = suma_total + calificacion_actual
			
		SiNo
			desaprobadas = desaprobadas + 1
			suma_desaprobadas = suma_desaprobadas + calificacion_actual
			suma_total = suma_total + calificacion_actual
			
		FinSi
		contador = contador + 1
	Fin Mientras
	Si aprobadas > 0 Entonces
		promedio_aprobadas = suma_aprobadas / aprobadas
		Escribir "Su promedio de aprobadas es:", promedio_aprobadas
	SiNo
		Escribir "No se encontró ninguna calificación aprobada, échale ganitas."
		
	FinSi
	Si desaprobadas > 0 Entonces
		promedio_desaprobadas = suma_desaprobadas / desaprobadas
		Escribir "Su promedio de desaprobadas es:", promedio_desaprobadas
	SiNo
		Escribir "No se encontró ninguna calificación desaprobada, felicidades."
	FinSi
	promedio_general = suma_total / calificaciones
SiNo
	Escribir "No se ha ingresado ninguna calificación."
FinSi

	Escribir "El total de calificaciones aprobadas son:", aprobadas
	Escribir "El total de calificaciones desaprobadas son:", desaprobadas
	Escribir "Su promedio general es:", promedio_general
	
FinAlgoritmo
