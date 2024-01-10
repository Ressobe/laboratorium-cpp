#include "Kierownik.h"

Kierownik::Kierownik(Napis nazwaDzialu, int liczbaPracownik) : m_NazwaDzialu(nazwaDzialu) , m_nliczbaPracownikow(liczbaPracownik) {}

Kierownik::Kierownik(const Kierownik& inny) : Pracownik(inny), m_NazwaDzialu(inny.m_NazwaDzialu), m_nliczbaPracownikow(inny.m_nliczbaPracownikow) {}
// Kierownik& Kierownik::operator=(const Kierownik& wzor) const {
// 	if (this != &wzor) {
//         m_NazwaDzialu = wzor.m_NazwaDzialu;
//         m_nliczbaPracownikow = wzor.m_nliczbaPracownikow;
// 	}
//
//   return *this;
// }

bool Kierownik::operator==(const Kierownik& wzor) const {
	return this->Porownaj(wzor)  && this->m_NazwaDzialu.SprawdzNapis(wzor.m_NazwaDzialu.Zwroc()) && (this->m_nliczbaPracownikow == wzor.m_nliczbaPracownikow);
}

void Kierownik::WypiszDane() {
	this->Wypisz();
  std::cout << std::endl;
  std::cout << this->m_nliczbaPracownikow << std::endl;
  std::cout << this->m_NazwaDzialu << std::endl;
}

Pracownik* Kierownik::KopiaObiektu() const {
	return new Kierownik(*this);
}

std::ostream& operator<<(std::ostream& wy, const Kierownik& s) {
  s.Wypisz();
  return wy;
}

std::istream& operator>>(std::istream& wy, Kierownik& s) {
  s.Wpisz();
  std::cin.ignore();
  std::cout << "-------------------------" << std::endl;
  std::cout << "Dodatkowe dane dla kierownika" << std::endl;

  std::cout << "Podaj liczbe pracowników" << std::endl;
  wy >> s.m_nliczbaPracownikow;

  std::cout << "Podaj nazwe odzialu" << std::endl;
  wy >> s.m_NazwaDzialu;

  return wy;
}
