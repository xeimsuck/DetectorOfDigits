#include "window.hpp"

using std::make_unique;

dod::core::window::window(){
    this->setFixedSize(WINDOW_WIDTH, WINDOW_HEIGHT);
    this->setWindowTitle(WINDOW_TITLE);

    /*=============== WINDOW STUFF ===============*/
    centralWidget = make_unique<QWidget>();
    this->setCentralWidget(centralWidget.get());

    mainLayout = make_unique<QGridLayout>();
    centralWidget->setLayout(mainLayout.get());

    /*=============== INPUT GROUP ===============*/
    inputGroup = make_unique<QGroupBox>();
    inputGroupLayout = make_unique<QVBoxLayout>();
    inputGroup->setLayout(inputGroupLayout.get());
    mainLayout->addWidget(inputGroup.get());

    QSize q_sizeInputField(DRAW_WIDGET_WIDTH, DRAW_WIDGET_HEIGHT);
    inputField = std::make_unique<gui::drawWidget>(q_sizeInputField , this);
    QObject::connect(inputField.get(), &gui::drawWidget::changed, this, &window::updateResults);
    inputGroupLayout->addWidget(inputField.get());

    clearButton = make_unique<QPushButton>("Clear");
    QObject::connect(clearButton.get(), &QPushButton::clicked, inputField.get(), &gui::drawWidget::clear);
    QObject::connect(clearButton.get(), &QPushButton::clicked, this, &core::window::clear);
    inputGroupLayout->addWidget(clearButton.get());

    /*=============== OUTPUT GROUP ===============*/
    outputGroupLayout = make_unique<QVBoxLayout>();
    outputGroup = make_unique<QGroupBox>();
    outputGroup->setLayout(outputGroupLayout.get());
    mainLayout->addWidget(outputGroup.get(), 1, 0);

    finalResultLabel = make_unique<QLabel>("-");
    finalResultLabel->setFont(QFont("Arial", 35, QFont::Bold));
    finalResultLabel->setAlignment(Qt::AlignCenter);
    outputGroupLayout->addWidget(finalResultLabel.get());

    allResultsLayout = make_unique<QHBoxLayout>();
    outputGroupLayout->addLayout(allResultsLayout.get());
    for(size_t i = 0; i<10; ++i){
        allResultsLabels[i] = make_unique<gui::resultWidget>(QString::number(i));
        allResultsLayout->addWidget(allResultsLabels[i].get());
    }

    /*=============== Neural Network ===============*/
    neuralNet = make_unique<neuralNetwork>(DRAW_WIDGET_WIDTH*DRAW_WIDGET_HEIGHT, 100, 10);
}

void dod::core::window::clear() {
    finalResultLabel->setText("-");
    for(int i = 0; i < 10; ++i){
        allResultsLabels[i]->setProgressValue(0);
    }
}

void dod::core::window::updateResults() {
    decltype(auto) v = neuralNet->getOutputNeurons();
    int winner = 0;
    for(int i = 0; i < v.size(); ++i){
        if(v[i]>v[winner]) winner = i;
        allResultsLabels[i]->setProgressValue(static_cast<int>(v[i]*100));
    }
    finalResultLabel->setText(QString::number(winner));
}