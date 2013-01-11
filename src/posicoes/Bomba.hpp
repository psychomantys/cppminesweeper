/*
 * =====================================================================================
 *
 *       Filename:  Bomba.hpp
 *
 *    Description:  Declara��o de uma posi��o no campo minado que representa uma bomba.
 *
 *        Version:  1.0
 *        Created:  12/10/05 02:00:11
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Psycho Mantys (P.M.), psycho.mantys(.AT,)gmail dot com
 *
 * =====================================================================================
 */
/** 
* @file Bomba.hpp
* @brief Declara��o de uma posi��o no campo minado que representa uma bomba.
* @author Psycho Mantys
* @date 2005-12-10
*/
#ifndef	BOMBA_H_
#define	BOMBA_H_

/* #####   HEADER FILE INCLUDES   ################################################### */
#include	"Posicao.hpp"

/* #####   EXPORTED CLASS DEFINITIONS   ############################################# */
/** 
* @brief Classe que implementa uma bomba no campo minado.
*/
class Bomba : public Posicao {

	friend class Campo_minado ;

	public:
		/* ====================  LIFECYCLE     ======================================= */
		/** 
		* @brief No construtor, toda vez que uma bomba � criada, o jogo ao qual ela pertence
		*	 deve � informado dessa cria��o. Tamb�m sera incrementado avisado aos campos
		*	 ao lado dessa posi��o que foi colocado uma bomba ao seu lado.
		*
		* @param campo	O campo ao qual essa bomba pertence.
		* @param x	Coordenada \a "x" da bomba no campo.
		* @param y	Coordenada \a "y" da bomba no campo.
		*/
		Bomba ( Campo_minado* campo , unsigned int x , unsigned int y );	/* constructor */
		
		/* ====================  MUTATORS      ======================================= */
		/** 
		* @brief Joga em um campo com bomba. Esse metodo vai dizer ao jogo que ele foi
		*	 perdido.
		*/
		void click() ;

		/** 
		* @brief Fun��o que sera executada ao redor da bomba quando ela for criada. Essa
		*	 fun��o serve pra indicar aos campo ao redor que existe uma bomba ao seu
		*	 lado.
		* 
		* @param posicao	Aceita um campo. Esse campo esta ao redor de uma bomba.
		*/
		static void incrementa( Posicao* posicao ) ;

}; /* -----  end of class Bomba  ----- */

#endif     /* -----  end BOMBA_H_  ----- */

