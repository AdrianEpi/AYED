/*=========================================================================
===========================================================================
    =            Proyecto:      Práctica 1                            =
    =            Archivo:       main.cpp                              =
    =            Autor:         Adrián Epifanio R.H                   =
    =            Fecha:         21/02/2019                            =
    =            Asignatura:    Algoritmos y Estructuras de Datos     =
    =            Lenguaje:      C++                                   = 
===========================================================================          
=========================================================================*/



/**  ===  MAKEFILE  ===
    
    compile:
        g++ main_rational_t.cpp rational_t.cpp  -std=c++11 -o test


**/



/*----------  DECLARACION DE LIBRERIAS  ----------*/
#include <iostream>
#include <cmath>
#include <cstdlib>

using namespace std;
/*------------------------------------------------*/
/**
 *
 *
 *   Autor: Adrián Epifanio R.H
 *   Fecha: 21/02/2019
 *
 *
**/

/*----------  DECLARACION DE FUNCIONES  ----------*/
#include "rational_t.hpp"

/*------------------------------------------------*/
/**
 *
 *
 *   Autor: Adrián Epifanio R.H
 *   Fecha: 21/02/2019
 *
 *
**/

/*===================================================================
=                            MAIN PROGRAM                           =
===================================================================*/
// FASE III: función de búsqueda
bool search(const rational_t* v, const int n, const rational_t& x)
{
	for(int i = 0; i<n; i++)
	{
		if ((v[i].get_num() == x.get_num()) && (v[i].get_den() == x.get_den())) //Comprobamos que el numerador de v y el de x sean iguales y sus respectivos denominadores
			return true;
	}
	return false; //En caso de que finalice el bucle y no haya retornado true es porque no se ha encontrado.

}
/**
 *
 *
 *   Autor: Adrián Epifanio R.H
 *   Fecha: 21/02/2019
 *
 *
**/
//Funcion principal
int main (void)
{

	int sentinel;
  	rational_t a(1, 2), b(3), c;

  	int n;
	cout << "Introduce n: ";
	cin >> n;
	rational_t *v = new rational_t[n]; //Reservamos memoria dinamicamente

	do 
	{
		cout << "Elija la operación que quiera realizar: " << endl;
		cout << endl << "\t1. Mostrar valores de a, b, c." << endl << "\t2. Mostrar opuesto de a" << endl << "\t3. Mostrar recíproco de b" << endl << " ////////// F A S E   III /////////" << endl << "\t4. Buscar un racional en un vector" << endl << " ////////// F A S E   IV /////////" << endl << "\t5. Resolver a + b"  << endl << "\t6. Resolver b -a" << endl << "\t7. Resolver a * b" << endl << "\t8. Resolver a / b" << endl << "\t0. Finalizar el programa" << endl << endl;

		cin >> sentinel;
		system("clear");	//Llamada al sistema para limpiar la consola 
		switch (sentinel)
		{
			case 1: 
	        	cout << "a.value()= " << a.value() << endl;
			  	cout << "b.value()= " << b.value() << endl;
			  	cout << "c.value()= " << c.value() << endl;

			  	cout << "a: ";
			  	a.write();
			  	cout << "b: ";
			  	b.write();

			  	c.read();
			  	cout << "c: ";
			  	c.write();

	            break;


	        case 2: 
	        	cout << "Opuesto de a: ";
  				a.opposite().write(); 	//Calculamos el opuesto y nos lo iprime con la llamada a la función write

	            break; 
	        

	        case 3: 
	        	cout << "Recíproco de b: ";
 			 	b.reciprocal().write();		//Calculamos el recíproco y lo imprimimos con la llamada a la función write

	            break; 
	        

	        case 4: 
				
				if (v != NULL) 
				{
					for (int i = 0; i < n; i++) 
					{
						v[i] = rational_t(1, pow(2, i));	//Creamos un vector v[i] racional de la forma 1/2^i
						v[i].write();
					}

					rational_t x(1, pow(2, 3)); 	// queremos bucar el valor 1/2^3
					bool b = search(v, n, x); 		//Creamos una booleana b y llamamos a la funion search pasandole el vector v, el numero de racionales en el vector (n) y el rational_t x creado anteriormente
					cout << "Valor " << x.value() << (b ? "" : "no") << " encontrado" << endl;

			  	}
			  	else 
			  	{
					cerr << "ERROR: no se ha podido reservar memoria dinámica" << endl;
					return 1;
				}
  		        
  		        break;


	        case 5: 
				cout << "a + b: ";
			  	a.add(b).write();
  	        
  	            break;
	        

	        case 6: 
	           	cout << "b - a: ";
	          	b.substract(a).write();
	            
	            break; 


	        case 7: 
	           	cout << "a * b: ";
  				a.multiply(b).write();
	            
	            break; 


	        case 8: 
	           	cout << "a / b: ";
  				a.divide(b).write();	            
	        
	            break; 


	        case 0: 
	        	
	            for(int i = 0; i<1; i++)
	            {
	            	cout << endl << endl << endl;
	            	cout << "\tFinalizando ejecución  . . ." << endl << endl << endl; 	for(int j = 0; j<700000000; j++){}
	            	cout << "\tTerminando procesos  . . ." << endl << endl << endl;		for(int j = 0; j<700000000; j++){}
	            	//cout << "\tCerrando subrutinas  . . ." << endl << endl << endl;		for(int j = 0; j<700000000; j++){}
	            	cout << "\tSaliendo  . . ." << endl << endl << endl;				for(int j = 0; j<1200000000; j++){}

	            	cout << "El programa ha finalizado con éxito." << endl << endl << endl;


	            }

	            break;

	        default: 

	            break; 
		}//End switch
	}while (sentinel != 0); //End do while


	delete[] v; // Eliminamos la memoria reservada dinámicamente

    return 0;

}
/*=================================================================*/
/*=========================  End of Main  =========================*/
/**
 *
 *
 *   Autor: Adrián Epifanio R.H
 *   Fecha: 21/02/2019
 *
 *
**/







