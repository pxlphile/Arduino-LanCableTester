// This code is based losely on the cable tester from VarieCose
// https://variecose.wordpress.com/2012/04/15/ethernet-lan-rj45-cable-tester-with-arduino/
#define VERBOSE
int straightMode[8] = {2, 3, 4, 5, 6, 7, 8, 9};
int crossOverMode[8] = {4, 7, 2, 5, 6, 3, 8, 9};

void setup() {
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(12, INPUT); // Detect switch for straigth or cross-over cable (high=straight, low=cross-over)
  pinMode(13, OUTPUT); // onboard control LED?

//#ifdef VERBOSE
  Serial.begin(9600);
//#endif
}

void logDebug(String logString) {
#ifdef VERBOSE
  Serial.println(logString);
#endif
}

void loop() {
  pulseStartSequence(straightMode);
  delay(500);

  logDebug("cable mode: straight");
  pulseEveryPin(straightMode);
}

void logDebug(int logInt) {
  logDebug(String(logInt, DEC));
}

void pulseStartSequence(int cablePinOut[]) {
  startPulseSequenceOnAllPins(cablePinOut, 200);
}

void startPulseSequenceOnAllPins(int cablePinOut[], int delayTimeInMillis) {
  digitalWrite(13, HIGH);
  
  for (int n = 0; n < 8; n++) {
    pulseOut(cablePinOut[n], delayTimeInMillis, 0);
  }

  // reverse direction: start at the second last for optical reasons
  for (int n = 6; n > -1; n--) {
    pulseOut(cablePinOut[n], delayTimeInMillis, 0);
  }

  digitalWrite(13, LOW);
}

void pulseEveryPin(int cablePinOut[]) {
  int noOffTime = 0;
  for (int n = 0; n < 8; n++) {
//    logDebug("Line ");
//    logDebug(cablePinOut[n]);

    int pinPulseDelayTimeInMs = 1000;
    pulseOut(cablePinOut[n], pinPulseDelayTimeInMs, noOffTime);

    int switchPulseDelayTimeInMs = 50;
    pulseOut(13, switchPulseDelayTimeInMs, noOffTime);
  }
}

void pulseOut(char pin, int ledActiveTimeInMillis, int ledDeactivateTimeInMillis) {
  digitalWrite(pin, HIGH);
  delay(ledActiveTimeInMillis);
  digitalWrite(pin, LOW);
  delay(ledDeactivateTimeInMillis);
}
