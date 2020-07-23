#define DELAYbwDIGITS 1
#define DELAYbwTWOnos 10000

float Vin=5.0;     // [V]        
float Rt=10000;    // Resistor t [ohm]
float R0=10000;    // value of rct in T0 [ohm]
float T0=298.15;   // use T0 in Kelvin [K]
float Vout1=0.0;    // Vout in A0 
float Rout1=0.0;    // Rout in A0
float Vout2=0.0; 
float Rout2=0.0;
// use the datasheet to get this data.
float T1=273.15;      // [K] in datasheet 0º C
float T2=373.15;      // [K] in datasheet 100° C
float RT1=35563;   // [ohms]  resistence in T1
float RT2=549;    // [ohms]   resistence in T2
float beta=0.0;    // initial parameters [K]
float Rinf=0.0;    // initial parameters [ohm]   
float TempK1=0.0;   // variable output
float TempC1=0.0;   // variable output
float TempK2=0.0;
float TempC2=0.0;
void setup() {
  //Serial.begin(9600);
  beta=(log(RT1/RT2))/((1/T1)-(1/T2));
  Rinf=R0*exp(-beta/T0);
  //ssd
  for(int i = 2; i<= 13; i++) {
    pinMode(i, OUTPUT);
  }                         //D1-D4:2-5; a-g,dp: 6-13
}

/*abcdefg
  1111110 = 0
  0110000 = 1
  1101101 = 2
  1111001 = 3
  0110011 = 4
  1011011 = 5
  1011111 = 6
  1110000 = 7
  1111111 = 8
  1111011 = 9
*/

int displaytable[10][7] = {
  {1, 1, 1, 1, 1, 1, 0},  //0
  {0, 1, 1, 0, 0, 0, 0},  //1
  {1, 1, 0, 1, 1, 0, 1},  //2
  {1, 1, 1, 1, 0, 0, 1},  //3
  {0, 1, 1, 0, 0, 1, 1},  //4
  {1, 0, 1, 1, 0, 1, 1},  //5
  {1, 0, 1, 1, 1, 1, 1},  //6
  {1, 1, 1, 0, 0, 0, 0},  //7
  {1, 1, 1, 1, 1, 1, 1},  //8
  {1, 1, 1, 1, 0, 1, 1}   //9  
};

void printdigit(int place, int digit, int decimal = 0) {
  digitalWrite(place+1, HIGH);
  for(int i = 6; i <= 12; i++) {
    digitalWrite(i, displaytable[digit][i-6]);
  }
  digitalWrite(13, decimal);
  delay(DELAYbwDIGITS);
  //digitalWrite(place+1, LOW);
  for(int i = 2; i <= 13; i++) {
    digitalWrite(i, LOW);
  }
}

void show(int num, int decplace = 0) {
  long a = millis();
  while(millis() - a <= DELAYbwTWOnos) {
      for(int i = 1; i <= 4; ++i) {
        if(int(num/pow(10,(4-i))) != 0) {
          if(i != decplace) {
            printdigit(i, ((num/pow(10,(4-i))) - (10*int(num/pow(10,(5-i))))));
          }
          if(i == decplace) {
            printdigit(i, ((num/pow(10,(4-i))) - (10*int(num/pow(10,(5-i))))), 1);
          }
        }
      }
    
  }
}

void loop()
{//thermistor
  Vout1=Vin*(float(analogRead(A6))/1024.0); // calc for ntc
  Rout1=(Rt*Vout1/(Vin-Vout1));
  Vout2=Vin*(float(analogRead(A7))/1024.0); // calc for ntc
  Rout2=(Rt*Vout2/(Vin-Vout2));
  
  TempK1=(beta/log(Rout1/Rinf)); // calc for temperature
  TempC1=TempK1-273.15;
  TempK2=(beta/log(Rout2/Rinf));
  TempC2=TempK2-273.15; 
  //ssd
  float TempC = (TempC1+TempC2)/2;
  show(TempC*100, 1, 2);
}
