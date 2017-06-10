/**
 * Student Name: Thomas Herr
 * Student Number: 200325519
 * 17S Introduction to C++ - 01 (COMP2006-17S-30694)
 */

using namespace std;

#include <iostream>
#include "Assn2-Hospital-Thomas-Herr.h"

void question_one();
void question_two();
void question_three();

int main() {
    cout << "Select one of the following menu options" << endl;
    cout << "(1) Intravenous Rate Assistant" << endl;
    cout << "(2) Battery" << endl;
    cout << "(3) Complex Number Calculator" << endl;

    int selection;

    for(;;) {
        std::cout << "Enter the number of the programme you wish to solve: ";

        if(std::cin >> selection) {
            if(selection<1|selection>3) {
                std::printf("Invalid Integer Entered. Select an integer from the menu options. Please try again \n");
                std::cin.clear();
                std::cin.ignore();
            } else {
                break;
            }
        } else {
            std::printf("Invalid Integer Entered. Please try again \n");
            std::cin.clear();
            std::cin.ignore();
        }
    }

    switch(selection) {
        default:
            cout << "Invalid Selection. Exiting..." << endl;
        case 1:
            question_one();
            break;
    }


    return 0;
}

void question_one() {
    int selection = COMP2006_ASSIGNMENT2_ASSN2_HOSPITAL_THOMAS_HERR_H::get_problem();
    int result = 0;

    switch(selection) {
        default:
            printf("Invalid Selection. Exiting... \n");
        case 1:
            COMP2006_ASSIGNMENT2_ASSN2_HOSPITAL_THOMAS_HERR_H::get_rate_drop_factor(result);
            printf("The drop rate per minute is %d \n", result);
        break;

        case 2:
            COMP2006_ASSIGNMENT2_ASSN2_HOSPITAL_THOMAS_HERR_H::get_one_l_n_hr(result);
            printf("The rate in millilitres per hour is: %d \n", result);
        break;

        case 3:
            COMP2006_ASSIGNMENT2_ASSN2_HOSPITAL_THOMAS_HERR_H::get_kg_rate_conc(result);
            printf("The rate in millilitres per hour is: %d \n", result);
        break;

        case 4:
            COMP2006_ASSIGNMENT2_ASSN2_HOSPITAL_THOMAS_HERR_H::get_units_conc(result);
            printf("The rate in millilitres per hour is: %d \n", result);
        break;
    }
}