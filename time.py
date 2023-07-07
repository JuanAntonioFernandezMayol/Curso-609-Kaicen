import keyboard
import time

def mensaje():
    print("Mensaje cada 2 segundos.")

continuar = True

def detener_script(event):
    global continuar
    if event.name == "x":
        continuar = False

keyboard.on_press(detener_script)

while continuar:
    mensaje()
    time.sleep(2)

keyboard.unhook_all()