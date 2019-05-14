#include"MyVektor.h"
#define funktion fkt3
double fkt2(CMyVektor x)
{

	//letztere
	return -( 2 * pow(x.getPart(0),2.0) - 2 * x.getPart(0) * x.getPart(1) + pow(x.getPart(1),2.0) + pow(x.getPart(2),2.0) - 2 * x.getPart(0) - 4 * x.getPart(2));
}



double fkt3(CMyVektor x)
{
	//erste
	return sin(x.getPart(0) + pow(x.getPart(1), 2.0)) + pow(x.getPart(1), 3.0) - 6 * (pow(x.getPart(1), 2.0)) + 9 * x.getPart(1);

}

CMyVektor gradient(CMyVektor x, double(*funktion)(CMyVektor x))
{
	
	double h = pow(10, -8);// 10^-8

	CMyVektor tmp = x; // alter vektor bzw. Kopie
	vector<double> vs; // vector speichern
	CMyVektor grad;
	grad.setDimension(x.getDimension());

	for (int stelle = 0; stelle < x.getDimension(); stelle++)
	{
				x.setPart(stelle, x.getPart(stelle) + h);
				grad.setPart(stelle,((funktion(x) - funktion(tmp)) / h));
				x.setPart(stelle, x.getPart(stelle) - h);
	}


	return grad;
}

int main()
{
	double lambda = 0.1;
	CMyVektor vektor2;
	vektor2.setDimension(3);
	vektor2.setPart(0, 0.0);
	vektor2.setPart(1, 0.0);
	vektor2.setPart(2, 0.0);
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
			vektor2.print();
			cout << "   lambda = " << lambda << endl;
			cout << "   f(x) = " << funktion(vektor2) << endl;
			cout << "   grad f(x) = ";
			gradient(vektor2, funktion).print();
			cout << "   ||grad f(x)|| = " << gradient(vektor2, funktion).length() << endl << endl;
			break;
		}
		else
		{
			//Schrittfolge
			cout << "Schritt: " << i << endl;
			cout << "   x = ";
			vektor2.print();
			cout << "   lambda = " << lambda << endl;
			cout << "   f(x) = " << funktion(vektor2) << endl;
			cout << "   grad f(x) = ";
			gradient(vektor2, funktion).print();
			cout << "   ||grad f(x)|| = " << gradient(vektor2, funktion).length() << endl << endl;
		}

		xneu = vektor2 + lambda * gradient(vektor2, funktion);
		cout << "   x_neu = ";
		xneu.print();
		cout << "   f(x_neu) = " << funktion(xneu) << endl << endl;

		// liegt höher => richtiger weg
		if (funktion(xneu) > funktion(vektor2))
		{
			// teste doppelte Schrittweite
			cout << "   Test mit doppelter Schrittweite (lambda = " << lambda * 2.0 << "): " << endl;
			xtest = vektor2 + 2.0 * lambda * gradient(vektor2, funktion);
			cout << "   x_test = ";
			xtest.print();
			cout << "   f(x_test) = " << funktion(xtest) << endl;
			if (funktion(xtest) > funktion(xneu)) // liegt höher
			{
				// test wird übernommen und lambda verdoppelt
				vektor2 = xtest;
				lambda *= 2.0;
			
			}
			else // nicht höher
			{
				// xneu ist das neue x und lambda bleibt gleich
				vektor2 = xneu; // weiter mit punkt da verdopplung zu groß
				cout << " bleibe bei alter Schrittweite!" << endl << endl;
			}
		}
		else //  xneu <= vektor2 ;neue pos ist kleiner= alterwert
		{
			// zu weit halbieren
			while (!(funktion(xneu) > funktion(vektor2)))
			{
				cout << "   Halbiere Schrittweite (lambda = " << lambda << "): " << endl;
				lambda /= 2.0;
				xneu = vektor2 + lambda * gradient(vektor2, funktion);
				cout << "   x_neu = ";
				xneu.print();
				cout << "   f(x_neu) = " << funktion(xneu) << endl << endl;
			}
			vektor2 = xneu;// 
		}

		// 2te Absprungbedingung
		if (gradient(xneu, funktion).length() < 1e-5 )
		{
			cout << "Ende wegen ||grad f(x)|| <  1e-5 bei: " << endl;
			cout << "   x = ";
			vektor2.print();
			cout << "   lambda = " << lambda << endl;
			cout << "   f(x) = " << funktion(vektor2) << endl;
			cout << "   grad f(x) = ";
			gradient(vektor2, funktion).print();
		
			cout << "   ||grad f(x)|| = " << gradient(vektor2, funktion).length() << endl;

			break;
		}
	}
	system("Pause");
	return 0;
}