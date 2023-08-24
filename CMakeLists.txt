#
# DANTE :: System Automatycznych Testów Jednostkowych oraz Akceptacyjnych
# Tomasz Jaworski, 2018-2020
#
# Plik wygenerowany automatycznie
# Znacznik czasowy: 2022-01-08 15:30:04.391240
#

cmake_minimum_required(VERSION 3.17)
project(project1 C)

# Przyjmij standard C11
set(CMAKE_C_STANDARD 11)

# Ustaw opcje kompilatora (z raportu Dante)
add_compile_options(
      "-DINSIDE_DANTE"
      "-Wall"
      "-pedantic"
      "-Wextra"
      "-Werror"
      "-fmax-errors=5"
      "-fdiagnostics-color"
      "-D_ANSI_OUTPUT"
      "-Wno-parentheses"
      "-Werror=vla"
      "-Wno-error=implicit-fallthrough"
      "-D_GNU_SOURCE"
      "-std=c11"
      "-xc"
      "-Wno-error=parentheses"
      "-ggdb3"
      "-Wno-error=unused-parameter"

)

# Ustaw opcje konsolidatora (z raportu Dante)
add_link_options(
        "-Wl,-cref"
        "-Wl,-Map=main.map"
        "-Wl,-wrap,main"
        "-ggdb3"
)

# Utwórz target 'project1' i dodaj do niego pliki źródlowe:
add_executable(project1
        "file_reader.c"
        "main.c"
        "unit_helper_v2.c"
        "unit_test_v2.c"
        "rdebug.c"
)

# Dołącz niezbędne biblioteki
target_link_libraries(project1
        "m"
)