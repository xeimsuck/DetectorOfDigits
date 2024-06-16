#include "neuralNetwork.hpp"

#include "math/rectifier.hpp"

dod::core::neuralNetwork::neuralNetwork(const int inputCount, const int hiddenCount, const int outputCount) :
        neuronsInputCount(inputCount),
        neuronsHidden(hiddenCount,0), neuronsOutput(outputCount, 0),
        biasesHidden(hiddenCount),
        biasesOutput(outputCount),
        weightsInputHidden(inputCount, std::vector<double>(hiddenCount)),
        weightsHiddenOutput(hiddenCount, std::vector<double>(outputCount)){
    reset();
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

void dod::core::neuralNetwork::reset() {
    for(auto& i : biasesHidden)
        i = (randomGenerator.generateDouble() * 2 - 1) * 0.01;
    for(auto& i : biasesOutput)
        i = (randomGenerator.generateDouble() * 2 - 1) * 0.01;
    for(auto& i : weightsInputHidden)
        for(auto& j : i) j = (randomGenerator.generateDouble() * 2 - 1) * 0.01;
    for(auto& i : weightsHiddenOutput)
        for(auto& j : i) j = (randomGenerator.generateDouble() * 2 - 1) * 0.01;
}

const std::vector<double>& dod::core::neuralNetwork::use(const uchar input[]) {
    feedForward(input);
    return neuronsOutput;
}

void dod::core::neuralNetwork::feedForward(const uchar input[]) {
    for(size_t i = 0; i < neuronsHidden.size(); ++i){
        double result = biasesHidden[i];
        for (size_t j = 0; j < neuronsInputCount; ++j) {
            result+= static_cast<double>(input[j])/255 * weightsInputHidden[j][i];
        }
        neuronsHidden[i]= math::rectifier(result);
    }
    for(size_t i = 0; i < neuronsOutput.size(); ++i){
        double result = biasesOutput[i];
        for (size_t j = 0; j < neuronsHidden.size(); ++j) {
            result+= neuronsHidden[j] * weightsHiddenOutput[j][i];
        }
        neuronsOutput[i]= math::rectifier(result);
    }
}

// TODO: learn dont work
void dod::core::neuralNetwork::feedBackward(const std::vector<double> &waited) {
    if(waited.size() != neuronsOutput.size()) return;
}

const std::vector<double>& dod::core::neuralNetwork::getOutputNeurons() {
    return neuronsOutput;
}