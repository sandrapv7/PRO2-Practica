/** @file Conjunto_mensajes.cc
    @brief Código de la clase Conjunto_mensajes
 */

#include "Conjunto_mensajes.hh"


Conjunto_mensajes::Conjunto_mensajes() {}

void Conjunto_mensajes::borra_mensaje(const string& idm) {
    map<string, Mensaje>::iterator it = cjt_mensajes.find(idm); 
    cjt_mensajes.erase(it);
    
}

void Conjunto_mensajes::nuevo_mensaje(const string& idm, const Mensaje& m) {
    cjt_mensajes.insert(make_pair(idm, m)); 
    
}

void Conjunto_mensajes::codificar_permutacion(const string& idm, int b, string& mensaje_permutado) {
    map<string, Mensaje>::iterator it = cjt_mensajes.find(idm); 
    (*it).second.codificar_permutacion(b, mensaje_permutado);

}

void Conjunto_mensajes::codificar_sustitucion(const string& idm, const string& cl, string& mensaje_sustituido, const Conjunto_alfabetos& ca) {
    map<string, Mensaje>::iterator it = cjt_mensajes.find(idm); 
    string ida = (*it).second.consultar_ida(); 
    Alfabeto a = ca.consultar_alfabeto(ida); 
    (*it).second.codificar_sustitucion(cl, a, mensaje_sustituido);

}

void Conjunto_mensajes::listar_mensajes() const {
    map<string, Mensaje>::const_iterator it = cjt_mensajes.begin();  
    int pos = 1;
    while (it != cjt_mensajes.end()) {
        cout << pos  << ". " << (*it).first << endl; 
        cout << (*it).second.consultar_ida() << endl; 
        cout << "\"" << (*it).second.consultar_mensaje() << "\"" << endl; 
        ++it; 
        ++pos; 
    }
    
}

Mensaje Conjunto_mensajes::consultar_mensaje(const string& idm) const {
    map<string, Mensaje>::const_iterator it = cjt_mensajes.find(idm); 
    return (*it).second; 

}


bool Conjunto_mensajes::existe_mensaje(const string& idm) const {
    map<string, Mensaje>::const_iterator it = cjt_mensajes.find(idm); 
    bool existe = (it != cjt_mensajes.end()); 
    return existe;

}

int Conjunto_mensajes::numero_mensajes() const{
    return cjt_mensajes.size();

}

string Conjunto_mensajes::consultar_ida_mensaje(const string& idm) const {
    map<string, Mensaje>::const_iterator it = cjt_mensajes.find(idm); 
    return (*it).second.consultar_ida(); 

}

void Conjunto_mensajes::leer_conjunto_mensajes(Conjunto_alfabetos& ca) {
    int num_mensajes; 
    cin >> num_mensajes; 

    Mensaje m;
    string idm; 
    string ida;
    for (int i = 0; i < num_mensajes; ++i) { 
        cin >> idm; 
        cin >> ida; 
        m.leer_mensaje_mensaje(ida); 
        ca.nuevo_mensaje(ida); 
        cjt_mensajes.insert(make_pair(idm, m)); 

    }

}






