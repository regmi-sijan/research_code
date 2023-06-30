AUTOMAKE_OPTIONS = foreign

AM_CPPFLAGS = \
  -I$(includedir) \
  -I$(OFFLINE_MAIN)/include \
  -I$(ROOTSYS)/include

lib_LTLIBRARIES = \
  libsavecatonode_io.la \
  libsavecatonode.la

AM_LDFLAGS = \
  -L$(libdir) \
  -L$(OFFLINE_MAIN)/lib

libsavecatonode_io_la_LIBADD = \
  -lphool

libsavecatonode_la_LDFLAGS = \
  -L$(libdir) \
  -L$(OFFLINE_MAIN)/lib \
  -lcalo_io \
  -lfun4all \
  -lg4detectors_io \
  -lphg4hit \
  -lg4dst \
  -lg4eval \
  `fastjet-config --libs`

libsavecatonode_la_LIBADD = \
  libsavecatonode_io.la

pkginclude_HEADERS = \
  SaveCAtoNode.h \
  ClonesContainer.h \
  CaloInfo.h \
	TowerInfoContainer.h \
  TowerInfo.h

if ! MAKEROOT6
  ROOT5_DICTS = \
    SaveCAtoNode_Dict.cc \
    ClonesContainer_Dict.cc \
    CaloInfo_Dict.cc \
		TowerInfoContainer_Dict.cc \
	  TowerInfo_Dict.cc
endif

ROOTDICTS = \
  SaveCAtoNode_Dict.cc \
  ClonesContainer_Dict.cc \
	CaloInfo_Dict.cc \
	TowerInfoContainer_Dict.cc \
	TowerInfo_Dict.cc

pcmdir = $(libdir)
nobase_dist_pcm_DATA = \
  ClonesContainer_Dict_rdict.pcm \
  CaloInfo_Dict_rdict.pcm \
	TowerInfoContainer_Dict_rdict.pcm \
	TowerInfo_Dict_rdict.pcm \
  SaveCAtoNode_Dict_rdict.pcm

libsavecatonode_io_la_SOURCES = \
  $(ROOTDICTS) \
  ClonesContainer.cc \
  CaloInfo.cc \
	TowerInfoContainer.cc \
  TowerInfo.cc

libsavecatonode_la_SOURCES = \
  $(ROOT5_DICTS) \
  SaveCAtoNode.cc

################################################
# Rule for generating table CINT dictionaries.
%_Dict.cc: %.h %LinkDef.h
	rootcint -f $@ @CINTDEFS@ -c $(DEFAULT_INCLUDES) $(AM_CPPFLAGS) $^

#just to get the dependency
%_Dict_rdict.pcm: %_Dict.cc ;

# linking tests
noinst_PROGRAMS = \
  testexternals

testexternals_io_SOURCES = testexternals.cc
testexternals_io_LDADD   = libsavecatonode_io.la

testexternals_SOURCES = testexternals.C
testexternals_LDADD = libsavecatonode.la

testexternals.C:
	echo "//*** this is a generated file. Do not commit, do not edit" > $@
	echo "int main()" >> $@
	echo "{" >> $@
	echo "  return 0;" >> $@
	echo "}" >> $@



clean-local:
	rm -f *Dict* $(BUILT_SOURCES) *.pcm
