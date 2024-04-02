/** @file Conjunto_alfabetos.hh
    @brief Especificación de la clase Conjunto_alfabetos
*/


#ifndef _CONJUNTO_ALFABETOS_HH_
#define _CONJUNTO_ALFABETOS_HH_	

#include "Alfabeto.hh"


#ifndef NO_DIAGRAM         
							
#include <iostream>         
#include <map>				 
#include <string>


#endif                      

/** @class Conjunto_alfabetos
    @brief Representa un conjunto de alfabetos


*/
using namespace std;
class Conjunto_alfabetos {

private:
	/** @brief Diccionario que contiene los alfabetos*/
	map<string, Alfabeto> cjt_alfabetos;

public:
	/** @brief Creadora por defecto
		
		Se ejecuta automáticamente al declarar un Conjunto_alfabetos.
		\pre <em>cierto</em>.
		\post El resultado es un conjunto de alfabetos vacío.
	*/
	Conjunto_alfabetos();

	//CONSULTORAS
	
	/** @brief Consultora de la existencia de un alfabeto

		\pre <em>cierto</em>.
		\post El resultado retorna <em>cierto</em> si el identificador <em>ida</em> existe.
    */
	bool existe_alfabeto(const string& ida) const;
	
	/** @brief Consultora del número de alfabetos

		\pre <em>cierto</em>.
		\post El resultado retorna el número total de alfabetos dentro del conjunto.
    */
	int numero_alfabetos() const;

    /** @brief Consultora de un alfabeto

		\pre <em>ida</em> tiene que ser <em>válido</em>.
		\post El resultado retorna un alfabeto de identificador <em>ida</em>.
    */
	Alfabeto consultar_alfabeto(const string& ida) const;

	/** @brief Consultora del contador de mensajes de un alfabeto

		\pre <em>ida</em> tiene que ser <em>válido</em>.
		\post El resultado retorna el contador de mensajes del alfabeto con identificador <em>ida</em>.
    */
	int contador_mensajes_alfabeto(const string& ida) const; 

	//MODIFICADORAS
	
	/** @brief Elimina un alfabeto del conjunto
		
		\pre <em>ida</em> tiene que ser <em>válido</em>.
		\post El resultado es la eliminación del alfabeto con identificador <em>ida</em> del conjunto total del sistema.
	*/
	void borra_alfabeto(const string& ida);
	
	/** @brief Añade un alfabeto al conjunto
		
		\pre <em>ida</em> tiene que ser <em>válido</em>.
		\post El resultado es la adición del afabeto con identificador <em>ida</em> al conjunto total del sistema.
	*/
	void nuevo_alfabeto(const string& ida, const Alfabeto& a);
	
	/** @brief Operación de ordenación del conjunto de alfabeto

		\pre <em>cierto</em>.
		\post Se devuelve el conjunto de alfabetos ordenado en orden creciente de identificador.
     */
	void listar_alfabeto() const;

	/** @brief Incrementador del contador de mensajes de un alfabeto

		\pre <em>ida</em> tiene que ser <em>válido</em>.
		\post Se incrementa el contador de mensajes de un alfabeto con identificador <em>ida</em>.
     */
	void nuevo_mensaje(const string& ida);
	
	/** @brief Decrementador del contador de mensajes de un alfabeto
		
		\pre <em>ida</em> tiene que ser <em>válido</em>.
		\post Se decrementa el contador de mensajes de un alfabeto con identificador <em>ida</em>.
	*/
	void borrar_mensaje(const string& ida); 
		
	//LECTURA Y ESCRITURA

	/** @brief Operación de lectura del conjunto de alfabetos

		\pre A>0; el canal estándar contiene un entero; a continuación recibe A alfabetos.
		\post El resultado es un conjunto de alfabetos no vacío.
     */
	void leer_conjunto_alfabetos();
	
};

#endif
