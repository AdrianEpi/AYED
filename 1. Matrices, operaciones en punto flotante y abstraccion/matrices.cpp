/*=========================================================================
===========================================================================
    =            Nombre Archivo:    matrices.cpp                      =
    =            Autor:         Adrián Epifanio R.H                   =
    =            Fecha:         2019                                  =
    =            Asignatura:    Algoritmos y Estructuras de Datos     =
    =            Lenguaje:      C++                                   = 
===========================================================================          
=========================================================================*/

/*----------  Libraries set  ----------*/
#include "matrices_3.hpp"
#include <iomanip>
#include <cmath>

using namespace std;



/*====================================
=            FUNCTIONS FILE          =
====================================*/
//========================================================================================
// Métodos privados.
//========================================================================================



vector_inx_t matrix_t::pos(matrix_inx_t i,matrix_inx_t j)
{
	if ((i<1)||(i>m_)||(j<1)||(j>n_)){
		cerr << "Error accediendo a matriz"<< endl;
		return 0;
        }

	return (i-1)*n_+j-1;


}

vector_inx_t matrix_t::pos(matrix_inx_t i,matrix_inx_t j) const
{
	if ((i<1)||(i>m_)||(j<1)||(j>n_)){
		cerr << "Error accediendo a matriz"<< endl;
		return 0;
        }

	return (i-1)*n_+j-1;


}


void matrix_t::crearMatriz(void) 
{
	M_= new matrix_item_t [m_*n_];	// Crea un vector de mxn elementos. 
	
	if (M_==NULL)  		// Si ha fallado la reserva de memoria. 
		cerr << "Error creando matriz." << endl;
}		



void matrix_t::destruirMatriz(void)
{
	if (M_!=NULL){
		delete [] M_;		// Libera la memoria previamente reservada para la matriz.
		M_=NULL;		// Asigna NULL al puntero.
	}

	m_=0;
	n_=0;
}




void matrix_t::redimensiona(matrix_inx_t m,matrix_inx_t n)
{
	destruirMatriz();

	m_=m;
	n_=n;

	crearMatriz();
}


//========================================================================================
// Métodos públicos.
//========================================================================================

matrix_t::matrix_t(matrix_inx_t m,matrix_inx_t n):
M_(NULL),
m_(m),
n_(n)
{
	crearMatriz();
}	




matrix_t::matrix_t(void):
M_(NULL),
m_(0),
n_(0)
{}		



matrix_t::~matrix_t(void)
{
	destruirMatriz();
}


matrix_item_t matrix_t::get_matrix_item(matrix_inx_t i,matrix_inx_t j) const
{
	return M_[pos(i,j)];
}


void matrix_t::set_matrix_item(matrix_inx_t i,matrix_inx_t j,matrix_item_t it)
{
	M_[pos(i,j)]=it;	
}




matrix_inx_t matrix_t::get_m(void) const
{
	return m_;
}




matrix_inx_t matrix_t::get_n(void) const
{
	return n_;
}




istream& matrix_t::read(istream& is)
{
	int m,n;

	is >> m >> n;

	redimensiona(m,n);

	const int sz=m*n;

	for(int i=0;i<sz;i++)
		is >> M_[i];
	
}



ostream& matrix_t::write(ostream& os) const
{

	os << setw(10) << get_m() << setw(10) << get_n() << endl;

	for(int i=1;i <= get_m();i++){

		for(int j=1;j <= get_n() ;j++)
			os << setw(10) << fixed << setprecision(6) << get_matrix_item(i,j);
		
		os << endl;
	}
}

void matrix_t::write(void) const 
{

	for(int i=1;i <= get_m();i++){
		cout << "|";
		for(int j=1;j <= get_n();j++)
			cout << setw(10) << fixed << setprecision(6) << get_matrix_item(i,j);
		cout << " |";
		cout << endl;
	}

	cout << endl;
}
/////////////////////////////////////////////////////////////////////////////////////

/**
 *
 *
 *   Autor: Adrián Epifanio R.H
 *   Fecha: 2019
 *
 *
**/
/*----------  Fase 2 Funciones igual, mayor, menor y zero  ----------*/

/* Funcion igual, le pasamos por parametros dos numeros reales y la precision */
bool matrix_t::igual(matrix_item_t a, matrix_item_t b, double precision)
{
	if (fabs(double (a-b)) < precision)		//Si |a-b|<precision entonces devolvemos true
		return true;

	else
		return false;
	
}
/**
 *
 *
 *   Autor: Adrián Epifanio R.H
 *   Fecha: 2019
 *
 *
**/
/* Funcion mayor, le pasamos por parametros dos numeros reales y la precision */
bool matrix_t::mayor(matrix_item_t a, matrix_item_t b, double precision)
{
	if ((a-b) > precision)		//Si a-b>precision entonces devolvemos true
		return true;

	else
		return false;
}
/**
 *
 *
 *   Autor: Adrián Epifanio R.H
 *   Fecha: 2019
 *
 *
**/
/* Funcion menor, le pasamos por parametros dos numeros reales y la precision */
bool matrix_t::menor(matrix_item_t a, matrix_item_t b, double precision)
{
	if ((b-a) > precision) 		//tambien: a-b < -precision
		return true;

	else
		return false;
}
/**
 *
 *
 *   Autor: Adrián Epifanio R.H
 *   Fecha: 2019
 *
 *
**/
/* Funcion zero, le pasamos por parametros un numero real y la precision */
bool matrix_t::zero(matrix_item_t a, double precision)
{
	if (fabs(double (a)) < precision)		//Si |a|<precision entonces devolvemos true
		return true;

	else
		return false;

}
/**
 *
 *
 *   Autor: Adrián Epifanio R.H
 *   Fecha: 2019
 *
 *
**/
/*----------  Fase 3 Funcion de filtar por precision  ----------*/
/* Funcion filtrar, le pasamos por parametros M, el numero a igualar y precision */
void matrix_t::filtra(matrix_t& M, matrix_item_t it, double precision)
{

	M.redimensiona(m_, n_);		//Llamamos a la funcion redimensiona creada antes para hacer una copia de la matriz en M
	for (int i = 1; i < m_; i++)
	{
		for (int j = 1; j < n_; j++)
		{
			if (igual(get_matrix_item(i, j), it, precision) == true)		//Llamando a la funcion igual le pasamos el numero de la matriz, el numero a igualar y la precision
				M.set_matrix_item(i, j, get_matrix_item(i, j));		//Si la funcion devuelve "true" en la nueva matriz a ese puesto le asignamos el valor de la matriz original

			else
				M.set_matrix_item(i, j, 0.000000);		//En caso de que no se cumpla a la nueva matriz le asignamos el 0.000000 en esa posicion
		}
	}
}
/**
 *
 *
 *   Autor: Adrián Epifanio R.H
 *   Fecha: 2019
 *
 *
**/
/*----------  Fase 4 Traspuesta de la matriz A  ----------*/
/*
void matrix_t::trasponer(void)
{
	matrix_t& M(get_m(), get_n());
	//M[get_m()][get_n()];
	M.redimensiona(m_, n_);
	for (int i = 1; i < m_; i++)
	{
		for (int j = 1; j < n_; j++)
			M.set_matrix_item(i, j, get_matrix_item(j, i));
	}

	//get_m(), get_n(), pos(matrix_inx_t i, matrix_inx_t j)
}
*/



/*====================================*/
/*=====  End of FUNCTIONS FILE  ======*/








