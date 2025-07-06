// Usuario.h
#ifndef USUARIO_H
#define USUARIO_H

#include <string>

class Usuario {
private:
    std::string nombre;
    std::string id;
    std::string correo;

public:
    // Constructor
    Usuario(std::string nombre, std::string id, std::string correo);

    // Getters
    std::string getNombre() const;
    std::string getID() const;
    std::string getCorreo() const;

    //Muestra info
    void mostrarInformacion() const;
};

#endif
