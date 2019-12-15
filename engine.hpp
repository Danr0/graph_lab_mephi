#ifndef ENGINE_H
# define ENGINE_H

#include <iostream>

#include <iomanip>

#include "tests.hpp"

#include "command.hpp"

#include "algfloid.hpp"

#include <map>

template < typename T > T evaluate(string message, std::map < string, T > options) {
    auto itr = options.find(message);
    if (itr != options.end()) {
        return options.at(message);
    }
    return (T) 404;
}

enum StorageType {
    Floidal,
    Test
};

enum FloidVarTypes {
    IntSymmetric,
    FloatSymmetric,
    DoubleSymmetric,
    IntUnsymmetric,
    FloatUnsymmetric,
    DoubleUnsymmetric
};

class Application {
public:
    Application() {
        print("Initializing shell");

    }

    void run() {
        eventLoop();
    }

private:
    string base;
    void eventLoop() {
        int succesful = 0;
        while (!succesful) {
            print("Select algorithm or run tests: Floid or Test");
            string first = getCommand();
            Command task = Command(first);
            map < string, StorageType > options1 = {
                    {
                            "Floid",
                            StorageType::Floidal
                    },
                    {
                            "Test",
                            StorageType::Test
                    }
            };
            switch (evaluate < StorageType > (task.base(), options1)) {
                case StorageType::Test:
                    print("Start tests");
                    succesful = 1;
                    Tests();
                    break;
                case StorageType::Floidal:
                    print("Using Floid algoritm");
                    succesful = 1;
                    AlgFloid();
                    break;

                case 404:
                    print("Invalid command was entered");
                    break;

                default:
                    print("Undefined behaviour");
                    break;
            }
        }
    }

    void Tests() {
        floidtests();
    }

    void AlgFloid() {
        print("Choose graph type: IntSymmetric, DoubleSymmetric, FloatSymmetric, IntUnsymmetric, DoubleUnsymmetric or FloatUnsymmetric");
        string third = getCommand();
        Command task = Command(third);
        map < string, FloidVarTypes > options {
                {
                        "IntSymmetric",
                        IntSymmetric
                }, {
                        "FloatSymmetric",
                        FloatSymmetric
                }, {
                        "DoubleSymmetric",
                        DoubleSymmetric
                }, {
                        "IntUnsymmetric",
                        IntUnsymmetric
                }, {
                        "FloatUnsymmetric",
                        FloatUnsymmetric
                }, {
                        "DoubleUnsymmetric",
                        DoubleUnsymmetric
                }
        };

        switch (evaluate < FloidVarTypes > (task.base(), options)) {
            case IntSymmetric:
                IntSymmetricM();
                break;

            case FloatSymmetric:
                FloatSymmetricM();
                break;

            case DoubleSymmetric:
                DoubleSymmetricM();
                break;

            case IntUnsymmetric:
                IntUnsymmetricM();
                break;

            case FloatUnsymmetric:
                FloatUnsymmetricM();
                break;

            case DoubleUnsymmetric:
                DoubleUnsymmetricM();
                break;

            default:
                break;
        }
    }

    void FloatSymmetricM() {
        print("Enter amount of vertices");
        string third = getCommand();
        int N = stoi(third);
        float ** Matrix;
        int i, j;
        Matrix = (float ** ) malloc(N * sizeof(float * ));
        for (i = 0; i < N; i++)
            Matrix[i] = (float * ) malloc(N * sizeof(float));

        for (i = 0; i < N; i++)
            for (j = 0; j < N; j++) {
                if (i == j)
                    Matrix[i][j] = (float) 0;
                else if (j > i)
                    Matrix[i][j] = static_cast < float > (rand()) / static_cast < float > (RAND_MAX / 100);
                else
                    Matrix[i][j] = Matrix[j][i];
            }
        print("Created matrix:");
        printMatrix(Matrix, N);
        print("Floid algorithm:");
        float * tmp = Floid(Matrix, N, (float) 0, (float) - 1);
        for (i = 0; i < N; i++)
            cout << " " << tmp[i];
    }

    void DoubleSymmetricM() {
        print("Enter amount of vertices");
        string third = getCommand();
        int N = stoi(third);
        double ** Matrix;
        int i, j;
        Matrix = (double ** ) malloc(N * sizeof(double * ));
        for (i = 0; i < N; i++)
            Matrix[i] = (double * ) malloc(N * sizeof(double));

        for (i = 0; i < N; i++)
            for (j = 0; j < N; j++) {
                if (i == j)
                    Matrix[i][j] = (double) 0;
                else if (j > i)
                    Matrix[i][j] = static_cast < double > (rand()) / static_cast < double > (RAND_MAX / 100);
                else
                    Matrix[i][j] = Matrix[j][i];
            }
        print("Created matrix:");
        printMatrix(Matrix, N);
        print("Floid algorithm:");
        double * tmp = Floid(Matrix, N, (double) 0, (double) - 1);
        for (i = 0; i < N; i++)
            cout << " " << tmp[i];
    }

    void IntSymmetricM() {
        print("Enter amount of vertices");
        string third = getCommand();
        int N = stoi(third);
        int ** Matrix;
        int i, j;
        Matrix = (int ** ) malloc(N * sizeof(int * ));
        for (i = 0; i < N; i++)
            Matrix[i] = (int * ) malloc(N * sizeof(int));

        for (i = 0; i < N; i++)
            for (j = 0; j < N; j++) {
                if (i == j)
                    Matrix[i][j] = (int) 0;
                else if (j > i)
                    Matrix[i][j] = static_cast < int > (rand()) / static_cast < int > (RAND_MAX / 100);
                else
                    Matrix[i][j] = Matrix[j][i];
            }
        print("Created matrix:");
        printMatrix(Matrix, N);
        print("Floid algorithm:");
        int * tmp = Floid(Matrix, N, (int) 0, (int) - 1);
        for (i = 0; i < N; i++)
            cout << " " << tmp[i];
    }

    void FloatUnsymmetricM() {
        print("Enter amount of vertices");
        string third = getCommand();
        int N = stoi(third);
        float ** Matrix;
        int i, j;
        Matrix = (float ** ) malloc(N * sizeof(float * ));
        for (i = 0; i < N; i++)
            Matrix[i] = (float * ) malloc(N * sizeof(float));

        for (i = 0; i < N; i++)
            for (j = 0; j < N; j++) {
                if (i == j)
                    Matrix[i][j] = (float) 0;
                else
                    Matrix[i][j] = static_cast < float > (rand()) / static_cast < float > (RAND_MAX / 100);
            }
        print("Created matrix:");
        printMatrix(Matrix, N);
        print("Floid algorithm:");
        float * tmp = Floid(Matrix, N, (float) 0, (float) - 1);
        for (i = 0; i < N; i++)
            cout << " " << tmp[i];
    }

    void DoubleUnsymmetricM() {
        print("Enter amount of vertices");
        string third = getCommand();
        int N = stoi(third);
        double ** Matrix;
        int i, j;
        Matrix = (double ** ) malloc(N * sizeof(double * ));
        for (i = 0; i < N; i++)
            Matrix[i] = (double * ) malloc(N * sizeof(double));

        for (i = 0; i < N; i++)
            for (j = 0; j < N; j++) {
                if (i == j)
                    Matrix[i][j] = (double) 0;
                else
                    Matrix[i][j] = static_cast < double > (rand()) / static_cast < double > (RAND_MAX / 100);
            }
        print("Created matrix:");
        printMatrix(Matrix, N);
        print("Floid algorithm:");
        double * tmp = Floid(Matrix, N, (double) 0, (double) - 1);
        for (i = 0; i < N; i++)
            cout << " " << tmp[i];
    }

    void IntUnsymmetricM() {
        print("Enter amount of vertices");
        string third = getCommand();
        int N = stoi(third);
        int ** Matrix;
        int i, j;
        Matrix = (int ** ) malloc(N * sizeof(int * ));
        for (i = 0; i < N; i++)
            Matrix[i] = (int * ) malloc(N * sizeof(int));

        for (i = 0; i < N; i++)
            for (j = 0; j < N; j++) {
                if (i == j)
                    Matrix[i][j] = (int) 0;
                else
                    Matrix[i][j] = static_cast < int > (rand()) / static_cast < int > (RAND_MAX / 100);
            }
        print("Created matrix:");
        printMatrix(Matrix, N);
        print("Floid algorithm:");
        int * tmp = Floid(Matrix, N, (int) 0, (int) - 1);
        for (i = 0; i < N; i++)
            cout << " " << tmp[i];
    }

    string getCommand() {
        string commandToGet;
        getline(cin, commandToGet);
        if (commandToGet.empty()) {
            return "unkn";
        } else return commandToGet;
    }

    void print(string message) {
        cout << message << endl;
    }
};

#endif