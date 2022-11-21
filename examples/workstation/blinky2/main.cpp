#include "qpcpp.hpp"
#include "blinky2.hpp"

#include <iostream>

using namespace QP;
using namespace std;

static QEvt const* blinky_queueSto[10];

extern "C" void Q_onAssert(char const* const module, int loc) {
	cout << "Assertion failed in " << module << ':' << loc << endl;
	exit(-1);
}

void QF::onStartup(void) {}
void QF::onCleanup(void) {}
void QF::onClockTick(void) {
	QTimeEvt::TICK_X(0U, nullptr);  // perform the QF clock tick processing
}

static Blinky l_blinky;

QActive* const AO_Blinky = &l_blinky;
//extern QActive* const AO_Blinky;
int main() {

	QF::init(); // Initialize the framework
	//QF::onStartup(); // callback function configures and starts interrupts

	// statically allocate event queue buffer for the Blinky AO
	QTimeEvt m_timeEvt(AO_Blinky, TIMEOUT_SIG, 0U);

	cout << "Modified blink application:" << endl;
		cout << "with main and clas def in seperate files" << endl;

	m_timeEvt.armX(BSP_TICKS_PER_SEC / 2, BSP_TICKS_PER_SEC / 2);
	AO_Blinky->start(1U, // priority
			blinky_queueSto, Q_DIM(blinky_queueSto),
			nullptr, 0U);

	return QF::run();
}