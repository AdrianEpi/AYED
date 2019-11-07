#pragma once

#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <string>
#include <iostream>
#include <cmath>


using namespace std;

namespace AED {

	template <class T>
	class RPN_calc_t{
	private:
		T stack_;

	public:
		RPN_calc_t() {}

		~RPN_calc_t() {}
	
		const int compute(istream& is)
		{

			int operando;
			char operador;

			while(!is.eof()){

				is >> ws;
				int c = is.peek();

				if (!cin.eof()) {

					if (isdigit(c)){
						is >> operando;
						//...
						stack_.push(operando);
					}
					else {
						is >> operador;
						//...
						//	1) sacar 2 operandos y aplicar el operador  //top pop
						//	2) resultado.push()
						operate(operador);
					}
				}
			}

			const int result = stack_.top();
			stack_.pop();

			return result;
		}

		private: 

			void operate(char operador){
				
			int pedro, pica, piedra = 0;
			pedro = stack_.top();
			stack_.pop();
			if (operador == '+' || operador == '-' || operador == '*' || operador == '/' || operador == '^')
			{
				pica = stack_.top();
				stack_.pop();
			}

				switch (operador)
				{
					case '+':						
						piedra = pedro + pica;						
						cout << endl << "Suma: " <<  piedra;
						break;

					case '-':						
						piedra = pedro - pica;						
						cout << endl << "Resta: " <<  piedra;
						break;

					case '*':						
						piedra = pedro * pica;						
						cout << endl << "Multiplicación: " <<  piedra;
						break;

					case '/':						
						piedra = pica / pedro;						
						cout << endl << "Suma: " <<  piedra;
						break;

					case '^':						
						piedra = pow(pica, pedro);
						cout << endl << "Potencia: " <<  piedra;
						break;

					case 'r':
						piedra = sqrt(pedro);
						cout << endl << "Raiz: " <<  piedra;
						break;

					case 'l':
						piedra = log2(pedro);
						cout << endl << "Logaritmo base 2: " <<  piedra;
						break;

					case 'c':
						piedra = pedro * pedro;
						cout << endl << "Cuadrado: " <<  piedra;
						break;

					case 'n':
						piedra = pedro * (-1);
						cout << endl << "Negativo: " <<  piedra;
						break;
					
				}

				stack_.push(piedra);
			}

       };

}

