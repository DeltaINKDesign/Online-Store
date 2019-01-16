#include <iostream>
#include <vector>
#include <cstdlib>
#include <string>

using namespace std;

double saldo;
int zabezpieczenie=0;  //zabezpieczenie zeby nie wyswietlac numeru identyfikcji podczas ogladania koszyka
double wydatki;  //cena naszego koszyka

struct produkt  //struktura produktu
{
	string name;
	float  price;
	int amount;	
};

void wysljeden(produkt pierwszy) //wyswietanie jednego elementu z tablicy 
{
	
	cout<<"Nazwa: "<<pierwszy.name<<endl;
	cout<<"Cena: "<<pierwszy.price<<endl;
	cout<<"Ilosc: "<<pierwszy.amount<<endl;	
				
}

void wyswietlanieall(vector <produkt> all )  //wyswietlenie wszystich produktow
{
	for(int m=0;m<all.size();m++)
	{
		if(zabezpieczenie==1)
		{
			cout<<"NUMER IDENTYFIKACJI: "<<m+1<<". "<<endl;
		}
		
		wysljeden(all[m]);
		cout<<endl;
	}	
		
}

void dostepnabaza(vector <produkt> baza)  //wyswietlenie dostepnych produktow w sklepie
{
	for(int m=0;m<baza.size();m++)
	{
		if(baza[m].amount>0)
		{
			cout<<"NUMER IDENTYFIKACJI: "<<m+1<<". "<<endl;
			wysljeden(baza[m]);
			cout<<endl;
		}
	}
}

void calasuma(vector <produkt> koszyk)   //zliczanie ceny koszyka
{
	float suma; 	
	for(int j=0;j<koszyk.size();j++)
		{
			suma=suma+(koszyk[j].price*koszyk[j].amount);
		}
	cout<<"Kwota za caly koszyk: "<<suma<<endl;
	wydatki=suma;
}

int main()
{	
							
	vector <produkt> baza;
	vector <produkt> koszyk;
	produkt p;
		produkt produkt1 ={"Laptop",1500.69,0};	//lista produktow na start w sklepie
		produkt produkt2 ={"Myszka",30,20};
		produkt produkt3 ={"Klawiatura",120.50,5};
		produkt produkt4 ={"Monitor",300,15};
		produkt produkt5 ={"Gra",20,20}; 
		baza.push_back(produkt1);
		baza.push_back(produkt2);
		baza.push_back(produkt3); 
		baza.push_back(produkt4);
		baza.push_back(produkt5);
		int wyborwmenu;
	do
	{
		cout<<"---MENU---"<<endl;
		cout<<"1. Podaj saldo konta\n2. Dodaj produkt do koszyka\n3. Wyswietl koszyk\n4. Wyswietl stan konta\n5. Kup\n6. Wyswietl najdrozsze\n8. Dodaj produkt\n9. Wyswietl produkty\n10. Wyswietl dostepne produkty\n";
		cin>>wyborwmenu;
		switch(wyborwmenu)
		{
			case 1:
				{	//podawanie salda
					cout<<"Podaj swoje saldo:\n";  
					cin>>saldo;	
					system("cls");
					break;
				}
			case 2:
				{
					//dodawanie do koszyka
					system("cls");
					int zmienna1=0;
					int zmienna2=0;
					int zapas=0;
					cout<<"Podaj numer produktu: "<<endl;
					cin>>zmienna1;
					zmienna1=zmienna1-1;
					if (zmienna1<baza.size())
					{
						cout<<"Podaj ilosc: "<<endl;
						cin>>zmienna2;
						zapas=baza[zmienna1].amount;	//notatnik still lepszy
						if (zmienna2<=zapas)
						{
							baza[zmienna1].amount=zmienna2;
							koszyk.push_back(baza[zmienna1]);
							baza[zmienna1].amount=zapas;	
							
						}
						else
						{
							cout<<"Nie ma tyle produktu!"<<endl;
						}
					}
					else
					{
						cout<<"Nie istnieje taki produkt";
					}	
				break;
				}
			case 3:
				{
					//wyswietlanie koszyka
					if(koszyk.size()==0)
					{
						cout<<"Twoj koszyk jest pusty!"<<endl;
						cout<<endl;
					
					}
					else
					{
					wyswietlanieall(koszyk);
					calasuma(koszyk);
					}
					break;
				}
			case 4:
				{
					//wyswietlanie aktualnego salda
					system("cls");
					cout<<"Aktualne saldo konta: "<<saldo<<endl;
					cout<<endl;
					break;
				}
			case 5:
				{
					//zakupy
					system("cls");
					calasuma(koszyk);
						if(saldo>=wydatki)
						{
							for(int q=0;q<koszyk.size();q++)
							{
								for(int e=0;e<baza.size();e++)
								{
									if(koszyk[q].name==baza[e].name)
									{
										baza[e].amount=baza[e].amount-koszyk[q].amount;
									}	
								}
							}
						saldo=saldo-wydatki;		//saldo po zakupie
						cout<<"Koszyk kupiony, aktualne saldo wynosi : "<<saldo<<endl;
						}
						else		
						{
							cout<<"Niestety nie posiadasz wystarczajacych srodkow !"<<endl;	
						}
					koszyk.clear();
					break;
				}
				
			case 6: 
				{
					
					//wyswietlanie najdrozsze
					system("cls");
					vector <int> najwieksza;
					double najdrozsza=koszyk[0].price*koszyk[0].amount;
					for(int s=0; s<=koszyk.size()-1; s++)
					{
						if(najdrozsza<(koszyk[s].price*koszyk[s].amount))
						najdrozsza=(koszyk[s].price*koszyk[s].amount);
					}		 
					for(int a=0;a<=koszyk.size()-1;a++)
					{
						if(najdrozsza==(koszyk[a].price*koszyk[a].amount))
						{
							najwieksza.push_back(a);
						}
					}
					
					cout<<"Najdrozsze: "<<endl;
					for(int b=0;b<=najwieksza.size()-1;b++)
					{
						cout<<koszyk[najwieksza[b]].name<<" "<<(koszyk[najwieksza[b]].price*koszyk[najwieksza[b]].amount)<<" "<<endl;
					}
					break;
				}
					
			case 8:
				{
				//dodawanie produktu do bazy
				system("cls");
				cout<<"Dodaj produkt do bazy:"<<endl;
				cout<<"Podaj nazwe: "<<endl;
				cin>>p.name;
				cout<<"Podaj cene: "<<endl;
				cin>>p.price;
				cout<<"Podaj ilosc: "<<endl;
				cin>>p.amount;
				baza.push_back(p);
				break;
				}
			case 9:
				{
					//wyswietla wszytskie produkty
					system("cls");
					cout<<endl;
					cout<<"Wyswietl produkty"<<endl;
					cout<<endl;
					zabezpieczenie++;
					wyswietlanieall(baza);
					zabezpieczenie--;
					break;
				}
			case 10:
				{
					//wyswietla dostepne produkty
					system("cls");
					cout<<"Wyswietl dostepne produkty"<<endl;
					dostepnabaza(baza);
					break;
				}	
		}
	}
	while((wyborwmenu<=10) && (wyborwmenu!=7) );
	return 0;
}
