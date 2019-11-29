cmake_minimum_required (VERSION 3.13.0)

if (NOT DEFINED CMAKE_BUILD_TYPE)
    set (CMAKE_BUILD_TYPE "Release" CACHE STRING "" FORCE)
endif ()

project ("N64 Controller")

include (GNUInstallDirs)

add_subdirectory ("n64c")
add_subdirectory ("application")

