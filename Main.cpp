#include <iostream>
#include "napis/Napis.h"
#include "pracownik/Pracownik.h"
#include "data/Data.h"


void testPracownik() {
    Pracownik pracownik1("Anna", "Kowalska", 15, 5, 1990);
    Pracownik pracownik2("Jan", "Nowak", 20, 8, 1985);

    std::cout << "Informacje o pracownikach:" << std::endl;
    pracownik1.Wypisz();
    pracownik2.Wypisz();
    std::cout << std::endl;

    // konstruktor kopiujacy
    Pracownik pracownik3 = pracownik1;
    std::cout << "Pracownik 3 (skopiowany z pracownika 1):" << std::endl;
    pracownik3.Wypisz();
    std::cout << std::endl;

    // przeciazenie operatora przypisania
    Pracownik pracownik4("Adam", "Mickiewicz", 1, 12, 1810);
    pracownik4 = pracownik2;
    std::cout << "Pracownik 4 (przypisany z pracownika 2):" << std::endl;
    pracownik4.Wypisz();
    std::cout << std::endl;

    int porownanie = pracownik1.Porownaj(pracownik2);
    if (porownanie == 0) {
        std::cout << "Pracownik 1 jest identyczny z pracownikiem 2." << std::endl;
    } else if (porownanie > 0) {
        std::cout << "Pracownik 1 jest pozniejszy niz pracownik 2." << std::endl;
    } else {
        std::cout << "Pracownik 1 jest wczesniejszy niz pracownik 2." << std::endl;
    }
}


//void WyswietlMenu() {
//    std::cout << "Menu:\n";
//    std::cout << "a) Dodaj pracownika\n";
//    std::cout << "b) Usun pracownika\n";
//    std::cout << "c) Wypisz liste pracownikow\n";
//    std::cout << "d) Znajdz pracownika po nazwisku i imieniu\n";
//    std::cout << "q) Zakoncz program\n";
//}
//
//void InterfejsDoListy() {
//    ListaPracownikow lista;
//    char opcja;
//
//    do {
//        WyswietlMenu();
//        std::cout << "Wybierz opcje: ";
//        std::cin >> opcja;
//
//        switch (opcja) {
//            case 'a': {
//                Pracownik nowyPracownik;
//                nowyPracownik.Wpisz();
//                lista.Dodaj(nowyPracownik);
//                break;
//            }
//            case 'b': {
//                Pracownik wzorzec;
//                wzorzec.Wpisz();
//                lista.Usun(wzorzec);
//                break;
//            }
//            case 'c':
//                lista.WypiszPracownikow();
//                break;
//            case 'd': {
//                char nazwisko[40], imie[40];
//                std::cout << "Podaj nazwisko: ";
//                std::cin >> nazwisko;
//                std::cout << "Podaj imie: ";
//                std::cin >> imie;
//
//                const Pracownik* znaleziony = lista.Szukaj(nazwisko, imie);
//
//                if (znaleziony != nullptr) {
//                    std::cout << "Znaleziono pracownika:\n";
//                    znaleziony->Wypisz();
//                } else {
//                    std::cout << "Pracownik nie znaleziony.\n";
//                }
//
//                break;
//            }
//            case 'q':
//                std::cout << "Koniec programu.\n";
//                break;
//            default:
//                std::cout << "Niepoprawna opcja.\n";
//        }
//
//    } while (opcja != 'q');
//}



int main() {

 /*   Data data1(12, 11, 2002);
    Data data2;*/

    Napis napis1("nowy napisdksldkls");
    Napis napis2("nowy napis");

  /*  std::cout << data1;

    std::cin >> data2;

    std::cout << data2;*/

    bool s = napis1 == napis2;

    std::cout << s << std::endl;

    std::cout << napis2 << std::endl;

    std::cin >> napis1;

    std::cout << napis2;

	return 0;
}
