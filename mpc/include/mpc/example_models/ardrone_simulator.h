#ifndef MPC_MODEL_ARDRONESIM_H
#define MPC_MODEL_ARDRONESIM_H

#include <mpc/model/model.h>
#include <mpc/model/simulator.h>

namespace mpc
{

    namespace example_models
    {
		/**
		 This class provides methods to simulate a example model of tanks system
 		 @brief This class provides methods to simulate a example model of tanks system defined by a class mpc::model::Model object
			 \f[ \dot{x}(t) = Ax(t) + Bu(t) \f]
			 \f[ y(t) = Cx(t) \f]
		 on a fixed prediction horizon interval \f$ [t_0, t_N] \f$ with initial value \f$ x(t_0, x_0) = x_0 \f$ and given control \f$ u(\cdot, x_0) \f$. That is, for a given class mpc::model::Model object and a given control \f$ u \f$ the simulator can solve the differential or difference equation forward in time.
		 */
		class ArDroneSimulator : public mpc::model::Simulator
		{
		    public:
				/** @brief Constructor function */
				ArDroneSimulator();

				/** @brief Destructor function */
				~ArDroneSimulator() {};
				
				/**
				 @brief Function used to simulate the specified plant 
				 @param double* state_vect	State vector
				 @param double* input_vect	Input vector
				 @param double sampling_time	Sampling time
				 @return double*	New state vector
				 */
				double* simulatePlant(double *current_state, double *current_input, double sampling_time);


		    protected:


		    private:
				/** @brief Parameter of the system called beta 
				double beta_;
				
				 @brief Parameter of the system called At 
				double At_;
				
				 @brief Parameter of the system called cf 
				double cf_;
				
				 @brief Parameter of the system called g 
				double g_;*/

				/** @brief New state vector **/
				double* new_state_;

				Eigen::MatrixXd A_;
				Eigen::MatrixXd B_;

				double Ct_;
				double Cq_;
				double Ixx_;
				double Iyy_;
				double Izz_;
				double m_;
				double d_;
				double Jr_;
				double At_;
				
				
		};  //@class ArDroneSimulator

    }  //@namespace model

}  //@namespace mpc


#endif
