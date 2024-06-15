# mlp-neural-network-from-scratch
A simple MLP (Multilayer Perceptron) neural network made entirely with C++ libraries.

The neural network is designed to be trained to detect its input pattern. With two inputs that are either 1 or 0, it will output to the four possible combinations of the input:

---

```
double input[2] = {1, 0};
```

```
double input[2] = {0, 1};
```

```
double input[2] = {1, 1};
```

```
double input[2] = {0, 0};
```

---

> **Note:** This program will need some minor tweaking (not just changing the hiddenLayerNodes variable) in order for the use of more nodes and layers, at least at the moment.
