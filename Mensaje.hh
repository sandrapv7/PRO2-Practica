/** @file Mensaje.hh
    @brief Especificación de la clase Mensaje
*/


#ifndef _MENSAJE_HH_
#define _MENSAJE_HH_	

#include "Alfabeto.hh"


#ifndef NO_DIAGRAM          

#include "BinTree.hh"
#include <iostream>         
#endif                      

/** @class Mensaje
    @brief Representa un mensaje a encriptar


*/
using namespace std;
class Mensaje {

private:
	/** @brief Identificador del alfabeto*/
	string ida; 

	/** @brief Texto del mensaje*/
	string mensaje; 

public:

	/** @brief Creadora por defecto
		
		Se ejecuta automáticamente al declarar un mensaje.
		\pre <em>cierto</em>.
		\post El resultado es un mensaje vacío.
	*/
	Mensaje();

		
	//CONSULTORAS
//------------------------------------------	
	/** @brief Consultora del identificador del alfabeto mediante el cual está escrito el mensaje

		\pre <em>cierto</em>.
		\post El resultado retorna el identificador <em>ida</em> del alfabeto correspondiente al mensaje.
    */
	string consultar_ida() const;

	/** @brief Consultora del texto del mensaje

		\pre <em>cierto</em>.
		\post El resultado retorna el texto del mensaje.
    */
	string consultar_mensaje() const; 

	//MODIFICADORAS
//------------------------------------------

	/** @brief Operación de codificación del mensaje

		\pre <em>cierto</em>.
		\post Se devuelve el mensaje con identificador <em>idm</em> codificado por sustitución con la clave <em>cl</em>.
    */
	void codificar_sustitucion(const string& cl, const Alfabeto& a, string& mensaje_sustituido) const ; 

	/** @brief Operación de decodificación del mensaje

		\pre <em>cierto</em>.
		\post Se devuelve el mensaje con identificador <em>idm</em> decodificado por sustitución con la clave <em>cl</em>.
    */
	void decodificar_sustitucion(const string& cl, const Alfabeto& a, string& mensaje_sustituido) const; 

	/** @brief Operación de codificación del mensaje

		\pre <em>cierto</em>.
		\post Se devuelve el mensaje codificado por permutación en bloques de tamaño <em>b</em>.
    */
	void codificar_permutacion(int b, string& mensaje_permutado); 

	//LECTURA Y ESCRITURA
//------------------------------------------
	/** @brief Operación de lectura de un mensaje

		\pre Un mensaje <em>válido</em>.
		\post El resultado es la lectura de un mensaje.
    */
	void leer_mensaje_men();

	/** @brief Operación de lectura de un mensaje

		\pre Un mensaje <em>válido</em>.
		\post El resultado es la lectura de un mensaje.
    */
	void leer_mensaje(); 

	/** @brief Operación de lectura de un mensaje

		\pre <em>ida</em> tiene que ser <em>válido</em>.
		\post El resultado es la lectura de un mensaje.
    */
	void leer_mensaje_mensaje(const string& a_ida); 
	
	/** @brief Operación de escritura de un mensaje

		\pre <em>cierto</em>.
		\post El resultado es la escritura de un mensaje.
    */
	void escribir_mensaje() const;  

private:

	/** @brief Función de escritura del árbol de permutación del mensaje en inorden

		\pre <em>a</em> no es vacío.
		\post El resultado es la escritura del mensaje permutado. 
    */
	static void escribir_inordre(const BinTree<char> &a, string& mensaje_permutado);

	/** @brief Genera el árbol de permutación de mensaje[x..y]

		\pre <em>cierto</em>.
		\post <em>a</em> pasa a ser el árbol de permutación del fragmento del mensaje entre las posiciones <em>x</em> e <em>y</em> y tendrá como raíz <em>v</em>.
    */
  void leer_arbol(BinTree<char>& a, int x, int y, int v);

}; 

#endif
