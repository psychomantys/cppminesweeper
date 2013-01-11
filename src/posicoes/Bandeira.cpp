/*
 * =====================================================================================
 *
 *       Filename:  Bandeira.cpp
 *
 *    Description:  Implementa??o de uma posi??o do campo minado que ? uma bandeira.
 *
 *        Version:  1.0
 *        Created:  12/10/05 01:49:31
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Psycho Mantys (P.M.), psycho.mantys(.AT,)gmail dot com
 *
 * =====================================================================================
 */
/** 
* @file Bandeira.cpp
* @brief Implementa??o de uma posi??o do campo minado que ? uma bandeira.
* @author Psycho Mantys
* @date 2005-12-10
*/
/* #####   HEADER FILE INCLUDES   ################################################### */
#include	"Bandeira.hpp"
#include	"../Campo_Minado.hpp"
#include	<stdio.h>

/* #####   CLASS IMPLEMENTATIONS  -  EXPORTED CLASSES   ############################# */
Bandeira::Bandeira( Posicao *posicao ) : Posicao( posicao->campo_pai , posicao->x , posicao->y ) ,
	old(posicao) {

	this->clicked = true ;
	this->simbolo = Posicao::flag ;
	campo_pai->qtd_bandeiras++ ;
}	/* -----  end of method Bandeira::Bandeira  ----- */

void Bandeira::click(){
	this->clicked = true ;
	old->click();
	campo_pai->campo[y][x] = old.get() ;
	delete this;
	return ;
}	/* -----  end of method Bandeira::click  ----- */

Bandeira::~Bandeira(){
	campo_pai->qtd_bandeiras-- ;
}

