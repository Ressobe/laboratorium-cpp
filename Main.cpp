#include <iostream>
#include "./pracownik/ListaPracownikow.h"
#include "./pracownik/Pracownik.h"


void WyswietlMenu() {
    std::cout << "Menu:\n";
    std::cout << "a) Dodaj pracownika\n";
    std::cout << "b) Usun pracownika\n";
    std::cout << "c) Wypisz liste pracownikow\n";
    std::cout << "d) Znajdz pracownika po nazwisku i imieniu\n";
    std::cout << "e) Znajdz pracownika po dacie urodzenia\n";
    std::cout << "q) Zakoncz program\n";
}


int main() {
    ListaPracownikow lista;

    char opcja;

    do {
        WyswietlMenu();
        std::cout << "Wybierz opcje: ";
        std::cin >> opcja;

        switch (opcja) {
            case 'a': {
                // Dodaj pracownika
                Pracownik nowyPracownik;
                nowyPracownik.Wpisz();
                lista.Dodaj(nowyPracownik);
                break;
            }
            case 'b': {
                // Usun pracownika
                Pracownik wzorzec;
                wzorzec.Wpisz();
                lista.Usun(wzorzec);
                break;
            }
            case 'c':
                // Wypisz liste pracownikow
                lista.WypiszPracownikow();
                break;
            case 'd': {
                // Znajdz pracownika po nazwisku i imieniu
                char nazwisko[40], imie[40];
                std::cout << "Podaj nazwisko: ";
                std::cin >> nazwisko;
                std::cout << "Podaj imie: ";
                std::cin >> imie;

                const Pracownik* znaleziony = lista.Szukaj(nazwisko, imie);

                if (znaleziony != nullptr) {
                    std::cout << "Znaleziono pracownika:\n";
                    znaleziony->Wypisz();
                } else {
                    std::cout << "Pracownik nie znaleziony.\n";
                }

                break;
            }
            case 'q':
                // Zakoncz program
                std::cout << "Koniec programu.\n";
                break;
            default:
                std::cout << "Niepoprawna opcja.\n";
        }

    } while (opcja != 'q');



  return 0;
}
