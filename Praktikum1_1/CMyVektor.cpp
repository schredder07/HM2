#include "CMyVektor.h"


CMyVektor::CMyVektor(vector<double> *values)
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

void CMyVektor:: setlambda(double lam)
{
	lambda = lam;
}

double CMyVektor::getlambda()
{
	return lambda;
}

void CMyVektor::setDimension(int d)
{
	dimension = d;
	vec.resize((size_t)d);
}

void CMyVektor::setKomponente(int index, double wert)
{
	if (vec.size() <= 0 || index >= vec.size())
	{
		cout << "Kann Komponente nicht ändern!" << endl;
	}
	else
	{
		vec[index] = wert;
	}
}

int CMyVektor::getDimension()
{
	return dimension;
}

vector<double> CMyVektor::getKomponenten()
{
	return vec;
}

double CMyVektor::getKomponente(int index)
{
	return vec.at(index);
}

void CMyVektor::print()
{
	{
		cout << "(";

		for (int i = 0; i < getDimension(); i++)
		{

			if (i == vec.size() - 1)
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
}

//Betrag vom Vektor: wurzel aus (a²+b²...)

double CMyVektor::length()
{
	double l = 0.00;

		for (int i = 0; i < vec.size(); i++)
		{
			l += abs(vec.at(i) * vec.at(i));

		}

	return sqrt(l);
}

// Vektor Addition
/*  /1\ /2\ /3\
    |2|+|3|=|5|
    \3/ \4/ \7/   */

CMyVektor operator+(CMyVektor a, CMyVektor b)
{
	if (a.getDimension() != b.getDimension()) {
		cout << "Kann nicht addieren!"<<endl;
		return 0;
	}
	else
	{
		CMyVektor add;
		add.setDimension(a.getDimension());
		int di = add.getDimension();
		for (int i = 0; i < di; i++)
		{
			add.setKomponente(i, a.getKomponente(i) + b.getKomponente(i));
		}
		return add;
	}
}

/*
CMyVektor operator-(CMyVektor a, CMyVektor b)
{
	if (a.getDimension() != b.getDimension()) {
		cout << "Kann nicht subtrahieren!" << endl;
	}
	else
	{
		CMyVektor sub;
		sub.setDimension(a.getDimension());
		int di = sub.getDimension();
		for (int i = 0; i < di; i++)
		{
			sub.setKomponente(i, a.getKomponente(i) - b.getKomponente(i));
		}
		return sub;
	}
}
*/

// Skalare Multiplikation
/*     /2\ /4\
    2 *|3|=|6|
       \4/ \8/   */

CMyVektor operator*(double lambda, CMyVektor b)
{
	CMyVektor mult;
	mult.setDimension(b.getDimension());
	int di = mult.getDimension();
	for (int i = 0; i < di; i++)
	{
		mult.setKomponente(i, lambda * b.getKomponente(i));
	}
	return mult;

}


