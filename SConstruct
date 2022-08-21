#!/usr/bin/env python

import os
import SCons

EnsureSConsVersion(3, 0, 0)
EnsurePythonVersion(3, 6)

def remove_object_files(): 
    import os 
    import glob 
    print('Removing object files ..') 
    for tmp in glob.glob("src/*.o"): 
        os.remove(tmp) 
        print('Delete ' + str(tmp))

env = Environment()
env.ParseConfig("pkg-config --cflags --libs sdl2")

env.Append(CPPPATH=["src", "include"])

def GlobRecursive(pattern, node='.'):
    results = []
    for f in Glob(str(node) + '/*', source=True):
        if type(f) is SCons.Node.FS.Dir:
            results += GlobRecursive(pattern, f)
    results += Glob(str(node) + '/' + pattern, source=True)
    return results

matches = GlobRecursive("*.cpp", "src/")


# debug output
print('src env CPPPATH:')
print(env['CPPPATH'])

# build a shared library
env.StaticLibrary('bin/sengine', matches, LIBS=['SDL2'])
remove_object_files()