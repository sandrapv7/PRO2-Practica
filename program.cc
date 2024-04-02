/**
 * @mainpage Programa basado en la encriptación de mensajes.

Se construye un programa modular que ofrece un menú de opciones enfocadas en el ámbito de la Criptografía. Se introducen las clases <em>Conjunto_mensajes</em>, 
<em>Conjunto_alfabetos</em>, <em>Alfabeto</em>, <em>Mensaje</em>

*/

/** @file program.cc
    @brief Programa principal de <em>Encriptación de mensajes</em>.
 */

/** @brief Este es el programa principal de <em>Encriptación de mensajes</em>.
*/

#include "Conjunto_mensajes.hh"
#include "Conjunto_alfabetos.hh"


using namespace std;


int main() {
	Conjunto_alfabetos ca; 
	ca.leer_conjunto_alfabetos(); 

	Conjunto_mensajes cm; 
	cm.leer_conjunto_mensajes(ca); 

	string operacion; 
	cin >> operacion; 

	while(operacion != "fin") {
		if (operacion == "nuevo_mensaje" or operacion == "nm") {
			string idm;  
			cin >> idm;

			string ida; 
			cin >> ida;  

			cout << "#" << operacion << " " << idm << " " << ida << endl; 

			if (ca.existe_alfabeto(ida)) {
				if (not cm.existe_mensaje(idm)) {
					Mensaje m; 
					m.leer_mensaje_mensaje(ida);
					cm.nuevo_mensaje(idm, m);  
					ca.nuevo_mensaje(ida); 
					cout << cm.numero_mensajes() << endl; 
				}
				else {
					cout << "error: ya existe un mensaje con ese identificador" << endl; 
				}
			}

			else {
				cout << "error: el alfabeto no existe" << endl; 
			}		

		}

		else if (operacion == "nuevo_alfabeto" or operacion == "na") {
			string ida; 
			cin >> ida; 

			cout << "#" << operacion << " " << ida << endl; 

			if (not ca.existe_alfabeto(ida)) {
				Alfabeto a; 
				a.leer_alfabeto();
				ca.nuevo_alfabeto(ida, a); 
				cout << ca.numero_alfabetos() << endl; 
			}

			else {
				cout << "error: el alfabeto ya existe" << endl;
			}


		}

		else if (operacion == "borra_mensaje" or operacion == "bm") {
			string idm; 
			cin >> idm; 

			cout << "#" << operacion << " " << idm << endl; 

			if (cm.existe_mensaje(idm)) {
				ca.borrar_mensaje(cm.consultar_ida_mensaje(idm)); 
				cm.borra_mensaje(idm); 
				cout << cm.numero_mensajes() << endl; 

			}

			else { 
				cout << "error: el mensaje no existe" << endl; 
			}

		}

		else if (operacion == "borra_alfabeto" or operacion == "ba") {
			string ida; 
			cin >> ida; 

			cout << "#" << operacion << " " << ida << endl;

			if (ca.existe_alfabeto(ida)) {
				if(ca.contador_mensajes_alfabeto(ida) == 0) {
					ca.borra_alfabeto(ida); 
					cout << ca.numero_alfabetos() << endl; 

				}

				else {
					cout << "error: hay mensajes guardados con el alfabeto" << endl;
				}

			}

			else {
				cout << "error: el alfabeto no existe" << endl;
			}

		}

		else if (operacion == "listar_mensajes" or operacion == "lm") {
			cout << "#" << operacion << endl; 
			cm.listar_mensajes(); 

		}

		else if (operacion == "listar_alfabetos" or operacion == "la") {
			cout << "#" << operacion << endl; 
			ca.listar_alfabeto(); 

		}

		else if (operacion == "codificar_sustitucion_guardado" or operacion == "csg") {
			string idm; 
			cin >> idm; 
			
			cin.ignore(); 
			string cl; 
			getline(cin,cl);

			cout << "#" << operacion << " " << idm << " " << "\"" << cl << "\"" << endl; 

			if (cm.existe_mensaje(idm)) {
				string mensaje_sustituido; 
				cm.codificar_sustitucion(idm, cl, mensaje_sustituido, ca);
				cout << "\"" << mensaje_sustituido << "\"" << endl; 
			}

			else {
				cout << "error: el mensaje no existe" << endl; 
			}

		}

		else if (operacion == "codificar_sustitucion" or operacion == "cs") {
			string ida; 
			cin >> ida; 

			cin.ignore();
			string cl; 
			getline(cin,cl); 

			cout << "#" << operacion << " " << ida << " " << "\"" << cl << "\"" << endl;

			if (ca.existe_alfabeto(ida)) { 
				Mensaje m;
				m.leer_mensaje(); 
				Alfabeto a = ca.consultar_alfabeto(ida); 
				string mensaje_sustituido; 
				m.codificar_sustitucion(cl, a, mensaje_sustituido);

				cout << "\"" << mensaje_sustituido << "\"" << endl; 
			}

			else {
				cout << "error: el alfabeto no existe" << endl; 
			}

		}

		else if (operacion == "decodificar_sustitucion" or operacion == "ds") {
			string ida; 
			cin >> ida; 

			string cl; 
			cin.ignore();
			getline(cin,cl);

			cout << "#" << operacion << " " << ida << " " << "\"" << cl << "\"" << endl; 

			if (ca.existe_alfabeto(ida)) { 
				Mensaje m;  
				m.leer_mensaje(); 
				Alfabeto a = ca.consultar_alfabeto(ida); 
				string mensaje_sustituido; 
				m.decodificar_sustitucion(cl, a, mensaje_sustituido); 
				cout << "\"" << mensaje_sustituido << "\"" << endl; 
			}

			else {
				cout << "error: el alfabeto no existe" << endl; 
			}

		}

		else if (operacion == "codificar_permutacion_guardado" or operacion == "cpg") {
			string idm; 
			cin >> idm; 

			int b; 
			cin >> b; 
			
			cout << "#" << operacion << " " << idm << " " << b << endl; 

			if (cm.existe_mensaje(idm)) {
				string mensaje_permutado; 
				cm.codificar_permutacion(idm, b, mensaje_permutado);
				cout << "\"" << mensaje_permutado << "\"" << endl; 	
			}

			else {
				cout << "error: el mensaje no existe" << endl; 
			}

		}
		

		else if (operacion == "codificar_permutacion" or operacion == "cp") { 
			int b; 
			cin >> b; 

			cout << "#" << operacion << " " << b << endl; 

			Mensaje m;
			m.leer_mensaje_men(); 
			string mensaje_permutado; 
			m.codificar_permutacion(b, mensaje_permutado); 
			cout << "\"" << mensaje_permutado << "\"" << endl; 
		}

		
		else if (operacion == "decodificar_permutacion" or operacion == "dp") {
			int b; 
			cin >> b; 

			cout << "#" << operacion << " " << b << endl; 

			Mensaje m; 
			m.leer_mensaje_men(); 
			string mensaje_permutado; 
			m.codificar_permutacion(b, mensaje_permutado); 
			cout << "\"" << mensaje_permutado << "\"" << endl; 
		}
		

		cin >> operacion;
		 
	}


}