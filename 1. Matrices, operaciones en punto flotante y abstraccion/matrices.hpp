/*=========================================================================
===========================================================================
    =            Nombre Archivo:    matrices.hpp                      =
    =            Autor:         Adrián Epifanio R.H                   =
    =            Fecha:         2019                                  =
    =            Asignatura:    Algoritmos y Estructuras de Datos     =
    =            Lenguaje:      C++                                   = 
===========================================================================          
=========================================================================*/

/*----------  Libraries set  ----------*/
#pragma once

#include <cstdio>		// Cabecera que contendrá el procedimiento sprintf
#include <iostream>		// Cabecera que tendrá la E/S mediante flujo
#include <cmath>		// Cabecera que contendrá las funcioens matemáticas

using namespace std;


/*====================================
=            MAIN PROGRAM            =
====================================*/

//========================================================================================
// Definición de tipos
//========================================================================================

/** Tipo de dato que almacenará cada elemento de la matriz. */
typedef double 		matrix_item_t;	
/** Tipo de dato para índices de la matriz.                 */
typedef unsigned short int 	matrix_inx_t;	
/** Tipo de dato para índices del vector  .                 */
typedef unsigned short int 	vector_inx_t;	

class matrix_t 
{
	//========================================================================================
	// Atributos privados.
	//========================================================================================
	private:

		matrix_item_t*	M_;	/**< Puntero que apunta al comienzo del vector conteniendo los elementos de la matriz. */
		matrix_inx_t  	m_;	/**< Número de filas.   */
		matrix_inx_t	n_;	/**< Número de columnas.*/
		bool			traspuesta_;	//Variable boobleana para la traspuesta


	//========================================================================================
	// Métodos públicos.
	//========================================================================================

	public:

		matrix_t(matrix_inx_t m,matrix_inx_t n); 
		matrix_t(void); 	
		~matrix_t(void);
		matrix_item_t get_matrix_item(matrix_inx_t i,matrix_inx_t j) const;
		void set_matrix_item(matrix_inx_t i,matrix_inx_t j,matrix_item_t it);
		matrix_inx_t get_m(void) const;
		matrix_inx_t get_n(void) const;
		istream& read(istream& is);
		ostream& write(ostream& os) const;
		void write(void) const;
		//FASE 2
		bool igual(matrix_item_t a, matrix_item_t b, double precision);
		bool mayor(matrix_item_t a, matrix_item_t b, double precision); 
		bool menor(matrix_item_t a, matrix_item_t b, double precision);
		bool zero(matrix_item_t a, double precision);
		//FASE 3
		void filtra(matrix_t& M, matrix_item_t it, double precision);
		//FASE 4
		void trasponer(void);

	//========================================================================================
	// Métodos privados.
	//========================================================================================

	private:

		vector_inx_t pos(matrix_inx_t i,matrix_inx_t j);
		vector_inx_t pos(matrix_inx_t i,matrix_inx_t j) const;
		void crearMatriz(void); 
		void destruirMatriz(void);
		void redimensiona(matrix_inx_t m,matrix_inx_t n);
};
/*==========================*/
/*=====  End of Main  ======*/



