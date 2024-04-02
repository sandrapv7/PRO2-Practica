/** @file Conjunto_alfabetos.cc
    @brief Código de la clase Conjunto_alfabetos
 */

#include "Conjunto_alfabetos.hh"



Conjunto_alfabetos::Conjunto_alfabetos() {}

void Conjunto_alfabetos::borra_alfabeto(const string& ida) {
    map<string, Alfabeto>::iterator it = cjt_alfabetos.find(ida); 
    cjt_alfabetos.erase(it); 

}

void Conjunto_alfabetos::nuevo_alfabeto(const string& ida, const Alfabeto& a) {
    cjt_alfabetos.insert(make_pair(ida, a)); 

}

void Conjunto_alfabetos::listar_alfabeto() const{
    map<string, Alfabeto>::const_iterator it = cjt_alfabetos.begin();  
    int pos = 1;
    while (it != cjt_alfabetos.end()) {
        cout << pos  << ". " << (*it).first << endl; 
        (*it).second.escribir(); 
        
        ++it; 
        ++pos; 
    } 

}

int Conjunto_alfabetos::contador_mensajes_alfabeto(const string& ida) const{
    map<string, Alfabeto>::const_iterator it = cjt_alfabetos.find(ida); 
    return (*it).second.contador_mensajes_alfabeto(); 

}

void Conjunto_alfabetos::nuevo_mensaje(const string& ida) {
    map<string, Alfabeto>::iterator it = cjt_alfabetos.find(ida); 
    (*it).second.incrementar_contador_mensajes(); 

}

void Conjunto_alfabetos::borrar_mensaje(const string& ida) {
    map<string, Alfabeto>::iterator it = cjt_alfabetos.find(ida); 
    (*it).second.decrementar_contador_mensajes();

}


bool Conjunto_alfabetos::existe_alfabeto(const string& ida) const {
    map<string, Alfabeto>::const_iterator it = cjt_alfabetos.find(ida); 
    bool existe = (it != cjt_alfabetos.end()); 
    return existe;       

}

int Conjunto_alfabetos::numero_alfabetos() const {
    return cjt_alfabetos.size(); 

}

Alfabeto Conjunto_alfabetos::consultar_alfabeto(const string& ida) const {
    map<string, Alfabeto>::const_iterator it = cjt_alfabetos.find(ida); 
    return (*it).second; 

}

void Conjunto_alfabetos::leer_conjunto_alfabetos() {
    int num_alfabetos; 
    cin >> num_alfabetos; 
    
    Alfabeto a;     
    for (int i = 0; i < num_alfabetos; ++i) {
        string ida; 
        cin >> ida;
        a.leer_alfabeto();  
        cjt_alfabetos.insert(make_pair(ida, a)); 
    }
    
}

