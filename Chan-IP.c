#sistema linux created by cholohatwhite 
#dirigido a interfaz eth0 en caso de tener otra interfaz modificar linea 27 


import os,time
import random as ran
import requests  as r
import time


link="http://icanhazip.com/"

def conection(link):
	req=r.get(link)
	tar=req.text
	
	print(f"""codigo de respuesta: {req}\nIP asignada: {tar}""")
	
conection(link)

def new_connection():
	
	for i in range(10):
		for x in range(i):
			f=ran.randint(0,10)
			os.system(f"ifconfig eth0 192.168.0.{f} netmask 255.255.255.0")
			os.system("/etc/init.d/networking restart")
			time.sleep(5)
			print("Espere...")
			try:
				conection(link)
			except r.exceptions.ConnectionError:
				print("Conexion Rechazada :(")
				os.system("nmcli radio wifi off")
				time.sleep(5)
				os.system(" nmcli radio wifi on")
			break

new_connection()
