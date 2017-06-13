/**
 * Student Name: Thomas Herr
 * Student Number: 200325519
 * 17S Introduction to C++ - 01 (COMP2006-17S-30694)
 */

using namespace std;

#include <iostream>
#include "Assn2-Hospital-Thomas-Herr.h"
#include "Assn2-Battery-Thomas-Herr.h"
#include "Assn2-ComplexCalc-Thomas-Herr.h"

void question_one();
void question_two();
int question_three();

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
        case 2:
            question_two();
            break;
        case 3:
            for(;;) {
                int running = question_three();
                if(!running) {
                    break;
                }
            }
            break;
    }

    #if defined(__linux__)
        __pause();
    #elif defined(__APPLE__)
        system( "read -n 1 -s -p \"Press any key to continue...\"" );
    #elif defined(_WIN32)
        system("pause");
    #elif defined(_WIN64)
        system("pause");
    #endif

    return 0;
}

void question_one() {

    for(;;) {
        int selection = COMP2006_ASSIGNMENT2_ASSN2_HOSPITAL_THOMAS_HERR_H::get_problem();
        int result = 0;

        if(selection==5) {
            cout << "Exiting..." << endl;
            break;
        }

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
}

void question_two() {
    battery_t battery;
    battery.name = "Automotive Battery";
    battery.voltage = 12;
    battery.maximum_potential_storage = 5000000;

    //Start the battery off fully charged
    battery.recharge();

    //Power a 4 Amp light for 15 minutes
    COMP2006_ASSIGNMENT2_ASSN2_BATTERY_THOMAS_HERR_H::power_device(4, 15*60, battery);
    //Then find out how long the battery’s remaining energy could power an 8 Amp device.
    COMP2006_ASSIGNMENT2_ASSN2_BATTERY_THOMAS_HERR_H::max_time(battery, 8);
    //Recharge the battery
    battery.recharge();
    //Recalculate how long it could operate an 8 Amp device once fully charged
    COMP2006_ASSIGNMENT2_ASSN2_BATTERY_THOMAS_HERR_H::max_time(battery, 8);
}

int question_three() {
    ComplexNumber A;
    ComplexNumber B;

    string first_complex;
    string second_complex;

    int userOperation;

    //Provide List of available operations
    for(;;) {
        cout << "Available Operations: " << endl;
        cout << "(1). C = A+B" << endl;
        cout << "(2). C = A-B" << endl;
        cout << "(3). C = A*B" << endl;
        cout << "(4). C = A/B" << endl;
        cout << "(5). Exit" << endl;
        cin >> userOperation;

        if(!cin.fail()) {
            if(userOperation>=1|userOperation<=5) {
                break;
            } else {
                printf("Invalid selection \n");
                cin.clear();
                cin.ignore();
            }
        } else {
            printf("Invalid selection \n");
            cin.clear();
            cin.ignore();
        }
    }

    if(userOperation==5) {
        cout << "Exiting..." << endl;
        return 0;
    }


    //Get the input from the user
    for(;;) {
        printf("Enter the First Complex Number: A =");
        //Use cin.get();
        cin >> setw(20) >> first_complex;

        if(A.processString(first_complex)) {
            break;
        } else {
            printf("Invalid complex number. Please enter in the form A+jB Where A and B are integers. \n");
            cin.clear();
            cin.ignore();
        }
    }

    for(;;) {
        printf("Enter the Second Complex Number: B =");
        cin >> second_complex;

        if(B.processString(second_complex)) {
            break;
        } else {
            printf("Invalid complex number. Please enter in the form A+jB Where A and B are integers. \n");
            cin.clear();
            cin.ignore();
        }
    }

    ComplexNumber result;

    switch(userOperation) {
        default:
            cout << "Invalid Operation. Exiting..." << endl;
            break;
        case 1:
            result = COMP2006_ASSIGNMENT2_ASSN2_COMPLEXCALC_THOMAS_HERR_H::add(A,B);
            break;
        case 2:
            result = COMP2006_ASSIGNMENT2_ASSN2_COMPLEXCALC_THOMAS_HERR_H::subtract(A,B);
            break;
        case 3:
            result = COMP2006_ASSIGNMENT2_ASSN2_COMPLEXCALC_THOMAS_HERR_H::multiply(A,B);
            break;
        case 4:
            result = COMP2006_ASSIGNMENT2_ASSN2_COMPLEXCALC_THOMAS_HERR_H::divide(A,B);
            break;
        case 5:
            cout << "Exiting..." << endl;
            return 0;
    }

    cout << fixed << "Result :" << result.toString() << endl;
    return 1;
}