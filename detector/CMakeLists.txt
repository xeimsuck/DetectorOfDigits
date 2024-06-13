# detector
add_executable(detector sources/main.cpp
        sources/core/window.cpp
        sources/core/window.hpp)

# QT6
## link
find_package(Qt6 COMPONENTS Core Gui Widgets REQUIRED)
target_link_libraries(detector Qt6::Core Qt6::Gui Qt6::Widgets)
