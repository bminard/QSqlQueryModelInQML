# PROJECT TEMPLATE (C++)

This repository contains a simple project template for your C++ applications.

## Prerequisites

Using this template requires that the following packages be installed.

1. CMake
2. [Doxygen](#doxygen-updates)

CMake will download and install Google Test in the project directory.

### Doxygen Updates

Update the following values in your Doxygen.in file.

```
(jtlib) ↪ diff  Doxyfile docs/Doxyfile.in
35c35
< PROJECT_NAME           = "My Project"
---
> PROJECT_NAME           = "Qt Database"
47c47
< PROJECT_BRIEF          =
---
> PROJECT_BRIEF          = "Experiments using Qt SQL database classes."
61c61
< OUTPUT_DIRECTORY       =
---
> OUTPUT_DIRECTORY       = @CMAKE_CURRENT_BINARY_DIR@/docs/
816c816
< INPUT                  =
---
> INPUT                  = @CMAKE_CURRENT_SOURCE_DIR@
1022c1022
< SOURCE_BROWSER         = NO
---
> SOURCE_BROWSER         = YES
1497c1497
< GENERATE_TREEVIEW      = NO
---
> GENERATE_TREEVIEW      = YES
1552c1552
< USE_MATHJAX            = NO
---
> USE_MATHJAX            = YES
2252c2252
< HIDE_UNDOC_RELATIONS   = YES
---
> HIDE_UNDOC_RELATIONS   = NO
2261c2261
< HAVE_DOT               = NO
---
> HAVE_DOT               = YES
2327c2327
< UML_LOOK               = NO
---
> UML_LOOK               = YES
2378c2378
< CALL_GRAPH             = NO
---
> CALL_GRAPH             = YES
2390c2390
< CALLER_GRAPH           = NO
---
> CALLER_GRAPH           = YES
```
## Set Up

To set up a new project, run the following commands.

```
git clone git@github.com:bminard/project_template_cpp.git
cd project_template_cpp
rm -fr .git
git init
vim README.md
git add README.md
git commit -m "Initial commit"
make init
git add .
make
```

## Make Output

If the project set up is sucessful, then the make output should look something line the following.
(The tests fail intentionally.)

```
Cloning into 'project_template_cpp'...
Enter passphrase for key '/Users/brian/.ssh/id_rsa': 
remote: Enumerating objects: 24, done.
remote: Counting objects: 100% (24/24), done.
remote: Compressing objects: 100% (20/20), done.
remote: Total 24 (delta 7), reused 10 (delta 0), pack-reused 0
Receiving objects: 100% (24/24), 5.37 KiB | 5.37 MiB/s, done.
Resolving deltas: 100% (7/7), done.
Initialized empty Git repository in /Users/brian/Desktop/programs/project_template_cpp/.git/
[master (root-commit) fdb9484] Initial commit
 1 file changed, 1 insertion(+)
 create mode 100644 README.md
mkdir -p docs
doxygen -g docs/Doxyfile.in


Configuration file `docs/Doxyfile.in' created.

Now edit the configuration file and enter

  doxygen docs/Doxyfile.in

to generate the documentation for your project

mkdir -p build
cd build; cmake -DCMAKE_BUILD_TYPE=Debug ..; make
-- The C compiler identification is AppleClang 10.0.1.10010046
-- The CXX compiler identification is AppleClang 10.0.1.10010046
-- Check for working C compiler: /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc
-- Check for working C compiler: /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc -- works
-- Detecting C compiler ABI info
-- Detecting C compiler ABI info - done
-- Detecting C compile features
-- Detecting C compile features - done
-- Check for working CXX compiler: /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++
-- Check for working CXX compiler: /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ -- works
-- Detecting CXX compiler ABI info
-- Detecting CXX compiler ABI info - done
-- Detecting CXX compile features
-- Detecting CXX compile features - done
-- Found Doxygen: /usr/local/bin/doxygen (found version "1.8.15") found components:  doxygen dot 
Doxygen build started
-- Configuring done
-- Generating done
-- Build files have been written to: /Users/brian/Desktop/programs/project_template_cpp/build/googletest-download
gmake[1]: Entering directory '/Users/brian/Desktop/programs/project_template_cpp/build/googletest-download'
gmake[2]: Entering directory '/Users/brian/Desktop/programs/project_template_cpp/build/googletest-download'
gmake[3]: Entering directory '/Users/brian/Desktop/programs/project_template_cpp/build/googletest-download'
Scanning dependencies of target googletest
gmake[3]: Leaving directory '/Users/brian/Desktop/programs/project_template_cpp/build/googletest-download'
gmake[3]: Entering directory '/Users/brian/Desktop/programs/project_template_cpp/build/googletest-download'
[ 11%] Creating directories for 'googletest'
[ 22%] Performing download step (git clone) for 'googletest'
Cloning into 'googletest-src'...
Already on 'master'
Your branch is up to date with 'origin/master'.
[ 33%] No patch step for 'googletest'
[ 44%] Performing update step for 'googletest'
Current branch master is up to date.
[ 55%] No configure step for 'googletest'
[ 66%] No build step for 'googletest'
[ 77%] No install step for 'googletest'
[ 88%] No test step for 'googletest'
[100%] Completed 'googletest'
gmake[3]: Leaving directory '/Users/brian/Desktop/programs/project_template_cpp/build/googletest-download'
[100%] Built target googletest
gmake[2]: Leaving directory '/Users/brian/Desktop/programs/project_template_cpp/build/googletest-download'
gmake[1]: Leaving directory '/Users/brian/Desktop/programs/project_template_cpp/build/googletest-download'
-- Found PythonInterp: /Users/brian/Envs/jtlib/bin/python (found version "3.7.2") 
-- Looking for pthread.h
-- Looking for pthread.h - found
-- Looking for pthread_create
-- Looking for pthread_create - found
-- Found Threads: TRUE  
-- Configuring done
-- Generating done
-- Build files have been written to: /Users/brian/Desktop/programs/project_template_cpp/build
Scanning dependencies of target gtest
[ 11%] Building CXX object googletest-build/googletest/CMakeFiles/gtest.dir/src/gtest-all.cc.o
[ 22%] Linking CXX static library ../../lib/libgtestd.a
[ 22%] Built target gtest
Scanning dependencies of target gtest_main
[ 33%] Building CXX object googletest-build/googletest/CMakeFiles/gtest_main.dir/src/gtest_main.cc.o
[ 44%] Linking CXX static library ../../lib/libgtest_maind.a
[ 44%] Built target gtest_main
Scanning dependencies of target t_new_project
[ 55%] Building CXX object CMakeFiles/t_new_project.dir/t_new_project.cc.o
[ 66%] Linking CXX executable t_new_project
[ 66%] Built target t_new_project
Scanning dependencies of target new_project
[ 77%] Building CXX object CMakeFiles/new_project.dir/new_project.cc.o
[ 88%] Linking CXX executable new_project
[ 88%] Built target new_project
Scanning dependencies of target doc_doxygen
[100%] Generating API documentation with Doxygen
Searching for include files...
Searching for example files...
Searching for images...
Searching for dot files...
Searching for msc files...
Searching for dia files...
Searching for files to exclude
Searching INPUT for files to process...
Searching for files in directory /Users/brian/Desktop/programs/project_template_cpp/build
Reading and parsing tag files
Parsing files
Building group list...
Building directory list...
Building namespace list...
Building file list...
Building class list...
Associating documentation with classes...
Computing nesting relations for classes...
Building example list...
Searching for enumerations...
Searching for documented typedefs...
Searching for members imported via using declarations...
Searching for included using directives...
Searching for documented variables...
Building interface member list...
Building member list...
Searching for friends...
Searching for documented defines...
Computing class inheritance relations...
Computing class usage relations...
Flushing cached template relations that have become invalid...
Computing class relations...
Add enum values to enums...
Searching for member function documentation...
Creating members for template instances...
Building page list...
Search for main page...
Computing page relations...
Determining the scope of groups...
Sorting lists...
Freeing entry tree
Determining which enums are documented
Computing member relations...
Building full member lists recursively...
Adding members to member groups.
Computing member references...
Inheriting documentation...
Generating disk names...
Adding source references...
Adding xrefitems...
Sorting member lists...
Computing dependencies between directories...
Generating citations page...
Counting data structures...
Resolving user defined references...
Finding anchors and sections in the documentation...
Transferring function references...
Combining using relations...
Adding members to index pages...
Generating style sheet...
Generating search indices...
Generating example documentation...
Generating file sources...
Generating file documentation...
Generating page documentation...
Generating group documentation...
Generating class documentation...
Generating namespace index...
Generating graph info page...
Generating directory documentation...
Generating index page...
Generating page index...
Generating module index...
Generating namespace index...
Generating namespace member index...
Generating annotated compound index...
Generating alphabetical compound index...
Generating hierarchical class index...
Generating member index...
Generating file index...
Generating file member index...
Generating example index...
finalizing index lists...
writing tag file...
lookup cache used 0/65536 hits=0 misses=0
finished...
[100%] Built target doc_doxygen
make -C build test
Running tests...
Test project /Users/brian/Desktop/programs/project_template_cpp/build
    Start 1: TestMain.TestExecution
1/2 Test #1: TestMain.TestExecution ...........***Failed    0.01 sec
    Start 2: t_new_project
2/2 Test #2: t_new_project ....................***Failed    0.00 sec

0% tests passed, 2 tests failed out of 2

Total Test time (real) =   0.01 sec

The following tests FAILED:
	  1 - TestMain.TestExecution (Failed)
	  2 - t_new_project (Failed)
Errors while running CTest
make[1]: *** [test] Error 8
make: *** [test] Error 2
```
