# detector
add_executable(detector sources/main.cpp
        sources/core/window.cpp
        sources/core/window.hpp
        sources/core/neuralNetwork.cpp
        sources/core/neuralNetwork.hpp
        sources/math/rectifier.cpp
        sources/math/rectifier.hpp
        sources/gui/resultWidget.cpp
        sources/gui/resultWidget.hpp
        sources/gui/drawWidget.cpp
        sources/gui/drawWidget.hpp)
set_target_properties(detector PROPERTIES AUTOMOC TRUE)

target_include_directories(detector PRIVATE sources)

# QT6
## link
find_package(Qt6 COMPONENTS Core Gui Widgets REQUIRED)
target_link_libraries(detector Qt6::Core Qt6::Gui Qt6::Widgets)
