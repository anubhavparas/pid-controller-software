/** Copyright 2021 Anubhav Paras, Charu Sharma, Arunava Basu & Shon Cortes  
 *  @Authors
 *  Part 1: Design:
 *  - Driver: Anubhav Paras
 *  - Navigator: Charu Sharma
 * 
 *  Part 2: Implementation:
 *  - Driver:
 *  - Navigator:
*/

#include <gtest/gtest.h>
#include <memory>
#include <stdexcept>

#include <pid.hpp>

void createPIDCtrlInstanceWithInvalidDT(double dt) {
  std::unique_ptr<AbstractPIDController> pidController(
      new PIDController(0.1, 0.1, 0.1, 100.0, -100.0, dt));
}

// To test that the dt (sampling time) in the PIDController can never be <=0
TEST(PIDController_Test, invalid_dt_throws_exception) {
  EXPECT_THROW(createPIDCtrlInstanceWithInvalidDT(0), std::invalid_argument);
  EXPECT_THROW(createPIDCtrlInstanceWithInvalidDT(-1), std::invalid_argument);
}

// To test that prev_error and integral_sum is 0 when
// PIDController is instantiated
TEST(PIDController_Test, prev_error_and_integralsum_zero_initially) {
  std::unique_ptr<AbstractPIDController> pidController(
      new PIDController(0.1, 0.1, 0.1, 100.0, -100.0, 0.1));

  EXPECT_EQ(0, pidController->get_prev_error());
  EXPECT_EQ(0, pidController->get_integral_sum());
}

// Test set_dt() with invalid sampling time (dt): with dt <= 0
TEST(PIDController_Test, set_invalid_dt_throws_exception) {
  std::unique_ptr<AbstractPIDController> pidController(
      new PIDController(0.1, 0.1, 0.1, 100.0, -100.0, 0.1));

  EXPECT_THROW(pidController->set_dt(0), std::invalid_argument);
  EXPECT_THROW(pidController->set_dt(-1), std::invalid_argument);
}

// TEST all Getters and Setters
TEST(PIDController_Test, setters_and_getters_working) {
  std::unique_ptr<AbstractPIDController> pidController(
      new PIDController(0.1, 0.1, 0.1, 100.0, -100.0, 0.1));

  double kP = 0.2;
  double kI = 0.2;
  double kD = 0.2;
  double max_value = 50.0;
  double min_value = -50.0;
  double dt = 0.2;
  pidController->set_kP(kP);
  pidController->set_kI(kI);
  pidController->set_kD(kD);
  pidController->set_max_value(max_value);
  pidController->set_min_value(min_value);
  pidController->set_dt(dt);

  EXPECT_EQ(kP, pidController->get_kP());
  EXPECT_EQ(kI, pidController->get_kI());
  EXPECT_EQ(kD, pidController->get_kD());
  EXPECT_EQ(max_value, pidController->get_max_value());
  EXPECT_EQ(min_value, pidController->get_min_value());
  EXPECT_EQ(dt, pidController->get_dt());
}


// TEST if prev_error is set after compute()
TEST(PIDController_Test, prev_error_is_set_after_compute) {
  std::unique_ptr<AbstractPIDController> pidController(
      new PIDController(0.1, 0.1, 0.1, 100.0, -100.0, 0.1));
  double old_prev_error = pidController->get_prev_error();
  double setpoint_value = 20.0;
  double measured_value = 10.0;
  double error = setpoint_value - measured_value;
  pidController->compute(20.0, 10.0);
  double new_prev_error = pidController->get_prev_error();

  // new prev_error should not be the same as the old prev_error for this input
  EXPECT_FALSE(old_prev_error == new_prev_error);

  // the prev_error value should be set to the current error
  EXPECT_EQ(error, new_prev_error);
}

// TEST if integralsum is set after compute()
TEST(PIDController_Test, integral_sum_is_set_after_compute) {
  std::unique_ptr<AbstractPIDController> pidController(
      new PIDController(0.1, 0.1, 0.1, 100.0, -100.0, 0.1));

  double old_integral_sum = pidController->get_integral_sum();
  double setpoint_value = 20.0;
  double measured_value = 10.0;
  double error = setpoint_value - measured_value;
  double integral_sum = old_integral_sum + error * pidController->get_dt();
  pidController->compute(20.0, 10.0);
  double new_integral_sum = pidController->get_integral_sum();

  // new integral_sum should not be same as the old integral_sum for this input
  EXPECT_FALSE(old_integral_sum == new_integral_sum);

  // the integral_sum value should be set to the current integral_sum
  EXPECT_EQ(integral_sum, new_integral_sum);
}


// To test if compute() method works fine and returns appropriate value
TEST(PIDController_Test, test_compute_works) {
  std::unique_ptr<AbstractPIDController> pidController(
      new PIDController(0.1, 0.1, 0.1, 100.0, -100.0, 0.1));
  double actualValue = pidController->compute(20.0, 10.0);
  double expectedValue = 11.1;
  EXPECT_NEAR(expectedValue, actualValue, 0.001);

  // second iteration:
  actualValue = pidController->compute(20, 21.1);
  expectedValue = -11.121;
  EXPECT_NEAR(expectedValue, actualValue, 0.001);
}


// To test if compute() method works fine and returns max clipped value
TEST(PIDController_Test, compute_returns_max_val) {
  double max_value = 50.0;
  double min_value = -50.0;

  std::unique_ptr<AbstractPIDController> pidController(
      new PIDController(1, 1, 1, max_value, min_value, 0.1));

  double actualValue = pidController->compute(20.0, 10.0);
  double expectedValue = max_value;  // max_value
  EXPECT_NEAR(expectedValue, actualValue, 0.001);
}


// To test if compute() method works fine and returns min clipped value
TEST(PIDController_Test, compute_returns_min_val) {
  double max_value = 50.0;
  double min_value = -50.0;

  std::unique_ptr<AbstractPIDController> pidController(
      new PIDController(-1, -1, -1, max_value, min_value, 0.1));

  double actualValue = pidController->compute(20.0, 10.0);
  double expectedValue = min_value;  // min_value
  EXPECT_NEAR(expectedValue, actualValue, 0.001);
}



