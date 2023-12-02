#include "Napis.h"


const char* Napis::Zwroc() const {
    return m_pszNapis;
}


void Napis::Ustaw(const char* nowy_napis) {
    strncpy(m_pszNapis, nowy_napis, sizeof(m_pszNapis) - 1);
    m_pszNapis[sizeof(m_pszNapis) - 1] = '\0';
}


void Napis::Wypisz() const {
    std::cout << m_pszNapis;
}


void Napis::Wpisz() {
    std::cin.getline(m_pszNapis, sizeof(m_pszNapis));
}


int Napis::SprawdzNapis(const char* por_napis) const {
    return strcmp(m_pszNapis, por_napis);
}
