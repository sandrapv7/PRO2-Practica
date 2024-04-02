/** @file Alfabeto.hh
    @brief Especificación de la clase Alfabeto
*/


#ifndef _ALFABETO_HH_
#define _ALFABETO_HH_	

#ifndef NO_DIAGRAM          
							 
#include <iostream>         
#include <string>
#include <map>

#endif                      

/** @class Alfabeto
    @brief Representa un alfabeto


*/
using namespace std;
class Alfabeto {

private:
	/** @brief Texto del alfabeto*/
	string entrada_alfabeto; 
	/** @brief Booleano que indica si el alfabeto es especial(true) o normal(false).*/
	bool especial; 
	/** @brief Contador de mensajes de un alfabeto*/
	int contador_mensajes = 0; 

public:
	/** @brief Creadora por defecto
		
		Se ejecuta automáticamente al declarar un alfabeto.
		\pre <em>cierto</em>.
		\post El resultado es un alfabeto vacío.
	*/
	Alfabeto();
			
	//CONSULTORAS

	/** @brief Consultora del número de mensajes que tiene un alfabeto
	
		\pre <em>cierto</em>.
		\post El resultado retorna el número total de mensajes de un alfabeto con identificador <em>ida</em>.
     */
	int contador_mensajes_alfabeto() const;

	/** @brief Consultora del texto del alfabeto

		\pre <em>cierto</em>.
		\post El resultado retorna el texto del alfabeto con identificador <em>ida</em>.
     */
	string consultar_alfabeto() const; 

	/** @brief Consultora del número de mensajes que tiene un alfabeto

		\pre <em>cierto</em>.
		\post El resultado retorna <em>cierto</em> si el alfabeto consultado es especial.
     */
	bool consultar_especial() const; 
	
   //MODIFICADORAS

   /** @brief Modificadora del contador de mensajes

		\pre Un alfabeto <em>válido</em>.
		\post El resultado es el incremento del contador de mensajes de un alfabeto con identificador <em>ida</em>.
     */
   void incrementar_contador_mensajes();

   /** @brief Modificadora del contador de mensajes

		\pre Un alfabeto <em>válido</em>.
		\post El resultado es el decremento del contador de mensajes de un alfabeto con identificador <em>ida</em>.
     */
   void decrementar_contador_mensajes();

   /** @brief Operación de codificación por sustitución 

		\pre <em>cierto</em>.
		\post El resultado retorna un caracter codificado por sustitución.
    */
   char codificar_sustitucion_caracter(char c1, char c2) const; 

   /** @brief Operación de codificación por sustitución 

		\pre <em>cierto</em>.
		\post El resultado retorna un caracter decodificado por sustitución.
    */
   char decodificar_sustitucion_caracter(char c1, char c2) const; 

	//LECTURA Y ESCRITURA

	/** @brief Operación de lectura de un alfabeto

		\pre Un alfabeto <em>válido</em>.
		\post El resultado es la lectura de un alfabeto.
     */
	void leer_alfabeto();

	/** @brief Operación de escritura

		\pre Un alfabeto <em>válido</em>.
		\post El resultado es la escritura de la salida correspondiente según si se trata de un alfabeto especial o normal.
     */
	void escribir() const; 

};

#endif
