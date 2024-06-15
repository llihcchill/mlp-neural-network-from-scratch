#include <iostream>
#include <ctime>
#include <string>
using namespace std;

const int hiddenLayerNodes = 6;

double input[2];
double firstLayerWeights[12];
double hiddenLayerBiases[hiddenLayerNodes];
double secondLayerWeights[24];
double outputLayerBiases[4];

double firstCalculations[12];
double secondCalculations[hiddenLayerNodes];
double thirdCalculations[24];

double firstOutputCalculations[6];
double secondOutputCalculations[6];
double thirdOutputCalculations[6];
double fourthOutputCalculations[6];

double outputCalculations[4];

// when training is finished, add a function to display all weights and biases on a seperate file
// function for backpropogation

void randomInitialisation();
void hiddenLayerCalculations(int nodes);
double compareOutput(double outputCalcs[]);


int main(int argc, char *argv[]) 
{

    cout << "What is your first input?" << endl;
    cout << "Note: it must be either 1 or 0" << endl;
    cin >> input[0];

    cout << "What is your second input?" << endl;
    cin >> input[1];

    if(input[0] != 1) {
        if(input[0] != 0) {
            cout << "Error: a number besides 1 or 0 has been picked";
            return 0;
        }
    }

    if(input[1] != 1) {
        if(input[1] != 0) {
            cout << "Error: a number besides 1 or 0 has been picked";
            return 0;
        }
    }

    // continue

    // ------------------------------------------------------------------------------------------------------------
    // initialise random weights and biases' to make the neural network 'guess' the best settings to then train it
    // ------------------------------------------------------------------------------------------------------------
    randomInitialisation();

    // calculate the mathematics behind the hidden layer
    hiddenLayerCalculations(hiddenLayerNodes);

    // compare all four outputs and print the highest one
    compareOutput(outputCalculations);

    // backpropogation algorithm to 'train' AI by tweaking the weights and biases to get a better result
    // yet to be made

    return 0;
}



void randomInitialisation() 
{
    // sets firstLayerWeights weights
    for(int i = 0; i < 12; i++) {
        srand(time(NULL));
        firstLayerWeights[i] = rand() % 10 + 1;
    }

    // sets hiddenLayerBiases biases
    for(int i = 0; i < hiddenLayerNodes; i++) {
        srand(time(NULL));
        hiddenLayerBiases[i] = rand() % 10 + 1;
    }

    // sets secondLayerWeights weights
    for(int i = 0; i < 24; i++) {
        srand(time(NULL));
        secondLayerWeights[i] = rand() % 10 + 1;
    }

    // sets outputLayerBiases biases
    for(int i = 0; i < 4; i++) {
        srand(time(NULL));
        outputLayerBiases[i] = rand() % 10 + 1;
    }
}

void hiddenLayerCalculations(int nodes) 
{
    // the 1 / (1 + exp(-(input))) is the an activation function under the name of a sigmoid function
    // it puts every value between 0 and 1, along with turning negative values to positive values
    
    // calculating with weights (input x weight)
    for(int i = 0; i < (12 / 2); i++) {
        firstCalculations[i] = 1 / (1 + exp(-(input[1] * firstLayerWeights[i])));
    }

    cout << endl;

    for(int i = 0; i < (12 / 2); i++) {
        firstCalculations[i+6] = 1 / (1 + exp(-(input[2] * firstLayerWeights[i+6])));
    }

    // calculating the biases ((input x weightj) + (input x weighti) + bias)
    for(int i = 0; i < hiddenLayerNodes; i++) {
       secondCalculations[i] = 1 / (1 + exp(-(hiddenLayerBiases[i] + firstCalculations[i] + firstCalculations[i+6])));
    }

    // calculating output weights (secondcalculations x weight)
    for(int i = 0; i < hiddenLayerNodes; i++) {
        firstOutputCalculations[i] = 1 / (1 + exp(-(secondCalculations[i] * secondLayerWeights[i])));
    }
    
    for(int i = 0; i < hiddenLayerNodes; i++) {
        secondOutputCalculations[i] = 1 / (1 + exp(-(secondCalculations[i] * secondLayerWeights[i+6])));
    }

    for(int i = 0; i < hiddenLayerNodes; i++) {
        thirdOutputCalculations[i] = 1 / (1 + exp(-(secondCalculations[i] * secondLayerWeights[i+12])));
    }

    for(int i = 0; i < hiddenLayerNodes; i++) {
        fourthOutputCalculations[i] = 1 / (1 + exp(-(secondCalculations[i] * secondLayerWeights[i+18])));
    }

    // compare each output to see which one is highest
    for(int i = 0; i < 4; i++) {
        outputCalculations[i] = 1 / (1 + exp(-(firstOutputCalculations[i] + secondOutputCalculations[i+6] + thirdOutputCalculations[i+12] + fourthOutputCalculations[i+18] + outputLayerBiases[i])));
    }


    
}

double compareOutput(double outputCalcs[]) 
{
    int index;
    double o = 0;

    for(int i = 0; i < 4; i++) {
        if(outputCalcs[i] > o) {
            o = outputCalcs[i];
            index = i;
        }
    }

    if(index == 0) {
        cout << "AI chose the sequence (1, 0)";
    }

    if(index == 1) {
        cout << "AI chose the sequence (0, 1)";
    }

    if(index == 2) {
        cout << "AI chose the sequence (1, 1)";
    }

    if(index == 3) {
        cout << "AI chose the sequence (0, 0)";
    }

    return o;
}
