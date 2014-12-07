#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <cmath>
#include <stdio.h>
#include <fstream>
using namespace std;
class menu;
class wzor;
class dane;

class menu{
	
public:
	unsigned int a;
	void wyswietl(){
		cout<<"____________________________________________________________________________\n"<<endl;
		cout<<"\t\t\t\tMENU: "<<endl<<endl;
		cout << "\t\t\t1.Licz" << endl;
		cout << "\t\t\t2.Wyswietl wzory" << endl;
		cout << "\t\t\t3.Zamknij" << endl;
	}
	unsigned int wybierz(){
		cout << "\nWybierz z menu, jaka operacje chcesz wykonac: ";
		cin >> this->a;
		while((this->a)<1 || (this->a)>3){
			cout << "\nError: Wprowadz cyfre z zakresu 1-3: ";
			cin >> this->a;
		}
		return this->a;
	}
};
void logo(){
	cout << "\t\t-----------------------------------------" << endl;
	cout << "\t\t\tProsty kalkulator fizyczny" << endl;
	cout << "\t\t\t                __		\n";
	cout << "\t\t\t       ,      ,' e`-o	\n";
	cout << "\t\t\t      ((     (  | _,'	\n";
	cout << "\t\t\t       \\~--' `-'/		\n";
	cout << "\t\t\t       (        /		\n";
	cout << "\t\t\t       /) .___. )		\n";
	cout << "\t\t\t      (( (   (( (	  	\n";
	cout << "\t\t\t       ``-'   ``-'		\n";
	cout << "\t\t-----------------------------------------" << endl << endl;
}
class dane{
public:
	float d1;
	float d2;
public:
	dane wprowadz(int nr){
		if (nr == 1){
			cout << "\nPodaj wartosc pracy: ";
			cin >> this->d1;
			cout << "\nPodaj wartosc czasu: ";
			cin >> this->d2;
			if(this->d2==0)
			{
				cout<<"\nNie mozesz dzielic przez 0!\n \nPodaj wartosc czasu jeszcze raz: "<<endl;
				cin >> this->d2;
			}
			while (this->d2 < 0){
				cout << "\nCzas nie moze byc wartoscia ujemna!"<<endl;
				cout<<"\nPodaj wartosc czasu jeszcze raz: "<<endl;
				cin >> this->d2;
			}
		}
		if (nr == 2){
			cout << "\nPodaj wartosc masy: " << endl;
			cin >> this->d1;
			while (this->d1 < 0)
			{
				cout << "\nMasa nie moze byc ujemna!\n\nPodaj wartosc masy jeszcze raz: ";
				cin >> this->d1;
			}
			cout << "\nPodaj przyspieszenie: ";
			cin >> this->d2;
		}
		if (nr == 3){
			cout << "\nPodaj wartosc drogi: ";
			cin >> this->d1;
			while (this->d1<0)
			{
				cout << "\nDroga nie moze byc ujemna!\n\nPodaj wartosc drogi jeszcze raz: ";
				cin >> this->d1;
			}
			cout << "\nPodaj wartosc czasu: " << endl;
			cin >> this->d2;
			if(this->d2==0)
			{
				cout<<"\nNie mozesz dzielic przez 0!\n\nPodaj wartosc czasu jeszcze raz: ";
				cin >> this->d2;
			}
			while (this->d2 < 0)
			{
				cout << "\nCzas nie moze byc ujemny!\n\nPodaj wartosc czasu jeszcze raz: ";
				cin >> this->d2;
			}
		}
		if (nr == 4){
			cout << "\nPodaj wartosc sily: " << endl;
			cin >> this->d1;
			cout << "\nPodaj wartosc przesuniecia: " << endl;
			cin >> this->d2;
			while (this->d2<0)
			{
				cout << "\nPrzesuniecie nie moze byc ujemne!\n\nPodaj wartosc przesuniecia jeszcze raz: " << endl;
				cin >> this->d2;
			}
		}
		if (nr == 5 || nr == 6){
			cout << "\nPodaj wartosc masy: " << endl;
			cin >> this->d1;
			while (this->d1 < 0)
			{
				cout << "\nMasa nie moze byc ujemna!\n\nPodaj wartosc masy jeszcze raz: " << endl;
				cin >> this->d1;
			}
			cout << "\nPodaj wartosc predkosci: " << endl;
			cin >> this->d2;
			while (this->d2<0)
			{
				cout << "\nPredkosc nie moze byc ujemna!\n\nPodaj wartosc predkosci jeszcze raz: " << endl;
				cin >> this->d2;
			}
		}
		return *this;
	}
	void wyswietl_dane(){
		cout << "\n\tPierwsza wartosc danej: " << this->d1 << endl;
		cout << "\n\tDruga wartosc danej: " << this->d2 << endl;
	}
};
class wzor: public dane{
	
public:
	float znajdz_licz();
	unsigned int nr_s;
public:
	
	unsigned int wybierz_nrwzoru()
	{
		cout << "\nWybierz  z listy wielkoc fizyczna ktora chcesz policzyc:" << endl << endl;
		cout << "\t1.P-moc\t\t 2.F- sila\t 3.v-predkosc " << endl << endl;
		cout << "\t4.W-praca\t 5.p-ped\t 6.Ek-energia kinetyczna " << endl << endl;
		cin >> nr_s;
		
		while (nr_s<1 || nr_s>6){
			cout << "Error: ";
			cout << "Podaj numer z zakresu 1-6: ";
				cin >> this->nr_s;
		}
		return this->nr_s;
	}
	float znajdz_licz(dane a){
		float w;
		if (nr_s == 1 || nr_s==3){
			w = a.d1 / a.d2;
		}
		if (nr_s == 2 || nr_s == 4 || nr_s == 5){
			w = a.d1 *a.d2;
		}
		if (nr_s== 6){
			w = (a.d1 *pow(a.d2, 2)) / 2;
		}
		return w;
	}

};

class rezultat: wzor{	
public:
	float wynik;
	float znajdz_licz(dane a);
public:
	void zapisz(wzor w)
	{ 
		fstream plik("wyniki.txt", ios::app);
		if (w.nr_s == 1){ plik << "P="; } 
		if (w.nr_s == 2){ plik << "F="; } 
		if (w.nr_s == 3){ plik << "v="; } 
		if (w.nr_s == 4){ plik << "W="; } 
		if (w.nr_s == 5){ plik << "p="; } 
		if (w.nr_s == 6){ plik << "Ek="; }
		plik<<this->wynik<< endl; 
		plik.close(); 
	
	}
	rezultat(wzor w, dane a)
	{
		wynik = w.znajdz_licz(a);
	}

};

class druk: rezultat
{ 
	public: 
	void drukuj(rezultat wy){ } 
};
	
int main()
{
	logo();
	while(1){
	menu pierwsze;
	pierwsze.wyswietl();
	int i;
	i=pierwsze.wybierz();
	int numer = 0;
	cout << "\nWybrales operacje numer:   " << i<< endl;
	
	if(i==1)
	{
	unsigned int n = 0;
		wzor w;
		n = w.wybierz_nrwzoru();
		dane zmienne;
		zmienne.wprowadz(n);
		zmienne.wyswietl_dane();
		rezultat wyn(w, zmienne);
		cout << "\n\n\t Wynik:" << wyn.wynik;
		wyn.zapisz(w);
		cout<< endl << endl;
		cout<<"\nCzy chcesz wydrukowac wynik?"<<endl;
		cout<<"\nWybierz opcje T, jezeli chcesz wydrukowac lub dowolny klawisz, jezeli nie chcesz wydrukowac"<<endl;
		char a;
		cin>>a;
		if(a=='T')
		{
			cout<<"\nDrukuje wynik"<<endl;
		}
		else if(a=='N')
		{
			cout<<"\nWybrales opcje pominiecia drukowania"<<endl;
		}

	}

	else if(i==2)
	{
		cout<<"\nDostepne wzory:\n"<<endl;
		cout<<" \t\t\tP=W/t    F=m*a    v=s/t "<<endl;
		cout<<" \n\t\t\tW=F*s    p=m*v    Ek=(m*v*v)/2 \n"<<endl;
		
	}
	
	else if(i==3)
	{
		cout<<"\n\t\t************************************************************"<<endl;
		cout<<"\t\t*                                                          *\n";
		cout<<"\t\t*";
		cout<<"\tDziekujemy za skorzystanie z naszego programu      *"<<endl;
		cout<<"\t\t*                                                          *\n";
		cout<<"\t\t*                                                          *";
		cout<<"\t\t\t*";
		cout << "\t\tNacisnij enter, zeby zakonczyc...          *"<<endl;
		cout<<"\t\t*                                                          *\n";
		cout<<"\t\t************************************************************"<<endl;
		cin.get();
		break;
	}
	}
	system("PAUSE");
	return EXIT_SUCCESS;
}
