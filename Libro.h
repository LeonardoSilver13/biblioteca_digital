// Libro.h
#ifndef LIBRO_H
#define LIBRO_H

#include <string>

class Libro {
private:
    std::string titulo;
    std::string autor;
    std::string isbn;
    int anio;
    int copiasTotales;
    int copiasDisponibles;

public:
    // Constructor
    Libro(std::string titulo, std::string autor, std::string isbn, int anio, int copias);

    // Getters
    std::string getTitulo() const;
    std::string getAutor() const;
    std::string getISBN() const;
    int getAnio() const;
    int getCopiasTotales() const;
    int getCopiasDisponibles() const;

    // Métodos de gestión de copias
    void prestar();
    void devolver();

    // Muestra info
    void mostrarInformacion() const;
};

#endif
