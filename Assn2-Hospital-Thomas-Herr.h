//
// Created by Thomas Herr on 2017-05-29.
//

#ifndef COMP2006_ASSIGNMENT2_ASSN2_HOSPITAL_THOMAS_HERR_H
#define COMP2006_ASSIGNMENT2_ASSN2_HOSPITAL_THOMAS_HERR_H

#include <cstdio>
#include <iostream>
#include <iomanip>
#include <cmath>

/**
 * Takes rate and drop factor as input parameters and
 * returns drops/min (rounded to nearest whole drop) as a function value
 */

int fig_drops_min(int drops, int mins) {
    return (int) ceil(drops / mins);
}

/**
 * Takes as an input parameter the number of hours over which 1 L is to
 * be delivered and returns ml/hr (rounded) as a function value
 */

int fig_ml_hr(int num_hours) {
    return (1000/num_hours);
}

/**
 * Takes as input parameters rate in mg/kg/hr, patient weight in kg, and concentration of
 * drug in mg/ml and returns ml/hr (rounded) as function value
 */

int by_weight(float rate, int patient_weight, int concentration) {
    //Look at time based units - both are hours
    //mg/kg/hour
    //ml/hr


    //mg*kg  multiplied by 1/hr
    //multiply by kg/1 to cancel out
    //this equals mg/hr
    //multiply that by ml/mg

    return static_cast<int>((patient_weight*rate)/concentration);
}

/**
 * Takes as input parameters rate in units/hr and concentration in units/ml, and returns ml/hr
 * (rounded) as function value
 *
 */

int by_units(int rate, int concentration) {
    return (rate/concentration);
}

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
    std::cout << "(2) 1 L for n hr" << std::setw(10) << "ml / hr" << std::endl;
    std::cout << "(3) mg/kg/hr & concentration in mg/ml" << std::setw(10) << "ml / hr" << std::endl;
    std::cout << "(4) units/hr & concentration in units/ml" << std::setw(10) << "ml/hr" << std::endl;
    std::cout << "(5) Exit" << std::endl;

    int problem;

    for(;;) {
        std::cout << "Enter the number of the programme you wish to solve: ";

        if(std::cin >> problem) {
            if(problem<1|problem>5) {
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

    return problem;
}

/**
 * Prompts the user to enter the data required for problem 1, and sends
 * this data back to the calling module vai output parameters
 */
void get_rate_drop_factor(int &result) {
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
        std::cout << "Enter tubing's drop factor (drops/ml): ";

        if(std::cin >> drops) {
            break;
        } else {
            std::printf("Invalid Integer Entered. Please try again \n");
            std::cin.clear();
            std::cin.ignore();
        }
    }

    result = (fig_drops_min(rate,60) * drops);
}
/**
 * Prompts the user to enter the data required for problem 2, and sends
 * this data back to the calling module via output parameters
 */
void get_one_l_n_hr(int &result) {
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

    result = fig_ml_hr(hours);
}

/**
 * Prompts the user to enter the data required for problem 3,
 * and sends this data back to the calling module via output parameters
 */
void get_kg_rate_conc(int &result) {
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

    result = by_weight(rate, patient_weight, concentration);
}

/**
 * Prompts the user to enter the data required for problem 4,
 * and sends this data back to calling module via output parameters
 */

void get_units_conc(int &result) {

    int rate;
    int concentration;


    for(;;) {
        std::cout << "Enter rate in units/hr: ";

        if(std::cin >> rate) {
            break;
        } else {
            std::printf("Invalid Rate Entered. Please try again \n");
            std::cin.clear();
            std::cin.ignore();
        }
    }

    for(;;) {
        std::cout << "Enter concentration in units/ml: ";

        if(std::cin >> concentration) {
            break;
        } else {
            std::printf("Invalid Concentration Entered. Please try again \n");
            std::cin.clear();
            std::cin.ignore();
        }
    }

    result = by_units(rate, concentration);
}

#endif //COMP2006_ASSIGNMENT2_ASSN2_HOSPITAL_THOMAS_HERR_H
