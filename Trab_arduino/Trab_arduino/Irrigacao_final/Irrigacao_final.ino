#define rele 3
#define sensor 2

bool soloSeco = false;
unsigned long tempoAtual = 0;
unsigned long tempoAnterior = 0;
const unsigned long intervalo = 10000;
const unsigned long duracao = 2000;

void setup() 
{
  Serial.begin(9600);
  pinMode(rele, OUTPUT);
  pinMode(sensor, INPUT);
  digitalWrite(rele, HIGH);
}

void loop() {
  tempoAtual = millis();
  soloSeco = digitalRead(sensor);
  
  if (soloSeco && (tempoAtual - tempoAnterior >= intervalo)) {
    tempoAnterior = tempoAtual;
    digitalWrite(rele, LOW);
    Serial.println("Bomba acionada");
    delay(duracao);
    digitalWrite(rele, HIGH);
  }

  delay(500);
}
