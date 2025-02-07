//définir la broche de la DEL
const int LED = 13;
//définir l'état de la DEL
bool ledState = LOW;

const int All_Eteint = 2000;
int appState = 0;
static int counter = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(LED, OUTPUT);
  Serial.begin(9600);
}

void allumer() {
  ledState = !ledState;
  digitalWrite(LED, ledState);
  delay(All_Eteint);
  Serial.println("Allume – 2412876");
  ledState = !ledState;
  digitalWrite(LED, ledState);
  appState = 1;
}

void clignotement() {
  if (appState == 1) {
    if (counter == 0) {
      Serial.println("Clignotement-2412876");
    }
    while (counter <= 10) {
      ledState = !ledState;
      digitalWrite(LED, ledState);
      delay(250);
      counter++;
    }
  };
  counter = 0;
  appState = 2;
}

void variation() {
  if (appState == 2) {
    Serial.println("Variation-2412876");
    for (int fadeValue = 0; fadeValue <= 255; fadeValue += 8) {

      analogWrite(LED, fadeValue);

      delay(64);
    }
  };
  appState = 3;
}

void eteint() {
  if (appState == 3) {
    Serial.println("Eteint-2412876");
    digitalWrite(LED, ledState);
    delay(All_Eteint);
  };
  appState = 0;
}


void loop() {
  // put your main code here, to run repeatedly:
  allumer();
  clignotement();
  variation();
  eteint();
}
