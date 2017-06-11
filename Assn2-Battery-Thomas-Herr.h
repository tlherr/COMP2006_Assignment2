/**
 *  P = I*V		P = Power in watts (W)		V = Voltage in Volts (V)
    W = P*t		I = Current in Amps (A)		W = Energy in Joules (J)
			    t = Time in seconds (s)		(re-arrange the equations as required)
 */
#ifndef COMP2006_ASSIGNMENT2_ASSN2_BATTERY_THOMAS_HERR_H
#define COMP2006_ASSIGNMENT2_ASSN2_BATTERY_THOMAS_HERR_H

#include <cstdio>
#include <string>

/**
 * Represent a battery with members consisting of the voltage, how much energy the battery is capable of storing,
 * and how much energy it is currently storing (in Joules).
 */
struct battery_t {
    std::string name;
    int voltage;
    int current_energy; //Joules
    int maximum_potential_storage; //Joules

    //Define functions for input and output of batteries
    void charge(int energy_input);
    void discharge(int energy_draw);

    void recharge();

};
/**
 * Fully charge a battery
 */
void battery_t::recharge() {
    this->current_energy = maximum_potential_storage;
    printf("Battery (%s %dv) has been recharged. Current Energy: %dJ \n", this->name.c_str(), this->voltage, this->current_energy);
}

/**
 * Input energy into the battery
 * @param energy_input Measured in Joules
 */
void battery_t::charge(int energy_input) {
    this->current_energy = this->current_energy + energy_input;
}

/**
 *
 * @param energy_draw Measured in Joules
 */
void battery_t::discharge(int energy_draw) {
    this->current_energy = this->current_energy - energy_draw;
}

/**
 * Determines whether the battery’s energy reserve is adequate to power the device for the prescribed time, if so:
a.i. the function updates the battery’s energy reserve by subtracting the energy
       consumed and then returns the value true (1).
a.ii. Otherwise it returns the value false (0) and leaves the energy reserve unchanged.

 *
 * @param current Measured in Amps
 * @param seconds
 * @param battery
 */
bool power_device(int current, int seconds, battery_t battery) {

    //Energy in Joules = Power in watts * time
    //Power in watts = Current in amps * voltage

    int requested_watts = current * battery.voltage;
    int requested_joules = requested_watts * seconds;

    //Determine if energy reserve is adequate to power device for prescribed time
    if((battery.current_energy-requested_joules)>0) {
        //We have power to spare, device can be run. Withdraw energy
        battery.discharge(requested_joules);
        printf("Battery (%s %dv) can discharge: %dJ to power %dA for %d seconds. Current battery energy: %dJ \n", battery.name.c_str(), battery.voltage, requested_joules, current, seconds, battery.current_energy);
        return true;
    } else {
        printf("Battery (%s %dv) cannot discharge: %dJ to power %dA for %d seconds. Energy after operation: %dJ \n", battery.name.c_str(), battery.voltage, requested_joules, current, seconds, battery.current_energy);
        return false;
    }
}

/**
 * that takes a battery and the current of an electrical device as input parameters and returns the number of
 * seconds the battery can operate the device before it is fully discharged (assume ideal battery).
 * @param battery
 * @param current Measured in Amps
 * @return int Maximum time battery could provide the specified amount of energy
 */
int max_time(battery_t battery, int current) {

    int max_time = battery.current_energy/(current*battery.voltage);
    //Trying to solve for t (time in seconds)
    //Time = Current Energy in Joules/(Current in Amps*Voltage)
    printf("Battery (%s %dv) could provide %d Amps of power for %d seconds \n", battery.name.c_str(), battery.voltage, current, max_time);
    return max_time;
}

#endif //COMP2006_ASSIGNMENT2_ASSN2_BATTERY_THOMAS_HERR_H
