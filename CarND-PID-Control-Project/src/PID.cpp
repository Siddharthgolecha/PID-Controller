#include "PID.h"

#include <algorithm>
// using namespace std;


PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp, double Ki, double Kd) {
  values[0] = PID::Kp = Kp;
  values[1] = PID::Ki = Ki;
  values[2] = PID::Kd = Kd;
  p_err = 0.0;
  i_err = 0.0;
  d_err = 0.0;
  prev_cte = 0.0;
}

void PID::UpdateError(double cte) {
  // Proportional error.
  p_err = cte;

  // Integral error.
  i_err += cte;

  // Diferential error.
  d_err = cte - prev_cte;
  prev_cte = cte;

}

double PID::TotalError() {
  return p_err * Kp + i_err * Ki + d_err * Kd;
}

