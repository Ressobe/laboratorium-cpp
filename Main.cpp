#include "./pracownik/ListaPracownikow.h"
#include "pracownik/Pracownik.h"

void testData() {
  Data dzisiaj = Data(18, 1, 2024);
  Data wczoraj = Data(17, 1, 2024);

  Data* d = new Data(2, 3, 2003);
 
  dzisiaj.Wypisz();

  std::cout << std::endl;

  std::cout << dzisiaj.Porownaj(*d) << std::endl;
  std::cout << d->Porownaj(dzisiaj) << std::endl;
  
  std::cout << d->Rok() << std::endl;
  std::cout << d->Miesiac() << std::endl;
  std::cout << d->Dzien() << std::endl;

  wczoraj.Ustaw(18, 1, 2024);

  wczoraj.Wypisz();

  delete d;
}

void testNapis() {
  Napis napisek = Napis("ooooo");
  std::cout << napisek.SprawdzNapis("ooooo") << std::endl;
  napisek.Wypisz();
  std::cout << std::endl;
  napisek.Ustaw("aaaaaaaaaabbbx");
  napisek.Wypisz();
}

void testPracownik() {
  Pracownik p1 = Pracownik("b", "s", 11, 12, 2002);
  Pracownik p2 = Pracownik("b", "s", 11, 12, 2002);

}

void testListaPracownikow() {
    ListaPracownikow pracownicy;

    Pracownik p1 = Pracownik("x1", "x12", 11, 12, 2002);
    Pracownik p2 = Pracownik("x2", "x23", 26, 8, 2003);
    Pracownik p3 = Pracownik("x3", "x34", 26, 8, 2003);

    Pracownik* kopia_pierwszego = p2.KopiaObiektu();


    pracownicy.Dodaj(p2);
    pracownicy.Dodaj(p3);
    pracownicy.Dodaj(p1);
    
    pracownicy.WypiszPracownikow();
    pracownicy.Usun(*kopia_pierwszego);
    pracownicy.WypiszPracownikow();
}

int main() {
    testNapis() ;
    return 0;
}
