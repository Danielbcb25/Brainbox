#include <LiquidCrystal_I2C.h>
#define Vermelho 8
#define Verde 10
#define Azul 9
#define BotaoVerd 3
#define BotaoVer 2
#define BotaoAzul 4
#define BotaoRoxo 5
#define num1 13
#define num2 12
#define num3 6
#define num4 11 
#define num5 7
#define ss A0
#define nn A1
LiquidCrystal_I2C lcd(0x27, 16, 2);
int modo = 0;
int uran = 0;
int a = 1;
int uni = 0;
int dez = 0;
int cent = 0;
int b = 0;
int n = 0;
int n2 = 0;
int n3 = 0;
int resultc = cent * 100 + dez * 10 + uni;
int resultd = dez * 10 + uni;
int fase = 1;
void setup() {
  pinMode(Vermelho, OUTPUT);
  pinMode(Verde, OUTPUT);
  pinMode(Azul, OUTPUT);
  pinMode(BotaoVer, INPUT);
  pinMode(BotaoVerd, INPUT);
  pinMode(BotaoAzul, INPUT);
  pinMode(BotaoRoxo, INPUT);
  pinMode(num1, INPUT);
  pinMode(num2, INPUT);
  pinMode(num3, INPUT);
  pinMode(num4, INPUT);
  pinMode(num5, INPUT);
  pinMode(ss, OUTPUT);
  pinMode(nn, OUTPUT);
  Serial.begin(9600);
  lcd.setCursor(0, 0);
  lcd.setBacklight(1);
  lcd.init();
  digitalWrite(ss, HIGH);
  digitalWrite(nn, HIGH);
}
void loop(){
  if (modo == 0){
  	lcd.print("BrainBox");
  	delay(500);
    lcd.setCursor(0, 0);
  	lcd.clear();
    lcd.print("Escolha um modo:");
    delay(500);
    lcd.clear();
    lcd.print("1- Acertar Cores");
    lcd.setCursor(0, 1);
    lcd.print("2- Numeros");
    delay(1000);
    lcd.setCursor(0 ,0);
    a = 1;
    while(a == 1) {
    	if(digitalRead(num1) == 1) {
          	lcd.clear();
   			lcd.print("Acertar Cores!!");
    		delay(500);
    		lcd.clear();
        	Serial.print("ac");
          	modo = 1;
          	a = 0;
  		}
  		else if (digitalRead(num2) == 1){
          	lcd.clear();
			lcd.print("Numeros");
    		delay(500);
    		lcd.clear();
          	Serial.print("n");
          	modo = 2;
          	a = 0;
    	}
    }
	}
	if (modo == 1) {
  			lcd.clear();
  			srand(analogRead(A3));
  			int ran = random(1, 5);
  		if (uran == ran){
  			ran = 5;
  		}
  		else if(ran != uran) {
  			uran = ran;
  		}
  		Serial.println(ran);
  			if (ran == 1){
  				digitalWrite(Vermelho, HIGH);
    			while(digitalRead(BotaoVerd) == 0 && digitalRead(BotaoVer) == 0 &&
    		  		digitalRead(BotaoAzul) == 0 && digitalRead(BotaoRoxo) == 0){
    	 	  		delay(1);
    				}
    		if(digitalRead(BotaoVer) == 1) {
              	digitalWrite(ss, LOW);
				lcd.print("Acertou! :)");
              	delay(500);
                digitalWrite(ss, HIGH);
    		}
    		else {
              	digitalWrite(nn, LOW);
   		 	    lcd.print("Errou :C");
              	delay(500);
              	digitalWrite(nn, HIGH);
    		}
  		}	
  		if (ran == 2){
  			digitalWrite(Verde, HIGH);
    		while(digitalRead(BotaoVerd) ==  0 && digitalRead(BotaoVer) == 0 && digitalRead(BotaoAzul) == 0 && digitalRead(BotaoRoxo) == 0){
    		  delay(1);
    		}
    		if(digitalRead(BotaoVerd) == 1) {
              	digitalWrite(ss, LOW);
  				lcd.print("Acertou! :)");
              	delay(500);
              	digitalWrite(ss, HIGH);
    		}
    		else{
              	digitalWrite(nn, LOW);
  				lcd.print("Errou :C");
              	delay(500);
              	digitalWrite(nn, HIGH);
    		}
  		}	
  		if (ran == 3){
			digitalWrite(Azul, HIGH);
		    while(digitalRead(BotaoVerd) == 0 && digitalRead(BotaoVer) == 0 && digitalRead(BotaoAzul) == 0 && digitalRead(BotaoRoxo) == 0){
		      	delay(1);
		    }
		    if(digitalRead(BotaoAzul) == 1) {
		    	digitalWrite(ss, LOW);
  				lcd.print("Acertou! :)");
              	delay(500);
              	digitalWrite(ss, HIGH);
		    }
		    else{
		      	digitalWrite(nn, LOW);
  				lcd.print("Errou :C");
              	delay(500);
              	digitalWrite(nn, HIGH);
		    	}
		  }
		  if (ran == 4){
		  	digitalWrite(Verde, HIGH);
		   	digitalWrite(Vermelho, HIGH);
		   	while(digitalRead(BotaoVerd) == 0 && digitalRead(BotaoVer) == 0 && digitalRead(BotaoAzul) == 0 && digitalRead(BotaoRoxo) == 0){
		   	  	delay(1);
		    }
		    if(digitalRead(BotaoRoxo) == 1) {
		    	digitalWrite(ss, LOW);
  				lcd.print("Acertou! :)");
              	delay(500);
              	digitalWrite(ss, HIGH);
		   	}
		    else{
		   		digitalWrite(nn, LOW);
  				lcd.print("Errou :C");
              	delay(500);
              	digitalWrite(nn, HIGH);
		    }
		  	
  		}
  		digitalWrite(Azul, LOW);
  		digitalWrite(Verde, LOW);
  		digitalWrite(Vermelho, LOW);
  		delay(2000);
      	lcd.clear();
    }
  if(modo == 2) {
  	lcd.clear();
    srand(analogRead(A3));
    uni = random(1, 6);
    srand(analogRead(A4));
    dez = random(1, 6);
    srand(analogRead(A5));
    cent = random(1, 6);
    b = 0;
    n = 0;
    resultc = cent * 100 + dez * 10 + uni;
    resultd = dez * 10 + uni;
    fase = 1;
    if (fase == 1) {
    	lcd.print(uni);
      	b = 0;
        n = 0;
    	while (b == 0) {
    		if(digitalRead(num1) == 1) {
        		n = 1;
        	 	b = 1;
        	}
        	else if (digitalRead(num2) == 1) {
        		n = 2;
        	  	b = 1;
        	}	
      		else if (digitalRead(num3) == 1) {
      			n = 3;
        	  	b = 1;
        	}
     		else if (digitalRead(num4) == 1) {
        		n = 4;
        	  	b = 1;
        	}
      		else if (digitalRead(num5) == 1) {
        		n = 5;
        	  	b = 1;
        	}
    	}
    	if(n == uni){
    	  	lcd.clear();
    		lcd.print("Acertou! :)");
    	  	digitalWrite(ss, LOW);
    	  	delay(500);
    	  	digitalWrite(ss, HIGH);
    	  	lcd.clear();
          	fase = 2;
    	}
    	else {
    	  	lcd.clear();
    	  	digitalWrite(nn, LOW);
    		lcd.print("Errou :(");
    	    lcd.setCursor(0, 1);
    	    lcd.print("Tente Novamente:");
    	    lcd.setCursor(0, 0);
    	  	delay(500);
    	  	digitalWrite(nn, HIGH);
    	  	lcd.clear();
            fase = 1;
    	}
    }
    if(fase == 2) {
    	lcd.print(resultd);
      	b = 0;
        n = 0;
    	while (b == 0) {
    		if(digitalRead(num1) == 1) {
        		n = 1;
        	 	b = 1;
        	}
        	else if (digitalRead(num2) == 1) {
        		n = 2;
        	  	b = 1;
        	}	
      		else if (digitalRead(num3) == 1) {
      			n = 3;
        	  	b = 1;
        	}
     		else if (digitalRead(num4) == 1) {
        		n = 4;
        	  	b = 1;
        	}
      		else if (digitalRead(num5) == 1) {
        		n = 5;
        	  	b = 1;
        	}
    	}
      	delay(500);
      	b = 0;
        n2 = 0;
    	while (b == 0) {
    		if(digitalRead(num1) == 1) {
        		n2 = 1;
        	 	b = 1;
        	}
        	else if (digitalRead(num2) == 1) {
        		n2 = 2;
        	  	b = 1;
        	}	
      		else if (digitalRead(num3) == 1) {
      			n2 = 3;
        	  	b = 1;
        	}
     		else if (digitalRead(num4) == 1) {
        		n2 = 4;
        	  	b = 1;
        	}
      		else if (digitalRead(num5) == 1) {
        		n2 = 5;
        	  	b = 1;
        	}
    	}
      	if(n * 10 + n2 == resultd) {
          	Serial.println(n * 10 + n2);
    	  	lcd.clear();
    		lcd.print("Acertou! :)");
    	  	digitalWrite(ss, LOW);
    	  	delay(500);
    	  	digitalWrite(ss, HIGH);
    	  	lcd.clear();
          	fase = 3;
    	}
    	else {
    	  	lcd.clear();
    	  	digitalWrite(nn, LOW);
    		lcd.print("Errou :(");
    	    lcd.setCursor(0, 1);
    	    lcd.print("Tente Novamente:");
    	    lcd.setCursor(0, 0);
    	  	delay(500);
    	  	digitalWrite(nn, HIGH);
    	  	lcd.clear();
            fase = 1;
    }
      if(fase == 3) {
    	lcd.print(resultc);
      	b = 0;
        n = 0;
        n2 = 0;
    	while (b == 0) {
    		if(digitalRead(num1) == 1) {
        		n = 1;
        	 	b = 1;
        	}
        	else if (digitalRead(num2) == 1) {
        		n = 2;
        	  	b = 1;
        	}	
      		else if (digitalRead(num3) == 1) {
      			n = 3;
        	  	b = 1;
        	}
     		else if (digitalRead(num4) == 1) {
        		n = 4;
        	  	b = 1;
        	}
      		else if (digitalRead(num5) == 1) {
        		n = 5;
        	  	b = 1;
        	}
    	}
      	delay(500);
      	b = 0;
        n2 = 0;
    	while (b == 0) {
    		if(digitalRead(num1) == 1) {
        		n2 = 1;
        	 	b = 1;
        	}
        	else if (digitalRead(num2) == 1) {
        		n2 = 2;
        	  	b = 1;
        	}	
      		else if (digitalRead(num3) == 1) {
      			n2 = 3;
        	  	b = 1;
        	}
     		else if (digitalRead(num4) == 1) {
        		n2 = 4;
        	  	b = 1;
        	}
      		else if (digitalRead(num5) == 1) {
        		n2 = 5;
        	  	b = 1;
        	}
    	}
			delay(500);
      	b = 0;
		n3 = 0;
		while (b == 0) {
    		if(digitalRead(num1) == 1) {
        		n3 = 1;
        	 	b = 1;
        	}
        	else if (digitalRead(num2) == 1) {
        		n3 = 2;
        	  	b = 1;
        	}	
      		else if (digitalRead(num3) == 1) {
      			n3 = 3;
        	  	b = 1;
        	}
     		else if (digitalRead(num4) == 1) {
        		n3 = 4;
        	  	b = 1;
        	}
      		else if (digitalRead(num5) == 1) {
        		n3 = 5;
        	  	b = 1;
        	}
    	}
      	if(n * 100 + n2 * 10 + n3 == resultc) {
			Serial.println(resultc);
          	Serial.println(n * 100 + n2 * 10 + n3);
    	  	lcd.clear();
    		lcd.print("Acertou! :)");
    	  	digitalWrite(ss, LOW);
    	  	delay(500);
    	  	digitalWrite(ss, HIGH);
    	  	lcd.clear();
          	fase = 4;
    	}
    	else {
    	  	lcd.clear();
          Serial.println(n * 100 + n2 * 10 + n3);
			Serial.println(resultc);
    	  	digitalWrite(nn, LOW);
    		lcd.print("Errou :(");
    	    lcd.setCursor(0, 1);
    	    lcd.print("Tente Novamente:");
    	    lcd.setCursor(0, 0);
    	  	delay(500);
    	  	digitalWrite(nn, HIGH);
    	  	lcd.clear();
            fase = 1;
    }
  }
    if(fase == 4) { 
    	lcd.print("Parabens,");
      	lcd.setCursor(0, 1);
        lcd.print("Voce ganhou!!");
      	delay(2000);
      	lcd.clear();
        modo = 0; 
    }
  }
    }
  }
  
