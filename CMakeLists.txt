cmake_minimum_required(VERSION 3.5)

project(matroska VERSION 2.0.0)

include(CMakeDependentOption)

option(DISABLE_PKGCONFIG "Disable PkgConfig module generation" OFF)
option(DISABLE_CMAKE_CONFIG "Disable CMake package config module generation" OFF)
cmake_dependent_option(BUILD_SHARED_LIBS "Build libebml as a shared library (except Windows)" OFF "NOT WIN32" OFF)
option(BUILD_TESTING "Build tests" OFF)
option(DEV_MODE "Developer mode with extra compilation checks" OFF)

find_package(EBML 2.0.0 REQUIRED)

include(GNUInstallDirs)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(CheckCXXCompilerFlag)
include(CMakeParseArguments)
function(add_cxx_flag_if_supported)
  foreach(flagname ${ARGN})
    string(REPLACE "-" "_" TEST_RESULT ${flagname})
    check_cxx_compiler_flag(${flagname} HAVE_FLAG_${TEST_RESULT})
    # message(STATUS "supported ${flagname}: ${HAVE_FLAG_${TEST_RESULT}}")

    if (HAVE_FLAG_${TEST_RESULT})
      add_compile_options(${flagname})
    endif()
  endforeach()
endfunction()

if(DEV_MODE)
  message(STATUS "Using developer mode for ${CMAKE_CXX_COMPILER_ID}")
  set(CMAKE_CXX_EXTENSIONS OFF)
  add_cxx_flag_if_supported(-Wno-error=unused-command-line-argument
                            -Wall -Wextra -Wpedantic -Wfatal-errors -fstack-protector-strong
                            -Wcast-align
                            -W4)
endif()

set(libmatroska_SOURCES
  src/KaxAttached.cpp
  src/KaxAttachments.cpp
  src/KaxBlock.cpp
  src/KaxBlockData.cpp
  src/KaxCluster.cpp
  src/KaxContexts.cpp
  src/KaxCues.cpp
  src/KaxCuesData.cpp
  src/KaxSeekHead.cpp
  src/KaxSegment.cpp
  src/KaxSemantic.cpp
  src/KaxTracks.cpp
  src/KaxVersion.cpp)

set(libmatroska_PUBLIC_HEADERS
  matroska/KaxBlockData.h
  matroska/KaxBlock.h
  matroska/KaxCluster.h
  matroska/KaxConfig.h
  matroska/KaxContexts.h
  matroska/KaxCuesData.h
  matroska/KaxCues.h
  matroska/KaxDefines.h
  matroska/KaxSeekHead.h
  matroska/KaxSegment.h
  matroska/KaxSemantic.h
  matroska/KaxTracks.h
  matroska/KaxTypes.h
  matroska/KaxVersion.h)

add_library(matroska ${libmatroska_SOURCES} ${libmatroska_PUBLIC_HEADERS})
target_link_libraries(matroska PUBLIC EBML::ebml)
set_target_properties(matroska PROPERTIES
  VERSION 8.0.0
  SOVERSION 8
  CXX_VISIBILITY_PRESET hidden
  VISIBILITY_INLINES_HIDDEN ON
)
target_include_directories(matroska
  PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
    $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>)
if(WIN32)
  target_compile_definitions(matroska PRIVATE _CRT_SECURE_NO_WARNINGS)
endif()

include(GenerateExportHeader)
generate_export_header(matroska EXPORT_MACRO_NAME MATROSKA_DLL_API)
target_sources(matroska
  PRIVATE
    ${CMAKE_CURRENT_BINARY_DIR}/matroska_export.h
)

if(NOT BUILD_SHARED_LIBS)
  target_compile_definitions(matroska PUBLIC MATROSKA_STATIC_DEFINE)
endif()

if(BUILD_EXAMPLES)
  add_executable(mkvtree test/mkvtree/mkvtree.cpp)
  target_link_libraries(mkvtree matroska)
  target_include_directories(mkvtree PRIVATE $<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}>)

  add_executable(test00 test/ebml/test00.cpp)
  target_link_libraries(test00 matroska)
  target_include_directories(test00 PRIVATE $<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}>)

  add_executable(test6 test/mux/test6.cpp)
  target_link_libraries(test6 matroska)
  target_include_directories(test6 PRIVATE $<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}>)

  add_executable(test8 test/mux/test8.cpp)
  target_link_libraries(test8 matroska)
  target_include_directories(test8 PRIVATE $<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}>)

  add_executable(test9 test/tags/test9.cpp)
  target_link_libraries(test9 matroska)
  target_include_directories(test9 PRIVATE $<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}>)
endif()

install(TARGETS matroska
  EXPORT MatroskaTargets
  RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
  ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
  LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})

install(FILES ${libmatroska_PUBLIC_HEADERS} DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/matroska)
install(FILES ${CMAKE_CURRENT_BINARY_DIR}/matroska_export.h DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/matroska)

if(NOT DISABLE_PKGCONFIG)
  set(prefix ${CMAKE_INSTALL_PREFIX})
  set(exec_prefix "\$\{prefix\}")
  if (IS_ABSOLUTE ${CMAKE_INSTALL_LIBDIR})
    set(libdir "${CMAKE_INSTALL_LIBDIR}")
  else()
    set(libdir "\$\{prefix\}/${CMAKE_INSTALL_LIBDIR}")
  endif()
  if (IS_ABSOLUTE ${CMAKE_INSTALL_INCLUDEDIR})
    set(includedir "${CMAKE_INSTALL_INCLUDEDIR}")
  else()
    set(includedir "\$\{prefix\}/${CMAKE_INSTALL_INCLUDEDIR}")
  endif()
  set(PACKAGE_VERSION ${PROJECT_VERSION})
  configure_file(libmatroska.pc.in libmatroska.pc @ONLY)
  install(FILES ${CMAKE_CURRENT_BINARY_DIR}/libmatroska.pc DESTINATION ${CMAKE_INSTALL_LIBDIR}/pkgconfig)
endif()

if(NOT DISABLE_CMAKE_CONFIG)
  set(CMAKE_INSTALL_PACKAGEDIR ${CMAKE_INSTALL_LIBDIR}/cmake/Matroska)
  include(CMakePackageConfigHelpers)
  configure_package_config_file(MatroskaConfig.cmake.in ${CMAKE_CURRENT_BINARY_DIR}/MatroskaConfig.cmake
    INSTALL_DESTINATION ${CMAKE_INSTALL_PACKAGEDIR})
  write_basic_package_version_file(MatroskaConfigVersion.cmake COMPATIBILITY SameMajorVersion)
  install(EXPORT MatroskaTargets NAMESPACE Matroska:: DESTINATION ${CMAKE_INSTALL_PACKAGEDIR})
  install(FILES
    ${CMAKE_CURRENT_BINARY_DIR}/MatroskaConfig.cmake
    ${CMAKE_CURRENT_BINARY_DIR}/MatroskaConfigVersion.cmake
    DESTINATION ${CMAKE_INSTALL_PACKAGEDIR})
endif()
