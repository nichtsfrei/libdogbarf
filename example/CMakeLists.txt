cmake_minimum_required(VERSION 3.13...3.16 FATAL_ERROR)
project(dogbarfcal_example_c VERSION 0.0.1 LANGUAGES C)

add_executable(print-weekly ./print_weekly.c)
find_package(Dogbarfcal REQUIRED)
target_link_libraries(print-weekly Dogbarfcal::Dogbarfcal)
target_link_options(print-weekly PRIVATE
    -fsanitize=address)
target_compile_options(print-weekly PRIVATE
    -Wall -Wextra -Werror -Wsequence-point -Wstrict-prototypes -Wshadow -Wmissing-prototypes -Wpedantic -fsanitize=address)
