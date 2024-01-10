#pragma once
#include "Pracownik.h"

class Kierownik : public Pracownik {
private:
	Napis m_NazwaDzialu;
	int m_nliczbaPracownikow;

public:
	Kierownik(Napis nazwaDzialu, int liczbaPracownik);
	Kierownik(const Kierownik& inny);


	Kierownik& operator=(const Kierownik& wzor);

	bool operator==(const Kierownik& wzor) const;

	void WypiszDane() override;
	Pracownik* KopiaObiektu() const override;

	friend std::ostream& operator<<(std::ostream& wy, const Kierownik& s);
	friend std::istream& operator>>(std::istream& wy, Kierownik& s);
};
