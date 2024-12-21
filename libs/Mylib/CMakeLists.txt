set(LIB_NAME Mylib)
# Add any dependencies here (other libraries that this one depends on)
set(LIB_DEPS)


# --------------------------------------------
# Header-only Library Template
# --------------------------------------------
#
# # Create a header-only library target
# # This type of library is just an interface, no source files are required.
# add_library(${LIB_NAME} INTERFACE)
#
# # Set C++ standard
# target_compile_features(${LIB_NAME} INTERFACE cxx_std_17)
#
# # Specify the location of the public headers (API)
# target_include_directories(${LIB_NAME} INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/api)
#
# # Install the public headers (only *.hpp files)
# install(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/api/
#     DESTINATION include
#     FILES_MATCHING PATTERN "*.hpp"
# )
#
# # Optional: Add tests if needed
# if (BUILD_TESTING)
#     add_subdirectory(test)
# endif()
#

# --------------------------------------------
# Shared Library Template
# --------------------------------------------

# Create a shared library target
add_library(${LIB_NAME} SHARED)

# Set C++ standard
target_compile_features(${LIB_NAME} INTERFACE cxx_std_17)

# Collect all source files in the 'source' directory
file(GLOB LIB_SOURCES ${CMAKE_CURRENT_LIST_DIR}/source/*.cpp)

# Add the source files to the target
target_sources(${LIB_NAME} PRIVATE ${LIB_SOURCES})

# Include directories
target_include_directories(${LIB_NAME}
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/api  # Public headers (API)
    PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include  # Private headers (implementation)
)

# Link dependencies (if any)
target_link_libraries(${LIB_NAME} PRIVATE ${LIB_DEPS})

# Set versioning properties
set_target_properties(${LIB_NAME} PROPERTIES
    OUTPUT_NAME ${LIB_NAME}  # Ensures the installed library is named libMylib.so
    SOVERSION ${PROJECT_VERSION_MAJOR}
    VERSION ${PROJECT_VERSION}
)

# Install the shared library
install(TARGETS ${LIB_NAME}
    LIBRARY DESTINATION lib
    INCLUDES DESTINATION include
)

# Install the public headers (API)
install(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/api/
    DESTINATION include
    FILES_MATCHING PATTERN "*.hpp"
)

# Optional: Add tests if needed
if (BUILD_TESTING)
    add_subdirectory(test)
endif()


# --------------------------------------------
# Shared Library Template
# --------------------------------------------
# --------------------------------------------
# Static Library Template
# --------------------------------------------
# set(LIB_NAME Mylib)
# set(LIB_DEPS)  # Add any dependencies here
#
# # Create a static library target
# # This library will be linked statically into the target project.
# add_library(${LIB_NAME} STATIC)
#
# # Set C++ standard
# target_compile_features(${LIB_NAME} INTERFACE cxx_std_17)
#
# # Collect all source files in the 'source' directory
# file(GLOB LIB_SOURCES ${CMAKE_CURRENT_LIST_DIR}/source/*.cpp)
#
# # Add the source files to the target
# target_sources(${LIB_NAME} PRIVATE ${LIB_SOURCES})
#
# # Include directories
# target_include_directories(${LIB_NAME}
#     PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/api  # Public headers (API)
#     PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include  # Private headers (implementation)
# )
#
# # Link dependencies (if any)
# target_link_libraries(${LIB_NAME} PRIVATE ${LIB_DEPS})
#
# # Install the static library
# install(TARGETS ${LIB_NAME}
#     ARCHIVE DESTINATION lib
# )
#
# # Install the public headers (API)
# install(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/api/
#     DESTINATION include
#     FILES_MATCHING PATTERN "*.hpp"
# )
#
# # Optional: Add tests if needed
# if (BUILD_TESTING)
#     add_subdirectory(test)
# endif()
