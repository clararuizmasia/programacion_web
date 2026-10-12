#include <iostream>
#include <string>

using namespace std;

class SessioUsuari
{
    private:
             std::string nomUsuari;
             int tempsLimitSegons;
             bool activa;

             void tancarSesion () {
                activa = false; //Cerrar la sesion 
             }


    public: 

        ~SessioUsuari() {
            tancarSesion();
        }


    SessioUsuari()

        :nomUsuari ("convidat"), tempsLimitSegons (300), activa(true) {}

    explicit SessioUsuari(const std::string& nom)

        :nomUsuari(nom), tempsLimitSegons (600), activa(true) {}
        
    SessioUsuari(const std::string& nom, int tempsLimit) 

        :nomUsuari(nom), tempsLimitSegons (tempsLimit > 0 ? tempsLimit: 60), activa(true) {}

    std::string getNomUsuari() const{
        return nomUsuari;
    }

    bool esActiva() const {
        return activa;
    }

    void ampliarTemps(int segons){
        if (segons > 0)
        {
            tempsLimitSegons += segons;
        }
    }
};


int main() {
   
    SessioUsuari s1("Clara");
    cout << "Usuario: " << s1.getNomUsuari() << endl;
    cout << "¿Activa?: " << (s1.esActiva() ? "Si" : "No") << endl;

  
    s1.ampliarTemps(100);

    cout << "Fin del programa, la sesion se cerrara sola al salir" << endl;
    return 0;
}




