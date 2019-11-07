/*
Práctica #4. Matrices dispersas
Matrices dispersas

Palabras clave
Vectores, listas enlazadas, matrices dispersas, comparación de números reales, constructor por defecto, constructor de copia, referencia, referencia constante, métodos para objetos constantes, lectura y escritura mediante streams.

Objetivo
Esta práctica persigue que el estudiante aborde el concepto de matriz dispersa, una generalización del concepto de vector disperso. Para ello debe afianzarse los conceptos estudiados en las prácticas anteriores. Se pretende además que el alumnado sea capaz de componer desde cero una clase compleja a partir de código desarrollado previamente contenido en bibliotecas. 

Material
El alumnado deberá utilizar el material proporcionado en las prácticas anteriores, el aula virtual y la plataforma GitHub (https://github.com/RieraULL/ALG-ULL). Se deberá utiliza la clase rational_t, pair_t, dll_node_t, dll_t, vector_t, matrix_t, etc.

Desarrollo
Fase I
El alumno debe leer y comprender el material que se ha referenciado en el apartado anterior. Se debe esbozar una clase (sparse_matrix_t, por ejemplo) que represente una matriz dispersa en un vector cuyos elementos son listas doblemente enlazadas, cuyos nodos tienen como dato un par que representa la fila/columna a la que pertenece el elemento y su valor, siendo este valor de tipo racional.

Fase II
El alumno debe representar una matriz dispersa, para ello debe construir una clase que se denominará sparse_matrix_t, que contendrá los siguientes atributos:

Número de filas de la matriz original (m_),
Número de columnas de la matriz original (n_),
Una estructura que almacenará los elementos no nulos de la matriz. Esta estructura será un vector cuyos elementos son listas (doblemente enlazadas) en las que sus elementos, a su vez, contienen un par con un índice del elemento no nulo y un valor de tipo rational_t. La matriz dispersa admite dos configuraciones: columnas y filas. En caso de que la configuración sea de columnas en este vector habrá una lista por cada columna.  En el caso de que la configuración sea de filas se extrapolará la configuración anterior para este caso.
Un entero con un valor enumerativo (conf_) que contendrá los valores COL_CONF o ROW_CONF, según sea la configuración por columnas o filas, respectivamente.
La clase debe contener como métodos:

Un constructor al que se le pase una referencia constante de una matriz cuyos elementos sean de tipo rational_t, y un entero con el valor de la configuración de almacenamiento (los detalles sobre cómo llevar a cabo este constructor se darán durante la tutoría),
Un destructor.
Un procedimiento de impresión con un parámetro de tipo referencia a ostream, que envíe al ostream el contenido de la matriz,
Fase III
Adicionalmente, debe llevarse a cabo un método para la multiplicación de la matriz dispersa invocante por una matriz densa que se pasa como referencia constante, y el resultado, que será una matriz densa, debe almacenarse sobre un parámetro que se pasa como referencia.
 */
#include <cstdio>
#include <iostream>

#include "matrix_t.hpp"
#include "rational_t.hpp"
#include "sparse_matrix_t.hpp"

#define MAX_DIM 5

using namespace std;

int main(void)
{
	matrix_t<rational_t> A(MAX_DIM,MAX_DIM);
	matrix_t<rational_t> B(MAX_DIM,MAX_DIM);

	for(int i = 1; i <= MAX_DIM; i++)
		A(i,i) = rational_t(1,i + 1);

	A(1,2) = rational_t(5);
	A(3,4) = rational_t(3,2);
		
	A.write(cout);
	cout << endl;

	sparse_matrix_t SA(A, 1E-2, COL_CONF);
	SA.write(cout);
	cout << endl;

	sparse_matrix_t SB(A, 1E-2, ROW_CONF);
	SB.write(cout);
	cout << endl;


	cout << endl << "La multiplicación es:" << endl << endl;
	SA.multiply(A, B);
	B.write(cout);
	cout << endl;

	cout << "El numero de elementos no nulos en la fila 3 es: " << SA.get_nz(3);
	cout << endl;
	return 0;
}
