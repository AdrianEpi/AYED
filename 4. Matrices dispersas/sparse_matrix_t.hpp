#pragma once

#include "vector_t.hpp"
#include "matrix_t.hpp"
#include "dll_node_t.hpp"
#include "dll_t.hpp"
#include "pair_t.hpp"
#include "rational_t.hpp"

enum {COL_CONF, ROW_CONF};

typedef pair_t<rational_t> spair_t;
typedef dll_node_t<spair_t> node_pair_t;
typedef dll_t<spair_t> list_pair_t;
typedef vector_t<list_pair_t> vectorcillo_t;

class sparse_matrix_t 
{
	private: 
		int m_; 		// Numero de filas de la matriz original
		int n_;			// Numero columnas matriz original
		int conf_;		// Entero con valor enumerativo(configuracion)
		vectorcillo_t mat;

	public: 	
		sparse_matrix_t(const matrix_t<rational_t>& M, double eps, int conf):
		m_(M.get_m()),
		n_(M.get_n()),
		conf_(conf),
		mat()
		{
			if (conf == COL_CONF)
			{
				mat.resize(m_);
			 	for (int j = 1; j <= n_; j++)
			 	{
			 		for (int i = 1; i <= m_; i++)
			 		{
						if(M(i,j).get_num() != 0)
							mat[i-1].insert_head(new node_pair_t (spair_t(j, M(i,j))));
					}
				}
			}

			else
			{
				mat.resize(n_);
			 	for (int j = 1; j <= m_; j++)
			 	{
			 		for (int i = 1; i <= n_; i++)
			 		{
						if(M(i,j).get_num() != 0)
							mat[j-1].insert_head(new node_pair_t (spair_t(i, M(i,j))));						
					}
				}
			}
		}



		~sparse_matrix_t(void){}



		void write(ostream& os = cout)
		{ 
			node_pair_t* sentinel;
			if(conf_ == ROW_CONF)
			{
				cout << endl << endl <<  "Configuracion filas:" << endl;
				for (int i = 0; i < m_; i++)
				{
					cout << endl << "Lista " << "|" << i << "|  -->  ";
					mat[i].write(cout);
				}				
			}
			else
			{
				cout << endl << endl <<  "Configuracion columnas:" << endl;
				for (int i = 0; i < m_; i++)
				{
					cout << endl << "Lista " << "|" << i << "|  -->  ";
					mat[i].write(cout);
				}					
			}
		}


		void multiply(const matrix_t<rational_t>& A, matrix_t<rational_t>& B)
		{
			assert (n_ == A.get_m());
			B.resize(m_,A.get_n());
			for (int i = 1; i <= B.get_m(); i++)
				for (int j = 1; j >= B.get_n(); j--)
					B.at(i,j)=0;
				
			for (int i = 1; i<= m_; i++)
				for (int j = 1; j <= A.get_n(); j++)			
				{
					node_pair_t* aux = mat[i-1].get_head();	
					while (aux != NULL)
					{
					B(i,j) = B(i,j) + (aux -> get_data().get_val() * A(j,aux -> get_data().get_inx()));
					aux = aux -> get_next();
					}		
				}
		}


		int get_nz(int i) 
		{
			return mat[i - 1].get_size();
		}
};



ostream& operator<<(ostream& os, const pair_t<rational_t>& a)
{
	a.write(os);
	return os;
}

