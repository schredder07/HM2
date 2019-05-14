#include "CMyVektor.h"
#define funktion fktg

double fktf(CMyVektor x)
{
	//sin(xy)+sinx+cosy, x=(0,2,-2,1), default
	return sin(x.getKomponente(0)*x.getKomponente(1)) + sin(x.getKomponente(0)) + cos(x.getKomponente(1));
}



double fktg(CMyVektor x)
{
	//-(2[x1]^2-2[x1][x2]+[x2]^2+[x3]^2-2[x1]-4[x3])
	return -(2 * pow(x.getKomponente(0), 2.0) - 2 * (x.getKomponente(0)*x.getKomponente(1)) + pow(x.getKomponente(1), 2.0) + pow(x.getKomponente(2), 2.0) - 2 * x.getKomponente(0) - 4 * x.getKomponente(2));

}

CMyVektor gradient(CMyVektor x, double(*funktion)(CMyVektor x))
{
	double h = pow(10, -8);				// 10^-8
	CMyVektor tmp = x;					// Kopie des Vektors
	vector<double> vs;					// Vektor speichern
	CMyVektor grad;
	grad.setDimension(x.getDimension());

	for (int stelle = 0; stelle < x.getDimension(); stelle++)
	{
		x.setKomponente(stelle, x.getKomponente(stelle) + h);
		grad.setKomponente(stelle, ((funktion(x) - funktion(tmp)) / h));
		x.setKomponente(stelle, x.getKomponente(stelle) - h);
	}

	return grad;
}



int main()
{
	//double lambda = 1.0;

	//Funktion f(x,y)
	/*CMyVektor vektor1;
	vektor1.setDimension(2);
	vektor1.setKomponente(0, 0.2);
	vektor1.setKomponente(1, -2.1);
	CMyVektor xneu;
	xneu.setDimension(2);
	CMyVektor xtest;
	xtest.setDimension(2);
	*/


	//Funktion g(x1,x2,x3)
	double lambda = 0.1;
	CMyVektor vektor1;
	vektor1.setDimension(3);
	vektor1.setKomponente(0, 0.0);
	vektor1.setKomponente(1, 0.0);
	vektor1.setKomponente(2, 0.0);
	CMyVektor xneu;
	xneu.setDimension(3);
	CMyVektor xtest;
	xtest.setDimension(3);
	
	


	for (int i = 0; i <= 25; i++)
	{
		if (i == 25)
		{
			// Ende
			cout << "Ende wegen Schrittanzahl = 25 bei" << endl;
			cout << "Schritt: " << i << endl;
			cout << "   x = ";
			vektor1.print();
			cout << "   lambda = " << lambda << endl;
			cout << "   f(x) = " << funktion(vektor1) << endl;
			cout << "   grad f(x) = ";
			gradient(vektor1, funktion).print();
			cout << "   ||grad f(x)|| = " << gradient(vektor1, funktion).length() << endl << endl;
			break;
		}
		else
		{
			//Schrittfolge
			cout << "Schritt: " << i << endl;
			cout << "   x = ";
			vektor1.print();
			cout << "   lambda = " << lambda << endl;
			cout << "   f(x) = " << funktion(vektor1) << endl;
			cout << "   grad f(x) = ";
			gradient(vektor1, funktion).print();
			cout << "   ||grad f(x)|| = " << gradient(vektor1, funktion).length() << endl << endl;
		}

		xneu = vektor1 + lambda * gradient(vektor1, funktion);
		cout << "   x_neu = ";
		xneu.print();
		cout << "   f(x_neu) = " << funktion(xneu) << endl << endl;

		// liegt höher => richtiger weg
		if (funktion(xneu) > funktion(vektor1))
		{
			// teste doppelte Schrittweite
			cout << "   Test mit doppelter Schrittweite (lambda = " << lambda * 2.0 << "): " << endl;
			xtest = vektor1 + 2.0 * lambda * gradient(vektor1, funktion);
			cout << "   x_test = ";
			xtest.print();
			cout << "   f(x_test) = " << funktion(xtest) << endl;
			if (funktion(xtest) > funktion(xneu)) // liegt höher
			{
				// test wird übernommen und lambda verdoppelt
				vektor1 = xtest;
				lambda *= 2.0;

			}
			else // nicht höher
			{
				// xneu ist das neue x und lambda bleibt gleich
				vektor1 = xneu; // weiter mit punkt da verdopplung zu groß
				cout << " bleibe bei alter Schrittweite!" << endl << endl;
			}
		}
		else //  xneu <= vektor1 ;neue pos ist kleiner= alterwert
		{
			// zu weit halbieren
			while (!(funktion(xneu) > funktion(vektor1)))
			{
				cout << "   Halbiere Schrittweite (lambda = " << lambda << "): " << endl;
				lambda /= 2.0;
				xneu = vektor1 + lambda * gradient(vektor1, funktion);
				cout << "   x_neu = ";
				xneu.print();
				cout << "   f(x_neu) = " << funktion(xneu) << endl << endl;
			}
			vektor1 = xneu;// 
		}

		// 2te Absprungbedingung
		if (gradient(xneu, funktion).length() < 1e-5)
		{
			cout << "Ende wegen ||grad f(x)|| <  1e-5 bei: " << endl;
			cout << "   x = ";
			vektor1.print();
			cout << "   lambda = " << lambda << endl;
			cout << "   f(x) = " << funktion(vektor1) << endl;
			cout << "   grad f(x) = ";
			gradient(vektor1, funktion).print();

			cout << "   ||grad f(x)|| = " << gradient(vektor1, funktion).length() << endl;

			break;
		}
	}

	system("Pause");
	return 0;
}