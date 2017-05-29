//
// Created by Thomas Herr on 2017-05-29.
//

#ifndef COMP2006_ASSIGNMENT2_ASSN2_HOSPITAL_THOMAS_HERR_H
#define COMP2006_ASSIGNMENT2_ASSN2_HOSPITAL_THOMAS_HERR_H

/**
 * Displays the user menu, then inputs and returns as the function value
 * the problem number selected.
 * @return Integer value selected by the user
 */
int get_problem() {
    return 0;
}

/**
 * Prompts the user to enter the data required for problem 1, and sends
 * this data back to the calling module vai output parameters
 */
void get_rate_drop_factor(int *data) {

}

/**
 * Prompts the user to enter the data required for problem 3,
 * and sends this data back to the calling module via output parameters
 */
void get_kg_rate_conc(int *data) {

}

/**
 * Prompts the user to enter the data required for problem 4,
 * and sends this data back to calling module via output parameters
 */

void get_units_conc(int *data) {

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
