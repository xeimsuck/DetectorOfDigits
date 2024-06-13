#include <QApplication>
#include "core/window.hpp"

int main(int argc, char* argv[]){
    QApplication app(argc, argv);
    dod::core::window wnd;
    wnd.show();
    return QApplication::exec();
}