//============================================================================
// Product: DPP example
// Last Updated for Version: 7.1.0
// Date of the Last Update:  2022-08-28
//
//                    Q u a n t u m     L e a P s
//                    ---------------------------
//                    innovating embedded systems
//
// Copyright (C) Quantum Leaps, LLC. All rights reserved.
//
// This program is open source software: you can redistribute it and/or
// modify it under the terms of the GNU General Public License as published
// by the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// Alternatively, this program may be distributed and modified under the
// terms of Quantum Leaps commercial licenses, which expressly supersede
// the GNU General Public License and are specifically designed for
// licensees interested in retaining the proprietary status of their code.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program. If not, see <www.gnu.org/licenses/>.
//
// Contact information:
// https://state-machine.com
// <info@state-machine.com>
//============================================================================
#ifndef BSP_HPP
#define BSP_HPP

namespace BSP {

enum { TICKS_PER_SEC = 100 };

void init(void);
void displayPaused(std::uint8_t const paused);
void displayPhilStat(std::uint8_t const n, char const *stat);
void terminate(std::int16_t const result);

void randomSeed(std::uint32_t const seed); // random seed
std::uint32_t random(void); // pseudo-random generator

// for testing...
void wait4SW1(void);
void ledOn(void);
void ledOff(void);

} // namespace BSP

namespace DPP {
extern QP::QActive *the_Ticker0;
} // namespace DPP

#endif // BSP_HPP
