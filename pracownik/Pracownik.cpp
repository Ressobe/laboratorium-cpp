#include "Pracownik.h"


int Pracownik::s_nLiczbaPracownikow = 0;


Pracownik::Pracownik(const char* im, const char* naz, int dzien, int miesiac, int rok) 
	: m_Imie(im), m_Nazwisko(naz), m_DataUrodzenia(dzien, miesiac, rok), m_nIDZatrudnienia(++s_nLiczbaPracownikow) {}


Pracownik::Pracownik(const Pracownik& wzor) : m_nIDZatrudnienia(++s_nLiczbaPracownikow) {
	m_Imie.Ustaw(wzor.Imie());
	m_Nazwisko.Ustaw(wzor.Nazwisko());
}


Pracownik& Pracownik::operator=(const Pracownik& wzor) {
    if (this != &wzor) {
        this->m_Imie.Ustaw(wzor.Imie());
        this->m_Nazwisko.Ustaw(wzor.Nazwisko());
    }

	return *this;
}

int Pracownik::Porownaj(const Pracownik& wzorzec) const {
    int porownanieImie = this->m_Imie.SprawdzNapis(wzorzec.Imie());
    int porownanieNazwisko = this->m_Nazwisko.SprawdzNapis(wzorzec.Nazwisko());
    int porownanieData = this->m_DataUrodzenia.Porownaj(wzorzec.m_DataUrodzenia);

    if (porownanieImie == 0 && porownanieNazwisko == 0 && porownanieData == 0) {
        return 0;
    } else if (porownanieImie > 0 || porownanieNazwisko > 0 || porownanieData > 0) {
        return 1;
    } else {
        return -1;
    }
}


const char* Pracownik::Imie() const {
	return this->m_Imie.Zwroc();
}


void Pracownik::Imie(const char* nowe_imie) {
	this->m_Imie.Ustaw(nowe_imie);
}


const char* Pracownik::Nazwisko() const {
	return this->m_Nazwisko.Zwroc();
}


void Pracownik::Nazwisko(const char* nowe_nazwisko) {
	this->m_Nazwisko.Ustaw(nowe_nazwisko);
}


void Pracownik::DataUrodzenia(int nowy_dzien, int nowy_miesiac, int nowy_rok) {
	this->m_DataUrodzenia.Ustaw(nowy_dzien, nowy_miesiac, nowy_rok);
}


void Pracownik::Wypisz() const {
	std::cout << this->m_Imie.Zwroc() << "		" << this->m_Nazwisko.Zwroc() << "		";
	this->m_DataUrodzenia.Wypisz();    
	std::cout << std::endl;
}


void Pracownik::Wpisz() {
  std::cin.ignore();

  std::cout << "Dane pracownika" << std::endl;
  std::cout << "-------------------------" << std::endl;
  std::cout << "\nPodaj imie: ";
  this->m_Imie.Wpisz();

  std::cout << "\nPodaj nazwisko: ";
  this->m_Nazwisko.Wpisz();

  std::cout << "\nPodaj date urodzenia:	" << std::endl;
  this->m_DataUrodzenia.Wpisz();
  std::cout << "-------------------------" << std::endl;

  std::cin.ignore();
}


int Pracownik::SprawdzImie(const char* por_imie) const {
	return this->m_Imie.SprawdzNapis(por_imie);
}


int Pracownik::SprawdzNazwisko(const char* por_nazwisko) const {
	return this->m_Nazwisko.SprawdzNapis(por_nazwisko);
}
