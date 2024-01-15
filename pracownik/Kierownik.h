#pragma once

#include "Pracownik.h"

class Kierownik : public Pracownik {
private:
	Napis m_NazwaDzialu;
	int m_nliczbaPracownikow;

public:
	Kierownik(
      const char* nazwaDzialu = "", 
      int liczbaPracownik = 0, 
      const char* im = "", 
      const char* naz = "", 
      int dzien = 1, 
      int miesiac = 1, 
      int rok = 1
  );

	Kierownik(const Kierownik& inny);

	Kierownik& operator=(const Kierownik& wzor);
	bool operator==(const Kierownik& wzor) const;

	void WypiszDane() override;
  
	Pracownik* KopiaObiektu() const override;

	friend std::ostream& operator<<(std::ostream& wy, const Kierownik& s);
	friend std::istream& operator>>(std::istream& we, Kierownik& s);
};
