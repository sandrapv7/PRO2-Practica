/** @file Alfabeto.cc
    @brief Código de la clase Alfabeto
 */

#include "Alfabeto.hh"


Alfabeto::Alfabeto() {}

int Alfabeto::contador_mensajes_alfabeto() const {
	return contador_mensajes; 

}

void Alfabeto::incrementar_contador_mensajes() {
	++contador_mensajes; 

}

void Alfabeto::decrementar_contador_mensajes() {
	--contador_mensajes; 

}

bool Alfabeto::consultar_especial() const {
	return especial; 

}

void Alfabeto::escribir() const {
	if (especial) {
		cout << "especial [" << entrada_alfabeto[0] << ".."; 
        cout << entrada_alfabeto[entrada_alfabeto.size() - 1]<< "]"; 

	}

    else cout << "normal \"" << entrada_alfabeto << "\""; 

    cout << " " << contador_mensajes << " mensajes" << endl; 

}

string Alfabeto::consultar_alfabeto() const {
	return entrada_alfabeto; 

}

void Alfabeto::leer_alfabeto()  {
	cin.ignore(); 
	getline(cin, entrada_alfabeto);  

	int tamano = entrada_alfabeto.size(); 
	int j = 0; 

	especial = true; 

	while (j < tamano-1 and especial) {
		if (entrada_alfabeto[j + 1] - entrada_alfabeto[j] != 1) especial = false; 
		++j; 

	}

}

char Alfabeto::codificar_sustitucion_caracter(char c1, char c2) const{
	int suma = 0; 
	if(not especial) {
		map<char, int> mapa_alfabeto; 
		int tamano = entrada_alfabeto.size(); 		
		for (int i = 0; i < tamano; ++i) {
			char incluir = entrada_alfabeto[i]; 
			mapa_alfabeto.insert(make_pair(incluir,i)); 
		}	

		map<char, int>::const_iterator it2 = mapa_alfabeto.find(c1); 
		suma += (*it2).second;  
		map<char, int>::const_iterator it3 = mapa_alfabeto.find(c2);	
		suma += (*it3).second; 
		
	}

	else {
		suma += c1 - entrada_alfabeto[0];
		suma += c2 - entrada_alfabeto[0];
	}

	if(suma >= entrada_alfabeto.size()) suma = suma%entrada_alfabeto.size();
	return entrada_alfabeto[suma];

}

char Alfabeto::decodificar_sustitucion_caracter(char c1, char c2) const{
	int suma = 0; 
	
	if(not especial){
		map<char, int> mapa_alfabeto; 
		int tamano = entrada_alfabeto.size(); 		
		for (int i = 0; i < tamano; ++i) {
			char incluir = entrada_alfabeto[i]; 
			mapa_alfabeto.insert(make_pair(incluir,i)); 
		}
			
		map<char, int>::const_iterator it2 = mapa_alfabeto.find(c1); 	
		map<char, int>::const_iterator it3 = mapa_alfabeto.find(c2);
		suma = ((*it2).second - (*it3).second); 
		if (suma < 0) {
			suma += entrada_alfabeto.size(); 	
		}
	
	}
	
	else{
		suma += int(c1 - entrada_alfabeto[0]);
		suma -= int(c2 - entrada_alfabeto[0]);
		if (suma < 0) {
			suma += entrada_alfabeto.size(); 
		}

	}

	return entrada_alfabeto[suma%entrada_alfabeto.size()];

}




