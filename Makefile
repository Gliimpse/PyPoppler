
PYTHON = /Users/kbranson/.virtualenv/development/bin/python
PYINC = -DHAVE_CONFIG_H -I/Users/kbranson/.virtualenv/development/include/python2.7
PYTHON_DLINK = -Wl,-rpath,@loader_path/.

MODULE = .so
MODULEFLAGS = -bundle -undefined dynamic_lookup 
#MODULEFLAGS = -bundle -undefined dynamic_lookup
DLL = .dylib
LINK = 

POPPLERINC = /usr/local/include/poppler/cpp

VPATH = /usr/local/include/poppler/cpp
LOCALLIBS = -lz -lpoppler-cpp
CXX = g++
CXXFLAGS =    -W -Wall  -DSWIG_COBJECT_TYPES  -O3 -fomit-frame-pointer -ffast-math -arch x86_64 -msse3
CSOFLAGS = -dynamic -fPIC -fno-common
CXXSHARED = ${MODULEFLAGS} 

SWIG	= /usr/local/bin/swig
SWIGOPT	= -modern -c++ -python


OBJECT =  poppler.o popplerExtension.o

_popplerExtension.so: $(OBJECT)
	 g++ $(CXXSHARED) $(OBJECT) $(PYTHON_DLINK) -o _popplerExtension$(MODULE) ${LOCALLIBS}; \




%.o: %.cc
	        g++  -c $(CXXFLAGS) $(CSOFLAGS) -I$(POPPLERINC) -o $@ $< 

%.o: %.cxx
	        g++  -c $(CXXFLAGS) $(CSOFLAGS) -I$(POPPLERINC) -I$(PYINC) -o $@ $< 

poppler.o: 	poppler.cc poppler.h
popplerExtension.o: 	popplerExtension.cxx
popplerExtension.cxx:	popplerExtension.i
	$(SWIG) -I${VPATH}  $(SWIGOPT) -o $@ $<	
#
#
clean:
	rm *.cxx
	rm $(OBJECT)

test:
	$(PYTHON) test.py 


