#pragma once

#include <fstream>
#include <iostream>
#include "Pracownik.h"
#include "Kierownik.h"

class ListaPracownikow {
	private:
		Pracownik* m_pPoczatek;
		int m_nLiczbaPracownikow;
    void WyswietlMenu();

	public:
		ListaPracownikow();
		~ListaPracownikow();

		void Dodaj(const Pracownik& p);
		void Usun(const Pracownik& wzorzec);
		void WypiszPracownikow() const;
		const Pracownik* Szukaj(const char* nazwisko, const char* imie);

    void Interfejs();
    void ZapiszDoPliku(const char* filename);
    void WczytajZPliku(const char* filename);
};
