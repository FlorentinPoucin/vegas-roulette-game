cmake_minimum_required(VERSION 2.6)
file(TO_CMAKE_PATH "$ENV{IMAGINEPP_ROOT}/CMake" p)
list(APPEND CMAKE_MODULE_PATH "${p}") #For old Imagine++
list(APPEND CMAKE_SYSTEM_FRAMEWORK_PATH /Library/Frameworks) #Mac, why not auto?
find_package(Imagine REQUIRED)

project(Projet)
add_executable(Projet Projet.cpp roullette.cpp roullette.h tapis.cpp tapis.h affichage.cpp affichage.h)
ImagineUseModules(Projet Graphics)
