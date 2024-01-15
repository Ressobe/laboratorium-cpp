#include "Pracownik.h"

int Pracownik::s_nLiczbaPracownikow = 0;


Pracownik::Pracownik(const char* im, const char* naz, int dzien, int miesiac, int rok) 
	: m_Imie(im), m_Nazwisko(naz), m_DataUrodzenia(Data(dzien, miesiac, rok)), m_nIDZatrudnienia(++s_nLiczbaPracownikow) {
}


Pracownik::Pracownik(const Pracownik& wzor) : m_nIDZatrudnienia(++s_nLiczbaPracownikow) {
	m_Imie.Ustaw(wzor.Imie());
	m_Nazwisko.Ustaw(wzor.Nazwisko());
  m_DataUrodzenia.Ustaw(wzor.m_DataUrodzenia.Dzien(), wzor.m_DataUrodzenia.Miesiac(), wzor.m_DataUrodzenia.Rok());
}


Pracownik& Pracownik::operator=(const Pracownik& wzor) {
  if (this != &wzor) {
      this->m_Imie.Ustaw(wzor.Imie());
      this->m_Nazwisko.Ustaw(wzor.Nazwisko());
      this->m_DataUrodzenia.Ustaw(wzor.m_DataUrodzenia.Dzien(), wzor.m_DataUrodzenia.Miesiac(), wzor.m_DataUrodzenia.Rok());
  }
	return *this;
}

bool Pracownik::operator==(const Pracownik& wzor) const {
	if (this->Porownaj(wzor) == 0) {
		return true;
	}
	return false;
}


int Pracownik::Porownaj(const Pracownik& wzorzec) const {
    int porownanieImie = this->m_Imie.SprawdzNapis(wzorzec.Imie());
    int porownanieNazwisko = this->m_Nazwisko.SprawdzNapis(wzorzec.Nazwisko());
    int porownanieData = this->m_DataUrodzenia.Porownaj(wzorzec.m_DataUrodzenia);

    if (porownanieNazwisko != 0) {
        return porownanieNazwisko;
    }

    if (porownanieImie != 0) {
        return porownanieImie;
    }

    return porownanieData;
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
	std::cout << this->Imie() << ',' << this->Nazwisko() << ',';
  this->m_DataUrodzenia.Wypisz();
}


void Pracownik::Wpisz() {
  std::cout << "Dane pracownika" << std::endl;
  std::cout << "-------------------------" << std::endl;
  std::cout << "Podaj imie: ";
  this->m_Imie.Wpisz();

  std::cout << "Podaj nazwisko: ";
  this->m_Nazwisko.Wpisz();

  std::cout << "\nPodaj date urodzenia" << std::endl;
  this->m_DataUrodzenia.Wpisz();
}


int Pracownik::SprawdzImie(const char* por_imie) const {
	return this->m_Imie.SprawdzNapis(por_imie);
}


int Pracownik::SprawdzNazwisko(const char* por_nazwisko) const {
	return this->m_Nazwisko.SprawdzNapis(por_nazwisko);
}


std::ostream& operator<<(std::ostream& wy, const Pracownik& p) {
  wy << p.m_Imie << ',' << p.m_Nazwisko << ',' << p.m_DataUrodzenia;
	return wy;
}


std::istream& operator>>(std::istream& we, Pracownik& p) {
  p.Wpisz();
	return we;
}

void Pracownik::WypiszDane() {
	this->Wypisz();
}

Pracownik* Pracownik::KopiaObiektu() const {
	return new Pracownik(*this);
}
