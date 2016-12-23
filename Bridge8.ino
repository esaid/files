
/*
  Arduino Yun Monitoring
03/11/2016
example curl command :
 curl "http://arduino1.cern.ch/arduino/analog/0"  Pin A0 reads analog 3.30  Tension :  3.30
 curl "http://arduino1.cern.ch/arduino/analog/1"  Pin A1 reads analog 0.19  Tension :  0.38
 curl "http://arduino1.cern.ch/arduino/analog/2"  Pin A2 reads analog 0.00  Tension :  0.00
 curl "http://arduino1.cern.ch/arduino/analog/3"  Pin A3 reads analog 2.51  Tension :  5.02
 curl "http://arduino1.cern.ch/arduino/analog/4"  Pin A4 reads analog 2.64  Tension :  15.02
 curl "http://arduino1.cern.ch/arduino/analog/5"  Pin A5 reads analog 3.23  Tension :  -15.16
 curl "http://arduino1.cern.ch/arduino/analog/6"  Pin A6 reads analog 0.00  Tension :  0.00
 curl "http://arduino1.cern.ch/arduino/temperature"  Temperature est 29.00
 curl "http://arduino1.cern.ch/arduino/dust"   Dust microg/m^3 :  48.39
 curl "http://arduino1.cern.ch/arduino/write_code/100/code-carte-09867"    exemple ecriture code carte (string 50 caracteres max) a l'@dresse  100 DEC
 curl "http://arduino1.cern.ch/arduino/write_version/150/1.6"    exemple ecriture version Firmware dans Micro (string 50 caracteres max) a l'@dresse  150 DEC
 curl "http://arduino1.cern.ch/arduino/read_code/100"  lecture code carte a l'@dresse 100 DEC
 curl "http://arduino1.cern.ch/arduino/read_version/150"  lecture version Firmware  a l'@dresse 150 DEC
 -----------------------------------------------------------------------------------------------------
 snmp command  -->   localhost or hostname
 "hostname_" : snmpget -v 2c -c public localhost iso.3.6.1.4.1.36582.1.1.1.1.101.1       "arduino2"
 "partNo__" :  snmpget -v 2c -c public localhost iso.3.6.1.4.1.36582.1.1.1.2.101.1       "A00008" 
 "serialNo__" : snmpget -v 2c -c public localhost iso.3.6.1.4.1.36582.1.1.1.3.101.1      "code_lhc"
 "firmware__" : snmpget -v 2c -c public localhost iso.3.6.1.4.1.36582.1.1.1.4.101.1      "1.6"
 "macAdressEth1__" : snmpget -v 2c -c public localhost  iso.3.6.1.4.1.36582.1.1.1.5.101.1    "b4:21:8a:f8:30:be"
 "macAdressWlan0__" : snmpget -v 2c -c public localhost iso.3.6.1.4.1.36582.1.1.1.6.101.1  "b4:21:8a:f0:30:be"
 "softwareVersion__" :snmpget -v 2c -c public localhost iso.3.6.1.4.1.36582.1.1.1.7.101.1 "#1 Thu Jun 2 12:28:33 CEST 2016"
 "tempName__" : snmpget -v 2c -c public localhost iso.3.6.1.4.1.36582.1.1.2.1.101.1      "temperature"
 "tempValue__" : snmpget -v 2c -c public localhost  iso.3.6.1.4.1.36582.1.1.2.2.101.1    "29.94"
 "VoltageName__" : snmpget -v 2c -c public localhost  iso.3.6.1.4.1.36582.1.1.3.1.101.1  "voltage_0"
 "VoltageValue__" : snmpget -v 2c -c public localhost iso.3.6.1.4.1.36582.1.1.3.2.101.1  "3.30"
 "VoltageName__" : snmpget -v 2c -c public localhost iso.3.6.1.4.1.36582.1.1.3.3.101.1   "voltage_1"
 "VoltageValue__" : snmpget -v 2c -c public localhost iso.3.6.1.4.1.36582.1.1.3.4.101.1  "5.15"
 "VoltageName__" : snmpget -v 2c -c public localhost iso.3.6.1.4.1.36582.1.1.3.5.101.1   "voltage_2"
 "VoltageValue__" : snmpget -v 2c -c public localhost iso.3.6.1.4.1.36582.1.1.3.6.101.1  "12.17" 
 "VoltageName__" : snmpget -v 2c -c public localhost iso.3.6.1.4.1.36582.1.1.3.7.101.1   "voltage_3"
 "VoltageValue__" : snmpget -v 2c -c public localhost iso.3.6.1.4.1.36582.1.1.3.8.101.1  "5.15"
 "VoltageName__" : snmpget -v 2c -c public localhost iso.3.6.1.4.1.36582.1.1.3.9.101.1   "voltage_4"
 "VoltageValue__" : snmpget -v 2c -c public localhost iso.3.6.1.4.1.36582.1.1.3.10.101.1 "0.25"
 "VoltageName__" :  snmpget -v 2c -c public localhost iso.3.6.1.4.1.36582.1.1.3.11.101.1 "voltage_5"
 "VoltageValue__" : snmpget -v 2c -c public localhost iso.3.6.1.4.1.36582.1.1.3.12.101.1 "-2.15"
 "dustName__" : snmpget -v 2c -c public localhost iso.3.6.1.4.1.36582.1.1.4.1.101.1      "dust" 
 "dustValue__" : snmpget -v 2c -c public localhost iso.3.6.1.4.1.36582.1.1.4.2.101.1     "40.3"

 snmpwalk -v 2c -c public localhost 1.3.6.1.4.1.36582.1.1
-----------------------------------------------------------------------------------------------------
Dust 
PM2.5 density value (Î¼g/m3)  Air quality index    Air quality level     Air quality evaluation
0-35                             0-50                Level 1               Excellent
35-75                            51-100              Level 2               Average
75-115                          101-150              Level 3               Light pollution
115-150                         151-200              Level 4               Moderate pollution
150-250                         201-300              Level 5               Heavy pollution
250-500                           â‰¥300               Level 6              Serious pollution
-----------------------------------------------------------------------------------------------------
// Include the libraries we need
<SharpDust.h>  cern.ch\dfs\Users\e\esaid\Documents\Arduino\libraries\sharp_dust_gp2y1010au-master
<OneWire.h>  cern.ch\dfs\Users\e\esaid\Documents\Arduino\libraries\OneWire
<DallasTemperature.h> cern.ch\dfs\Users\e\esaid\Documents\Arduino\libraries\Arduino-Temperature-Control-Library-master
 */

// Include the libraries we need

#include <SharpDust.h>  
#include <OneWire.h>
#include <DallasTemperature.h>
#include <BridgeServer.h>
#include <BridgeClient.h>
#include <Process.h>
#include <FileIO.h>
#include <EEPROM.h>

#define ONE_WIRE_BUS 10  // Data wire is plugged into port 10 on the Arduino
#define DUST_LED_PIN    2  // dust sensor is plugged into pin 2 , 6
#define DUST_MEASURE_PIN  6
#define Range 3.30
#define led9 9  //led up
#define led11 11 //led middle
#define led12 12 //led down
#define adressEEPROM_code 100  // @ serial number card
#define adressEEPROM_version 150   // @ Firmware version code MCU
#define version 1.7  // Firmware version

// time to save datas to files 
const unsigned long Maj_interval = 30000; // 30 s
unsigned long previousMillis = 0;

// Setup a oneWire instance to communicate with any OneWire devices (not just Maxim/Dallas temperature ICs)
OneWire oneWire(ONE_WIRE_BUS);
// Pass our oneWire reference to Dallas Temperature.
DallasTemperature sensors(&oneWire);

// Listen to the default port 5555, the Yun webserver
// will forward there all the HTTP requests you send
BridgeServer server;

void init_pin () {
  analogReference(EXTERNAL);  // 3.3v reference diode
  pinMode(13, OUTPUT);
  pinMode(led12, OUTPUT);  
  pinMode(led11, OUTPUT); 
  pinMode(led9, OUTPUT); 
  digitalWrite(13, LOW);
  digitalWrite(led9, LOW);
  digitalWrite(led11, LOW);
  digitalWrite(led12, LOW);
}

void setup() {
  // Bridge startup
  Bridge.begin();
  Serial.begin(115200) ;
  delay(100) ;
  // initialisation Leds
  init_pin() ;
  // Start up the library ds1822 temperature
  sensors.begin();
  delay(100) ;
  // Start up the library Dust
  SharpDust.begin(DUST_LED_PIN, DUST_MEASURE_PIN , Range );
  delay(100) ;
  // Listen for incoming connection only from localhost
  server.listenOnLocalhost();
  server.begin();
  delay(1000) ;
  // Setup File IO 
  FileSystem.begin();
  // Upload script used
  Serial.println("creation du Fichier d'initialisation");
  createFile();
  delay(1000) ;
  Serial.println("initialisation : des donnees dans les fichiers data");
  init_script();
  delay(100) ;
}

void loop() 
{
  // store value millis
  unsigned long currentMillis = millis();
  String message = "" ;
  // Get clients coming from server
  BridgeClient client = server.accept();
  // There is a new client?
  if (client) 
  {
    // Process request
    process(client);
    // Close connection and free resources.
    client.stop();
  }
  auto_detect_chassis();
  // check time to update datas 
  if(currentMillis - previousMillis >= Maj_interval) 
  {
    previousMillis = currentMillis;
    // update datas
	message = acquisition() ;
    updatedata(message);
	delay(100) ;
  }
 

  delay(500); // Poll every 500ms



}

float mesure_tension (int pin) {
  
  analogReference(EXTERNAL);
  double vcc = 3.30 ;
  // coeffA0 = 1 ;
  // coeffA1  = 0.5 ;  // 100/(100+100)   mesure +5v chassis timing
  // coeffA2 = 0.12804 ; // 10/(68.1+10)   mesure +12v chassis timing
  // coeffA3 = 0.5 ; // 100/(100+100)     mesure +5v chassis Gdac
  // coeffA4 = 0.17543  ; // 100/(470+100)  mesure +15v chassis Gdac
  // coeffA5 = 0.21276 ; // 10/47         mesure -15v chassis Gdac
  double coeff[] = {1, 0.5, 0.12804, 0.5, 0.17543, -0.21276} ;
  // Read analog pin
  int sensorValue = analogRead(pin);
  delay (10) ;
  float val = fmap2(sensorValue, 0, 1023, 0.0, vcc);
  float tension = val / coeff[pin] ;
  return tension ;
}

void auto_detect_chassis() {

  // chassis GDAC : A3=5v , A4 = 15v, A5= -15v
  // chassis Timing type PS (ancien) :  A1 = 5v , A2 = 24v
  // chassis Timing type LHC  :  A1 = 5v, et A3 = 5v , A2 =12v
  // 
  float mesure_array[6];
  for (size_t  i = 1; i < 6 ; i++)
  {
   mesure_array[i] = mesure_tension(i);
   delay(50);
  }
  bool flagCrate = false ;
  int LED12 = 0 ;
  int LED11 = 0 ;
  int LED9 = 0 ;
  // GDAC 
  // mesure A4 , 15v ?
  LED11 = compri(mesure_array[4] , 15, 5 , led11 ) ;
  // mesure A5 , -15v ?
  LED12 = compri(-mesure_array[5] , 15, 5 , led12);
  // mesure A3 , 5v ?
  LED9 = compri(mesure_array[3] , 5, 5 , led9 ) ;
  flagCrate = LED11 and LED12 and LED9 ; // chassis Gdac ?
  
  if (flagCrate == false)
  {
	// chassis Timing type PS
	// mesure A1 , 5v ?
	  LED9 = LED9 or compri(mesure_array[1], 5, 5 , led9);
	// mesure A2 , 24v ?
	  LED11 = LED11 or compri(mesure_array[2], 24, 5 , led11);
	  flagCrate = LED9 and LED11  ;  // chassis PS ?
    
  }

  if (flagCrate == false)
  {
	 // chassis Timing type LHC
   // mesure A1 , 5v ?
	 LED9 = LED9 or compri(mesure_array[1], 5, 5 , led9);
   // mesure A3 , 5v ?
	 LED9 = LED9 or compri(mesure_array[3], 5, 5 , led9);
   // mesure A2 , 12v ?
	 LED11 = LED11 or compri(mesure_array[2], 12, 5 , led11);
	 flagCrate = LED9 and LED11 ;  // chassis LHC ?
   
  }
  // allume les LEDS si la tension est ok
  digitalWrite(led12, LED12);
  digitalWrite(led11, LED11 );
  digitalWrite(led9, LED9 );
}

void process(BridgeClient client) {
	int pin ;
	// read the command
	String command = client.readStringUntil('/');
	command.trim();
	if (command == "dust") {  printClient(client, "Dust value", String(readDust()) ); }
	if (command == "temperature") { printClient(client, "Temperature value", String(readTemperature()) ); }
	if (command == "write_code" or command == "write_version")
	{
		int addr = client.parseInt(); //@dresse
		if (client.read() == '/')
		{
			writeEeprom(addr, client.readString()); // value
		}
	}
	if (command == "read_code" or command == "read_version"  ) { printClient(client, " value", String( readEeprom(client.parseInt()) ) ); }
	if (command == "analog") { pin = client.parseInt();  printClient(client, String(pin), ""); printClient(client, "Analog value", String(mesure_tension(pin)) ); }
}

void printClient (BridgeClient client , String data , String val) 
{
	client.print(data + " : ");
	client.print(val);
	client.println("");
}


String readEeprom(int Addr)
{
  char customVar[50];
  return EEPROM.get(Addr,customVar);
}

void writeEeprom(int addr , String valeur)
{
  char customVar[50];
  // hostname/arduino/write_code/@dresse/code
  // hostname/arduino/write_version/@dresse/version
  
  valeur.toCharArray(customVar, 50);
  EEPROM.put(addr, customVar);
  
}



float readTemperature() 
{
  sensors.requestTemperatures(); // Send the command to get temperatures
  delay(100) ;
  return sensors.getTempCByIndex(0);
}

float readDust() {
  return SharpDust.measure();
}

void createFile() {
  // Write Files  in /tmp
  // Using /tmp stores the script in RAM this way we can preserve
  // the limited amount of FLASH erase/write cycles
  File script = FileSystem.open("/tmp/script.sh", FILE_WRITE);

  script.print("#!/bin/ash\n");
  script.print("cd /tmp\n") ;
  script.print("if [ $11 = 'init' ] ;\n");
  script.print("then\n");
  script.print("rm U0 U1 U2 U3 U4 U5 temperature dust code version\n");
  script.print("touch U0 U1 U2 U3 U4 U5 temperature dust code version\n");
  script.print("echo 0 >> U0\n");
  script.print("echo 0 >> U1\n");
  script.print("echo 0 >> U2\n");
  script.print("echo 0 >> U3\n");
  script.print("echo 0 >> U4\n");
  script.print("echo 0 >> U5\n");
  script.print("echo 0 >> temperature\n");
  script.print("echo 0 >> dust\n");
  script.print("echo $9 >> code\n");
  script.print("echo $10 >> version\n");
  script.print("else\n");
  script.print("sed -i 1s/.*/$1/ U0\n");
  script.print("sed -i 1s/.*/$2/ U1\n");
  script.print("sed -i 1s/.*/$3/ U2\n");
  script.print("sed -i 1s/.*/$4/ U3\n");
  script.print("sed -i 1s/.*/$5/ U4\n");
  script.print("sed -i 1s/.*/$6/ U5\n");
  script.print("sed -i 1s/.*/$7/ temperature\n");
  script.print("sed -i 1s/.*/$8/ dust\n");
  script.print("fi\n");
  
  script.close();  // close the file
  // Instantiate a Process to make the script executable.
  Process chmod;
  chmod.begin("chmod");      // chmod: change mode
  chmod.addParameter("+x");  // x stays for executable
  chmod.addParameter("/tmp/script.sh");
  chmod.run();
  chmod.close();
}

void init_script()
{   
 // read code board at @dress 100
  String codeboard = readEeprom(adressEEPROM_code);
  codeboard.trim();
  delay(500);
  //String Version = readEeprom(adressEEPROM_version);
  //Version.trim();
  //delay(500);
  String Version = String(version) ;
  writeEeprom(adressEEPROM_version, Version);
  delay(500);
  String s = "/tmp/script.sh 0 0 0 0 0 0 0 0 " + codeboard + " " +  Version + " init" ; 
  Serial.println(s);
  Process pInit;
  pInit.runShellCommand(s);
  pInit.close();

}



void updatedata(String message) 
{
  // Run the script
  String parametre;
  //message = "0 1 2 3 4 5 6 7 8  none" ;
  parametre = "/tmp/script.sh " + message  +  " none none none" ;
  
  Serial.print("parametre : ");
  Serial.println(parametre);
  Process pUpdate;
  pUpdate.runShellCommand(parametre);
  
  pUpdate.close();
  Serial.println("updateData ") ;
}


String acquisition()
{
  String resultat = "" ;
  //mesure tensions U0....U5
  for (int i = 0; i <= 5; i++)
  {
	 resultat = resultat + String(mesure_tension (i)) + " " ;
  }
  resultat = resultat + readTemperature() + " " ;
  resultat = resultat +  readDust() + " " ;
  return resultat ;
}


float fmap2(float x, float in_min, float in_max, float out_min, float out_max)
{
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}


void blinkAlert (int Led)
{
  for (int i= 0 ; i<5 ; i++)
  {
    // blink Led
    digitalWrite(Led , HIGH);
    delay (50) ;
    digitalWrite(Led , LOW);
    delay (100) ;
  }
}  

int compri(float x, float reference, float pourcentage, int Led )
{
  // si valeur est dans la tolerance alors retourne 1 sinon retourne 0
  double valeur_min = reference - ((reference * pourcentage) / 100) ;
  double valeur_max = reference + ((reference * pourcentage) / 100) ;
  if ( (x > valeur_min) && (x <= valeur_max) )
  {
    return 1 ;
  }
  else
  {
    if (x > valeur_max)
    { 
    blinkAlert(Led);
    }
  return 0;
 }
}

