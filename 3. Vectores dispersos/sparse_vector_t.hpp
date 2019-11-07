#pragma once

#include "list_pair_t.hpp"
#include "vector_t.hpp"
#include <cmath>

#include <iostream>
#include <iomanip>

#include "vector_t.hpp"

using namespace std;

namespace AED {

class sparse_vector_t{
private:
	list_pair_t   v_;    
	int           sz_;
	int 		  nz_;

public:
	sparse_vector_t(const vector_t<double>& v, double eps):
		v_(),
		sz_(v.size()),
		nz_(0) 
		{			
			for(int i = sz_ -1; i >= 0; i--)
			{
				if ( is_not_zero(v[i], eps) )
				{
					spair_t j(i,v[i]);
					node_pair_t* p =new node_pair_t(j);
					v_.insert_head(p);
					nz_++; 
				}	
			}


		}

	~sparse_vector_t(void){}

	ostream& write(ostream& os) const
	{	
		os << "[ " << setw(7) << sz_ << " ";
		v_.write(os);
		os << " ]";

		return os;
	}
	
	double scal_prod(const vector_t<double>& b) const
	{
		assert(b.size() == this -> sz_);
		double sentinela1, sentinela2, producto = 0;
		for (node_pair_t* alpha = v_.head(); alpha != NULL; alpha=alpha -> get_next())
		{
			for(int i = 0; i < b.size(); i++)
			{
				sentinela1 = alpha -> get_data().get_val();
				sentinela2 = alpha -> get_data().get_inx();
				if (sentinela2 == i)
					producto += sentinela1 * b[i];
			}			
		}
		return producto;
	}

	double scal_prod(const sparse_vector_t& b) const
	{
		assert(b.sz_ == this -> sz_);
		double sentinela1, sentinela2, sentinela3, sentinela4, producto = 0;
		node_pair_t* beta = b.v_.head();
		node_pair_t* alpha = v_.head(); 
		while ((alpha != NULL) && (beta != NULL))
		{
			for(int i = 0; i < b.sz_; i++)
			{
				sentinela1 = alpha -> get_data().get_val();
				sentinela2 = alpha -> get_data().get_inx();
				sentinela3 = beta -> get_data().get_val();
				sentinela4 = beta -> get_data().get_inx();

				if (sentinela2 == i)
					producto += sentinela1 * sentinela3;

				else if 
					(sentinela4 > sentinela2)
					alpha = alpha -> get_next();

				else if (sentinela4 < sentinela2)
					beta = beta -> get_next();
			}
			alpha = alpha -> get_next();
			beta = beta -> get_next();
		}
		return producto;
	}
 
 	void insert_pos(node_pair_t* n, int pos)
 	{
 		assert(pos > 0 && pos <= sz_ + 1);
 		node_pair_t* sentinel = v_.head();
		for (int i = 0; i < pos - 1; i++)
			sentinel = sentinel->get_next();

		sz_++;
		v_.insert_after(sentinel, n);
 	}
private:
	bool is_not_zero(double val, double eps){ return fabs(val) > eps;}

};


}