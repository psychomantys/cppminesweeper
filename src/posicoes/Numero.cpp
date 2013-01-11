/*
 * =====================================================================================
 *
 *       Filename:  Numero.cpp
 *
 *    Description:  Implementação da posição do campo minado que representa um numero.
 *
 *        Version:  1.0
 *        Created:  12/10/05 02:23:07
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Psycho Mantys (P.M.), psycho.mantys(.AT,)gmail dot com
 *
 * =====================================================================================
 */
/** 
* @file Numero.cpp
* @brief Implementação da posição do campo minado que representa um numero.
* @author Psycho Mantys
* @date 2005-12-10
*/
/* #####   HEADER FILE INCLUDES   ################################################### */
#include	"Numero.hpp"
#include	"../Campo_Minado.hpp"
#include	"Posicao.hpp"

/* #####   CLASS IMPLEMENTATIONS  -  EXPORTED CLASSES   ############################# */
Numero::Numero( Campo_minado* campo , unsigned int x , unsigned int y ) : Posicao( campo , x , y ) {
	this->simbolo = Posicao::vazio ;
}	/* -----  end of method Numero::Numero  ----- */

void Numero::click_lados(Posicao* posicao){
	if ( not posicao->clicked )
		posicao->click();
}

void Numero::click(){
	if ( not this->clicked ){
		campo_pai->step++ ;
		this->clicked = true ;
		if ( this->get() == Posicao::vazio )
			campo_pai->executa_nos_lados(this , Numero::click_lados );
	}
	return ;
}	/* -----  end of method Numero::click  ----- */

Numero::~Numero(){
	if ( this->clicked ){
		campo_pai->step-- ;
	}
}	/* -----  end of method Numero::~Numero  ----- */

