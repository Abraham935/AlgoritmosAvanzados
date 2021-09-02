//Abraham Mendoza Pérez A01274857 y Sebastián Andrés Rojas Salazar A01637557
El archivo acompañado contiene la solución al problema de otorgar el minimo número de monedas de cambio al recibir el precio de un producto y la cantidad
de dinero con que se va a pagar. De la misma forma que indican las intrucciones; los valores de entrada son un nummero enterno N, seguido de N valores enteros 
(uno en cada línea) que representan las diferentes denominaciones disponibles de las monedas. Seguido de esto, el programa recibe dos números enteros: P y Q, (uno en cada línea) 
por la entrada estándar, que representan P: el precio de un producto dado y Q: es el billete o moneda con el que se paga dicho producto.
Ya una vez redibidas las entradas se mandan a llamar las 2 funciones greedyCoinPicker() que representa el algoritmo avaro y dynamicCoinPicker() que representa la programación dinámica.

Complejidad del algoritmo greedy es O(C) donde C es el tamaño del array que contiene las 
denominaciones de monedas que se usaran.

Complejidad del algoritmo con programación dinámica es 
Casos de prueba ... (la salida se repite para dinamico y greedy)
1.- Entradas en cada linea: 
    3
    5
    10
    15
    135
    200
Salida:
    15
    15
    15
    15
    5
2.- Entradas en cada linea: 
    3
    4
    78
    1
    1200
    1500
Salida:
    78
    78
    78
    4
    4
    4
    4
    4
    4
    4
    4
    4
    4
    4
    4
    4
    4
    4
    4
    1
    1
3.- Entradas en cada linea:
    4
    25
    10
    20
    5
    60
    100
Salida: (Lo óptimo serían 2 monedas de 20)
    25
    10
    5
4.-Entradas en cada linea:
    4
    1
    2
    5
    10
    143
    200
    Salida:
    2
    5
    10
    10
    10
    10
    10

