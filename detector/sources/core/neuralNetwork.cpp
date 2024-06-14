#include "neuralNetwork.hpp"

#include "math/rectifier.hpp"

dod::core::neuralNetwork::neuralNetwork(const int inputCount, const int hiddenCount, const int outputCount) :
        neuronsInputCount(inputCount),
        neuronsHidden(hiddenCount,0), neuronsOutput(outputCount, 0),
        biasesHidden(hiddenCount, (randomGenerator.generate() * 2 - 1) * 0.005),
        biasesOutput(outputCount, (randomGenerator.generate() * 2 - 1) * 0.005),
        weightsInputHidden(inputCount, std::vector<double>(hiddenCount, (randomGenerator.generate() * 2 - 1) * 0.005)),
        weightHiddenOutput(hiddenCount, std::vector<double>(outputCount, (randomGenerator.generate() * 2 - 1) * 0.005)){
}

size_t dod::core::neuralNetwork::getInputNeuronsCount() const {
    return neuronsInputCount;
}
size_t dod::core::neuralNetwork::getHiddenNeuronsCount() const {
    return neuronsHidden.size();
}
size_t dod::core::neuralNetwork::getOutputNeuronsCount() const {
    return neuronsOutput.size();
}

std::vector<double> dod::core::neuralNetwork::use(const std::vector<double>&inputNeurons) {
    if(inputNeurons.size() != neuronsInputCount) throw;
    feedForward(inputNeurons);
    return neuronsOutput;
}

void dod::core::neuralNetwork::feedForward(const std::vector<double>&inputNeurons) {
    for(size_t i = 0; i < neuronsHidden.size(); ++i){
        double result = biasesHidden[i];
        for (size_t j = 0; j < inputNeurons.size(); ++j) {
            result+= inputNeurons[j] * weightsInputHidden[j][i];
        }
        neuronsHidden[i]= math::rectifier(result);
    }
    for(size_t i = 0; i < neuronsOutput.size(); ++i){
        double result = biasesOutput[i];
        for (size_t j = 0; j < neuronsHidden.size(); ++j) {
            result+= neuronsHidden[j] * weightHiddenOutput[j][i];
        }
        neuronsOutput[i]= math::rectifier(result);
    }
}

// TODO: learn dont work
void dod::core::neuralNetwork::learn(const std::vector<double> &waited) {
    if(waited.size() != neuronsOutput.size()) return;
}

std::vector<double>& dod::core::neuralNetwork::getOutputNeurons() {
    return neuronsOutput;
}