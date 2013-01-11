include src/include.mk
VPATH=src/

# Onde ficara a documentação. O caminho completo deve ser dado.
DOC_DIR=$(CURDIR)/doc
# Onde fica o arquivo de configuração que gera a documentação.
# O caminho completo deve ser dado.
DOXY_CONF=$(CURDIR)/Doxyfile

# Deixa o programa em modo de debug caso seja "yes". Qualquer outro valor,
# não fica no modo de debug.
DEBUG=yes

all:
	$(MAKE) -C src

# Limpa objetos e o executavel
clean:
	$(MAKE) -C src clean

# Limpa tudo que foi gerado.
distclean: clean
	rm -rf $(DOC_DIR) tags

# Gera documentação para o codigo
doc:
	$(MAKE) -C src doc DOC_DIR=$(DOC_DIR) DOXY_CONF=$(DOXY_CONF)

#cria tags do codigo
tags: $(FONTES) $(HEADERS)
	ctags -R --c++-kinds=+p --fields=+iaS --extra=+q ./

