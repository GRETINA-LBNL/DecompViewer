import sys
import os

colors = {}
colors['cyan']   = '\033[36m'
colors['purple'] = '\033[95m'
colors['blue']   = '\033[94m'
colors['green']  = '\033[92m'
colors['yellow'] = '\033[93m'
colors['red']    = '\033[91m'
colors['end']    = '\033[0m'

## If the output is not a terminal, remove the colors
if not sys.stdout.isatty():
   for key, value in colors.iteritems():
      colors[key] = ''

compile_source_message = '%sCompiling %s===================> %s$SOURCE%s' % \
   (colors['blue'], colors['purple'], colors['cyan'], colors['end'])

compile_shared_source_message = '%sCompiling shared %s============> %s$SOURCE%s' % \
   (colors['blue'], colors['purple'], colors['cyan'], colors['end'])

link_program_message = '%sLinking Program %s=============> %s$TARGET%s' % \
   (colors['red'], colors['purple'], colors['cyan'], colors['end'])

link_library_message = '%sLinking Static Library %s=====> %s$TARGET%s' % \
   (colors['red'], colors['purple'], colors['cyan'], colors['end'])

ranlib_library_message = '%sRanlib Library %s===========> %s$TARGET%s' % \
   (colors['red'], colors['purple'], colors['cyan'], colors['end'])

link_shared_library_message = '%sLinking Shared Library %s======> %s$TARGET%s' % \
   (colors['red'], colors['purple'], colors['cyan'], colors['end'])

java_library_message = '%sCreating Java Archive %s======> %s$TARGET%s' % \
   (colors['red'], colors['purple'], colors['cyan'], colors['end'])

root_dictionary_message = '%sGenerating ROOT dictionary %s==> %s$TARGET%s' % \
   (colors['red'], colors['purple'], colors['cyan'], colors['end'])
 
def rootcint(target, source, env):
    """Executes the ROOT dictionary generator over a list of headers. """
    dictname = target[0]
    headers = ""
    for f in source:
    	headers += str(f) + " "

    command = "rootcint -f %s -c -p %s" %(dictname, headers)
    ok = os.system(command)
    return ok

## Create construction environment propagating the external environment
env = Environment(ENV=os.environ, 
      		  CXXCOMSTR = compile_source_message,
  		  CCCOMSTR = compile_source_message,
  		  SHCCCOMSTR = compile_shared_source_message,
  		  SHCXXCOMSTR = compile_shared_source_message,
  		  ARCOMSTR = link_library_message,
  		  RANLIBCOMSTR = ranlib_library_message,
  		  SHLINKCOMSTR = link_shared_library_message,
  		  LINKCOMSTR = link_program_message,
  		  JARCOMSTR = java_library_message,
  		  JAVACCOMSTR = compile_source_message) 

## Create a rootcint builder and attach it to the environment
bld = Builder(action=Action(rootcint,root_dictionary_message))
env.Append(BUILDERS = {'RootCint':bld})

## Optimization flags ##################################################
env.Append(CCFLAGS = ['-O2', '-D_FILE_OFFSET_64', '-g'])

## Finding dependencies (ROOT)
try:
    env.ParseConfig('root-config --cflags')
    env.ParseConfig('root-config --glibs')
except OSError:
    print "scons: ROOT not found!"
    exit(1)

env.Append(CPPPATH='#')
env.Append(LIBPATH='.')

envDecompView = env.Clone()

## Building GRETINADict and libGRETINA #################################
gretinaDictTarget = 'src/GRETINADict.cpp'
gretinaDictHeaders = ['src/GRETINA.h', 'src/GRETINAWavefunction.h',
		      'src/LinkDefGRETINA.h']
env.RootCint(gretinaDictTarget, gretinaDictHeaders)

gretinaLibTarget = 'GRETINA'
gretinaLibSources = ['src/GRETINADict.cpp', 'src/GRETINA.cpp', 
		     'src/G3Waveform.cpp']
env.SharedLibrary(target = gretinaLibTarget, source = gretinaLibSources, 
                  SHLIBPREFIX='lib')

## Building DecompViewerDict and libDecompViewer ########################
decompViewerDictTarget = 'src/DecompViewerDict.cpp'
decompViewerDictHeaders = ['src/decompViewer.h', 'src/decompViewerLinkDef.h'] 
env.RootCint(decompViewerDictTarget, decompViewerDictHeaders)

decompViewerLibTarget = 'DecompViewer'
decompViewerLibSources = ['src/DecompViewerDict.cpp', 'src/decompViewer.cpp']
env.SharedLibrary(target = decompViewerLibTarget, 
	 	  source = decompViewerLibSources, SHLIBPREFIX='lib')

## Building DecompViewer executable ######################################
viewerTarget = 'DecompViewer'
viewerSources = ['src/decompViewer.cpp']
envDecompView.Append(LIBS=['DecompViewer', 'GRETINA'])
envDecompView.Program(target = viewerTarget, source = viewerSources)