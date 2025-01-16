#include <Servo.h>
Servo moteur;

const int entreeBuzz = A0; // Pin analogique
const int OuverturePorte = 24;
const int SimuAppel = 22;

void setup() {
  moteur.attach(2);
  moteur.write(90);// position initiale du moteur
  pinMode(OuverturePorte, OUTPUT);
  digitalWrite(OuverturePorte, LOW);
  digitalWrite(SimuAppel, HIGH);

  Serial.begin(9600);
  delay(1000);
  Serial.println("Setup complet, prêt à démarrer !");
}

void loop() {

  int analogBuzz = analogRead(entreeBuzz); // Lecture de la valeur brute (0 à 1023)
  float tensionBuzz = analogBuzz * (5.0 / 1023.0);  // Conversion en tension (0V à 5V)

  /* communication de la tension par USB
  Serial.print("Tension mesurée : ");
  Serial.print(tensionBuzz);
  Serial.println(" V");
  */

  if (tensionBuzz > 2.0) {
    Serial.println("APPEEEEEEEEEEL !!!! FAUT OUVRIIIIIIIIIIR");
    delay(2000);
    
    moteur.write(120);// simulation de décrochage
    Serial.println("On décroche.");

    delay(5000);

    digitalWrite(OuverturePorte, HIGH);
    Serial.println("On ouvre la porte #normalement ya un relais qui se chauffe...");

    delay(1000);

    digitalWrite(OuverturePorte, LOW);
    Serial.println("on arrête d'ouvrir la porte");

    delay(2000);

    moteur.write(90);// position raccrochée
    Serial.println("on raccroche.");
    Serial.println("et on attend...");

    delay(10000);
    Serial.println("fini d'attendre");
  }

}


/* controle du servomoteur
  moteur.write(90);// move servos to center position -> 90°
  delay(500);
  moteur.write(30);// move servos to center position -> 60°
  delay(500);
*/