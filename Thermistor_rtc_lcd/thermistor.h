float Vin = 5.0;     // [V]        
float Rt = 10000;    // Resistor t [ohm]
float R0 = 10000;    // value of rct in T0 [ohm]
float T0 = 298.15;   // use T0 in Kelvin [K]
float Vout = 0.0;    // Vout in A0 
float Rout = 0.0;    // Rout in A0
// use the datasheet to get this data.
float T1 = 273.15;      // [K] in datasheet 0� C
float T2 = 373.15;      // [K] in datasheet 100� C
float RT1 = 35563;   // [ohms]  resistence in T1
float RT2 = 549;    // [ohms]   resistence in T2
float TempK = 0.0;   // variable output
float TempC = 0.0;   // variable output
float TempF = 0.0;
float beta = (log(RT1 / RT2)) / ((1 / T1) - (1 / T2));
float Rinf = R0 * exp(-beta / T0);

float readKelvin(int pin) {
	Vout = Vin * (float(analogRead(pin)) / 1024.0); // calc for ntc
	Rout = (Rt * Vout / (Vin - Vout));
	TempK = (beta / log(Rout / Rinf)); // calc for temperature
	return TempK;
}

float readFahrenheit(int pin) {
	Vout = Vin * (float(analogRead(pin)) / 1024.0); // calc for ntc
	Rout = (Rt * Vout / (Vin - Vout));
	TempK = (beta / log(Rout / Rinf)); // calc for temperature
	TempF = ((9 / 5) * (TempK - 273.15)) + 32;
	return TempF;
}

float readCelcius(int pin) {
	Vout = Vin * (float(analogRead(pin)) / 1024.0); // calc for ntc
	Rout = (Rt * Vout / (Vin - Vout));
	TempK = (beta / log(Rout / Rinf)); // calc for temperature
	TempC = TempK - 273.15;
	TempF = (TempC * 9 / 5) + 32;
	return TempC;
}

float readTemp(int pin) {
	Vout = Vin * (float(analogRead(pin)) / 1024.0); // calc for ntc
	Rout = (Rt * Vout / (Vin - Vout));
	TempK = (beta / log(Rout / Rinf)); // calc for temperature
	TempC = TempK - 273.15;
	TempF = (TempC * 9 / 5) + 32;
  float Temp[3] = {TempC, TempF, TempK};
	return Temp[3];
}
