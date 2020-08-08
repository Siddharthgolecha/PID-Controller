#ifndef PID_H
#define PID_H

class PID {  
  
public:
 
  double Kp, Ki , Kd;
  double values[3] = {0.0, 0.0, 0.0};
  double p_err, i_err, d_err;
  double prev_cte;

  /*
  * Constructor
  */
  PID();

  /*
  * Destructor.
  */
  virtual ~PID();

  /*
  * Initialize PID.
  */
  void Init(double Kp, double Ki, double Kd);

  /*
  * Update the PID error variables given cross track error.
  */
  void UpdateError(double cte);

  /*
  * Calculate the total PID error.
  */
  double TotalError();
  
  /*
  * Returns the PID sum.
  */
  double PID_sum(){
  	return Kp + Ki + Kd;
  }

  /*
  * Returns the PID sum.
  */
  void Set_value(double p, double i, double d){
  	Kp = p;
    Ki = i;
    Kd = d;
  }
  
  double* Get_values(){
  	return values;
  }
  
};

#endif /* PID_H */