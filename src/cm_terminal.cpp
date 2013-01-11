/*
 * =====================================================================================
 *
 *       Filename:  main.c
 *
 *    Description:  Arquivo principal do campo minado.
 *
 *        Version:  1.0
 *        Created:  20-01-2009 14:39:31
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Psycho Mantys (P.M.), psycho.mantys(.AT,)gmail dot com
 *
 * =====================================================================================
 */
/** 
* @file main.c
* @brief Um jogo de campo minado feito para o terminal.
* @author Psycho Mantys
* @date 2009-01-23
*/

/* #####   HEADER FILE INCLUDES   ################################################### */
#include	"Campo_Minado.hpp"
#include	<memory>
#include	<cstdio>
#include	<cstdlib>

using std::auto_ptr ;

/* #####   MACROS  -  LOCAL TO THIS SOURCE FILE   ################################### */
#ifdef __win32__
	#define CLEAR "cls"
#else
	#define CLEAR "clear"
#endif

/* #####   PROTOTYPES  -  LOCAL TO THIS SOURCE FILE   ############################### */

int main ( int argc, char *argv[] ){
	int x,y, qtdBombas , opcao ;

	/* Cria um jogo */
	auto_ptr<Campo_minado> jogo;

	system(CLEAR);
	do{
		printf("Bem vindo ao jogo do campo minado!!\nDigite o tamanho do seu jogo e a quantidade de bombas:(x y qtdBombas):\n");
		scanf("%d %d %d",&x,&y,&qtdBombas);

		jogo.reset(new Campo_minado( x , y , qtdBombas ) );
		system(CLEAR);
		if ( ! jogo.get() )
			printf("Erro ao criar jogo. Passe valores certos!\n");
	}
	while ( ! jogo.get() ) ;

//	cm_make_field( jogo );

	while ( ! jogo->isEnd() ){
		system(CLEAR);
		jogo->display();

		printf("Escolha a sua ação:\n1 ) Arriscar um campo.\n2 ) Colocar Bandeira.\n3 ) Sair\n4 ) Reiniciar o jogo\n");
		scanf("%d", &opcao);

		switch (opcao){
			case 1 :
				printf("Qual o campo que você quer arriscar? ( x y )\n");
				scanf("%d %d",&x,&y);
				jogo->jogar(x,y);
			break;
			case 2 :
				printf("Qual o campo que você quer colocar a bandeira? ( x y )\n");
				scanf("%d %d",&x,&y);
				jogo->add_flag(x,y);
			break;
			case 3 :
				return EXIT_SUCCESS;
			break;
			case 4 :
				jogo->reset();
			break;

		}
	}

	system(CLEAR);
	jogo->display();

	if ( jogo->isWinner() ){
		printf("Parabens, você ganhou!!\n");
	}else{
		printf("Você perdeu, tente de novo ;).\n");
	}

	return EXIT_SUCCESS;
}	/* ----------  end of function main  ---------- */

