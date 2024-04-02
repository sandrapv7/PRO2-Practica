/** @file Mensaje.cc
    @brief Código de la clase Mensaje
 */

#include "Mensaje.hh"

Mensaje::Mensaje() {}

string Mensaje::consultar_ida() const{
    return ida; 

}

string Mensaje::consultar_mensaje() const {
    return mensaje; 

}
    
void Mensaje::codificar_permutacion(int b, string& mensaje_permutado) {
    int tamano_arbol = mensaje.size() - 1; 
    if (b >= mensaje.size()) {
        int y = tamano_arbol; 
        int x = 0; 
        BinTree<char> a;
        int v = (x + y)/2; 
        leer_arbol(a, x, y, v);
        escribir_inordre(a, mensaje_permutado);
    }

    else {
        double num_bloques = mensaje.size()/double(b);
        double redondeo = num_bloques - int(num_bloques);
        int numero_bloques = 0;

        if (redondeo == 0) numero_bloques = num_bloques;
        else  {
            numero_bloques = num_bloques + 1;
        }

        int count = 0;
        int x = 0;
        int y = b - 1;

        while (count < numero_bloques) {
            BinTree<char> a;
            int v = (x + y)/2;
            leer_arbol(a, x, y, v);
            escribir_inordre(a, mensaje_permutado);
            if (count == numero_bloques - 2) {
                x += b;
                y = mensaje.size() - 1;
            }

            else {
                x+= b;
                y+= b;
            }

            ++count;
        }
    }

}
    
void Mensaje::escribir_inordre(const BinTree<char> &a, string& mensaje_permutado){
    if(not a.empty()) {
        escribir_inordre(a.left(), mensaje_permutado);
        mensaje_permutado += a.value();
        escribir_inordre(a.right(), mensaje_permutado);
    }

}

void Mensaje::leer_arbol(BinTree<char>& a, int x, int y, int v) {
    if (x <= y) {
        BinTree<char> izq, der;
        int centro = (x + y)/2; 
        int centroizq = (x + centro - 1)/2; 
        int centroder = (centro + 1 + y)/2; 

        //Si el nodo izquierdo va a tener valor se intercambia con el valor del nodo derecho.  
        if (x <= centro - 1) {
            leer_arbol(izq, x, centro - 1, centroder);

        }
        //Si el nodo derecho y el nodo izquierdo van a tener valor se intercambia el valor del nodo izquierdo con el derecho. 
        if (centro + 1 <= y and x <= centro - 1) {
            leer_arbol(der, centro + 1, y, centroizq);

        }
        //Si solo el nodo derecho va a tener valor se deja el mismo valor del nodo derecho.
        else if(x > centro - 1){
            leer_arbol(der, centro + 1, y, centroder); 
        }
            
        a = BinTree<char> (mensaje[v], izq, der);
    }

}

void Mensaje::codificar_sustitucion(const string& cl, const Alfabeto& a, string& mensaje_sustituido) const {
    int pos = 0; 
    int tamano = mensaje.size(); 

    for (int i = 0; i < tamano; ++i) {
        mensaje_sustituido += a.codificar_sustitucion_caracter(mensaje[i], cl[pos]); 
        pos = (pos+1)%cl.size();
    }      
        
}

void Mensaje::decodificar_sustitucion(const string& cl, const Alfabeto& a, string& mensaje_sustituido) const {
    int pos = 0; 
    int tamano = mensaje.size(); 
       
    for (int i = 0; i < tamano; ++i) {
        mensaje_sustituido += a.decodificar_sustitucion_caracter(mensaje[i], cl[pos]); 
        pos = (pos+1)%cl.size();
    }

} 

void Mensaje::leer_mensaje_men() {
    cin.ignore();    
    getline(cin, mensaje); 

}

void Mensaje::leer_mensaje() {  
    getline(cin, mensaje); 

}

void Mensaje::leer_mensaje_mensaje(const string& a_ida) {
    ida = a_ida; 
    cin.ignore(); 
    getline(cin, mensaje); 

}

void Mensaje::escribir_mensaje() const {
    cout << ida << endl; 
    cout << "\"" << mensaje << "\"" << endl; 
    
}
