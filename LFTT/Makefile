comma   := ,
CXX      = $(shell $(ROSE_INSTALLATION)/bin/rose-config cxx)
CPPFLAGS = $(shell $(ROSE_INSTALLATION)/bin/rose-config cppflags) -I.
CXXFLAGS = $(shell $(ROSE_INSTALLATION)/bin/rose-config cxxflags)
LIBDIRS  = $(shell $(ROSE_INSTALLATION)/bin/rose-config libdirs)
LDFLAGS  = $(shell $(ROSE_INSTALLATION)/bin/rose-config ldflags) -L. \
           $(addprefix -Wl$(comma)-rpath -Wl$(comma), $(subst :, , $(LIBDIRS)))

## Translator
TRANSLATOR1=addDataStructureHeader
TRANSLATOR1_SOURCE=$(TRANSLATOR1).cpp

TRANSLATOR2=addDataStructureNodeHeader
TRANSLATOR2_SOURCE=$(TRANSLATOR2).cpp

TRANSLATOR3=modifyDataStructureNode
TRANSLATOR3_SOURCE=$(TRANSLATOR3).cpp

TRANSLATOR4=addLogicalStatus
TRANSLATOR4_SOURCE=$(TRANSLATOR4).cpp

# Input testcode for translator
TESTCODE=LFTT.h
TESTCODE2=LogicalStatus.h
TESTCODE3=$(LINKED_LIST_NODE_PATH)
TESTCODE4=$(LINKED_LIST_PATH)
#-------------------------------------------------------------
# Makefile Targets #-------------------------------------------------------------

all: $(TRANSLATOR2) $(TRANSLATOR1) $(TRANSLATOR3) $(TRANSLATOR4)

# compile the translator and generate an executable
# -g -> to be used by default to enable debugging code
$(TRANSLATOR2): $(TRANSLATOR2_SOURCE)
	$(CXX) -g $(TRANSLATOR2_SOURCE) $(CPPFLAGS) $(LDFLAGS) -o $(TRANSLATOR2)

$(TRANSLATOR1): $(TRANSLATOR1_SOURCE)
	$(CXX) -g $(TRANSLATOR1_SOURCE) $(CPPFLAGS) $(LDFLAGS) -o $(TRANSLATOR1)

$(TRANSLATOR3): $(TRANSLATOR3_SOURCE)
	$(CXX) -g $(TRANSLATOR3_SOURCE) $(CPPFLAGS) $(LDFLAGS) -o $(TRANSLATOR3)

$(TRANSLATOR4): $(TRANSLATOR4_SOURCE)
	$(CXX) -g $(TRANSLATOR4_SOURCE) $(CPPFLAGS) $(LDFLAGS) -o $(TRANSLATOR4)


# test the translator for atomic operations
translate: $(TRANSLATOR2) $(TRANSLATOR1) $(TRANSLATOR3) $(TRANSLATOR4)
	cp $(TESTCODE2) RoseIntermediateCPPFile.cpp
	./$(TRANSLATOR2) -c -std=c++11 -I. -I$(ROSE_INSTALLATION)/include RoseIntermediateCPPFile.cpp
	cp rose_RoseIntermediateCPPFile.cpp src/rose_LogicalStatus.h
	rm rose_RoseIntermediateCPPFile.cpp
	rm RoseIntermediateCPPFile.cpp

	cp $(TESTCODE) RoseIntermediateCPPFile.cpp
	./$(TRANSLATOR1) -c -std=c++11 -I. -I$(ROSE_INSTALLATION)/include RoseIntermediateCPPFile.cpp
	cp rose_RoseIntermediateCPPFile.cpp src/rose_LFTT.h
	rm rose_RoseIntermediateCPPFile.cpp
	rm RoseIntermediateCPPFile.cpp
	cp $(TESTCODE3) RoseIntermediateCPPFile.cpp
	./$(TRANSLATOR3) -c -std=c++11 -I. -I$(ROSE_INSTALLATION)/include RoseIntermediateCPPFile.cpp
	cp rose_RoseIntermediateCPPFile.cpp src/rose_LinkedListNode.h
	rm rose_RoseIntermediateCPPFile.cpp
	rm RoseIntermediateCPPFile.cpp

	cp $(TESTCODE4) RoseIntermediateCPPFile.cpp
	./$(TRANSLATOR4) -c -std=c++11 -I. -I$(ROSE_INSTALLATION)/include RoseIntermediateCPPFile.cpp
	cp rose_RoseIntermediateCPPFile.cpp src/rose_LinkedList.h
	rm rose_RoseIntermediateCPPFile.cpp
	rm RoseIntermediateCPPFile.cpp

	cp LFTT.h LFTTTypeDef.h LogicalStatus.h src/

clean:
	rm -rf $(TRANSLATOR) *.o rose_* *.dot
