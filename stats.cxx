//FILE: stats.cxx
//CLASS IMPLEMENTED: statistician (see stats.h for documentation)
#include "stats.h"
#include <cassert>

namespace main_savitch_2C
{

	statistician::statistician()
	{
	   	total=0;
		count=0;
	
	}

	void statistician::next(double r)
	{
		total+=r;
		count++;
		if(count==1){
		 largest=r;
		 tinyest=r;
		}
		if(r>largest)
			largest=r;
		else if(r<tinyest)
				tinyest=r;
		
	}

	void statistician::reset()
	{
		count=0;
		total=0;
	
	}

	int statistician::length() const
	{
		return count;
	}

	double statistician::sum() const
	{
		return total;
	
	}

	double statistician::mean() const
	{
		assert(count>0);
		return total/count;
	}

	double statistician::minimum() const
	{
		assert(count>0);
		return tinyest;
	}

	double statistician::maximum() const
	{
		assert(count>0);
		return largest;
	}

	statistician operator +(const statistician& s1,const statistician& s2)
	{
		statistician stat_sum;
	
		if(s1.length()==0)
			return s2;
		if(s2.length()==0)
			return s1;
		stat_sum.count=s1.length()+s2.length();
		stat_sum.total=s1.sum()+s2.sum();
		
			if((s1.length()>0)&&(s2.length()>0)&&(s1.minimum()<s2.minimum()))
			stat_sum.tinyest=s1.minimum();
			
			if((s1.length()>0)&&(s2.length()>0)&&(s2.minimum()<s1.minimum()))
				stat_sum.tinyest=s2.minimum();

			if((s1.length()>0)&&(s2.length()>0)&&(s1.maximum()>s2.maximum()))
			stat_sum.largest=s1.maximum();

			if((s1.length()>0)&&(s2.length()>0)&&(s2.maximum()>s1.maximum()))
			stat_sum.largest=s2.maximum();
		
		return stat_sum;
	}

	statistician operator *(double scale, const statistician& s)
	{
		statistician scalar_mult;
		scalar_mult.count=s.length();
		scalar_mult.total=scale*s.sum();

		if(scalar_mult.count>0){
		scalar_mult.tinyest=scale*s.minimum();
		scalar_mult.largest=scale*s.maximum();
		}

		if((scalar_mult.count>0)&&(scalar_mult.tinyest>scalar_mult.largest)){
			scalar_mult.largest=scale*s.minimum();
			scalar_mult.tinyest=scale*s.maximum();
		}
		
		return scalar_mult;	
	}

	bool operator ==(const statistician& s1, const statistician& s2)
	{
		bool is_equal=false;
		
	
		if(s1.length()!=s2.length())
		return false;
		if(s1.length()==0)
		return true;
		if((s1.length()>0)&&(s2.length()>0)
				&&(s1.mean()==s2.mean())
				&&(s1.length()==s2.length()) 
				&&(s1.sum()==s2.sum()) 
				&&(s1.minimum()==s2.minimum()) 
				&&(s1.maximum()==s2.maximum()));{
		
		return true;
		}
		

	
		return is_equal;

	}
}

