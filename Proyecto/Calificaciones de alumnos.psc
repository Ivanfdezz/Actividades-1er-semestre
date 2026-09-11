Algoritmo Registro_de_alumnos
	
		Definir alumno1, alumno2, alumno3 Como Caracter
		Definir par1_1, par2_1, par3_1 Como Real
		Definir par1_2, par2_2,par3_2 Como Real
		Definir par1_3, par2_3, par3_3 Como Real
		Definir prom1, prom2, prom3 como real
		Definir opcion Como entero
		Definir datos_capturados Como Logico
		
		datos_capturados <- Falso
	
		Escribir "Bienvenido al Menú"
		Escribir "Seleccione una opcion"
		Escribir "1. Adjuntar alumnos"
		Escribir "2. Mostrar Promedios"
		Escribir "3. Mostrar Promedio más alto"		
		Escribir "4. Salir"
		Leer opcion
		
		Si opcion = 4 Entonces
			Escribir "Hasta luego"
		FinSi
		
		mientras opcion <> 4 Hacer
			
			Segun opcion Hacer
				1:
					Escribir "Ingrese el nombre del alumno:"
					Leer alumno1
					Escribir "Ingrese sus calificaciones parciales:"
					Leer par1_1
					Leer par2_1
					Leer par3_1
					prom1 <- CalcularPromedio (par1_1, par2_1, par3_1)
					
					Escribir "Ingrese el nombre del alumno:"
					Leer alumno2
					Escribir "Ingrese sus calificaciones parciales:"
					Leer par1_2
					Leer par2_2
					Leer par3_2
					prom2 <- CalcularPromedio (par1_2, par2_2, par3_2)
					
					Escribir "Ingrese el nombre del alumno:"
					Leer alumno3
					Escribir "Ingrese sus calificaciones parciales:"
					Leer par1_3
					Leer par2_3
					Leer par3_3
					prom3 <- CalcularPromedio (par1_3, par2_3, par3_3)
					
					datos_capturados <- Verdadero
				2:
					si datos_capturados = Falso Entonces
						Escribir "Primero debe ingresar sus datos"
					SiNo
					Escribir "El promedio del alumno ", alumno1, " es: ", prom1
					Escribir "El promedio del alumno ", alumno2, " es: ", prom2
					Escribir "El promedio del alumno ", alumno3, " es: ", prom3
					FinSi
					
				3:
					si datos_capturados = Falso Entonces
						Escribir "Primero debe ingresar sus datos"
					SiNo

					si prom1 = prom2 y prom1 = prom3  Entonces
						Escribir "Los alumnos ", alumno1,"," alumno2 " y " alumno3 " obtuvieron el mismo promedio de ", prom1
					SiNo
						si prom1 = prom2 Entonces
							Escribir "Los alumnos ", alumno1 " y ", alumno2 " obtuvieron el mismo promedio de ", prom1
						SiNo
							si prom2 = prom3 Entonces
								Escribir "Los alumnos ", alumno2 " y ", alumno3 " obtuvieron el mismo promedio de ", prom2
							SiNo
								si prom1 = prom3 Entonces
									Escribir "Los alumnos ", alumno1 " y ", alumno3 " obtuvieron el mismo promedio de ", prom3
								SiNo									
					si prom1 >= prom2 y prom1>= prom3 Entonces
						Escribir "El promedio más alto es: ", prom1 " del ", alumno1
					SiNo
						si prom2 >= prom1 y prom2 >= prom3 Entonces
							Escribir "El promedio más alto es: ", prom2 " del ", alumno2
						SiNo
							si prom3 >= prom1 y prom3 >= prom2 Entonces
								Escribir "El promedio más alto es: ", prom3 " del ", alumno3
							FinSi
						FinSi
						
						
					FinSi
				FinSi
			FinSi
		FinSi
	FinSi
FinSi


				De Otro Modo:
					Escribir "Esta opción no es valida"
			Fin Segun
		
			Escribir "Bienvenido al Menú"
			Escribir "Seleccione una opcion"
			Escribir "1. Adjuntar alumnos"
			Escribir "2. Mostrar Promedios"
			Escribir "3. Mostrar Promedio más alto"		
			Escribir "4. Salir"
			Leer opcion
			Si opcion = 4 Entonces
				Escribir "Hasta luego"
			FinSi
		
	FinMientras
	

	
FinAlgoritmo

subproceso resultado <- CalcularPromedio (par1, par2, par3)
	resultado <- (par1 + par2 + par3) / 3
FinSubProceso
