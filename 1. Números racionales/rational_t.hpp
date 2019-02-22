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

/*----------  DECLARACION DE LIBRERIAS  ----------*/
#pragma once

#include <iostream>
#include <cassert>
#include <cmath>

# define EPSILON 1e-6

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
/*===================================================================
=                           Class PROGRAM                           =
===================================================================*/
class rational_t
{
	int num_, den_;

	public:
		rational_t(const int = 0, const int = 1);		//Constructor
		~rational_t() {}	//Destructor
		

		// GETTERS
		int get_num() const 	//Get del numerador
		{ 
			return num_; 
		}
		
		int get_den() const 	// get del denominador
		{ 
			return den_; 
		}
		

		// SETTERS
		void set_num(const int n)	//set del numerador
		{ 
			num_ = n; 
		}
		
		void set_den(const int d)	//set del denominador
		{ 
			assert(d != 0), den_ = d; 
		}


		// FUNCIONES
		double value(void) const;				//Función que imprime el valor en decimal
		rational_t opposite(void) const;		//Función que calcula el contrario
		rational_t reciprocal(void) const;		//Función que calcula el recíproco

		// FASE II
		bool equal(const rational_t& r, const double precision = EPSILON) const;		//Booleana igual
		bool greater(const rational_t& r, const double precision = EPSILON) const;		//Booleana mayor que
		bool less(const rational_t& r, const double precision = EPSILON) const;			//Booleana menor que
  
		// FASE IV
		rational_t add(const rational_t&);				// Operación suma
		rational_t substract(const rational_t&);		// Operación resta
		rational_t multiply(const rational_t&);			// Operación multiplicación
		rational_t divide(const rational_t&);			// Operación división
  
		void write(ostream& os = cout) const;		//Función que escribe el racional
		void read(istream& is = cin);		//Función que lee un racional por pantalla
};


/*==================================================================*/
/*=========================  End of Class  =========================*/
/**
 *
 *
 *   Autor: Adrián Epifanio R.H
 *   Fecha: 21/02/2019
 *
 *
**/



