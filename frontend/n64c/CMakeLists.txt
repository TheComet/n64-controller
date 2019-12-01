set (N64C_LIB_TYPE "SHARED" CACHE STRING "Build as shared or static library")
option (N64C_PIC "Generate position independent code" ON)

find_package (Qt5Widgets REQUIRED)
find_package (Qt5Gui REQUIRED)
find_package (Qt5Core REQUIRED)
find_package (Qt5LinguistTools REQUIRED)

set (n64c_SOURCES
    "src/api.cpp"
    "src/ContextPaneUser.cpp"
    "src/ControllerPakTool.cpp"
    "src/DeviceSettings.cpp"
    "src/MainWindow.cpp"
    "src/ProfileView.cpp"
    "src/ToolsPane.cpp")
set (n64c_HEADERS )
set (n64c_HEADERS_MOC
    "include_private/n64c/ContextPaneUser.hpp"
    "include_private/n64c/ControllerPakTool.hpp"
    "include_private/n64c/MainWindow.hpp"
    "include_private/n64c/DeviceSettings.hpp"
    "include_private/n64c/ProfileView.hpp"
    "include_private/n64c/ToolsPane.hpp")
set (n64c_FORMS
    "forms/ControllerPakTool.ui"
    "forms/DeviceSettings.ui"
    "forms/MainWindow.ui"
    "forms/ProfileView.ui")
set (n64c_RESOURCES
    "res/n64c.res")
set (n64c_TRANSLATION_FILES
    "translations/n64c_de.ts")

qt5_wrap_cpp (n64c_SOURCES_MOC ${n64c_HEADERS_MOC})
qt5_wrap_ui (n64c_FORMS_MOC ${n64c_FORMS})
qt5_add_resources (n64c_RESOURCES_GEN ${n64c_RESOURCES})
qt5_add_translation (n64c_QM_FILES ${n64c_TRANSLATION_FILES})

add_library (n64c ${N64C_LIB_TYPE}
    ${n64c_SOURCES}
    ${n64c_HEADERS}
    ${n64c_SOURCES_MOC}
    ${n64c_FORMS_MOC}
    ${n64c_RESOURCES_GEN}
    ${n64c_QM_FILES})
target_include_directories (n64c
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include_public>
        $<INSTALL_INTERFACE:include>
    PRIVATE
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include_private>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}/include>
        $<BUILD_INTERFACE:${CMAKE_BINARY_DIR}>)  # ui header files are written to <build dir>/n64c by the MOC
target_compile_definitions (n64c
    PRIVATE
        N64C_BUILDING)
target_compile_options (n64c
    PUBLIC
        $<$<CXX_COMPILER_ID:GNU>:-W -Wall -Wextra -pedantic -Wno-unused-parameters>
        $<$<CXX_COMPILER_ID:Clang>:-W -Wall -Wextra -pedantic -Wno-unused-parameters>
        $<$<CXX_COMPILER_ID:MSVC>:>)
set_property (TARGET n64c
    PROPERTY POSITION_INDEPENDENT_CODE ${N64C_PIC})
target_link_libraries (n64c
    PRIVATE
        Qt5::Core
        Qt5::Widgets
        Qt5::Gui
        QtColorWidgets)

###############################################################################
# Translation Files
###############################################################################

add_custom_target (tr_gen
    COMMAND Qt5::lupdate ${CMAKE_CURRENT_SOURCE_DIR} -ts ${n64c_TRANSLATION_FILES}
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
    COMMENT "Generating translation files")
