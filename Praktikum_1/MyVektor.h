#pragma once
#include<vector>
#include<iostream>
#include<math.h>

using namespace std;
/*• Implementieren Sie (public-)Methoden, um
– einen Vektor einer bestimmten Dimension anzulegen,
– die Dimension eines Vektors zuruckzugeben, ¨
– eine bestimmte Komponente des Vektors zu setzen,
– eine bestimme Komponente des Vektors zuruckzugeben
*/
class CMyVektor
{
private:

	vector<double> vec;
	int dimension;
	double lambda = 1.0;

public:
	CMyVektor( vector<double> *values);
	CMyVektor();
	~CMyVektor();
	void setLambda(double lam);
	double getLambda();
	void setDimension(int d);
	void setPart(int index, double value);
	vector<double> getParts();
	double getPart(int index);
	int getDimension();
	void print();
	double length();
	friend CMyVektor operator+( CMyVektor a, CMyVektor b);
	friend CMyVektor operator*(double lambda, CMyVektor b);
	

	
};

