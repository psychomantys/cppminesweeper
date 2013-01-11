include include.mk

all: $(EXECUTAVEL).cpp $(FONTES) ../$(EXECUTAVEL)

../$(EXECUTAVEL): $(EXECUTAVEL).o $(OBJETOS)
	$(CXX) $(DFLAGS) $(LDFLAGS) $(EXECUTAVEL).o $(OBJETOS) -o $@

%.o : %.cpp
	$(CXX) $(DFLAGS) $(CFLAGS) $(CPPFLAGS) $< -o $@

%.o : %.cc
	$(CXX) $(DFLAGS) $(CFLAGS) $(CPPFLAGS) $< -o $@


# Limpa objetos e o executavel
clean:
	rm -rf $(EXECUTAVEL).o $(OBJETOS) ../$(EXECUTAVEL) ../gmon.out

# Limpa tudo que foi gerado.
distclean: clean
	rm -rf $(DOC_DIR) tags

# Gera documentação para o codigo
doc: $(DOC_DIR)/html/index.html $(DOXY_CONF) $(FONTES) $(HEADERS)
	doxygen $(DOXY_CONF)

$(DOC_DIR)/html/index.html: $(FONTES) $(HEADERS)

