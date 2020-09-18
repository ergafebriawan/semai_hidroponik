//config pin input push button controll
#define pin_button_UP 3
#define pin_button_DOWN 4
#define pin_button_LEFT 5
#define pin_button_RIGHT 6
#define pin_button_OK 7
#define pin_button_BACK 8

//init push button control
#define button_UP digitalRead(pin_button_UP)
#define button_DOWN digitalRead(pin_button_DOWN)
#define button_LEFT digitalRead(pin_button_LEFT)
#define button_RIGHT digitalRead(pin_button_RIGHT)
#define button_OK digitalRead(pin_button_OK)
#define button_BACK digitalRead(pin_button_BACK)

//config pin sensor soil moisture
#define pin_soil_moisture A0

//config pin sensor DHT22
#define DHTPIN 2

void init_button() {
 pinMode(pin_button_UP, INPUT_PULLUP);
 pinMode(pin_button_DOWN, INPUT_PULLUP);
 pinMode(pin_button_LEFT, INPUT_PULLUP);
 pinMode(pin_button_RIGHT, INPUT_PULLUP);
 pinMode(pin_button_OK, INPUT_PULLUP);
 pinMode(pin_button_BACK, INPUT_PULLUP);
}
