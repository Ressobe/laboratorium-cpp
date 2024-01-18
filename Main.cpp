#include "./pracownik/ListaPracownikow.h"
#include "pracownik/Pracownik.h"

void testData();
void testNapis();
void testPracownik();
void testKierownik();
void testListaPracownikow();

int main() {
    return 0;
}

void testData() {
    Data data1(15, 7, 2022);

    std::cout << "Data1: ";
    data1.Wypisz();
    std::cout << std::endl;

    data1.Ustaw(31, 12, 2022);

    std::cout << "Data1 po aktualizacji: ";
    data1.Wypisz();
    std::cout << std::endl;

    std::cout << "Data1 po aktualizacji (operator <<): " << data1 << std::endl;

    Data data2;

    std::cout << "Podaj nową datę (dzien miesiac rok): ";
    std::cin >> data2;

    int wynikPorownania = data1.Porownaj(data2);

    if (wynikPorownania == 0) {
        std::cout << "Obiekty Data1 i Data2 są identyczne." << std::endl;
    } else if (wynikPorownania == 1) {
        std::cout << "Data1 jest późniejsza niż Data2." << std::endl;
    } else {
        std::cout << "Data1 jest wcześniejsza niż Data2." << std::endl;
    }
}

void testNapis() {
    Napis napis1("Hello, World!");
    std::cout << "Napis1: ";
    napis1.Wypisz();
    std::cout << std::endl;

    napis1.Ustaw("New Text");
    std::cout << "Napis1 po aktualizacji: ";
    napis1.Wypisz();
    std::cout << std::endl;

    std::cout << "Napis1 po aktualizacji (operator <<): " << napis1 << std::endl;

    Napis napis2;
    std::cout << "Podaj nowy napis: ";
    std::cin >> napis2;

    if (napis1 == napis2) {
        std::cout << "Napis1 i Napis2 są identyczne." << std::endl;
    } else {
        std::cout << "Napis1 i Napis2 są różne." << std::endl;
    }
}

void testPracownik() {
    Pracownik pracownik1("John", "Doe", 15, 7, 1985);
    std::cout << "Pracownik1: ";
    pracownik1.Wypisz();
    std::cout << std::endl;

    pracownik1.Imie("Jane");
    pracownik1.Nazwisko("Smith");
    pracownik1.DataUrodzenia(25, 12, 1990);

    std::cout << "Pracownik1 po aktualizacji: ";
    pracownik1.Wypisz();
    std::cout << std::endl;

    std::cout << "Pracownik1 po aktualizacji (operator <<): " << pracownik1 << std::endl;

    Pracownik pracownik2;
    std::cout << "Podaj dane pracownika (imię, nazwisko, data urodzenia): ";
    std::cin >> pracownik2;

    if (pracownik1 == pracownik2) {
        std::cout << "Pracownik1 i Pracownik2 są identyczni." << std::endl;
    } else {
        std::cout << "Pracownik1 i Pracownik2 są różni." << std::endl;
    }
}

void testKierownik() {
    Kierownik kierownik1("Zarzad", 10, "Adam", "Nowak", 5, 10, 1980);
    std::cout << "Kierownik1: ";
    kierownik1.WypiszDane();
    std::cout << std::endl;

    kierownik1.Imie("Anna");
    kierownik1.Nazwisko("Kowalska");
    kierownik1.DataUrodzenia(15, 8, 1992);
    kierownik1.Wpisz();

    std::cout << "Kierownik1 po aktualizacji: ";
    kierownik1.WypiszDane();
    std::cout << std::endl;

    std::cout << "Kierownik1 po aktualizacji (operator <<): " << kierownik1 << std::endl;

    Kierownik kierownik2;
    std::cout << "Podaj dane kierownika (imię, nazwisko, data urodzenia): ";
    std::cin >> kierownik2;

    if (kierownik1 == kierownik2) {
        std::cout << "Kierownik1 i Kierownik2 są identyczni." << std::endl;
    } else {
        std::cout << "Kierownik1 i Kierownik2 są różni." << std::endl;
    }
}

void testListaPracownikow() {
    ListaPracownikow lista;

    Pracownik pracownik1("Jan", "Kowalski", 10, 5, 1990);
    Pracownik pracownik2("Anna", "Nowak", 15, 8, 1985);
    Kierownik kierownik1("Zarzad", 5, "Piotr", "Mazurek", 3, 12, 1978);
    
    lista.Dodaj(pracownik1);
    lista.Dodaj(pracownik2);
    lista.Dodaj(kierownik1);

    std::cout << "Lista po dodaniu pracownikow:" << std::endl;
    lista.WypiszPracownikow();
    
    Pracownik wzorzec("Anna", "Nowak", 15, 8, 1985);
    lista.Usun(wzorzec);

    std::cout << "Lista po usunieciu pracownika:" << std::endl;
    lista.WypiszPracownikow();
    
    const Pracownik* znaleziony = lista.Szukaj("Kowalski", "Jan");
    
    if (znaleziony != nullptr) {
        std::cout << "Znaleziono pracownika:" << std::endl;
        std::cout << *znaleziony;
    } else {
        std::cout << "Pracownik nie znaleziony." << std::endl;
    }

    lista.ZapiszDoPliku("pracownicy.txt");
    ListaPracownikow nowaLista;
    nowaLista.WczytajZPliku("pracownicy.txt");

    std::cout << "Nowa lista wczytana z pliku:" << std::endl;
    nowaLista.WypiszPracownikow();
}
