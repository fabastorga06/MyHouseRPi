
import sys
from PyQt4 import QtCore, QtGui

from core.login import *

app = None
window = None

def start_app():
    print("...")
    create_login()

def init_window_manager():
    global app
    global window
    app = QtGui.QApplication( sys.argv )
    #window = QtWidgets.QMainWindow()