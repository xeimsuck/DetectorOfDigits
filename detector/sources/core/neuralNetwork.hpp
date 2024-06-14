#ifndef DOD_NEURALNETWORK
#define DOD_NEURALNETWORK

#include <cstddef>
#include <QRandomGenerator>

namespace dod::core {
    class neuralNetwork {
    public:
        neuralNetwork(int inputCount, int hiddenCount, int outputCount);
        [[nodiscard]]size_t getInputNeuronsCount() const;
        [[nodiscard]]size_t getHiddenNeuronsCount() const;
        [[nodiscard]]size_t getOutputNeuronsCount() const;

        std::vector<double> use(const std::vector<double>&input);
        void learn(const std::vector<double>&waited);

        const std::vector<double>& getOutputNeurons();
    private:
        void feedForward(const std::vector<double>&inputNeurons);

        QRandomGenerator randomGenerator;

        const int neuronsInputCount;

        std::vector<double> neuronsHidden, neuronsOutput;
        std::vector<double> biasesHidden, biasesOutput;
        std::vector<std::vector<double>> weightsInputHidden, weightHiddenOutput;
    };
}

#endif //DOD_NEURALNETWORK

