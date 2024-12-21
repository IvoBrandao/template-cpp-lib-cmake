
set(LIB_NAME Mylib)
set(LIB_NAMESPACE v1)
set(LIB_ALIAS ${LIB_NAME}::${LIB_NAMESPACE})

# Create a library target
add_library(${LIB_NAME} INTERFACE)
target_include_directories(${LIB_NAME} INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/include)

# Set C++ standard
target_compile_features(${LIB_NAME} INTERFACE cxx_std_17)

# Add the source/header files
target_sources(${LIB_NAME} INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/include/mylib.hpp)

# Create an alias for convenient usage
add_library(${LIB_ALIAS} ALIAS ${LIB_NAME} )

add_library(${LIB_NAME}_shared SHARED)
target_sources(${LIB_NAME}_shared PRIVATE ${CMAKE_CURRENT_LIST_DIR}/source/mylib.cpp)
target_include_directories(${LIB_NAME}_shared PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_link_libraries(${LIB_NAME}_shared PRIVATE ${LIB_ALIAS})
set_target_properties(${LIB_NAME}_shared PROPERTIES OUTPUT_NAME ${LIB_NAME})
install(TARGETS ${LIB_NAME}_shared LIBRARY DESTINATION lib)

# Optionally, build as a static library
add_library(${LIB_NAME}_static STATIC)
target_sources(${LIB_NAME}_static PRIVATE ${CMAKE_CURRENT_LIST_DIR}/source/mylib.cpp)
target_include_directories(${LIB_NAME}_static PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_link_libraries(${LIB_NAME}_static PRIVATE ${LIB_ALIAS})
set_target_properties(${LIB_NAME}_static PROPERTIES OUTPUT_NAME ${LIB_NAME})
install(TARGETS ${LIB_NAME}_static ARCHIVE DESTINATION lib)

# Installation
install(FILES mylib.h DESTINATION include)

# Testing # if enable_testing() is called in the root CMakeLists.txt
add_subdirectory(test)
