int car_y = 10;
int car_r_ped_g = 11;
int car_g_ped_r = 12;

int wait = 2000;

void setup() {                
  pinMode(car_r_ped_g, OUTPUT);     
  pinMode(car_y, OUTPUT);
  pinMode(car_g_ped_r, OUTPUT);
  digitalWrite(car_y, LOW);
  digitalWrite(car_g_ped_r, LOW);
  digitalWrite(car_r_ped_g, LOW);

}

int check = 0;
void loop() {
	if(check==0){ // Om pedestrian trycker på knappen
		digitalWrite(car_g_ped_r, HIGH); // Bilar har grönt, fotgängare har rött
		digitalWrite(car_r_ped_g, LOW);
		digitalWrite(car_y, LOW);
		delay(1000);
		digitalWrite(car_y, HIGH); // Gult ljus för bilar tänds i wait ms
		delay(wait);
		digitalWrite(car_y, LOW); // Gult ljus släcks
		digitalWrite(car_g_ped_r, LOW); // Grönt för bilar och rött för fotgängare släcks
		digitalWrite(car_r_ped_g, HIGH); // Rött för bilar och grönt för fotgängare tänds
		delay(wait);
		// Time for disco
		int i;
		for(i=0;i<6;i++){
			digitalWrite(car_r_ped_g, LOW);
			delay(300);
			digitalWrite(car_r_ped_g, HIGH);
			delay(300);
		}
		digitalWrite(car_r_ped_g, LOW);
		digitalWrite(car_y, HIGH);
		delay(wait*1.2);
		digitalWrite(car_y, LOW);
		digitalWrite(car_r_ped_g, LOW);
		check = 1;
	} else{
		digitalWrite(car_g_ped_r, HIGH);
	}

}    
