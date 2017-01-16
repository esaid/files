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


#include <lib_dust.h>
//#define DEBUG 1
// prescaler 
#define cbi(sfr, bit) (_SFR_BYTE(sfr) &= ~_BV(bit))
#define sbi(sfr, bit) (_SFR_BYTE(sfr) |= _BV(bit))

// GLOBALS

unsigned int delayTime=280;
unsigned int delayTime2=40;

float offTime=9680; // so that delayTime + delayTime2 + offTime = 10ms
unsigned int skip_measurements=50; // skip the first 50 mesurements of a series

unsigned int dustVal=0;
float voltage = 0;



float calcVoltage = 0 ;
float range = 3.3;

unsigned int dustValues[NB_MEAS];
unsigned long sum;
//unsigned int timemeasure[NB_MEAS]; 
unsigned long timestart ;
unsigned long timestop ;

float fmap(float x, float in_min, float in_max, float out_min, float out_max)
{
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}


// INITIALIZE DUST PIN
void initDust(void){
  pinMode(ledPower,OUTPUT);
   // set prescale to 16, 32, 64 or 128
  // init to 16
  sbi(ADCSRA,ADPS2) ;
  cbi(ADCSRA,ADPS1) ;
  cbi(ADCSRA,ADPS0) ;
}

// MEASURE DUST
  void measureDust(float &avgRetDust, float &medRetDust, float &stdevRetDust , float &ugRetDust){
  unsigned int i,j; // loop indexes
  unsigned int temp; // temporary dust value
  // some statistical values
  float avgDust = 0.0;
  float medianDust = 0.0 ;
  float stdevDust =0.0 ;
  float dustug =0.0 ;
  float varDust = 0.0 ;
  // skip initial measurements see dust_calib
  for (i=0; i<skip_measurements; i++) {
    digitalWrite(ledPower,LOW);     // power on the LED
    delayMicroseconds(delayTime);
    delayMicroseconds(delayTime2);
    digitalWrite(ledPower,HIGH);    // turn the LED off
    delayMicroseconds(offTime);
  }
  delay (PAUSE);
  // Let s do the real measurements
  for (i=0; i<NB_MEAS; i++) {
    digitalWrite(ledPower,LOW);     // power on the LED
    delayMicroseconds(delayTime);
    timestart = micros();
    
    dustValues[i]=analogRead(dustPin);
    timestop = micros();
    //timemeasure[i] = (timestop - timestart) ;
    delayMicroseconds(delayTime2);
    digitalWrite(ledPower,HIGH);    // turn the LED off
    delayMicroseconds(offTime);
    delay (PAUSE);
  }
#ifdef DEBUG
  // display values in measurement order first
  // because later the array is going to be sorted to find the median
  Serial.println("all values:");
  for (i=0; i<NB_MEAS; i++) {
    Serial.print(i);
    Serial.print(" ");
    Serial.print(dustValues[i]);
    Serial.print(" ") ;
    calcVoltage = fmap(dustValues[i], 0, 1023, 0.0, range ) * coefficient;
    Serial.print(calcVoltage);
    //Serial.print(" ") ;
    //Serial.print(timemeasure[i]);
    Serial.println();
	
  }
#endif
  // compute median values
  for (i=0; i<NB_MEAS-1; i++) { // careful: stopping 1 index before the end
    for(j=i+1; j<NB_MEAS; j++) {
      if(dustValues[j] < dustValues[i]) {
        // swap elements
        temp = dustValues[i];
        dustValues[i] = dustValues[j];
        dustValues[j] = temp;
      }
    }
  }
  
  
  // compute avg
  sum = 0;
  for (i=0; i<NB_MEAS; i++) {
    sum += dustValues[i];
  }
  avgDust = sum/NB_MEAS;
    
	
	// compute variance
  for (i=0; i<NB_MEAS; i++) {  
	varDust += (dustValues[i]-avgDust)*(dustValues[i]-avgDust);
	//Serial.println(varDust);
  }
  varDust = varDust/NB_MEAS;
  stdevDust = sqrt(varDust);
  // now dustValues is sorted
  if(NB_MEAS%2==0) {
    // if there is an even number of elements, return mean of the two elements in the middle
    medianDust = (dustValues[NB_MEAS/2] + dustValues[NB_MEAS/2 - 1]) / 2.0;
  } else {
    // else return the element in the middle
    medianDust = dustValues[NB_MEAS/2];
  }
 calcVoltage = fmap(avgDust, 0, 1023, 0.0, range ) * coefficient ;

// courbe de la droite selon le constructeur y = 5.8 x + 0.6 
// avec y = en volts et x en mg/m3  soit x = (y - 0.6) / 5.8
 if (calcVoltage < 0.6 ) calcVoltage = 0.6 ;
    	
    dustug = ((calcVoltage - 0.6) / 5.8)  *1000 ;
//return 0.17 * calcVoltage - 0.1;
    
#ifdef DEBUG
  Serial.print("medianDust: ");
  Serial.println(medianDust, 3);
  Serial.print("stdevDust: ");
  Serial.println(stdevDust,3);
  Serial.print("avgDust: ");
  Serial.println(avgDust,3);
  Serial.print("dust ug: ");
  Serial.println(dustug,3);
#endif
  // copy those in the results
  avgRetDust = avgDust;
  medRetDust = medianDust;
  stdevRetDust = stdevDust;
  ugRetDust = dustug ;



}





