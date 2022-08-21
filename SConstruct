#!/usr/bin/env python

import os

EnsureSConsVersion(3, 0, 0)
EnsurePythonVersion(3, 6)

env = Environment()
env.ParseConfig("pkg-config --cflags --libs sdl2")

print(env)

env.Append(CPPPATH=["src", "include"])

matches = []

for dirname in env['CPPPATH']:
    globStr = "%s/*.c*" % dirname
    matches.append(Glob(globStr))

# debug output
print('src env CPPPATH:')
print(env['CPPPATH'])

# build a shared library
env.SharedLibrary('bin/sengine', matches)