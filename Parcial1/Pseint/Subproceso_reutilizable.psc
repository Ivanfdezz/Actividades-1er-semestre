Algoritmo Subproceso_reutilizable
	
	definir par1_1, par2_1, par3_1 Como Real
	Definir  par1_2, par2_2, par3_2 Como Real
	Definir nombre1, nombre2 Como Caracter
	Definir promedio1, promedio2 Como Real
	
	Escribir "Escriba el nombre el alumno:"
	Leer nombre1
	Escribir "Escriba las calificaciones de ", nombre1
	Leer par1_1
	Leer par2_1
	Leer par3_1
	promedio1 <- CalcularPromedio (par1_1, par2_1, par3_1)
	
	Escribir "Escriba el nombre del alumno:"
	Leer nombre2 
	Escribir "Escriba las calificaciones de ", nombre2
	Leer par1_2
	Leer par2_2
	Leer par3_2
	promedio2 <- CalcularPromedio (par1_2, par2_2, par3_2)
	Escribir "La calificación de ", nombre1, " es ", promedio1
	Escribir "La calificación de ", nombre2, " es ", promedio2
	
FinAlgoritmo
subproceso resultado <- CalcularPromedio (par1, par2, par3)
	resultado <- (par1 + par2 + par3) / 3
FinSubProceso
