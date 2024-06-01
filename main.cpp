#include <iostream>
#include <ctime>
using namespace std;

const int hiddenLayerNodes = 6;

double input[2] = {};
double firstLayerWeights[12] = {};
double hiddenLayerBiases[hiddenLayerNodes] = {};
double secondLayerWeights[12] = {};
double outputLayerBiases[4] = {};

// when training is finished, add a function to display all weights and biases on a seperate file
// inputs will be an array
// each array will correspond to a node
// function for making sure that the input array does not exceed the number of nodes
// function for creating nodes
// function for backpropogation

void randomInitialisation() 
{
    cout << "randomInitialisation function:";

    for(double i : firstLayerWeights) {
        srand(time(NULL));
        i = rand() % 10 + 1;
    }

    for(double i : hiddenLayerBiases) {
        srand(time(NULL));
        i = rand() % 10 + 1;
    }

    for(double i : secondLayerWeights) {
        srand(time(NULL));
        i = rand() % 10 + 1;
    }

    for(double i : outputLayerBiases) {
        srand(time(NULL));
        i = rand() % 10 + 1;
    }
}

void hiddenLayerCreation(int nodes)
{
    for(int i = 0; i < nodes; i++) {
       
    }
}

int main(int argc, char *argv[]) 
{
    cout << "What is your first input?" << endl;
    cout << "Note: it must be either 1 or 0" << endl;
    cin >> input[0];

    cout << "What is your second input?" << endl;
    cin >> input[1];

    cout << "inputs:" << endl;
    cout << input[1] << endl;
    cout << input[0] << endl;

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

    // continue on with the program

    // initialise random weights and biases' to make the neural network 'guess' the best settings to then train it
    // ------------------------------------------------------------------------------------------------------------
    randomInitialisation();

    hiddenLayerCreation(hiddenLayerNodes);
    return 0;
}

/*

input: [1, 0]

hidden layers: [2.1, 5, 0.2, 4, 0.01, 1.2] (use random function from cmath for first time)

output: confidence([(1, 0), (0, 1), (1, 1), (0, 0)])

*/
