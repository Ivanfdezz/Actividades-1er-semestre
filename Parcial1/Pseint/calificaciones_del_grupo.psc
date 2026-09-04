Algoritmo calificaciones_del_grupo
	
	Definir respuesta Como caracter
	Definir par1, par2, par3 Como Real
	Definir total_de_alumnos Como Entero
	Definir todos_los_promedios Como Real
	Definir prom_por_alumno Como Real
	Definir prom_grupo Como Real
	
	total_de_alumnos = 0
	todos_los_promedios = 0
	Escribir "Ingrese las calificaciones de los alumnos. Escriba listo cuando termine"
	Escribir "Escriba su nombre"
	leer respuesta
	Mientras respuesta <> "listo" Hacer
		
	Escribir "Escriba las calificaciones de sus tres parciales:"
	Leer par1 
	Leer par2
	Leer par3
	prom_por_alumno = (par1 + par2 + par3) / 3
	
	Escribir "El promedio del alumno es:", prom_por_alumno
	
	todos_los_promedios = todos_los_promedios + prom_por_alumno
	total_de_alumnos = total_de_alumnos + 1
	
	Escribir "Para finalizar escriba listo"
	leer respuesta
	
FinMientras

si total_de_alumnos > 0 Entonces
	prom_grupo = todos_los_promedios / total_de_alumnos
	Escribir "El promedio del grupo es:", prom_grupo
SiNo
	Escribir "No se han ingresado datos de alumnos"
FinSi
	
FinAlgoritmo
