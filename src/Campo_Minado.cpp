/*
 * =====================================================================================
 *
 *       Filename:  Campo_Minado.cpp
 *
 *    Description:  Implementa??o da classe Campo_minado.
 *
 *        Version:  1.0
 *        Created:  04-02-2009 16:18:33
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Psycho Mantys (P.M.), psycho.mantys(.AT,)gmail dot com
 *
 * =====================================================================================
 */
/** 
* @file Campo_Minado.cpp
* @brief Implementa??o da classe Campo_minado.
* @author Psycho Mantys
* @date 2009-02-10
*/
/* #####   HEADER FILE INCLUDES   ################################################### */
#include	"Campo_Minado.hpp"
#include	"posicoes/Posicao.hpp"
#include	"posicoes/Bandeira.hpp"
#include	"posicoes/Bomba.hpp"
#include	"posicoes/Numero.hpp"

#include	<iostream>
#include	<stdlib.h>
/* #####   CLASS IMPLEMENTATIONS  -  EXPORTED CLASSES   ############################# */

void Campo_minado::display(){
	for( unsigned int i=0 ; i<campo.size() ; ++i){
		for( unsigned int j=0 ; j<campo[i].size() ; ++j){
			if ( campo[i][j]->clicked ){
				std::cout << campo[i][j]->get() << " " ;
			}else{
				std::cout << "  " ;
			}
		}
		std::cout << "\n" ;
	}
}

Campo_minado::Campo_minado ( unsigned int x , unsigned int y , unsigned int bomb ) : 
	campo( y , vector<Posicao*>(x) ) ,
	inicio( clock() ) ,
	lose( false ) ,
	max_X( x ) ,
	max_Y( y ) ,
	qtd_bandeiras( 0 ) ,
	qtd_bombas( bomb ) ,
	step( 0 ) ,
	max_step( x*y )
	{

	srand ( time(NULL) );

	/* Cria o campo com todas as posic?es vazias */
	for( unsigned int i=0 ; i<max_X ; ++i){
		for( unsigned int j=0 ; j<max_Y ; ++j){
			campo[j][i] = new Numero(this,i,j);
		}
	}

	/* Distribui as bombas no campo */
	fill_field_with_bombs();
}

bool Campo_minado::isEnd(){
	return lose or ( max_step==(step+qtd_bandeiras) and (qtd_bandeiras==qtd_bombas) ) ;
}

bool Campo_minado::isWinner(){
	return ( not lose ) and isEnd() ;
}

double Campo_minado::game_time(){
	return (double)( (clock()-inicio)/CLOCKS_PER_SEC );
}

 
//template<typename _funcao>
void Campo_minado::executa_nos_lados(Posicao* posicao , void (funcao)(Posicao*) ){
	int x=(int)(posicao->x) , y=(int)(posicao->y) ;
	/* Executa no meio */
	if ( x > 0 ){
		funcao( this->campo[y][x-1] );
	}
	if ( x < (int)(this->max_X-1) ){
		funcao( this->campo[y][x+1] );
	}
	/* Executa as casas de baixo */
	y-- ;
	if ( y >= 0 ){
		funcao( this->campo[y][x] );

		if ( x > 0 )
			funcao( this->campo[y][x-1] );
		if ( x < (int)(this->max_X-1) )
			funcao( this->campo[y][x+1] );
	}
	/* Executa as casas de cima */
	y+=2 ;
	if ( y < (int)(this->max_Y) ){
		funcao( this->campo[y][x] );

		if ( x > 0 ){
			funcao( this->campo[y][x-1] );
		}
		if ( x < (int)(this->max_X-1) )
			funcao( this->campo[y][x+1] );
	}
}

void Campo_minado::reset(){
	inicio = clock();
	/* Falta implementar ainda */
	/* REMAINS TO BE IMPLEMENTED */
}

bool Campo_minado::jogar( unsigned int x , unsigned int y ){
	if ( (x >= max_X) or (y >= max_Y) or campo[y][x]->get()==Posicao::flag )
		return false ;
	campo[y][x]->click();
	return true;
}

bool Campo_minado::add_flag(unsigned int x , unsigned int y){
	if ( ((x >= max_X) or (y >= max_Y)) and (campo[y][x]->get()!=Posicao::flag) )
		return false ;
	Posicao* aux ;
	aux = campo[y][x] ;
	campo[y][x] = new Bandeira(aux) ;
	return true ;
}

void Campo_minado::fill_field_with_bombs(){
	unsigned int i,x,y;
	x = this->max_X;
	y = this->max_Y;
	/* Coloca bombas no campo */
	for ( i=0 ; i<qtd_bombas ; ++i ){
		int temp1 = random() % y ;
		int temp2 = random() % x ;
		while( not (campo[temp1][temp2]->get() >= Posicao::vazio and campo[temp1][temp2]->get() <= Posicao::maior_numero) ){
			temp1 = random() % y ;
			temp2 = random() % x ;
		}
		std::cout << temp2 << " " << temp1 << " " << campo[temp1][temp2]->get()  << "\n" ;
		delete campo[temp1][temp2] ;
		campo[temp1][temp2] = new Bomba(this,temp2,temp1) ;
	}
}

/* #####   CLASS IMPLEMENTATIONS  -  LOCAL CLASSES   ################################ */

