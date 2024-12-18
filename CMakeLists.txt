cmake_minimum_required(VERSION 3.29)
project(AtividadeAlgoritmos C)

set(CMAKE_C_STANDARD 23)

add_executable(AtividadeAlgoritmos main.c
        lista/lista.h
        lista/lista.c
        sort/sort_alg.h
        sort/sort_alg.c
        tabela_hash/tabela_hash.h
        tabela_hash/tabela_hash.c)
