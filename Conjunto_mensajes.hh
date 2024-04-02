/** @file Conjunto_mensajes.hh
    @brief Especificación de la clase Conjunto_mensajes
*/


#ifndef _CONJUNTO_MENSAJES_HH_
#define _CONJUNTO_MENSAJES_HH_	

#include "Mensaje.hh"
#include "Conjunto_alfabetos.hh"

#ifndef NO_DIAGRAM          
							 
#include <iostream>         
#include <map>				 
#include <string>
#endif                      

/** @class Conjunto_mensajes
    @brief Representa un conjunto de mensajes


*/
using namespace std;
class Conjunto_mensajes {

private:
	/** @brief Diccionario que contiene los mensajes*/
	map<string, Mensaje> cjt_mensajes;

public:
	
	/** @brief Creadora por defecto
		
		Se ejecuta automáticamente al declarar un Conjunto_mensajes.
		\pre <em>cierto</em>.
		\post El resultado es un conjunto de mensajes vacío.
	*/
	Conjunto_mensajes();
	
	//CONSULTORAS
		
	/** @brief Consultora de la existencia de un mensaje

		\pre <em>cierto</em>.
		\post El resultado retorna <em>cierto</em> si el identificador <em>idm</em> existe.
    */
	bool existe_mensaje(const string& idm) const;
	
	/** @brief Consultora del número de mensajes

		\pre <em>cierto</em>.
		\post El resultado retorna el número total de mensajes dentro del conjunto.
    */
	int numero_mensajes() const;

	/** @brief Consultora de un mensaje

		\pre <em>idm</em> tiene que ser <em>válido</em>.
		\post El resultado retorna un mensaje con identificador <em>idm</em>.
    */
	Mensaje consultar_mensaje(const string& idm) const; 

	/** @brief Consultora del identificador del alfabeto del mensaje

		\pre <em>idm</em> tiene que ser <em>válido</em>.
		\post El resultado retorna el identificador <em>ida</em> del alfabeto del mensaje con identificador <em>idm</em>.
    */
	string consultar_ida_mensaje(const string& idm) const; 

	//MODIFICADORAS
	
	/** @brief Elimina un mensaje del conjunto

		\pre <em>idm</em> tiene que ser <em>válido</em>.
		\post El resultado es la eliminación del mensaje con identificador <em>idm</em> del conjunto total del sistema.
	*/
	void borra_mensaje(const string& idm);
	
	/** @brief Añade un mensaje al conjunto

		\pre <em>idm</em> tiene que ser <em>válido</em>.
		\post El resultado es la adición del mensaje con identificador <em>idm</em> al conjunto total del sistema.
	*/
	void nuevo_mensaje(const string& idm, const Mensaje& m);
	
	/** @brief Operación de ordenación del conjunto de mensajes

		\pre <em>cierto</em>.
		\post Se devuelve el conjunto de mensajes ordenado en orden alfabético de identificador.
    */
	void listar_mensajes() const;

	/** @brief Operación de codificación por sustitución

		\pre <em>idm</em> tiene que ser <em>válido</em>.
		\post El resultado retorna un mensaje con identificador <em>idm</em> codificado por sustitución con la clave <em>ck</em>.
    */
	void codificar_sustitucion(const string& idm, const string& cl, string& mensaje_sustituido, const Conjunto_alfabetos& ca); 

	/** @brief Operación de codificación por permutación

		\pre <em>idm</em> tiene que ser <em>válido</em>.
		\post El resultado retorna un mensaje con identificador <em>idm</em> codificado por permutación por bloques de tamaño <em>b</em>.
    */
	void codificar_permutacion(const string& idm, int b, string& mensaje_permutado); 

	//LECTURA

	/** @brief Operación de lectura del conjunto de mensajes

		\pre M>0; el canal estándar contiene un entero; a continuación recibe M mensajes.
		\post El resultado es un conjunto de mensajes no vacío.
    */
	void leer_conjunto_mensajes(Conjunto_alfabetos& ca);
 
};

#endif
