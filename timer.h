/// \file 
/// \brief Definitions related to the Timer class

#ifndef TIMER_H
#define TIMER_H

#include <ctime>


class Timer           /// This class allows to represent timers
{
	private:
		clock_t begin;		///< the clock at the beggining of the timer
		double duration;	///< the duration of the the timer in seconds
	
	public:
		// constructors and destructor
		Timer ();						///< constructs a timer
		~Timer ();					///< destructor
		
		// functions in order to handle timer
		void Reset ();           ///< resets the timer
		void Start ();   				 ///< starts the timer
		void Stop ();   				 ///< stop the timer
		double Get_Duration ();  ///< returns the duration related to the timer in milliseconds
};


//-----------------------------
// inline function definitions
//-----------------------------


inline void Timer::Reset ()
// resets the timer
{
	duration = 0;
}


inline void Timer::Start ()
// starts the timer
{
	begin = clock();
}


inline void Timer::Stop ()
// stop the timer
{
	duration += ((double) (clock() - begin)) / CLOCKS_PER_SEC;
}


inline double Timer::Get_Duration ()
// returns the duration related to the timer in seconds
{
	return duration;
}

#endif

