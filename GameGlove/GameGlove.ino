//Digital Connections
const int buzzer = 9;

//Analogue Connections
const int joyX = 0;
const int joyY = 1;
const int joySwitch = 2;

const int matrixD = 4; // Not Used, but reference for Matrix Library
const int matrixC = 5; // Not Used, but reference for Matrix Library

// Game Logic ( Do not alter yourself)
byte posX = 5;
byte posY = 5;

byte enemyPosX = 0;
byte enemyPosY = 0;
bool enemyHasPosition = false;
bool enemyFirstPosition = false;
bool actionFrame  = false;
bool playerDead = false;
int toneCounter;
unsigned long previousMillis = 0;
int actionCooldown;

byte IMAGES[] = {
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00000000
};

// Game Options ( Feel free to change)
int baseActionCooldown = 400; // every 1000 is a second;
int actionCooldownModifier = 10; // Actioncooldown is reduced by actionCoolDownModifier each time you dodge an enemy
bool trackPlayer = true;
int toneDuration = 50;
int pitch = 300;



void setup() {
  actionCooldown = baseActionCooldown;
  matrixSetup();
  matrixBlinkoff();
  matrixBrightness(15);
  matrixPattern(IMAGES);
  Serial.begin(9600);
}

void loop() {
  if(!playerDead) {
    clearMatrix();
    setPosition();
    moveMatrix();
  }
  clearSound();
  checkButtons();
  //Serial.print(analogRead(joyX));
  //Serial.print(000);
  //Serial.print(analogRead(joyY));
  //Serial.println(000);
  matrixPattern(IMAGES);
}

void clearMatrix() {
  for(int i = 0; i<sizeof(IMAGES);i++) {
    IMAGES[i] = B00000000;
  }
}

void clearSound() {
  pinMode(buzzer, OUTPUT);
  if(toneCounter > 0) {
    toneCounter--;
  }
  else{
    noTone(buzzer);
  }
}

void setPosition() {
  posX = analogRead(joyX)/128;
  posY = analogRead(joyY)/128;
  unsigned long currentMillis = millis();
  if(currentMillis - previousMillis >= actionCooldown) {
    previousMillis = currentMillis;
    // Sets first enemy position
    if(enemyHasPosition == false){
      if(actionCooldown > actionCooldownModifier) {
        actionCooldown -= actionCooldownModifier;
      }
      enemyPosX = B00000000;
      if(trackPlayer == true) {
        enemyPosY = posY;
      }
      else {
        enemyPosY = random(7);
      }
      enemyHasPosition = true;
      enemyFirstPosition = true;
    }
    // If enemy already has a position ; move downwards.
    else {
      if(enemyFirstPosition) {
         enemyPosX = B00000001;
        enemyFirstPosition = false;
      }
      else {
        enemyPosX = enemyPosX+ 1;
      }
      if(enemyPosX >= 7) {
        enemyHasPosition = false;
      }
    }
    actionFrame == false;
  }
  else {
    actionFrame == true;
  }
}
void checkButtons() {
  Serial.println(analogRead(joySwitch));
  if(analogRead(joySwitch) == 0 && playerDead == true) {
    Serial.println("Resetting Game");
    playerDead = false;
    enemyHasPosition == false;
  }
}

void moveMatrix() {
  // Move Player
  byte playerPosition = B0000001 << 7-posX;
  IMAGES[posY] = playerPosition;

  // Move Enemy
  byte enemyPosition = B0000001 << 7-enemyPosX;
  if(posY != enemyPosY) {
    IMAGES[enemyPosY] = enemyPosition;
  }
  else {
    IMAGES[enemyPosY] = enemyPosition | playerPosition;
  }
  // Hit Effects
  if(posX == enemyPosX && posY == enemyPosY) {
    if(playerDead == false) {
      tone(buzzer,pitch);
      toneCounter = toneDuration;
      actionCooldown = baseActionCooldown;
      enemyHasPosition = false;
      playerDead = true;
    }
    IMAGES[posY-1] = IMAGES[posY-1] | B0000001 << 7-posX;
    IMAGES[posY] = IMAGES[posY] | B0000111 << 6-posX;
    IMAGES[posY+1] = IMAGES[posY+1] | B0000001 << 7-posX;
  }
}

