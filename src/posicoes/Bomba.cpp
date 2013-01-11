/*
 * =====================================================================================
 *
 *       Filename:  Bomba.cpp
 *
 *    Description:  Implementa??o da posi??o que representa uma bomba no campo minado.
 *
 *        Version:  1.0
 *        Created:  12/10/05 02:08:32
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Psycho Mantys (P.M.), psycho.mantys(.AT,)gmail dot com
 *
 * =====================================================================================
 */
/** 
* @file Bomba.cpp
* @brief Implementa??o da posi??o que representa uma bomba no campo minado.
* @author Psycho Mantys
* @date 2005-12-10
*/

/* #####   HEADER FILE INCLUDES   ################################################### */
#include	"Bomba.hpp"
#include	"../Campo_Minado.hpp"
#include	<stdio.h>

/* #####   CLASS IMPLEMENTATIONS  -  EXPORTED CLASSES   ############################# */
Bomba::Bomba( Campo_minado* campo , unsigned int x , unsigned int y ) : Posicao( campo , x , y ) {
	this->simbolo = Posicao::bomba ;
	campo_pai->executa_nos_lados(this , Bomba::incrementa );
}

void Bomba::click(){
	campo_pai->lose = true ;
	this->clicked = true ;
}

void Bomba::incrementa( Posicao *posicao ){
	printf("x:%d y:%d\n",posicao->x,posicao->y);
	if ( posicao->simbolo >= Posicao::vazio and posicao->simbolo <= Posicao::maior_numero )
		posicao->simbolo++ ;
}

