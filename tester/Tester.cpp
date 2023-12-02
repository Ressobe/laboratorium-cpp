#include "Tester.h"


void Tester::runTests() {
  testData();
  testNapis();
  testPracownik();
}


void Tester::testData() {
    // Test 1: Utwórz obiekt daty i wypisz go
    Data data1;
    data1.Wypisz();

    // Test 2: Wprowadź datę od użytkownika
    Data data2;
    data2.Wpisz();
    data2.Wypisz();  // Wypisz wprowadzoną datę

    // Test 3: Ustaw datę na niemożliwą (np. 0-0-0) i sprawdź, czy zostanie skorygowana
    Data data3;
    data3.Ustaw(0, 0, 0);
    data3.Wypisz();  // Powinno być skorygowane na 1-1-0

    // Test 4: Porównaj daty
    Data data4;
    data4.Ustaw(1, 1, 2022);

    if (data2.Porownaj(data4) == 0) {
        std::cout << "Data2 jest taka sama jak Data4.\n";
    } else if (data2.Porownaj(data4) == 1) {
        std::cout << "Data2 jest późniejsza niż Data4.\n";
    } else {
        std::cout << "Data2 jest wcześniejsza niż Data4.\n";
    }

    // Dodatkowy test: Pobierz i wyświetl dzień, miesiąc i rok z obiektu data2
    std::cout << "Dzien: " << data2.Dzien() << std::endl;
    std::cout << "Miesiac: " << data2.Miesiac() << std::endl;
    std::cout << "Rok: " << data2.Rok() << std::endl;
}


void Tester::testNapis() {
    // Test 1: Utwórz obiekt napisu, wypisz go i sprawdź wartość
    Napis napis1;
    napis1.Wypisz();
    std::cout << "Wartosc: " << napis1.Zwroc() << std::endl;

    // Test 2: Ustaw nowy napis i sprawdź wartość
    const char* nowyNapis = "Nowy Napis";
    napis1.Ustaw(nowyNapis);
    std::cout << "Nowa wartosc: " << napis1.Zwroc() << std::endl;

    // Test 3: Wprowadź napis od użytkownika
    Napis napis2;
    std::cout << "Podaj nowy napis: ";
    napis2.Wpisz();
    std::cout << "Wprowadzony napis: " << napis2.Zwroc() << std::endl;

    // Test 4: Sprawdź porównanie napisów
    const char* porownywanyNapis = "Inny Napis";
    int wynikPorownania = napis2.SprawdzNapis(porownywanyNapis);

    if (wynikPorownania == 0) {
        std::cout << "Napis2 jest identyczny z porownywanym napisem.\n";
    } else if (wynikPorownania > 0) {
        std::cout << "Napis2 jest alfabetycznie dalej niż porownywany napis.\n";
    } else {
        std::cout << "Napis2 jest alfabetycznie wcześniej niż porownywany napis.\n";
    }
}


void Tester::testPracownik() {
    // Test 1: Utwórz obiekt pracownika, wypisz go i sprawdź wartość
    Pracownik pracownik1;
    pracownik1.Wypisz();
    std::cout << "Wartosc: " << pracownik1.Imie() << " " << pracownik1.Nazwisko() << " ";
    std::cout << std::endl;

    // Test 2: Ustaw nowe wartości dla pracownika i sprawdź wartość
    pracownik1.Imie("Jan");
    pracownik1.Nazwisko("Kowalski");
    pracownik1.DataUrodzenia(15, 5, 1990);
    std::cout << "Nowa wartosc: " << pracownik1.Imie() << " " << pracownik1.Nazwisko() << " ";
    std::cout << std::endl;

    // Test 3: Wprowadź dane od użytkownika dla pracownika i wypisz
    Pracownik pracownik2;
    std::cout << "Podaj dane pracownika: " << std::endl;
    pracownik2.Wpisz();
    std::cout << "Wprowadzone dane pracownika: ";
    pracownik2.Wypisz();
    std::cout << std::endl;

    // Test 4: Porównaj pracowników
    int wynikPorownania = pracownik1.Porownaj(pracownik2);

    if (wynikPorownania == 0) {
        std::cout << "Oba obiekty Pracownik są identyczne.\n";
    } else if (wynikPorownania > 0) {
        std::cout << "Obiekt pracownik1 jest alfabetycznie dalej niż pracownik2.\n";
    } else {
        std::cout << "Obiekt pracownik1 jest alfabetycznie wcześniej niż pracownik2.\n";
    }
}
