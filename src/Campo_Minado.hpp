/*
 * =====================================================================================
 *
 *       Filename:  Campo_Minado.hpp
 *
 *    Description:  Arquivo que contem a classe do Campo Minado OO.
 *
 *        Version:  1.0
 *        Created:  04-02-2009 12:03:31
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Psycho Mantys (P.M.), psycho.mantys(.AT,)gmail dot com
 *
 * =====================================================================================
 */
/** 
* @file Campo_Minado.hpp
* @brief Arquivo que contem a classe do Campo Minado OO.
* @author Psycho Mantys
* @date 2009-02-04
*/

#ifndef _CAMPO_MINADO_HPP
#define _CAMPO_MINADO_HPP
/* #####   HEADER FILE INCLUDES   ################################################### */
/* Incluido porque usa vector */
#include	<vector>
/* Precisa do tipo clock_t */
#include	<ctime>

/* #####   EXPORTED CLASS DEFINITIONS   ############################################# */
/* Precisa da definição de posição, para instaciar um vector de posições. */
class Posicao ;

/* Para usar o vector mais em baixo */
using std::vector ;

/** 
* @brief Classe que representa o campo minado.
*/
class Campo_minado{
	friend class Bandeira ;
	friend class Bomba ;
	friend class Numero ;
	public:
		/* ====================  LIFECYCLE     ======================================= */
		/** 
		* @brief Construtor do campo minado. Sera medido o tempo que o jogo começou,
		* 	 construido o campo, distribuir bombas e inicializar todos os atributos
		* 	 do campo minado.
		* 
		* @param x	O \a x maximo do campo.
		* @param y	O \a y maximo do campo.
		* @param bomb	A quantidade de bombas que o campo vai ter.
		*/
		Campo_minado ( unsigned int x , unsigned int y , unsigned int bomb );/*constructor*/

		/* ====================  ACCESSORS     ======================================= */
		/** 
		* @brief	Avisa se o jogo foi perdido ou não.
		* 
		* @return	retorna \a true se o jogo esta perdido.
		*/
		bool isEnd();

		/** 
		* @brief	Indica se o jogo foi ganho ou não.
		* 
		* @return	Retorna \a true caso o jogo esteja ganho.
		*/
		bool isWinner();

		/** 
		* @brief	Indica a quanto tempo o jogo esta rodando em segundos.
		* 
		* @return	Retorna um double que representa em segundos o tempo do jogo.
		*/
		double game_time();

		/** 
		* @brief	Metodo que executa uma ação nas casas ao redor de uma casa que
		* 		você passa como parametro. Normalmente essa função é usada 
		* 		para desenvolvimento interno da api.
		* 
		* @param posicao	A posição que você que que seja executado a ação ao redor.
		* @param funcao		Função que você pede para o campo minado executar ao redor.
		*/
//		template<typename _funcao>
		void executa_nos_lados(Posicao* posicao , void (funcao)(Posicao*));

		/* ====================  MUTATORS      ======================================= */
		/** 
		* @brief	Esse metodo reseta o jogo e o começa de novo.
		*/
		void reset();

		/** 
		* @brief	Arrisca em um campo do campo minado.
		* 
		* @param x	Coordenada "\ax" de onde você vai colocar a bandeira.
		* @param y	Coordenada "\ay" de onde você vai colocar a bandeira.
		* 
		* @return	retorna \a true se você tiver conseguido jogar com sucesso.
		*/
		bool jogar( unsigned int x , unsigned int y );

		/** 
		* @brief Adiciona em uma casa uma bandeira.
		* 
		* @param x	Coordenada "\ax" de onde você vai colocar a bandeira.
		* @param y	Coordenada "\ay" de onde você vai colocar a bandeira.
		* 
		* @return	retorna \a true se a bandeira tiver sido colocada.
		*/
		bool add_flag( unsigned int x , unsigned int y );

		void display();

	protected:

	private:
		/* ====================  MUTATORS      ======================================= */
		/** 
		* @brief	Preenche o campo minado com as bombas. O campo deve estar só com
		* 		posições com numeros igual a zero para que essa função seja
		* 		executada corretamente. Caso passe a existir outra condição que
		* 		intrefira nesse processo, deve ser alterado somente esse metodo.
		*/
		void fill_field_with_bombs();

		/* ====================  DATA MEMBERS  ======================================= */
		/** 
		* @brief	Matriz que contem todas posições do campo minado.
		*/
		vector<vector<Posicao*> > campo;

		/** 
		* @brief	Atributo que contém o momento que o jogo começou.
		*/
		clock_t	inicio ;

		/** 
		* @brief	Atributo que indica se o jogo esta perdido.
		*/
		bool lose ;

		/** 
		* @brief	O tamanho maximo na coordenada "\ax"
		*/
		const unsigned int max_X ;

		/** 
		* @brief	O tamanho maximo na coordenada "\ay"
		*/
		const unsigned int max_Y ;

		/** 
		* @brief	A quantidade de bandeiras que você jogou no campo minado.
		*/
		unsigned int qtd_bandeiras ;

		/** 
		* @brief	A quantidade de bombas que existem no campo minado.
		*/
		unsigned int qtd_bombas ;

		/** 
		* @brief	A quantidade de campos que já foram jogados no jogo.
		*/
		unsigned int step ;

		/** 
		* @brief	A quantidade maxima de casas que você pode jogar no jogo.
		*/
		unsigned int max_step ;

}; /* -----  end of class Campo_minado  ----- */

#endif		/* End _CAMPO_MINADO_HPP */

