
# Installation prefix

```
cmake -D CMAKE_INSTALL_PREFIX=/home/myname/myfreefem ..

# Debug and release modes

```
cmake -D CMAKE_BUILD_Type=Debug ..
cmake -D CMAKE_BUILD_Type=Release ..
```

By default, CMake is configured in release mode.
Therefore, the two following lines are strictly equivalent:

```
cmake ..
cmake -D CMAKE_BUILD_Type=Release ..
```

# Useful CMake variables

```
CMAKE_SOURCE_DIR # root of the source repository (e.g. /home/myname/FreeFem-sources)
CMAKE_BINARY_DIR # root of the build directory (e.g. /home/myname/FreeFem-sources/build)

CMAKE_CURRENT_SOURCE_DIR # root of the source repository containing the current CMakeLists.txt
CMAKE_CURRENT_BINARY_DIR # root of the build repository associtated with the current CMakeLists.txt
```

# Debugging CMake

## Messages

CMake provides a useful function to print the content of variables.
It helps understanding why some variable contain some wrong value.

```
message(STATUS "My variable FOO is ${FOO}")
```

## Verbose mode

The verbose mode of ```make``` command is very useful to debug compilation and linking errors.

```
make VERBOSE=1
```

Note that it may be used with the parallel version of ```make```:

```
make -j 4 VERBOSE=1
```

