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
=                            Functions PROGRAM                      =
===================================================================*/
rational_t::rational_t(const int n, const int d)
{ 
	assert(d != 0);
	num_ = n, den_ = d;
}

double rational_t::value() const
{ 
	return double(get_num()) / get_den();
}

rational_t rational_t::opposite() const
{ 
	return rational_t((-1)*get_num(), get_den());
}

rational_t rational_t::reciprocal() const
{ 
	return rational_t(get_den(), get_num());
}

void rational_t::write(ostream& os) const
{ 
	os << get_num() << "/" << get_den() << "=" << value() << endl;
}

void rational_t::read(istream& is)
{
	cout << "Numerador: ";
	is >> num_;
	cout << "Denominador: ";
	is >> den_;
	assert(den_ != 0);
}
////////// F A S E  II    //////////
/**
 *
 *
 *   Autor: Adrián Epifanio R.H
 *   Fecha: 21/02/2019
 *
 *
**/
bool rational_t::equal(const rational_t& r, const double precision) const
{
	//int a = r.get_num();
	if (fabs(double (value() - r.value())) < precision)		//Si |a-b|<precision entonces devolvemos true
		return true;

	else
		return false;
}
/**
 *
 *
 *   Autor: Adrián Epifanio R.H
 *   Fecha: 21/02/2019
 *
 *
**/
bool rational_t::greater(const rational_t& r, const double precision) const
{
	if ((value() - r.value()) > precision)		//Si a-b>precision entonces devolvemos true
		return true;

	else
		return false;
}
/**
 *
 *
 *   Autor: Adrián Epifanio R.H
 *   Fecha: 21/02/2019
 *
 *
**/
bool rational_t::less(const rational_t& r, const double precision) const
{
	if ((value() - r.value()) < -precision) 		//Si a-b < -precision entonces devolvemos true
		return true;
	else
		return false;
}
////////// F A S E  IV    //////////
/**
 *
 *
 *   Autor: Adrián Epifanio R.H
 *   Fecha: 21/02/2019
 *
 *
**/
rational_t rational_t::add(const rational_t& r)
{
	int numerador = (num_ * r.get_den()) + (den_ * r.get_num()); //Creamos un entero numerador
	int denominador = den_ * r.get_den();	//Creamos un entero denominador
	rational_t sentinela(numerador, denominador); 	//Creamos un rational_t al que le pasamos el numerador y denominador 
	
	return sentinela;
}
/**
 *
 *
 *   Autor: Adrián Epifanio R.H
 *   Fecha: 21/02/2019
 *
 *
**/
rational_t rational_t::substract(const rational_t& r)
{
	int numerador = (num_ * r.get_den()) - (den_ * r.get_num());//Creamos un entero numerador
	int denominador = den_ * r.get_den();//Creamos un entero denominador
	rational_t sentinela(numerador, denominador);//Creamos un rational_t al que le pasamos el numerador y denominador 
	
	return sentinela;
}
/**
 *
 *
 *   Autor: Adrián Epifanio R.H
 *   Fecha: 21/02/2019
 *
 *
**/
rational_t rational_t::multiply(const rational_t& r)
{
	int numerador = (num_ * r.get_num());//Creamos un entero numerador
	int denominador = den_ * r.get_den();//Creamos un entero denominador
	rational_t sentinela(numerador, denominador);//Creamos un rational_t al que le pasamos el numerador y denominador 
	
	return sentinela;
}
/**
 *
 *
 *   Autor: Adrián Epifanio R.H
 *   Fecha: 21/02/2019
 *
 *
**/
rational_t rational_t::divide(const rational_t& r)
{
	int numerador = (num_ * r.get_den());//Creamos un entero numerador
	int denominador = den_ * r.get_num();//Creamos un entero denominador
	rational_t sentinela(numerador, denominador);//Creamos un rational_t al que le pasamos el numerador y denominador 
	
	return sentinela;

}

/*=================================================================*/
/*======================  End of Functions  =======================*/
/**
 *
 *
 *   Autor: Adrián Epifanio R.H
 *   Fecha: 21/02/2019
 *
 *
**/


