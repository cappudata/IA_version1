cmake_minimum_required(VERSION 3.5)

project(Projet_IA_moteur_d_inference LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS off)
if(CMAKE_CXX_COMPILER_ID MATCHES "GNU")
add_compile_options(-Wall -Wpedantic)
endif()

add_executable(Projet_IA_moteur_d_inference main.cc regle.cc moteurdinference.cc)
