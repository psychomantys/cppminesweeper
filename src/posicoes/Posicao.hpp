/*
 * =====================================================================================
 *
 *       Filename:  Posicao.hpp
 *
 *    Description:  Arquivo que contem todas as possibilidades para uma posição e 
 *                  sua interface
 *
 *        Version:  1.0
 *        Created:  01/30/09 10:19:52
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Psycho Mantys (P.M.), psycho.mantys(.AT,)gmail dot com
 *
 * =====================================================================================
 */
/** 
* @file Posicao.hpp
* @brief Arquivo que contem todas as possibilidades para uma posição e sua interface.
* @author Psycho Mantys
* @date 2009-01-30
*/

#ifndef _POSICAO_HPP
#define _POSICAO_HPP
/* #####   HEADER FILE INCLUDES   ################################################### */
/* Usando auto_ptr */
#include	<memory>

/* #####   EXPORTED CLASS DEFINITIONS   ############################################# */

class Campo_minado;
/* É preciso da declaração da classe bomba. Veja o friend abaixo. */
class Bomba ;
using std::auto_ptr ;

/** 
* @brief Interface para as posicoes do campo minado.
*/
class Posicao {
	/* A classe bomba precisa ter acesso ao simbolo para poder incrementa-lo */
	friend class Bomba;
	friend class Bandeira;
	public:
		/* ====================  LIFECYCLE     ======================================= */
		/** 
		* @brief Contrutor da posição. Aceita o \a x e o \a y da coordenada no campo.
		* 	 O construtor da posição também e responsavel por atualizar o campo pai
		*	 da posição.
		* 
		* @param campo	O campo ao qual essa posição pertence.
		* @param x	Coordenada \a "x" da posição do campo.
		* @param y	Coordenada \a "y" da posição do campo.
		*/
		Posicao ( Campo_minado *campo , unsigned int x , unsigned int y );/* constructor */

		/* ====================  ACCESSORS     ======================================= */
		/** 
		* @brief Metodo que pega o simbolo que representa o campo.
		* 
		* @return Retorna um simbolo que corresponde a entidade dessa posição.
		*/
		virtual char get() ;

		/* ====================  MUTATORS      ======================================= */
		/** 
		* @brief Joga nessa posição. Esse metodo vai executar algo dependendo da entidado
		*	 do que era o campo(vazio, uma bomba ...). Cada classe filha precisa
		*	 redefini-lo por esse motivo.
		*/
		virtual void click() = 0 ;

		/* ====================  DATA MEMBERS  ======================================= */
		/** 
		* @brief A coordenada \a "x" da posição no campo.
		*/
		int x ;
		/** 
		* @brief A coordenada \a "y" da posição no campo.
		*/
		int y ;

		/* #####   EXPORTED TYPE DEFINITIONS   ####################################### */
		/** 
		* @brief Enumeração que define os simbolos de cada posição do campo minado.
		*/
		enum simbols { 
			vazio='0' ,
			maior_numero='8' ,
			flag='F' ,
			bomba='B'
		};

	public :
		/* ====================  DATA MEMBERS  ======================================= */
		/** 
		* @brief Representação do que esta na posição.
		*/
		char simbolo ;

		/** 
		* @brief Indica se o campo foi clicado ou não.
		*/
		bool clicked;

	protected :
		/** 
		* @brief O campo ao qual a posição esta. E nescessario para fazer algumas atualizações
		*	 como a se você clicar numa bomba ou num espaço vazio.
		*/
		Campo_minado* campo_pai;

}; /* -----  end of class Posicao  ----- */

#endif	/* -----  not _POSICAO_HPP  ----- */

