#ifndef DOD_APPLICATION
#define DOD_APPLICATION

#include <QMainWindow>

inline constexpr char TITLE[] = "Detector Of Digits";
inline constexpr unsigned WIDTH = 600;
inline constexpr unsigned HEIGHT = 800;

namespace dod::core {
    class window : public QMainWindow {
    public:
        window();
    };
}

#endif //DOD_APPLICATION
