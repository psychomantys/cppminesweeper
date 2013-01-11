/*
 * =====================================================================================
 *
 *       Filename:  Bandeira.hpp
 *
 *    Description:  Declara��o da posi��o que � uma bandeira no campo minado.
 *
 *        Version:  1.0
 *        Created:  12/10/05 01:42:48
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Psycho Mantys (P.M.), psycho.mantys(.AT,)gmail dot com
 *
 * =====================================================================================
 */
/** 
* @file Bandeira.hpp
* @brief Declara��o da posi��o que � uma bandeira no campo minado.
* @author Psycho Mantys
* @date 2005-12-10
*/
#ifndef  BANDEIRA_HPP_
#define  BANDEIRA_HPP_
/* #####   HEADER FILE INCLUDES   ################################################### */
#include	"Posicao.hpp"

/* #####   EXPORTED CLASS DEFINITIONS   ############################################# */
/** 
* @brief Classe que representa uma bandeira no campo.
*/
class Bandeira : public Posicao {
	public:
		/* ====================  LIFECYCLE     ======================================= */
		/** 
		* @brief Bandeira que esta no jogo. Quando uma bandeira � criada, ela deve contar
		*	 como uma jogada. Tamb�m, se deve armazenar o que existia antes no campo,
		*	 atrav�s da variavel \a old.
		* 
		* @param posi��o Antigo campo que tinha onde a bandeira esta sendo colocada.
		*/
		Bandeira ( Posicao* posicao ); /* constructor*/

		/** 
		* @brief O destrutor de uma bandeira deve avisar ao campo pai que uma jogada foi
		*	 desfeita.
		*/
		~Bandeira ();

		/* ====================  ACCESSORS     ======================================= */

		/* ====================  MUTATORS      ======================================= */
		/** 
		* @brief Joga na casa com uma bandeira. Normalmente, deveria so chamar o metodo
		*	 click da posi��o antiga.
		*/
		void click();

	private:
		/* ====================  DATA MEMBERS  ======================================= */
		/** 
		* @brief Variavel que contem o antigo item do campo.
		*/
		auto_ptr <Posicao> old ;

}; /* -----  end of class Bandeira  ----- */

#endif     /* -----  end BANDEIRA_HPP_  ----- */

