#include "Kierownik.h"

Kierownik::Kierownik(
      const char* nazwaDzialu, 
      int liczbaPracownik, 
      const char* im, 
      const char* naz, 
      int dzien, 
      int miesiac, 
      int rok
): Pracownik(im, naz, dzien, miesiac, rok), 
  m_NazwaDzialu(Napis(nazwaDzialu)) , m_nliczbaPracownikow(liczbaPracownik) {}

Kierownik::Kierownik(const Kierownik& inny) : Pracownik(inny), 
  m_NazwaDzialu(inny.m_NazwaDzialu), m_nliczbaPracownikow(inny.m_nliczbaPracownikow) {}

Kierownik& Kierownik::operator=(const Kierownik& wzor) {
	if (this != &wzor) {
        Pracownik::operator=(wzor);
        this->m_NazwaDzialu = Napis(wzor.m_NazwaDzialu);
        this->m_nliczbaPracownikow = wzor.m_nliczbaPracownikow;
	}
  return *this;
}

bool Kierownik::operator==(const Kierownik& wzor) const {
  bool check1 = false;

  if (this->m_NazwaDzialu.SprawdzNapis(wzor.m_NazwaDzialu.Zwroc()) == 0) {
    check1 = true;
  }

  bool check2 = this->m_nliczbaPracownikow == wzor.m_nliczbaPracownikow;
  bool check3 = Pracownik::operator==(wzor);


	return check1 && check2 && check3; 
}

void Kierownik::WypiszDane()  {
	this->Wypisz();
  std::cout << ',' << this->m_nliczbaPracownikow << ',' << this->m_NazwaDzialu;
}

Pracownik* Kierownik::KopiaObiektu() const {
	return new Kierownik(*this);
}

std::ostream& operator<<(std::ostream& wy, const Kierownik& s) {
  wy << static_cast<const Pracownik&>(s);
  wy << ',' << s.m_NazwaDzialu << ',' << s.m_nliczbaPracownikow;
  return wy;
}

std::istream& operator>>(std::istream& we, Kierownik& s) {
  s.Wpisz();

  std::cout << "\nDodatkowe dane dla kierownika" << std::endl;
  std::cout << "-----------------------------" << std::endl;

  std::cout << "Podaj liczbe pracowników: ";
  we >> s.m_nliczbaPracownikow;

  we.ignore();

  std::cout << "Podaj nazwe odzialu: ";
  we >> s.m_NazwaDzialu;

  return we;
}
