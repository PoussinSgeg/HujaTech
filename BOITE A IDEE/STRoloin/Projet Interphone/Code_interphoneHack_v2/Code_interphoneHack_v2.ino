#include <Servo.h>
Servo moteur;

const int entreeBuzz = 5;
const int ResetSonnerie = 4;
const int SafeSonnerie = 10;
const int LedDecroche = 3;
const int OuverturePorte = 13;

void setup() {
  moteur.attach(6);
  moteur.write(35);// position initiale du moteur

  pinMode(entreeBuzz, INPUT);

  pinMode(ResetSonnerie, OUTPUT);
  digitalWrite(ResetSonnerie, HIGH);
  delay(500);
  digitalWrite(ResetSonnerie, LOW);

  pinMode(SafeSonnerie, OUTPUT);
  digitalWrite(SafeSonnerie, LOW);

  pinMode(LedDecroche, OUTPUT);
  digitalWrite(SafeSonnerie, LOW);

  pinMode(OuverturePorte, OUTPUT);
  digitalWrite(OuverturePorte, LOW);

  Serial.begin(9600);
  delay(1000);

  Serial.println("Setup complet, prêt à démarrer !");
}

void loop() {

  int SonnerieState = digitalRead(entreeBuzz);

  if (SonnerieState == HIGH) {
    Serial.println("APPEEEEEEEEEEL !!!! FAUT OUVRIIIIIIIIIIR");
    digitalWrite(SafeSonnerie, HIGH);
    delay(2000);
    
    moteur.write(150);// simulation de décrochage
    digitalWrite(LedDecroche, HIGH);
    Serial.println("On décroche.");

    delay(3000);

    digitalWrite(OuverturePorte, HIGH);
    Serial.println("On ouvre la porte");

    delay(1500);

    digitalWrite(OuverturePorte, LOW);
    Serial.println("on arrête d'ouvrir la porte");

    delay(2000);

    moteur.write(35);// position raccrochée
    digitalWrite(LedDecroche, LOW);
    Serial.println("on raccroche.");

    delay(1000);

    digitalWrite(SafeSonnerie, LOW);
    digitalWrite(ResetSonnerie, HIGH);
    delay(500);
    digitalWrite(ResetSonnerie, LOW);

    delay(1000);
    Serial.println("En roue libre à nouveau");
  }

}