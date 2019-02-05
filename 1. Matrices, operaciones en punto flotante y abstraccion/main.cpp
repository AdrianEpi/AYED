/*=========================================================================
===========================================================================
    =            Nombre Archivo:    main.cpp                          =
    =            Autor:         Adrián Epifanio R.H                   =
    =            Fecha:         2019                                  =
    =            Asignatura:    Algoritmos y Estructuras de Datos     =
    =            Lenguaje:      C++                                   = 
===========================================================================          
=========================================================================*/

/* Compile: g++ -o name main.cpp */



/**  ===  MAKEFILE  ===
    
    compile:
        g++ main.cpp matrices.cpp -std=c++11 -o name

**/



/*----------  Libraries set  ----------*/
#include "matrices.hpp"



/*====================================
=            MAIN PROGRAM            =
====================================*/
int main(void)
{
	matrix_t A;
	matrix_t B;

	cout << endl;
	A.read(cin);
	cout << "---  MATRIZ ORIGINAL A ---" << endl;
	A.write();

	/*const matrix_t& B=A;

	cout << endl;
	cout << "---  MATRIZ ORIGINAL B ---" << endl;
	B.write();	
	*/
	cout << "---  PRECISIÓN 0.0001 ---" << endl;
	A.filtra(B,5.254,1E-4);
	B.write();

	cout << "---  PRECISIÓN 0.001  ---" << endl;
	A.filtra(B,5.254,1E-3);
	B.write();

	cout << "---  PRECISIÓN 0.01   ---" << endl;
	A.filtra(B,5.254,1E-2);
	B.write();

	cout << "---  PRECISIÓN 0.1    ---" << endl;
	A.filtra(B,5.254,1E-1);
	B.write();

	cout << "---  PRECISIÓN 1.0    ---" << endl;
	A.filtra(B,5.254,1.0);
	B.write();

	cout << "---  MATRIZ ORIGINAL TRASPUESTA---" << endl;
	//A.trasponer();
	//A.write();

}

/*==========================*/
/*=====  End of Main  ======*/



