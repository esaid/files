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


// Dust measurement example:
// You need to include lib_dust.h
#define DEBUG 1

#include <lib_dust.h>

float dust=0;
float avgDust, medDust, stdevDust , ugDust;
float timeStart , timeEnd ;
void setup(){
  Serial.begin(9600);
  initDust();			// Don't forget to call initDust() to set A0 pin as input pin
}


void loop(){
  //float myAvgDust, myMedDust, myStdevDust; // my own calirated values
  timeStart = millis();
  dust = measureDust(avgDust, medDust, stdevDust , ugDust);		// Then, you just have to call measureDust() whenever you want, and get the dust level
  timeEnd = millis() - timeStart ;
  
  Serial.print("Dust value averaged by the dust library: ");
  Serial.println(dust);
  Serial.print("Time (ms): ") ;
  Serial.print(timeEnd) ;
  Serial.println();
  
  // finer custom made calibration for the sensor
  //myAvgDust = ((avgDust*0.0049)-0.0256)*120000-38000;
  //myMedDust = ((medDust*0.0049)-0.0256)*120000-38000;
  //myStdevDust = stdevDust*588;
  Serial.println("My values: ");
  Serial.println(avgDust);
  Serial.println(medDust);
  Serial.println(stdevDust);
  Serial.println(ugDust);
  delay(5000);
}

