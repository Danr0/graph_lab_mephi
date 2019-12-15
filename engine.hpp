#ifndef ENGINE_H
#define ENGINE_H
#include <iostream>
#include <iomanip>
#include "tests.hpp"
#include "command.hpp"
#include "algfloid.hpp"
#include <map>

template<typename T> T evaluate(string message, std::map<string,T> options) {
    auto itr = options.find(message);
    if( itr != options.end() ) {
        return options.at(message);
    }
    return (T)404;
}

enum StorageType {
    Floidal,
    Test
};


enum FloidVarTypes {
    TypeIntSym,
    TypeFloatSym,
    TypeDoubleSym,
    TypeIntUnSym,
    TypeFloatUnSym,
    TypeDoubleUnSym
};

enum MatrixType {
    SymmetricMatrix,
    UnSymmetricMatrix
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
                map<string,StorageType> options1 = {
                        {"Floid",StorageType::Floidal},
                        {"Test",StorageType::Test}
                    };
                switch (evaluate<StorageType>(task.base(),options1))
                {
                    case StorageType::Test:
                        print("Start tests");
                        succesful=1;
                        Tests();
                        break;
                    case StorageType::Floidal:
                        print("Using Floid algoritm");
                        succesful=1;
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

                void Tests(){
                    floidtests();
                }



                void AlgFloid() {
                    print("Select search type: TypeIntSym, Sym or TypeFloatSym");
                    string third = getCommand();
                    Command task = Command(third);
                    map<string,FloidVarTypes> options {{"TypeIntSym",TypeIntSym},{"TypeFloatSym",TypeFloatSym},{"PropTypeDoubleSym",TypeDoubleSym,
                    "TypeIntUnSym",TypeIntUnSym},{"TypeFloatUnSym",TypeFloatUnSym},{"PropTypeFloatUnSym",TypeDoubleUnSym,
                    }};

                    switch (evaluate<FloidVarTypes>(task.base(),options)) {
                        case TypeIntSym:
                            TypeIntSymM();
                            break;

                        case TypeFloatSym:
                            TypeFloatSymM();
                            break;

                        case TypeDoubleSym:
                            TypeDoubleSymM();
                            break;

                        default:
                            break;
                    }
                }


                        void TypeFloatSymM() {
                            print("Choose type of matrix");
                            string third = getCommand();
                            int amount = stoi(third);
                            /*
                            SortedAlgFloiduence<Person> AlgFloid = SortedAlgFloiduence<Person>();
                            print("Enter amount of elements");
                            string third = getCommand();
                            int amount = stoi(third);
                            Person* searchfor;
                            for (int i = 0; i<amount; i++) {
                                Person *dummy = new Person();
                                AlgFloid.add(*dummy);
                                if(i == amount-1)
                                    searchfor = dummy;
                            }
                            clock_t start, end;
                            start = clock();
                            AlgFloid.TypeFloatSymM(*searchfor, 0, AlgFloid.getLength()-1);
                            end = clock();
                            printf("The search was executed in %.7f sec for %d elements\n", ((double) end - start) / ((double) CLOCKS_PER_SEC), amount);
                            */
                        }



                        void TypeDoubleSym,
                        M() {
            
                        }

                        void TypeIntSymM() {
            
                        }
        string getCommand(){
            string commandToGet;
            getline(cin,commandToGet);
            if (commandToGet.empty()) {return "unkn";} else return commandToGet;
        }

        void print(string message) {
            cout << message << endl;
        }
};

#endif
