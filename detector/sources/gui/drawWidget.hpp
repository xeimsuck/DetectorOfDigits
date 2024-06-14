#ifndef DOD_DRAWWIDGET
#define DOD_DRAWWIDGET

#include <vector>
#include <memory>

#include <QMouseEvent>
#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QPainter>
#include <QPolygon>

namespace dod::gui {
    class drawWidget final : public QWidget {
        Q_OBJECT
    public:
        explicit drawWidget(QSize size, QWidget* parent = nullptr);
        void paintEvent(QPaintEvent* event) override;
        void addPoint(QPoint point);
        void mousePressEvent(QMouseEvent*) final;
        void mouseMoveEvent(QMouseEvent*) final;

    signals:
        void changed();

    public slots:
        void clear();

    private:
        std::vector<QPolygon> v_plPoints;
    };
}

#endif //DOD_DRAWWIDGET
