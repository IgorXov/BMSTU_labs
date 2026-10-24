cmake_minimum_required(VERSION 4.2)
project(BMSTU_labs C)

# Лабораторная 6
add_executable(lab6 labs/lab6/lab6.c)

# Лабораторная 8
add_executable(lab8 labs/lab8/lab8.c)

# Лабораторная 9
add_executable(lab9 labs/lab9/lab9.c)

# Рейтинг (если нужно)
add_executable(rating_first raiting/first/fir.c)
add_executable(rating_second raiting/second/sec.c)