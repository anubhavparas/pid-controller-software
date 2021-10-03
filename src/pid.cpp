
/** Copyright 2021 Anubhav Paras, Charu Sharma, Arunava Basu & Shon Cortes  
 *  @Authors
 *  Part 1: Design:
 *  - Driver: Anubhav Paras
 *  - Navigator: Charu Sharma
 * 
 *  Part 2: Implementation:
 *  - Driver: Shon Cortes
 *  - Navigator: Arunava Basu
*/

#include <pid.hpp>

#include <iostream>
#include <stdexcept>

PIDController::PIDController(double kP, double kI, double kD, double max_value,
                             double min_value, double dt)
    :
    kP(kP),
    kI(kI),
    kD(kD),
    max_value(max_value),
    min_value(min_value),
    dt(dt) {
  // TODO(Pair2):
  // if dt <= 0 then throw std::invalid_argument
  // set prev_error and integral_sum to 0
  if (dt <= 0) {
    throw std::invalid_argument("dt should be greater than 0.");
  }

  prev_error = 0;
  integral_sum = 0;
}

PIDController::~PIDController() {
}

double PIDController::compute(double setpoint_value, double measured_value) {
  std::cout << "Target setpoint value: " << setpoint_value << std::endl;
  std::cout << "Measured value: " << measured_value << std::endl;
  // TODO(Pair2): refer to the activity diagram for compute() method
  // ./docs/images/activity_diagram_PID_compute_method.png
  return 0;
}

double PIDController::get_dt() const {
  // TODO(Pair2): return dt
  return dt;
}

void PIDController::set_dt(double dt) {
  // TODO(Pair2): // if dt <= 0 then throw std::invalid_argument
  // else set the value of dt
}

double PIDController::get_kD() const {
  // TODO(Pair2): return the value of kD
  return kD;
}

void PIDController::set_kD(double kD) {
// TODO(Pair2): set the value of kD
  kD = kD;
}

double PIDController::get_kI() const {
// TODO(Pair2): return the value of kI
return kI;
}

void PIDController::set_kI(double kI) {
// TODO(Pair2): set the value of kI
kI = kI;
}

double PIDController::get_kP() const {
// TODO(Pair2): return the value of kP
return kP;
}

void PIDController::set_kP(double kP) {
// TODO(Pair2): set the value of kP
kP = kP;
}

double PIDController::get_max_value() const {
// TODO(Pair2): return the value of max_value
return max_value;
}

void PIDController::set_max_value(double maxValue) {
// TODO(Pair2): set the value of max_value
max_value = maxValue;
}

double PIDController::get_min_value() const {
// TODO(Pair2) return the value of min_value
return min_value;
}

void PIDController::set_min_value(double minValue) {
// TODO(Pair2): set the value of min_value
min_value = minValue;
}

double PIDController::get_prev_error() const {
// TODO(Pair2): return the value of prev_error
return prev_error;
}

double PIDController::get_integral_sum() const {
// TODO(Pair2): return the value of integral_sum
return integral_sum;
}
