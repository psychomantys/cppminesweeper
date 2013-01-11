/*
 * =====================================================================================
 *
 *       Filename:  Numero.hpp
 *
 *    Description:  Declaração da classe que representa um numero no campo.
 *
 *        Version:  1.0
 *        Created:  12/10/05 02:19:01
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Psycho Mantys (P.M.), psycho.mantys(.AT,)gmail dot com
 *
 * =====================================================================================
 */
/** 
* @file Numero.hpp
* @brief Declaração da classe que representa um numero no campo.
* @author Psycho Mantys
* @date 2005-12-10
*/
#ifndef	NUMERO_HPP_
#define	NUMERO_HPP_

/* #####   HEADER FILE INCLUDES   ################################################### */
#include	"Posicao.hpp"

class Campo_minado ;

/* #####   EXPORTED CLASS DEFINITIONS   ############################################# */
/** 
 * @brief	Classe que representa um numero no campo minado.
 */
class Numero : public Posicao {
	public :
		/* ====================  LIFECYCLE     ======================================= */
		/** 
		 * @brief	Sera avisado ao campo que a bomba pertence que ela foi criada e seus
		 * 		dados serao atualizados.
		 * 
		 * @param campo	O campo ao qual essa bomba pertence.
		 * @param x	Coordenada "\ax" da bomba no campo.
		 * @param y	Coordenada "\ay" da bomba no campo.
		 */
		Numero( Campo_minado* campo , unsigned int x , unsigned int y );

		/** 
		 * @brief	Caso a posição seja removida do jogo, seja um numero e tenha sido
		 * 		clicada, o destrutor deve avisar ao cmapo minado dono dessa posição
		 * 		que ela esa sendo tirado do jogo.
		 */
		~Numero();

		/* ====================  MUTATORS      ======================================= */
		/** 
		 * @brief	Joga num numero. Se for um numero, so vai marcar a posicao como jogada.
		 * 		Se for zero, vai requisitar que o campo pai rode uma funcao no campos
		 * 		ao seu redor, essa funcao so vai jogar nos campos ao redor. revelar
		 * 		ao redor.
		 */
		void click();

		/** 
		 * @brief	Funcao passada para ser executada nas casas ao redor de um campo
		 * 		em branco. Sera requisitado ao campo minado dono de um campo que
		 * 		execute essa funcao nas casas ao redor.Essa funcao ira jogar nesses
		 * 		campos, se eles ja nao tiverem jogados.
		 * 
		 * @param posicao	O campo que esta ao lado do campo vazio.
		 */
		static void click_lados(Posicao* posicao);
};
#endif     /* -----  end NUMERO_HPP_  ----- */

