#ifndef BLINKY2_HPP
#define BLINKY2_HPP

#include "qpcpp.hpp"
#include <iostream>
#include <cstdlib> // for exit()

using namespace QP;

enum { BSP_TICKS_PER_SEC = 100 };
// 1. Event signals that this active object handles.
enum BlinkySignals {
	TIMEOUT_SIG = QP::Q_USER_SIG,
	MAX_SIG
};

// 2. Event parameters

class BlinkyEvt : public QP::QEvt {
public:
	uint8_t key_code; /* QEvt adds signal parameter and this has the user enetered key info.*/
};

// 3. Create a pointer to the active object, which will be defined in another cpp file.


class Blinky : public QActive {
private:
	//QTimeEvt m_timeEvt;
public:
	Blinky();
protected:
	Q_STATE_DECL(initial);
	Q_STATE_DECL(off);
	Q_STATE_DECL(on);
};

#endif









