import base64
import sys
import telnetlib
import os
from fpdf import FPDF

tn_ip = "localhost"
tn_port = "5005"

def send_msg(cmd):
    try:
        tn = telnetlib.Telnet(tn_ip, tn_port, 15)
    except:
        print ("Unable to connect to Telnet server: " + tn_ip)
        return
    tn.write(cmd.encode('ascii') + b"\n")
    response = ""
    response = tn.read_all().decode('ascii')
    return response

def check_house():
    imgstring = send_msg("14")
    imgdata = base64.b64decode(imgstring)
    filename = 'myhouse.jpg'
    with open(filename, 'wb') as f:
        f.write(imgdata)
    os.system("shotwell myhouse.jpg")

def isLightOn( light, i ):
    status = ""
    if light == u'0':
        status = "Light " + str(i) + " is OFF"
    else:
        status = "Light " + str(i) + " is ON"
    return status

def isDoorOpen(door, i ):
    status = ""
    if door == u'0':
        status = "Door " + str(i) + " is closed"
    else:
        status = "Door " + str(i) + " is open"
    return status
        
def get_house_status():
    house_report = send_msg("13")
    status_list = list(house_report)
    doors = 1
    final_report = []

    for i in range (0, 5):
        final_report += [isLightOn(status_list[i], i+1)]
    
    for i in range (5, len(status_list)):
        final_report += [isDoorOpen(status_list[i], doors)]
        doors += 1

    print (final_report)
    return final_report


def change_light_mode(msg):
    lightMode = ""
    message = send_msg(msg)
    try:
        if (int(msg) > 0 and  int(msg) < 6):
            lightMode = "Light ON!"

        elif (int(msg) > 5 and  int(msg) < 11):
            lightMode = "Light OFF!"
        else:
            print("Error...")
    except:
        print ("Error: invalid data")

    print(lightMode)
    return lightMode

def turn_on_lights():
    message = send_msg("11")

def turn_off_lights():
    message = send_msg("12")

def createPDF(report):
    pdf = FPDF(orientation='P', unit='mm', format='A4')
    pdf.add_page()
    pdf.set_font("Arial", size=12)
    pdf.cell(0, 10, txt="MY HOUSE RPi STATUS REPORT", ln=1)
    for i in range(9):
        pdf.cell(0, 10, txt=report[i], ln=1)
    pdf.output("house_report.pdf")