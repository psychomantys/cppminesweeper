
FONTES= posicoes/Posicao.cpp posicoes/Bandeira.cpp posicoes/Bomba.cpp posicoes/Numero.cpp Campo_Minado.cpp

#DOC_DIR=../doc
#DOXY_CONF=../Doxyfile
CXX=g++

EXECUTAVEL=cm_terminal

DEBUG=yes
ifeq ($(DEBUG),yes)
DFLAGS=-O0 -g -pg
else
DFLAGS=-DNDEBUG
endif

CFLAGS= -c -O2 -Wall
LDFLAGS= -O2 -Wall

OBJETOS=$(patsubst %.cc,%.o,$(patsubst %.cpp,%.o,$(FONTES)))
HEADERS=$(patsubst %.cc,%.hpp,$(patsubst %.cpp,%.hpp,$(FONTES)))


