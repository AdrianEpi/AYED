/*=========================================================================
===========================================================================
    =            Proyecto:      Práctica 2                            =
    =            Archivo:       rational_matrix_t.hpp                              =
    =            Autor:         Adrián Epifanio R.H                   =
    =            Fecha:         18/03/2019                            =
    =            Asignatura:    Algoritmos y Estructuras de Datos     =
    =            Lenguaje:      C++                                   = 
===========================================================================          
=========================================================================*/


/*----------  DECLARACION DE LIBRERIAS  ----------*/
#pragma once
/*------------------------------------------------*/


/*----------  DECLARACION DE FUNCIONES  ----------*/
#include "matrix_t.hpp"
#include "rational_t.hpp"
/*------------------------------------------------*/



/*===================================================================
=                            MAIN PROGRAM                           =
===================================================================*/
typedef matrix_t<rational_t> rational_matrix_t;

ostream& operator<<(ostream& os, const rational_matrix_t& M)
{
    M.write(os);
    return os;
}
/**
 *
 *
 *   Autor: Adrián Epifanio R.H
 *   Fecha: 18/03/2019
 *
 *
**/
rational_matrix_t operator*(const rational_matrix_t& A, const rational_matrix_t& B)
{
	rational_matrix_t C;
	C.multiply(A, B);
	return C;
}

/*=================================================================*/
/*=========================  End of Main  =========================*/
/**
 *
 *
 *   Autor: Adrián Epifanio R.H
 *   Fecha: 18/03/2019
 *
 *
**/

