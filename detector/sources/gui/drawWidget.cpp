#include "drawWidget.hpp"

dod::gui::drawWidget::drawWidget(QSize size, QWidget *parent) : QWidget(parent) {
    this->setFixedSize(size);
}

void dod::gui::drawWidget::paintEvent(QPaintEvent *event) {
    QPainter painter(this);
    painter.setPen(QPen(QBrush(Qt::black), 10));
    for(auto& pl : v_plPoints) painter.drawPolyline(pl); //or drawPoints
}

void dod::gui::drawWidget::addPoint(QPoint point) {
    v_plPoints.back().push_back(point);
    update();
}

void dod::gui::drawWidget::clear() {
    v_plPoints.clear();
    update();
}

void dod::gui::drawWidget::mousePressEvent(QMouseEvent* event) {
   v_plPoints.emplace_back();
}

void dod::gui::drawWidget::mouseMoveEvent(QMouseEvent* event) {
    addPoint(event->pos());
    changed();
}