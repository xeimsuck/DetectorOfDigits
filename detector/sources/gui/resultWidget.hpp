#ifndef DOD_RESULTWIDGET
#define DOD_RESULTWIDGET

#include <memory>
#include <QWidget>
#include <QVBoxLayout>
#include <QLabel>
#include <QProgressBar>

namespace dod::gui {
    class resultWidget : public QWidget {
    public:
        explicit resultWidget(const QString& labelText, int value = 0);
        void setLabelText(const QString& labelText);
        void setProgressValue(int value);
    private:
        std::unique_ptr<QVBoxLayout> layout = nullptr;
        std::unique_ptr<QLabel> label = nullptr;
        std::unique_ptr<QProgressBar> bar = nullptr;
    };
}

#endif //DOD_RESULTWIDGET
