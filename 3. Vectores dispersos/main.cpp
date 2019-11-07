/*
Practica #3. Vectores dispersos
Vectores dispersos
Palabras clave
Vector disperso, lista simplemente enlazada, método constante, plantillas, sobrecarga de funciones, sobrecarga de operadores.

Objetivo
La práctica consiste en el desarrollo de una clase que cree un vector disperso a partir de un vector en formato denso. La clase vector disperso almacenará los sus elementos dentro de una lista de pares, en los que la primera parte es el índice del elemento no nulo, y la segunda es su valor. Se propondrá también el desarrollo de dos métodos para el cálculo del producto escalar. Un que contemple el producto de un vector disperso por uno denso, y otro que efectúe el producto entre dos vectores dispersos.

Recursos
Se proporciona el siguiente material:

El fichero vector_t.hpp: una clase vector denso.

El fichero sll_node_t.hpp: una clase de nodo de lista enlazada.

El fichero sll_t.hpp: una clase de lista enlazada.

El fichero pair_t.hpp: definición del tipo par.

El fichero list_pair_t.hpp: adaptaciones de las clases al tipo pair_t.

El fichero sparse_vector_t.hpp: definición de la clase vector disperso.

El fichero main.cpp: programa principal de prueba.

FASE I. COMPRENSIÓN DEL MATERIAL PROPORCIONADO
Descargar los ficheros fuente.

Compilarlos y ejecutarlos:

$ g++ -g main.cpp -o sparse_vector

$ ./sparse_vector

Examinar los ficheros de cabecera identificando los constructores, el destructor, los métodos para acceder a los atributos, los métodos para lectura desde teclado y escritura a pantalla, e identificar los elementos privados y públicos, tanto atributos como métodos. Identificar la sintaxis de las plantillas. Establecer dónde se efectúa la sobrecarga de operadores, determinar qué operadores han sido sobrecargados.

Comprender la definición de la lista enlazada, así como sus procedimientos de mantenimiento.

Comprender la definición de la clase vector dispersos.

FASE II. DESARROLLO DE UN CONSTRUCTOR PARA LA CLASE sparse_vector_t
Desarrollar el constructor de la clase sparse_vector_t tal y como se ha especificado durante la clase de teoría para una clase vector disperso sobre una lista simplemente enlazada.

FASE III. DESARROLLO DE UN MÉTODO PARA CÁLCULO DEL PRODUCTO ESCALAR I
Desarrollar un método que efectúe el producto escalar entre el vector disperso invocante y un vector denso que se pasa como parámetro.

FASE IV. DESARROLLO DE UN MÉTODO PARA EL CÁLCULO DEL PRODUCTO ESCALAR II
Desarrollar un método que efectúe el producto escalar entre el vector disperso invocante y un vector disperso que se pasa como parámetro.


 */
#include "vector_t.hpp"
#include "sparse_vector_t.hpp"

#include <iostream>
using namespace std;
using namespace AED;

#define V_SZ 10000
#define EPS  1E-3

int main(void)
{
	vector_t<double> v1(V_SZ);

	for(int i = 0; i < V_SZ; i++)
		v1[i] = 0.0;

	v1[0]    = 1.0; 
	v1[1000] = 1.0; 
	v1[2000] = 1.0; 
	v1[3000] = 1.0; 
	v1[4000] = 1.0; 
	v1[5000] = 1.0;
	v1[9000] = 1.0;

	sparse_vector_t sv1(v1, EPS);	

	sv1.write(cout);
	cout << endl;

	vector_t<double> v2(V_SZ);

	for(int i = 0; i < V_SZ; i++)
		v2[i] = 0.0;

	v2[0]    = 1.0; 
	v2[100]  = 1.0; 
	v2[1000] = 1.0;  
	v2[3000] = 1.0; 
	v2[5000] = 1.0;

	sparse_vector_t sv2(v2, EPS);	

	sv2.write(cout);
	cout << endl;

	const double prod1 = sv1.scal_prod(v2);
	const double prod2 = sv1.scal_prod(sv2);

	cout << endl << endl << "El producto de un vector denso por un vector disperso es:" << endl << prod1 << endl;
	cout << "El producto de un vector disperso por un vector disperso es: " << endl << prod2 << endl;

	cout << endl << endl << "Vector modificado: " << endl;
	node_pair_t* insert_nodo = new node_pair_t(spair_t(5, 15));
	sv1.insert_pos(insert_nodo,1000);
	sv1.write(cout);
	cout << endl;

}
