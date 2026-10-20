# AC2 · Mi primera aplicación en C

**Estudiante:** Valery Shanay Mora Acevedo  
**Fecha:** 20/10/2026  
**Módulo:** CSTI12010 Diseño de algoritmos · UA2

## Problema 1 · Nómina (AC2_P1_Nomina.c)

| Datos de entrada | Proceso | Datos de salida | Limitaciones |
|------------------|---------|-----------------|--------------|
| Nombre completo del empleado (cadena con espacios, ej: Maria Lopez) Salario bruto (flotante > 0, ej: 1000) | 1.Validar que el nombre no esté vacío usando fgets y strlen. 2. Validar que el salario sea mayor a 0 con do-while. 3. Calcular descuentos: CAJA (9.5%), IESS (2.5%) y Renta (10% si bruto > 800). 4. Calcular salario neto restando los descuentos al bruto. | 1.Nombre del empleado. 2.Salario bruto. 3.Descuento CAJA. 4.Descuento IESS. 5.Impuesto sobre la renta. 6.Salario neto (con 2 decimales y montos alineados)  | 1.El salario bruto debe ingresarse estrictamente en formato numérico. 2.Nombres sin tildes ni ñ por restricciones de consola (printf). |

**Ejecución con los datos del ejemplo:**

![Ejecución](/UA2/AC-2/P1_Nomina/evidencia_Nomina.png)

## Problema 2 · Calificaciones (AC2_P2_Calificaciones.c)

| Datos de entrada | Proceso | Datos de salida | Limitaciones |
|------------------|---------|-----------------|--------------|
|1.Nombre completo del estudiante (ej: Juan Perez) 2.Tres calificaciones numéricas entre 0 y 100 (ej: 75, 82, 68) | 1. Recibir nombre validando que no esté vacío.2. Almacenar las 3 notas en un arreglo float notas[3] usando un bucle for y validando cada valor con do-while.3. Recorrer el arreglo para calcular la suma, el promedio y hallar la nota más alta4. Asignar condición (APROBADO, EN RIESGO, NO APROBADO) usando strcpy. |Nombre del estudiante. 2.Detalle de las 3 calificaciones. 3.Promedio (2 decimales). 4.Nota más alta. 5.Condición académica  |1.Solo procesa exactamente tres calificaciones. 2.Rango de notas limitado de 0 a 100.|

**Ejecución con los datos del ejemplo:**

![Ejecución](/UA2/AC-2/P2_Calificaciones/evidencia-P2-Calificaciones.png)

## Problema 3 · Compras (AC2_P3_Compras.c)

| Datos de entrada | Proceso | Datos de salida | Limitaciones |
|------------------|---------|-----------------|--------------|
|  |  |  |  |

**Ejecución con los datos del ejemplo:**

![Ejecución](/UA2/AC-2/P3)

## Conclusión

(Qué aprendí y qué fue lo más difícil de pasar de PSeInt a C.)
