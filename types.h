#include <string>

struct Domicilio
{
    bool isInitialized;
    std::string calle;
    int numero;
    std::string interior;
    std::string colonia;
    std::string ciudad;
    std::string estado;
    int codigo_postal;

    Domicilio() : isInitialized(false) {}
};

typedef
    enum
    {
        Linea_Celular = 'C',
        Linea_Casa = 'H',
        Linea_Trabajo = 'W'
    }
Tipo_Linea;

struct Telefono
{
    bool   isInitialized;
    Tipo_Linea      line;
    std::string    local;
    std::string clave_cd;

    Telefono() : isInitialized(false) {}
};

struct Persona
{
    bool isInitialized;
    std::string nombre;
    std::string apellido_p;
    std::string apellido_m;

    Domicilio dom;
    Telefono tel;

    Persona() : isInitialized(false) {}

};
