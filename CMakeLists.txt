cmake_minimum_required(VERSION 3.12)
project(cryptolib)

file(GLOB sourceFiles CMAKE_CONFIGURE_DEPENDS
	"blockCiphers/*.c"
	"ellipticCurves/*.c"
	"hashFunctions/*.c"
)

add_library(crypto ${sourceFiles})
target_include_directories(crypto PUBLIC ./crypto)
target_link_libraries(crypto gmp)

add_subdirectory(playground)