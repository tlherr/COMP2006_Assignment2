//
// Created by Thomas Herr on 2017-05-29.
//

#ifndef COMP2006_ASSIGNMENT2_ASSN2_HOSPITAL_THOMAS_HERR_H
#define COMP2006_ASSIGNMENT2_ASSN2_HOSPITAL_THOMAS_HERR_H

#include <cstdio>
#include <iostream>
#include <iomanip>

/**
 * Displays the user menu, then inputs and returns as the function value
 * the problem number selected.
 * @return Integer value selected by the user
 */
int get_problem() {
    std::cout << std::setw(20) << "Intravenous Rate Assistant" << std::endl;
    std::cout << std::setw(5) << "Given a medical order in:" << std::setw(10)
              << "Calculate Rate in:" << std::endl;
    std::cout << "(1) ml/hr & tubing drop factor" << std::setw(10) << "drop/min" << std::endl;
    std::cout << "(2) ml/hr & tubing drop factor" << std::setw(10) << "ml / hr" << std::endl;
    std::cout << "(3) ml/hr & tubing drop factor" << std::setw(10) << "ml / hr" << std::endl;
    std::cout << "(4) ml/hr & tubing drop factor" << std::setw(10) << "ml/hr" << std::endl;
    std::cout << "(5) Exit" << std::endl;

    int problem;

    for(;;) {
        std::cout << "Enter the number of the programme you wish to solve: ";

        if(std::cin >> problem) {
            break;
        } else {
            std::printf("Invalid Integer Entered. Please try again \n");
            std::cin.clear();
            std::cin.ignore();
        }
    }

    return problem;
}

/**
 * Prompts the user to enter the data required for problem 1, and sends
 * this data back to the calling module vai output parameters
 */
void get_rate_drop_factor(int* result) {
    int rate;
    int drops;

    for(;;) {
        std::cout << "Enter rate in ml/hr: ";

        if(std::cin >> rate) {
            break;
        } else {
            std::printf("Invalid Integer Entered. Please try again \n");
            std::cin.clear();
            std::cin.ignore();
        }
    }

    for(;;) {
        std::cout << "Enter tubing’s drop factor (drops/ml): ";

        if(std::cin >> drops) {
            break;
        } else {
            std::printf("Invalid Integer Entered. Please try again \n");
            std::cin.clear();
            std::cin.ignore();
        }
    }

    result = (int *) (drops + rate);
}
/**
 * Prompts the user to enter the data required for problem 2, and sends
 * this data back to the calling module via output parameters
 */
void get_one_l_n_hr(int *result) {
    int hours;
    for(;;) {
        std::cout << "Enter number of hours: ";

        if(std::cin >> hours) {
            break;
        } else {
            std::printf("Invalid Integer Entered. Please try again \n");
            std::cin.clear();
            std::cin.ignore();
        }
    }

    result = (int *) (1000 / hours);
}

/**
 * Prompts the user to enter the data required for problem 3,
 * and sends this data back to the calling module via output parameters
 */
void get_kg_rate_conc(int *result) {
    float rate;
    int patient_weight;
    int concentration;


    for(;;) {
        std::cout << "Enter rate in mg/kg/hr: ";

        if(std::cin >> rate) {
            break;
        } else {
            std::printf("Invalid Float Entered. Please try again \n");
            std::cin.clear();
            std::cin.ignore();
        }
    }

    for(;;) {
        std::cout << "Enter patient weight in kg: ";

        if(std::cin >> patient_weight) {
            break;
        } else {
            std::printf("Invalid Weight Entered. Please try again \n");
            std::cin.clear();
            std::cin.ignore();
        }
    }

    for(;;) {
        std::cout << "Enter concentration in mg/ml: ";

        if(std::cin >> concentration) {
            break;
        } else {
            std::printf("Invalid Concentration Entered. Please try again \n");
            std::cin.clear();
            std::cin.ignore();
        }
    }

    result = (int *) 6;
}

/**
 * Prompts the user to enter the data required for problem 4,
 * and sends this data back to calling module via output parameters
 */

void get_units_conc(int *result) {

}

/**
 * Takes rate and drop factor as input parameters and
 * returns drops/min (rounded to nearest whole drop) as a function value
 */

int fig_drops_min(int drops, int mins) {
    return 0;
}

/**
 * Takes as an input parameter the number of hours over which 1 L is to
 * be delivered and returns ml/hr (rounded) as a function value
 */

int fig_ml_hr(int num_hours) {
   return 0;
}

/**
 * Takes as input parameters rate in mg/kg/hr, patient weight in kg, and concentration of
 * drug in mg/ml and returns ml/hr (rounded) as function value
 */

int by_weight(int rate, int patient_weight, int concentration) {
   return 0;
}

/**
 * Takes as input parameters rate in units/hr and concentration in units/ml, and returns ml/hr
 * (rounded) as function value
 *
 */

int by_units(int rate, int concentration) {
   return 0;
}

#endif //COMP2006_ASSIGNMENT2_ASSN2_HOSPITAL_THOMAS_HERR_H
