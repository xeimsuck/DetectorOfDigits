#include "resultWidget.hpp"

dod::gui::resultWidget::resultWidget(const QString& labelText, const int value) {
    label = std::make_unique<QLabel>(labelText);
    label->setAlignment(Qt::AlignCenter);

    bar = std::make_unique<QProgressBar>();
    bar->setRange(0, 100);
    bar->setValue(value);
    bar->setOrientation(Qt::Vertical);
    bar->setAlignment(Qt::AlignCenter);

    layout = std::make_unique<QVBoxLayout>();
    layout->addWidget(label.get());
    layout->addWidget(bar.get());
    this->setLayout(layout.get());
}

void dod::gui::resultWidget::setLabelText(const QString &labelText) {
    label->setText(labelText);
}

void dod::gui::resultWidget::setProgressValue(const int value) {
    bar->setValue(value);
}