#include "header.h"

int main(void){


    fstream outfile("outputSequence.log", ios::out);
    fstream results("results.log", ios::out);
    results << "Method  N   Duration"<< endl;
    outfile.clear();
    outfile.close();
    results.close();
    double listAvg = 0;
    double vectAvg = 0;
    listAvg = testListMain();
    vectAvg = testVectorMain();
    cout << "Average List Time: " << listAvg << endl;
    cout << "Average Vector Time: " << vectAvg << endl;
    return 0;
}