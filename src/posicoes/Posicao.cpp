/*
 * =====================================================================================
 *
 *       Filename:  Posicao.cpp
 *
 *    Description:  Implementação das possiveis posições do campo minado.
 *
 *        Version:  1.0
 *        Created:  04-02-2009 11:22:26
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Psycho Mantys (P.M.), psycho.mantys(.AT,)gmail dot com
 *
 * =====================================================================================
 */

/* #####   HEADER FILE INCLUDES   ################################################### */
#include	"Posicao.hpp"
#include	"../Campo_Minado.hpp"

/* #####   CLASS IMPLEMENTATIONS  -  EXPORTED CLASSES   ############################# */
Posicao::Posicao ( Campo_minado *campo, unsigned int x, unsigned int y ) : clicked(false) ,
	campo_pai(campo) 
	{
	this->x = x ;
	this->y = y ;
}	/* -----  end of method Posicao::Posicao  (constructor)  ----- */


char Posicao::get (){
	return this->simbolo ;
}	/* -----  end of method Posicao::get  ----- */

