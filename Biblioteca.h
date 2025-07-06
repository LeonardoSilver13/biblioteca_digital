// Biblioteca.h
#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H

#include "Libro.h"
#include "Usuario.h"
#include "Prestamo.h"
#include <vector>
#include <string>

class Biblioteca {
private:
    std::vector<Libro*> libros;
    std::vector<Usuario*> usuarios;
    std::vector<Prestamo*> prestamos;

public:
    // Constructor y destructor
    Biblioteca();
    ~Biblioteca();

    // Gestión de libros y usuarios
    void agregarLibro(Libro* libro);
    void agregarUsuario(Usuario* usuario);

    // Búsqueda
    Libro* buscarLibroPorISBN(const std::string& isbn);
    Usuario* buscarUsuarioPorID(const std::string& id);

    // Operaciones
    void registrarPrestamo(const std::string& isbn, const std::string& idUsuario, const std::string& fecha);
    void devolverLibro(const std::string& isbn);

    // Mostrar
    void mostrarLibros() const;
    void mostrarUsuarios() const;
    void mostrarPrestamos() const;

    // Lectura y escritura de archivos
    void cargarDatos();
    void guardarDatos();
};

#endif
