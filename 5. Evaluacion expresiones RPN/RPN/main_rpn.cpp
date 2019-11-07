/*
Práctica #5: Evaluación de expresiones RPN
Evaluación de expresiones RPN
Palabras clave
Tipo abstracto de dato. Listas, pilas, Notación polaca inversa. Abstracción.

Objetivo
El objetivo de esta práctica es poner en práctica las competencias adquiridas durante el desarrollo de los temas relacionados con Tipos abstractos de datos. En concreto se hará hincapié en los conceptos de pilas, listas, vectores.

Se persigue implementar una calculadora para evaluar expresiones RPN.

Material
El estudiante deberá utilizar los ficheros fuente proporcionado en este enunciado (RPN.zip). Se recomienda examinar las siguientes páginas web:

Pilas
Colas
Notación polaca inversa
Desarrollo
Fase I
El estudiante debe leer y comprender el material proporcionado, estudiando las clases tipo plantilla, comprobando cómo puede llevarse a cabo una concreción de una plantilla, y finalmente estudiando en profundidad la sintaxis de cada uno de los los ficheros. Es muy importante que se comprenda las dos clases pila proporcionadas: pila basada en vector, y pila basada en lista doblemente enlazada. Debe estudiarse el mecanismo de la notación polaca inversa, así como la implementación de una calculadora utilizando este tipo de notación mediante una pila.

Fase II
El estudiante debe completar la implementación de la calculadora RPN para los operandos de aridad dos +, -, * y /.

Fase III
El estudiante debe completar la implementación de la calculadora RPN para el operando de aridad dos ^, y los operandos de aridad uno raíz cuadrada (r), logaritmo en base 2 (l), y elevación al cuadrado (c).
 */

#include <cstdio>
#include <iostream>


#include "stack/stack_v_t.hpp"
#include "stack/stack_l_t.hpp"
#include <stack>

#include "RPN/RPN_calc_t.hpp"

using namespace std;
using namespace AED;

typedef stack_v_t<int> stack_vector;
typedef stack_l_t<int> stack_lista;  
typedef stack<int>     stack_stl;

int main(void)
{
	{
		RPN_calc_t<stack_vector> calculadora_vector;
		const int result_vector = calculadora_vector.compute(cin);
		cout << endl << "Calculadora vector: " << result_vector << endl;
	}
	
	cin.clear();             // OMG!
	cin.seekg(0, ios::beg);

	{
		RPN_calc_t<stack_lista> calculadora_lista;
		const int result_lista = calculadora_lista.compute(cin);
		cout << endl << "Calculadora lista:  " << result_lista << endl;
	}

	cin.clear();
	cin.seekg(0, ios::beg);

	{
		RPN_calc_t<stack_stl> calculadora_stl;
		const int result_stl = calculadora_stl.compute(cin);
		cout << endl << "Calculadora stl:    " << result_stl << endl;
	}

	return 0;
}
