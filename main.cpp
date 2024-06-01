#include <iostream>
#include <ctime>
using namespace std;


double input[2] = {};
double firstLayerWeights[12] = {};
double hiddenLayerBiases[6] = {};
double secondLayerWeights[12] = {};
double outputLayerBiases[4] = {};

// when training is finished, add a function to display all weights and biases on a seperate file
// inputs will be an array
// each array will correspond to a node
// function for making sure that the input array does not excedd the number of nodes
// function for creating nodes
// function for backpropogation

void randomInitialisation() 
{
    for(double i : firstLayerWeights) {
        srand(time(NULL));
        i = rand() % 10 + 1;

        cout << i << endl;
    }

    for(double i : hiddenLayerBiases) {
        srand(time(NULL));
        i = rand() % 10 + 1;

        cout << i << endl;
    }

    for(double i : secondLayerWeights) {
        srand(time(NULL));
        i = rand() % 10 + 1;

        cout << i << endl;
    }

    for(double i : outputLayerBiases) {
        srand(time(NULL));
        i = rand() % 10 + 1;

        cout << i << endl;
    }
}

void hiddenLayerCreation(int nodes)
{
  for(int i = 0; i < nodes; i++) {

  }

}

int main(int argc, char *argv[]) 
{

    randomInitialisation();

    double inp;
    cout << "How many neurons would you like today sir?" << endl;
    cin << inp << endl;

    return 0;
}

/*

input: [1, 0]

hidden layers: [2.1, 5, 0.2, 4, 0.01, 1.2] (use random function from cmath for first time)

output: confidence([(1, 0), (0, 1), (1, 1), (0, 0)])

*/
