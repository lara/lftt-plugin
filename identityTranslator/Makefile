comma   := ,
CXX      = $(shell $(ROSE_INSTALLATION)/bin/rose-config cxx)
CPPFLAGS = $(shell $(ROSE_INSTALLATION)/bin/rose-config cppflags) -I.
CXXFLAGS = $(shell $(ROSE_INSTALLATION)/bin/rose-config cxxflags)
LIBDIRS  = $(shell $(ROSE_INSTALLATION)/bin/rose-config libdirs)
LDFLAGS  = $(shell $(ROSE_INSTALLATION)/bin/rose-config ldflags) -L. \
           $(addprefix -Wl$(comma)-rpath -Wl$(comma), $(subst :, , $(LIBDIRS)))

## Translator
TRANSLATOR=myTranslator
TRANSLATOR_SOURCE=$(TRANSLATOR).cpp

## Input testcode for translator
TESTCODE=atomicCheck.cpp

#-------------------------------------------------------------
# Makefile Targets
#-------------------------------------------------------------

all: $(TRANSLATOR)

# compile the translator and generate an executable
# -g -> to be used by default to enable debugging code
$(TRANSLATOR): $(TRANSLATOR_SOURCE)
	$(CXX) -g $(TRANSLATOR_SOURCE) $(CPPFLAGS) $(LDFLAGS) -o $(TRANSLATOR)

# test the translator for atomic operations
check: $(TRANSLATOR)
	./$(TRANSLATOR) -c -std=c++11 -I. -I$(ROSE_INSTALLATION)/include $(TESTCODE)

clean:
	rm -rf $(TRANSLATOR) *.o rose_* *.dot
