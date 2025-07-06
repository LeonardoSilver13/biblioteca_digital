// Usuario.cpp
#include "Usuario.h"
#include <iostream>

// Constructor
Usuario::Usuario(std::string nombre, std::string id, std::string correo)
    : nombre(nombre), id(id), correo(correo) {}

// Getters
std::string Usuario::getNombre() const { return nombre; }
std::string Usuario::getID() const { return id; }
std::string Usuario::getCorreo() const { return correo; }

//Muestra info
void Usuario::mostrarInformacion() const {
    std::cout << "Nombre: " << nombre << "\n"
              << "ID: " << id << "\n"
              << "Correo: " << correo << "\n";
}
