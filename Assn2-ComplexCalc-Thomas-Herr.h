#ifndef COMP2006_ASSIGNMENT2_ASSN2_COMPLEXCALC_THOMAS_HERR_H
#define COMP2006_ASSIGNMENT2_ASSN2_COMPLEXCALC_THOMAS_HERR_H

#include <string>
#include <regex>

struct ComplexNumber {
    double real = 0;
    char op = ' ';
    double imag = 0;
    bool processString(string input);
    void show() {
        printf("Real: %lf, Imaginary: %lf, Operator: %c \n", this->real, this->imag, this->op);
    }
    string toString();
};

/**
 * Given an input string parse it and load values into struct variables
 * @param input
 * @return bool Indication if given input was able to be parsed
 */
bool ComplexNumber::processString(string input) {

    bool isValid = true;

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
    } else {
        isValid = false;
    }

    //Parse from symbol to end of string
    regex secondTerm ("[j|i](..)$");

    if(regex_search(input, match, secondTerm)) {
        printf("Successfully parsed second term: %s \n", match.str().c_str());

        string secondTermResult = match.str();
        secondTermResult.erase(0,1);
        std::stringstream secondTermStringStream(secondTermResult);
        secondTermStringStream >> this->imag;
    } else {
        isValid = false;
    }

    //Operator
    regex operation ("[0-9][^0-9|^a-z][a-z]");

    if(regex_search(input, match, operation)) {
        printf("Successfully parsed operation: %c \n", match.str().c_str()[1]);
        this->op = match.str().c_str()[1];

        if(op=='-') {
            this->imag = -this->imag;
        }

    } else {
        isValid = false;
    }

    return isValid;
}

string ComplexNumber::toString() {
    std::stringstream fmt;
    fmt << this->real << this->op << 'i' << this->imag;

    return fmt.str().c_str();
}

ComplexNumber add(ComplexNumber A, ComplexNumber B) {
    ComplexNumber result;

    result.real = A.real + B.real;
    result.imag = A.imag + B.imag;
    result.op = '+';

    return result;
}

ComplexNumber subtract(ComplexNumber A, ComplexNumber B) {
    ComplexNumber result;

    result.real = A.real - B.real;

    if(B.imag<0) {
        //Dealing with a negative number, add it
        result.imag = A.imag + abs(B.imag);
    } else {
        result.imag = A.imag - B.imag;
    }
    result.op = '-';

    return result;
}

ComplexNumber multiply(ComplexNumber A, ComplexNumber B) {
    ComplexNumber result;

    result.real = (A.real * B.real) - (A.imag * B.imag);
    result.imag = ((A.real * B.imag) + (A.imag * B.real));
    result.op = '+';

    return result;
}

ComplexNumber divide(ComplexNumber A, ComplexNumber B) {
    ComplexNumber result;

    result.real = ((A.real * B.real) + (A.imag * B.imag))/((B.imag * B.imag) + (B.real * B.real));
    result.imag = ((A.imag * B.real) - (A.real * B.imag))/((B.imag * B.imag) + (B.real * B.real));
    result.op = '+';

    return result;
}

#endif //COMP2006_ASSIGNMENT2_ASSN2_COMPLEXCALC_THOMAS_HERR_H
