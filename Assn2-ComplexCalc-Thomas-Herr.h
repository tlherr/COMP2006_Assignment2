#ifndef COMP2006_ASSIGNMENT2_ASSN2_COMPLEXCALC_THOMAS_HERR_H
#define COMP2006_ASSIGNMENT2_ASSN2_COMPLEXCALC_THOMAS_HERR_H

#include <string>
#include <regex>

struct ComplexNumber {
    double real = 0;
    char op = ' ';
    double imag = 0;
    bool processString(string input);
    void toString();
};

/**
 * Given an input string parse it and load values into struct variables
 * @param input
 * @return bool Indication if given input was able to be parsed
 */
bool ComplexNumber::processString(string input) {

    //Expecting a string in the format: 23+j34
    smatch match;

    //Parse initial digits from front of string to operator
    regex firstTerm ("^(...)\\D");

    if(regex_search(input, match, firstTerm)) {
        printf("Successfully parsed first term: %s \n", match.str().c_str());

        string firstTermResult = match.str();
        firstTermResult.pop_back();
        std::stringstream firstTermStringStream(firstTermResult);
        firstTermStringStream >> this->real;
    }

    //Parse from symbol to end of string
    regex secondTerm ("[j|i](..)$");

    if(regex_search(input, match, secondTerm)) {
        printf("Successfully parsed second term: %s \n", match.str().c_str());

        string secondTermResult = match.str();
        secondTermResult.erase(0,1);
        std::stringstream secondTermStringStream(secondTermResult);
        secondTermStringStream >> this->imag;
    }

    //Operator
    regex operation ("[0-9][^0-9|^a-z][a-z]");

    if(regex_search(input, match, operation)) {
        printf("Successfully parsed operation: %c \n", match.str().c_str()[1]);
        this->op = match.str().c_str()[1];
    }

    this->toString();

    return false;
}

void ComplexNumber::toString() {
    printf("Real: %lf, Imaginary: %lf, Operator: %c \n", this->real, this->imag, this->op);
}

void add(ComplexNumber firstTerm, ComplexNumber secondTerm) {

}

void subtract(ComplexNumber firstTerm, ComplexNumber secondTerm) {

}

void multiply(ComplexNumber firstTerm, ComplexNumber secondTerm) {

}

void divide(ComplexNumber firstTerm, ComplexNumber secondTerm) {

}

#endif //COMP2006_ASSIGNMENT2_ASSN2_COMPLEXCALC_THOMAS_HERR_H
