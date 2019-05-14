#include "MyVektor.h"



CMyVektor::CMyVektor( vector<double> *values)
{
	setDimension(values->size());
	
	for (int i = 0; i < values->size(); i++)
	{
		vec[i] = values->at(i);
		
	}
}

CMyVektor::CMyVektor()
{
}



CMyVektor::~CMyVektor()
{
}

void CMyVektor::setLambda(double lam)
{
	lambda = lam;
}

double CMyVektor::getLambda()
{
	return lambda;
}

void CMyVektor::setDimension(int d)
{
	dimension = d;
	vec.resize((size_t)d);
	
}

void CMyVektor::setPart(int index, double value)
{
	
	if (vec.size() <= 0 || index >= vec.size() )
	{
		cout << "Unmöglich" << endl;
	}
	else
	{
		vec[index] = value;
	}
	

	
}

vector<double> CMyVektor::getParts()
{
	return vec;
}

double CMyVektor::getPart(int index)
{

		return vec.at(index);
}

int CMyVektor::getDimension()
{
	return dimension;
}

void CMyVektor::print()
{
	cout << "(";
	
	for (int i = 0; i < getDimension() ; i++)
	{
	
		if (i == vec.size()-1)
		{
			cout << vec.at(i) << "";
		}
		else
		{
			cout << vec.at(i) << ", ";
		}
	
	}
	cout << ")" << endl;
}






CMyVektor operator+( CMyVektor a, CMyVektor b)
{
	if (a.getDimension() != b.getDimension()) { };
	CMyVektor ret;
	ret.setDimension(a.getDimension());
	int di = ret.getDimension();
	for (int i = 0; i < di; i++)
	{
		
		//ret.vec.push_back(a.getPart(i) + b.getPart(i));

		ret.setPart(i, a.getPart(i) + b.getPart(i));
	}
	return ret;
}

CMyVektor operator*(double lambda, CMyVektor b)
{
	
	
	CMyVektor ret;
	ret.setDimension(b.getDimension());
	int di = ret.getDimension();
	for (int i = 0; i < di; i++)
	{
		//ret.vec.push_back(lambda * b.getPart(i));
	
		ret.setPart(i, lambda * b.getPart(i));
	}
	return ret;
}

CMyVektor operator-(CMyVektor a, CMyVektor b)
{
	CMyVektor ret;
	ret.setDimension(a.getDimension());
	int di = ret.getDimension();
	for (int i = 0; i < di; i++)
	{

		//ret.vec.push_back(b.getPart(i) - a.getPart(i));

		ret.setPart(i, a.getPart(i) + b.getPart(i));
	}
	return ret;
}


double CMyVektor::length()
{
	
	double l = 0.00;

	for (int i = 0; i < vec.size(); i++)
	{
		l += abs(vec.at(i) * vec.at(i));
		
	}

	return sqrt(l);

}
