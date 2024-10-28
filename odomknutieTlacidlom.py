from machine import Pin, PWM
import utime

#inicializácia pinov
userLed = Pin(21, Pin.OUT)							#nastavenie vstavanej LED diody na "Seeed Studio Xiao ESP32S3"; POZOR! pri hodnote 0 svieti pri 1 zhasne
pwm = PWM(Pin(1), freq = 50, duty = 0)				#nastavenie pinu pre ovladanie servo motora "EF92A micro:servo 180°"
pwm.deinit()										#zastavi beh servo motora
buttonPin = Pin(3, Pin.IN)							#nastavenie vstupneho pinu pre tlacidlo
buttonPin.init(buttonPin.IN, buttonPin.PULL_DOWN) 	#inicializacia zisťovania zmeny stavu tlacidla

# podprogramy 
def Servo(servo, angle):
    dutyCycle = int(((angle)* 127/180)+1)  			#pomocny vypocet: mozne pozicie 1-128 pre cca 0°-180°
    pwm.duty(dutyCycle)								#nastavenie serva na poziciu
    print("Pozicia: ", dutyCycle)
    dutyPercent = int((100/128)*dutyCycle) 			#vypocet striedy (D) v %
    print("Strieda:", dutyPercent, "%")


def onBoardLED():
    for i in range(2):								#for cyklus: blikanie vstavanej LEDky 
        userLed.value(0)
        utime.sleep(0.1)
        userLed.value(1)
        utime.sleep(0.1)

def moveServo(position):
    if position <= 180:
        pwm.init(freq = 50, duty = position)
        Servo(pwm, position)
        print("Uhol serva : ", position, "°")
        print("-------------------")
        onBoardLED() 								#blikanie vstavanej LED pocas prebiehajucej aktivity
        pwm.deinit()   								#ukonci PWM vystup pre servo motor
        #utime.sleep(0.5)
        
    else:
        #pwm.deinit()
        print("Uhol serva je vacsi ako 180°. Ulohu nemozem vykonat")
    
    
#skuska pohybu servo motora od 0° po 180° a naspat
#moveServo(0)
#moveServo(45)
#moveServo(90)
#moveServo(135)
#moveServo(180)
#moveServo(135)
#moveServo(90)
#moveServo(45)
#moveServo(0)
    
while True:											#zistovanie stlacenia a pustenia tlacidla - nekonecna slucka
    first = buttonPin.value()
    utime.sleep(0.01)
    second = buttonPin.value()
    
    if first and not second:
        utime.sleep(3)
        print('Pustene!')      
        moveServo(0)								#po pusteni tlacidla sa mechanizmus zamku po danom case zatvori
            
    elif not first and second:
        
        print('Stlacene!')
        moveServo(45)								#po stlaceni tlacidla sa mechanizmus zamku ihned otvori
        
        
        
           

    


