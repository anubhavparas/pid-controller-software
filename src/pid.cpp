
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
    prev_error(0),
    integral_sum(0),
    dt(dt) {
  if (dt <= 0) {
    throw std::invalid_argument("dt should be greater than 0.");
  }
}

PIDController::~PIDController() {
}

double PIDController::compute(double setpoint_value, double measured_value) {
  std::cout << "Target setpoint value: " << setpoint_value << std::endl;
  std::cout << "Measured value: " << measured_value << std::endl;

  double error = setpoint_value - measured_value;

  double proportional_out = kP * error;

  integral_sum += error * dt;
  double integral_out = kI * integral_sum;

  double derivative = (error - prev_error) / dt;
  double derivative_out = kD * derivative;

  double output = proportional_out + integral_out + derivative_out;

  if (output > max_value) {
    output = max_value;
  } else if (output < min_value) {
    output = min_value;
  }

  prev_error = error;

  return output;
}

double PIDController::get_dt() const {
  return dt;
}

void PIDController::set_dt(double dT) {
  if (dT <= 0) {
    throw std::invalid_argument("dt should be greater than 0.");
  } else {
    this->dt = dT;
  }
}

double PIDController::get_kD() const {
  return kD;
}

void PIDController::set_kD(double kd) {
  this->kD = kd;
}

double PIDController::get_kI() const {
return kI;
}

void PIDController::set_kI(double ki) {
  this->kI = ki;
}

double PIDController::get_kP() const {
return kP;
}

void PIDController::set_kP(double kp) {
  this->kP = kp;
}

double PIDController::get_max_value() const {
return max_value;
}

void PIDController::set_max_value(double maxValue) {
max_value = maxValue;
}

double PIDController::get_min_value() const {
return min_value;
}

void PIDController::set_min_value(double minValue) {
min_value = minValue;
}

double PIDController::get_prev_error() const {
return prev_error;
}

double PIDController::get_integral_sum() const {
return integral_sum;
}
