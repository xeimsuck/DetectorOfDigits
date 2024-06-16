#ifndef DOD_NEURALNETWORK
#define DOD_NEURALNETWORK

#include <cstddef>
#include <QDebug>
#include <QRandomGenerator>

namespace dod::core {
    class neuralNetwork {
    public:
        neuralNetwork(int inputCount, int hiddenCount, int outputCount);
        [[nodiscard]]size_t getInputNeuronsCount() const;
        [[nodiscard]]size_t getHiddenNeuronsCount() const;
        [[nodiscard]]size_t getOutputNeuronsCount() const;

        void reset();
        const std::vector<double>& use(const uchar input[]);
        void learn(const std::vector<double>&waited);

        const std::vector<double>& getOutputNeurons();
    private:
        void feedForward(const uchar input[]);

        QRandomGenerator randomGenerator;

        const int neuronsInputCount;

        std::vector<double> neuronsHidden, neuronsOutput;
        std::vector<double> biasesHidden, biasesOutput;
        std::vector<std::vector<double>> weightsInputHidden, weightsHiddenOutput;
    };
}

#endif //DOD_NEURALNETWORK

