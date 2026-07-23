# Four In A Row
Four In A Row game written in C++ with multiple opponent options

Includes a neural network written from scratch in C++ with Eigen for efficient linear algebra calculations.


## Prerequisites for compilation

CMake and a C++ compiler must be installed

The Eigen library for C++ must be installed

# Build instructions
## How to compile 
	$ git clone git@github.com:BrianO-04/Four-In-A-Row.git
	$ cd Four-In-A-Row	
	$ mkdir build
	$ cmake .S . -B build
	$ cmake --build build
## How to run
    $ cd build
	$ ./FourInARow
## How to train the neural network

Before collecting data, you must create a "data" folder and a "weights" folder at the root of the repository.

After you have created those folders, play Four In A Row by running the Four In A Row application:

	$ cd Four-In-A-Row/build
	$ ./FourInARow

When a human controlled player wins a game of Four In A Row, a binary file containing each move made in that game will be saved to the "data" folder.

Once a sufficient amount of data is collected, you can train the neural network on the data by running the training application:

	$ cd Four-In-A-Row/build
	$ ./NetworkTrainer

After the neural network has finished training, the weights will be saved as "Weights.bin" to the "weights" folder.

To play against the trained neural network, select the "NN AI" option when starting the Four In A Row application.
