#ifndef DOD_APPLICATION
#define DOD_APPLICATION

#include <QObject>
#include <QMainWindow>
#include <QGroupBox>
#include "gui/drawWidget.hpp"
#include "gui/resultWidget.hpp"
#include "core/neuralNetwork.hpp"

inline constexpr char WINDOW_TITLE[] = "Detector Of Digits";
inline constexpr unsigned WINDOW_WIDTH = 600;
inline constexpr unsigned WINDOW_HEIGHT = 800;
inline constexpr unsigned DRAW_WIDGET_WIDTH = WINDOW_WIDTH/100*90;
inline constexpr unsigned DRAW_WIDGET_HEIGHT = WINDOW_HEIGHT/100*60;


namespace dod::core {
    class window final : public QMainWindow {
    public:
        window();

    public slots:
        void updateResults();

    private:
        // Window Stuff
        std::unique_ptr<QWidget> centralWidget = nullptr;
        std::unique_ptr<QGridLayout> mainLayout = nullptr;

        // Group "Input"
        std::unique_ptr<QGroupBox> inputGroup = nullptr;
        std::unique_ptr<QVBoxLayout> inputGroupLayout = nullptr;
        std::unique_ptr<gui::drawWidget> inputField = nullptr;
        std::unique_ptr<QPushButton> clearButton = nullptr;

        // Group "Result"
        std::unique_ptr<QGroupBox> outputGroup = nullptr;
        std::unique_ptr<QVBoxLayout> outputGroupLayout = nullptr;
        std::unique_ptr<QLabel> finalResultLabel = nullptr;

        std::unique_ptr<gui::resultWidget> allResultsLabels[10];
        std::unique_ptr<QHBoxLayout> allResultsLayout = nullptr;

        // Neural Network
        std::unique_ptr<neuralNetwork> neuralNet;
    };
}

#endif //DOD_APPLICATION
