cmake_minimum_required(VERSION 3.15)
project(weblibdedx)

add_subdirectory(libs) # tu wchodze w cmake konfugurujacego libdedx

set_property(GLOBAL PROPERTY USE_FOLDERS ON)

#common functions
set(CMAKE_MODULE_PATH "${CMAKE_MODULE_PATH};${CMAKE_SOURCE_DIR}/cmake")
include(common)

find_c_and_cpp_files("${CMAKE_CURRENT_SOURCE_DIR}/include" weblibdedx_includes)
find_c_and_cpp_files("${CMAKE_CURRENT_SOURCE_DIR}/src" weblibdedx_sources)

source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${weblibdedx_includes} ${weblibdedx_sources})

add_executable(weblibdedx ${weblibdedx_includes} ${weblibdedx_sources})
target_include_directories(weblibdedx PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include ${CMAKE_CURRENT_SOURCE_DIR}/libs/libdedx)
target_link_libraries(weblibdedx PRIVATE dedx)
#
# set_target_properties(weblibdedx PROPERTIES LINK_FLAGS "FLAGI") - do ustawiania flag linkera - uwaga!
# mogą być zależne od kompilatora (jakby ktoś wpadl na pomysl kompilowania w gcc/msvc/clang)
# OPCJONALNE FLAGI DO WKOMPILOWANIA PLIKOW
# --bind -s DEMANGLE_SUPPORT=1--preload-file ${CMAKE_SOURCE_DIR}/assets

set_target_properties(weblibdedx
            PROPERTIES
            CXX_STANDARD 17
            CXX_STANDARD_REQUIRED YES
            CXX_EXTENSIONS NO
            )
