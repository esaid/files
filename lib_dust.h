/******************************************************************************
 *
 * This file is part of the DCES project.
 * See http://www.ohwr.org/projects/dces-dtrhf-ser1ch-v1
 *
 * Copyright (C) 2016 CERN
 * All rights not expressly granted are reserved.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 3
 * of the License, or (at your option) any later version.
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
 *
 * @author DCES Dev team, dces-dev@cern.ch
 *****************************************************************************/


#include <Arduino.h>

#define NB_MEAS 20 // Number of measurements to do . 
// si PAUSE = 165 alors coeeficient =1
#define PAUSE 165 // tau = 5 *R*C = 165 ms temps de recharge du condensateur
#define coefficient 1
// si PAUSE = 0 , alors coefficient = 1.7 
//#define PAUSE 0 
//#define coefficient 1.7


#define dustPin 6
#define ledPower 2
void initDust(void);		// Call this function to initialize the pin (A0) used to measure dust 
float measureDust(float &avgRetDust, float &medRetDust, float &stdevRetDust , float &ugRetDust); // Call this function will measure dust and return the value(s)
