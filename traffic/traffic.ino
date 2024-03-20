// Define pins for traffic lights
#define RED_LIGHT_PIN 2
#define YELLOW_LIGHT_PIN 3
#define GREEN_LIGHT_PIN 4

// Define timing constants (in milliseconds)
const unsigned long GREEN_DURATION = 10000; // 10 seconds
const unsigned long YELLOW_DURATION = 3000; // 3 seconds
const unsigned long RED_DURATION = 10000;   // 10 seconds

// Define traffic light states
enum TrafficLightState {
  GREEN,
  YELLOW,
  RED
};

// Initialize variables
TrafficLightState currentState = GREEN;
unsigned long lastStateChangeTime = 0;

void setup() {
  pinMode(RED_LIGHT_PIN, OUTPUT);
  pinMode(YELLOW_LIGHT_PIN, OUTPUT);
  pinMode(GREEN_LIGHT_PIN, OUTPUT);
}

void loop() {
  // Determine current traffic light state
  switch (currentState) {
    case GREEN:
      if (millis() - lastStateChangeTime >= GREEN_DURATION) {
        currentState = YELLOW; // Change to yellow after green duration
        lastStateChangeTime = millis(); // Reset timer
      }
      digitalWrite(GREEN_LIGHT_PIN, HIGH);
      digitalWrite(YELLOW_LIGHT_PIN, LOW);
      digitalWrite(RED_LIGHT_PIN, LOW);
      break;
    case YELLOW:
      if (millis() - lastStateChangeTime >= YELLOW_DURATION) {
        currentState = RED; // Change to red after yellow duration
        lastStateChangeTime = millis(); // Reset timer
      }
      digitalWrite(GREEN_LIGHT_PIN, LOW);
      digitalWrite(YELLOW_LIGHT_PIN, HIGH);
      digitalWrite(RED_LIGHT_PIN, LOW);
      break;
    case RED:
      if (millis() - lastStateChangeTime >= RED_DURATION) {
        currentState = GREEN; // Change to green after red duration
        lastStateChangeTime = millis(); // Reset timer
      }
      digitalWrite(GREEN_LIGHT_PIN, LOW);
      digitalWrite(YELLOW_LIGHT_PIN, LOW);
      digitalWrite(RED_LIGHT_PIN, HIGH);
      break;
  }

  // Delay for a short period to improve efficiency
  delay(10);
}
