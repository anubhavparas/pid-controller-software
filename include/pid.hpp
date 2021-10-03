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

#ifndef PID_HPP_
#define PID_HPP_
#endif  // PID_HPP_

/**
 * @brief PIDController interface will have the compute() method.
 * This can be implemented by any concrete class
 */
class PIDControllerInterface {
 public:
  /**
   * @brief To find the controller output value based on the target setpoint and measured values
   * 
   * @param setpoint_value target value of the parameter
   * @param measured_value current measured estimate of the parameter
   * @return double 
   */
  virtual double compute(double setpoint_value, double measured_value) = 0;

  /**
   * @brief Destroy the PIDControllerInterface object
   * 
   */
  virtual ~PIDControllerInterface() {
  }
};



/**
 * @brief PIDController abstract class.
 * This contains all the getters and setters required for the member data.
 * 
 */
class AbstractPIDController : public PIDControllerInterface {
 public:
  virtual ~AbstractPIDController() {
  }
  virtual double get_dt() const = 0;
  virtual void set_dt(double dt) = 0;
  virtual double get_kD() const = 0;
  virtual void set_kD(double kD) = 0;
  virtual double get_kI() const = 0;
  virtual void set_kI(double kI) = 0;
  virtual double get_kP() const = 0;
  virtual void set_kP(double kP) = 0;
  virtual double get_max_value() const = 0;
  virtual void set_max_value(double maxValue) = 0;
  virtual double get_min_value() const = 0;
  virtual void set_min_value(double minValue) = 0;
  virtual double get_prev_error() const = 0;
  virtual double get_integral_sum() const = 0;
};



/**
 * @brief Concrete implementation of the PIDController abstract class and interface.
 * 
 */
class PIDController : public AbstractPIDController {
 public:
  /**
   * @brief Construct a new PIDController object
   * 
   * @param kP proportional gain
   * @param kI integral gain
   * @param kD differential gain
   * @param max_value maximum value that the parameter (ex: velocity) can have
   * @param min_value minimum value that the parameter (ex: velocity) can have
   * @param dt sampling time
   */
  PIDController(double kP, double kI, double kD, double max_value,
                    double min_value, double dt);
  /**
   * @brief Destroy the PIDController object
   * 
   */
  ~PIDController();

  /**
   * @brief 
   * 
   * @param setpoint_value target value of the parameter
   * @param measured_value current measured estimate of the parameter
   * @return double 
   */
  double compute(double setpoint_value, double measured_value) override;

  /**
   * @brief Get sampling time - dt
   * 
   * @return double 
   */
  double get_dt() const override;

  /**
   * @brief Set sampling time - dt
   * 
   * @param dt 
   */
  void set_dt(double dt) override;

  /**
   * @brief Get value of differential gain kD
   * 
   * @return double 
   */
  double get_kD() const override;

  /**
   * @brief Set value of differential gain kD
   * 
   * @param kD 
   */
  void set_kD(double kD) override;

  /**
   * @brief Get value of integral gain kI
   * 
   * @return double 
   */
  double get_kI() const override;

  /**
   * @brief Set value of integral gain kI
   * 
   * @param kI 
   */
  void set_kI(double kI) override;

  /**
   * @brief Get value of proportional gain kP
   * 
   * @return double 
   */
  double get_kP() const;

  /**
   * @brief Set value of proportional gain kP
   * 
   * @param kP
   */
  void set_kP(double kP);

  /**
   * @brief Get the max value for the parameter
   * 
   * @return double 
   */
  double get_max_value() const;

  /**
   * @brief Set the max value for the parameter
   * 
   * @param maxValue 
   */
  void set_max_value(double maxValue);

  /**
   * @brief Get the min value for the parameter
   * 
   * @return double 
   */
  double get_min_value() const;

  /**
   * @brief Set the min value for the parameter
   * 
   * @param minValue 
   */
  void set_min_value(double minValue);

  /**
   * @brief Get the prev_error
   * 
   * @return double 
   */
  double get_prev_error() const;

  /**
   * @brief Get the integral_sum over time
   * 
   * @return double 
   */
  double get_integral_sum() const;

 private:
  double kP;
  double kI;
  double kD;
  double max_value;
  double min_value;
  double dt;
  double integral_sum;
  double prev_error;
};
