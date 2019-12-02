set (N64C_LIB_TYPE "SHARED" CACHE STRING "Build as shared or static library")
option (N64C_PIC "Generate position independent code" ON)

find_package (Qt5Widgets REQUIRED)
find_package (Qt5Gui REQUIRED)
find_package (Qt5Core REQUIRED)
find_package (Qt5LinguistTools REQUIRED)

set (n64c_SOURCES
    "src/api.cpp"
    "src/models/nodes/BooleanData.cpp"
    "src/models/nodes/BooleanOperationModel.cpp"
    "src/models/nodes/CurveModel.cpp"
    "src/models/nodes/FloatData.cpp"
    "src/models/nodes/MathOperationModel.cpp"
    "src/models/nodes/N64ControllerInputDataModel.cpp"
    "src/models/nodes/N64ControllerOutputDataModel.cpp"
    "src/models/nodes/ThresholdModel.cpp"
    "src/views/ContextPaneUser.cpp"
    "src/views/ControllerPakTool.cpp"
    "src/views/DeviceSettings.cpp"
    "src/views/MainWindow.cpp"
    "src/views/NodeEditor.cpp"
    "src/views/ProfileView.cpp"
    "src/views/ToolsPane.cpp")
set (n64c_HEADERS
    "include_private/n64c/models/nodes/BooleanData.hpp"
    "include_private/n64c/models/nodes/FloatData.hpp")
set (n64c_HEADERS_MOC
    "include_private/n64c/models/nodes/BooleanOperationModel.hpp"
    "include_private/n64c/models/nodes/CurveModel.hpp"
    "include_private/n64c/models/nodes/MathOperationModel.hpp"
    "include_private/n64c/models/nodes/N64ControllerInputDataModel.hpp"
    "include_private/n64c/models/nodes/N64ControllerOutputDataModel.hpp"
    "include_private/n64c/models/nodes/ThresholdModel.hpp"
    "include_private/n64c/views/ContextPaneUser.hpp"
    "include_private/n64c/views/ControllerPakTool.hpp"
    "include_private/n64c/views/MainWindow.hpp"
    "include_private/n64c/views/NodeEditor.hpp"
    "include_private/n64c/views/DeviceSettings.hpp"
    "include_private/n64c/views/ProfileView.hpp"
    "include_private/n64c/views/ToolsPane.hpp")
set (n64c_FORMS
    "forms/ControllerPakTool.ui"
    "forms/DeviceSettings.ui"
    "forms/MainWindow.ui"
    "forms/NodeEditor.ui"
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
        QtColorWidgets
        nodes)

###############################################################################
# Translation Files
###############################################################################

add_custom_target (tr_gen
    COMMAND Qt5::lupdate ${CMAKE_CURRENT_SOURCE_DIR} -ts ${n64c_TRANSLATION_FILES}
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
    COMMENT "Generating translation files")
