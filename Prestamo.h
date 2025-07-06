// Prestamo.h
#ifndef PRESTAMO_H
#define PRESTAMO_H

#include <string>
#include "Libro.h"
#include "Usuario.h"

class Prestamo {
private:
    Libro* libroPrestado;      // Apunta al libro que se presta
    Usuario* usuario;          // Apunta al usuario que lo solicita
    std::string fechaPrestamo; 

public:
    // Constructor
    Prestamo(Libro* libro, Usuario* usuario, std::string fecha);

    // Getters
    Libro* getLibro() const;
    Usuario* getUsuario() const;
    std::string getFechaPrestamo() const;

    // Muestra info del préstamo
    void mostrarInformacion() const;
};

#endif
