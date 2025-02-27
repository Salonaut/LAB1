#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <ctime>
#include <string>

using namespace std;


double measureTimeIntAdd(int a, int b, int iterations);
double measureTimeLongAdd(long a, long b, int iterations);
double measureTimeDoubleAdd(double a, double b, int iterations);
double measureTimeFloatAdd(float a, float b, int iterations);
double measureTimeCharAdd(char a, char b, int iterations);


double measureTimeIntSub(int a, int b, int iterations);
double measureTimeLongSub(long a, long b, int iterations);
double measureTimeDoubleSub(double a, double b, int iterations);
double measureTimeFloatSub(float a, float b, int iterations);
double measureTimeCharSub(char a, char b, int iterations);


double measureTimeIntMul(int a, int b, int iterations);
double measureTimeLongMul(long a, long b, int iterations);
double measureTimeDoubleMul(double a, double b, int iterations);
double measureTimeFloatMul(float a, float b, int iterations);
double measureTimeCharMul(char a, char b, int iterations);


double measureTimeIntDiv(int a, int b, int iterations);
double measureTimeLongDiv(long a, long b, int iterations);
double measureTimeDoubleDiv(double a, double b, int iterations);
double measureTimeFloatDiv(float a, float b, int iterations);
double measureTimeCharDiv(char a, char b, int iterations);


void printResultsToFile(vector<string>& operations, vector<double>& times, vector<string>& dataTypes, int fastestIndex, int iterations);



int main() {
    vector<string> operations = {"Addition", "Subtraction", "Multiplication", "Division"};
    vector<string> dataTypes = {"int", "long", "double", "float", "char"};
    vector<int> iterations = {10000000}; // Кількість ітерацій
    vector<double> times(operations.size() * dataTypes.size(), 0);

    int fastestIndex = 0;


    for (int i = 0; i < operations.size(); i++) {
        for (int j = 0; j < dataTypes.size(); j++) {
            double timeTaken = 0.0;
            if (operations[i] == "Addition") {
                if (dataTypes[j] == "int") timeTaken = measureTimeIntAdd(1, 1, iterations[0]);
                if (dataTypes[j] == "long") timeTaken = measureTimeLongAdd(1, 1, iterations[0]);
                if (dataTypes[j] == "double") timeTaken = measureTimeDoubleAdd(1.0, 1.0, iterations[0]);
                if (dataTypes[j] == "float") timeTaken = measureTimeFloatAdd(1.0f, 1.0f, iterations[0]);
                if (dataTypes[j] == "char") timeTaken = measureTimeCharAdd('a', 'b', iterations[0]);
            } else if (operations[i] == "Subtraction") {
                if (dataTypes[j] == "int") timeTaken = measureTimeIntSub(1, 1, iterations[0]);
                if (dataTypes[j] == "long") timeTaken = measureTimeLongSub(1, 1, iterations[0]);
                if (dataTypes[j] == "double") timeTaken = measureTimeDoubleSub(1.0, 1.0, iterations[0]);
                if (dataTypes[j] == "float") timeTaken = measureTimeFloatSub(1.0f, 1.0f, iterations[0]);
                if (dataTypes[j] == "char") timeTaken = measureTimeCharSub('a', 'b', iterations[0]);
            } else if (operations[i] == "Multiplication") {
                if (dataTypes[j] == "int") timeTaken = measureTimeIntMul(1, 1, iterations[0]);
                if (dataTypes[j] == "long") timeTaken = measureTimeLongMul(1, 1, iterations[0]);
                if (dataTypes[j] == "double") timeTaken = measureTimeDoubleMul(1.0, 1.0, iterations[0]);
                if (dataTypes[j] == "float") timeTaken = measureTimeFloatMul(1.0f, 1.0f, iterations[0]);
                if (dataTypes[j] == "char") timeTaken = measureTimeCharMul('a', 'b', iterations[0]);
            } else if (operations[i] == "Division") {
                if (dataTypes[j] == "int") timeTaken = measureTimeIntDiv(1, 1, iterations[0]);
                if (dataTypes[j] == "long") timeTaken = measureTimeLongDiv(1, 1, iterations[0]);
                if (dataTypes[j] == "double") timeTaken = measureTimeDoubleDiv(1.0, 1.0, iterations[0]);
                if (dataTypes[j] == "float") timeTaken = measureTimeFloatDiv(1.0f, 1.0f, iterations[0]);
                if (dataTypes[j] == "char") timeTaken = measureTimeCharDiv('a', 'b', iterations[0]);
            }

            times[i * dataTypes.size() + j] = timeTaken;


            if (timeTaken < times[fastestIndex]) {
                fastestIndex = i * dataTypes.size() + j;
            }
        }
    }

    string it;
    for (int i = 0; i < iterations.size(); i++) {
        it += to_string(iterations[i]);
    }

    int iter = stoi(it);

    printResultsToFile(operations, times, dataTypes, fastestIndex, iter);

    return 0;
}




double measureTimeIntAdd(int a, int b, int iterations) {
    clock_t start = clock();
    for (int i = 0; i < iterations; ++i) {
        volatile int result = a + b;
    }
    clock_t end = clock();
    return double(end - start) / CLOCKS_PER_SEC;
}
double measureTimeLongAdd(long a, long b, int iterations) {
    clock_t start = clock();
    for (int i = 0; i < iterations; ++i) {
        volatile long result = a + b;
    }
    clock_t end = clock();
    return double(end - start) / CLOCKS_PER_SEC;
}
double measureTimeDoubleAdd(double a, double b, int iterations) {
    clock_t start = clock();
    for (int i = 0; i < iterations; ++i) {
        volatile double result = a + b;
    }
    clock_t end = clock();
    return double(end - start) / CLOCKS_PER_SEC;
}
double measureTimeFloatAdd(float a, float b, int iterations) {
    clock_t start = clock();
    for (int i = 0; i < iterations; ++i) {
        volatile float result = a + b;
    }
    clock_t end = clock();
    return double(end - start) / CLOCKS_PER_SEC;
}
double measureTimeCharAdd(char a, char b, int iterations) {
    clock_t start = clock();
    for (int i = 0; i < iterations; ++i) {
        volatile char result = a + b;
    }
    clock_t end = clock();
    return double(end - start) / CLOCKS_PER_SEC;
}




double measureTimeIntSub(int a, int b, int iterations) {
    clock_t start = clock();
    for (int i = 0; i < iterations; ++i) {
        volatile int result = a - b;
    }
    clock_t end = clock();
    return double(end - start) / CLOCKS_PER_SEC;
}
double measureTimeLongSub(long a, long b, int iterations) {
    clock_t start = clock();
    for (int i = 0; i < iterations; ++i) {
        volatile long result = a - b;
    }
    clock_t end = clock();
    return double(end - start) / CLOCKS_PER_SEC;
}
double measureTimeDoubleSub(double a, double b, int iterations) {
    clock_t start = clock();
    for (int i = 0; i < iterations; ++i) {
        volatile double result = a - b;
    }
    clock_t end = clock();
    return double(end - start) / CLOCKS_PER_SEC;
}
double measureTimeFloatSub(float a, float b, int iterations) {
    clock_t start = clock();
    for (int i = 0; i < iterations; ++i) {
        volatile float result = a - b;
    }
    clock_t end = clock();
    return double(end - start) / CLOCKS_PER_SEC;
}
double measureTimeCharSub(char a, char b, int iterations) {
    clock_t start = clock();
    for (int i = 0; i < iterations; ++i) {
        volatile char result = a - b;
    }
    clock_t end = clock();
    return double(end - start) / CLOCKS_PER_SEC;
}



double measureTimeIntMul(int a, int b, int iterations) {
    clock_t start = clock();
    for (int i = 0; i < iterations; ++i) {
        volatile int result = a * b;
    }
    clock_t end = clock();
    return double(end - start) / CLOCKS_PER_SEC;
}
double measureTimeLongMul(long a, long b, int iterations) {
    clock_t start = clock();
    for (int i = 0; i < iterations; ++i) {
        volatile long result = a * b;
    }
    clock_t end = clock();
    return double(end - start) / CLOCKS_PER_SEC;
}
double measureTimeDoubleMul(double a, double b, int iterations) {
    clock_t start = clock();
    for (int i = 0; i < iterations; ++i) {
        volatile double result = a * b;
    }
    clock_t end = clock();
    return double(end - start) / CLOCKS_PER_SEC;
}
double measureTimeFloatMul(float a, float b, int iterations) {
    clock_t start = clock();
    for (int i = 0; i < iterations; ++i) {
        volatile float result = a * b;
    }
    clock_t end = clock();
    return double(end - start) / CLOCKS_PER_SEC;
}
double measureTimeCharMul(char a, char b, int iterations) {
    clock_t start = clock();
    for (int i = 0; i < iterations; ++i) {
        volatile char result = a * b;
    }
    clock_t end = clock();
    return double(end - start) / CLOCKS_PER_SEC;
}



double measureTimeIntDiv(int a, int b, int iterations) {
    clock_t start = clock();
    for (int i = 0; i < iterations; ++i) {
        if (b != 0) {
            volatile int result = a / b;
        }
    }
    clock_t end = clock();
    return double(end - start) / CLOCKS_PER_SEC;
}
double measureTimeLongDiv(long a, long b, int iterations) {
    clock_t start = clock();
    for (int i = 0; i < iterations; ++i) {
        if (b != 0) {
            volatile long result = a / b;
        }
    }
    clock_t end = clock();
    return double(end - start) / CLOCKS_PER_SEC;
}
double measureTimeDoubleDiv(double a, double b, int iterations) {
    clock_t start = clock();
    for (int i = 0; i < iterations; ++i) {
        if (b != 0) {
            volatile double result = a / b;
        }
    }
    clock_t end = clock();
    return double(end - start) / CLOCKS_PER_SEC;
}
double measureTimeFloatDiv(float a, float b, int iterations) {
    clock_t start = clock();
    for (int i = 0; i < iterations; ++i) {
        if (b != 0) {
            volatile float result = a / b;
        }
    }
    clock_t end = clock();
    return double(end - start) / CLOCKS_PER_SEC;
}
double measureTimeCharDiv(char a, char b, int iterations) {
    clock_t start = clock();
    for (int i = 0; i < iterations; ++i) {
        if (b != 0) {
            volatile char result = a / b;
        }
    }
    clock_t end = clock();
    return double(end - start) / CLOCKS_PER_SEC;
}


void printResultsToFile(vector<string>& operations, vector<double>& times, vector<string>& dataTypes, int fastestIndex, int iterations) {
    ofstream outFile("operation_times.txt");

    if (!outFile.is_open()) {
        cerr << "Error opening file for writing results!" << endl;
        return;
    }

    outFile << "+-------------------+--------------------+-----------------------+------------------------+\n";
    outFile << "| Operation         | Data Type          | Operations per Second | Speed (Percentage)     |\n";
    outFile << "+-------------------+--------------------+-----------------------+------------------------+\n";

    if (fastestIndex < 0 || fastestIndex >= times.size()) {
        cerr << "Error: fastestIndex is out of bounds!\n";
        fastestIndex = 0;
    }

    double fastestTime = times[fastestIndex];

    if (fastestTime <= 0) {
        cerr << "Warning: fastestTime is invalid (<= 0), setting to 1e-9.\n";
        fastestTime = 1e-9;
    }

    for (int i = 0; i < operations.size(); i++) {
        for (int j = 0; j < dataTypes.size(); j++) {
            double timeTaken = times[i * dataTypes.size() + j];

            if (timeTaken <= 0) {
                outFile << "| " << left << setw(17) << operations[i]
                        << "| " << left << setw(18) << dataTypes[j]
                        << "| " << setw(21) << "N/A (Invalid Time)"
                        << "| " << left << setw(22) << "N/A" << " |\n";
                continue;
            }

            double opsPerSec = iterations / timeTaken;

            
            int speedPercentage = static_cast<int>((fastestTime / timeTaken) * 100);
            speedPercentage = std::max(speedPercentage, 1); // Мінімум 1% для найшвидшої операції

            
            cerr << "Time taken: " << timeTaken << ", Speed percentage: " << speedPercentage << "%" << endl;

            int maxBarLength = 50;
            int barLength = std::min(speedPercentage / 2, maxBarLength);
            string bar(barLength, '=');

            outFile << "| " << left << setw(17) << operations[i]
                    << "| " << left << setw(18) << dataTypes[j]
                    << "| " << setw(21) << fixed << setprecision(2) << opsPerSec
                    << "| " << left << setw(22) << bar << " " << speedPercentage << "%" << " |\n";
        }
    }

    outFile << "+-------------------+--------------------+-----------------------+------------------------+\n";
    outFile.close();
}
