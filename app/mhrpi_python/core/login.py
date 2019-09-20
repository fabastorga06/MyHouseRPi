from PyQt4 import QtCore, QtGui

from core.main import *
from core.lib.libuser import *
from core.lib.libmessage import *

try:
    _fromUtf8 = QtCore.QString.fromUtf8
except AttributeError:
    def _fromUtf8(s):
        return s

try:
    _encoding = QtGui.QApplication.UnicodeUTF8
    def _translate(context, text, disambig):
        return QtGui.QApplication.translate(context, text, disambig, _encoding)
except AttributeError:
    def _translate(context, text, disambig):
        return QtGui.QApplication.translate(context, text, disambig)

class Ui_LoginWindow(object):
    def setupUi(self, MainWindow):
        MainWindow.setObjectName(_fromUtf8("MainWindow"))
        MainWindow.setEnabled(True)
        MainWindow.resize(426, 249)
        self.centralwidget = QtGui.QWidget(MainWindow)
        self.centralwidget.setObjectName(_fromUtf8("centralwidget"))
        self.backgroundhouse = QtGui.QLabel(self.centralwidget)
        self.backgroundhouse.setGeometry(QtCore.QRect(-10, 0, 441, 251))
        self.backgroundhouse.setCursor(QtGui.QCursor(QtCore.Qt.PointingHandCursor))
        self.backgroundhouse.setText(_fromUtf8(""))
        self.backgroundhouse.setPixmap(QtGui.QPixmap(_fromUtf8("images/background-scaled.jpg")))
        self.backgroundhouse.setIndent(-1)
        self.backgroundhouse.setObjectName(_fromUtf8("backgroundhouse"))
        self.lineEdit_username = QtGui.QLineEdit(self.centralwidget)
        self.lineEdit_username.setGeometry(QtCore.QRect(70, 200, 113, 27))
        self.lineEdit_username.setObjectName(_fromUtf8("lineEdit_username"))
        self.lineEdit_password = QtGui.QLineEdit(self.centralwidget)
        self.lineEdit_password.setGeometry(QtCore.QRect(240, 200, 113, 27))
        self.lineEdit_password.setObjectName(_fromUtf8("lineEdit_password"))
        self.label_username = QtGui.QLabel(self.centralwidget)
        self.label_username.setGeometry(QtCore.QRect(90, 180, 71, 17))
        self.label_username.setObjectName(_fromUtf8("label_username"))
        self.label_password = QtGui.QLabel(self.centralwidget)
        self.label_password.setGeometry(QtCore.QRect(260, 180, 71, 17))
        self.label_password.setObjectName(_fromUtf8("label_password"))
        self.pushButton_go = QtGui.QPushButton(self.centralwidget)
        self.pushButton_go.setGeometry(QtCore.QRect(370, 200, 41, 31))
        self.pushButton_go.setCursor(QtGui.QCursor(QtCore.Qt.WaitCursor))
        self.pushButton_go.setObjectName(_fromUtf8("pushButton_go"))
        self.label_title = QtGui.QLabel(self.centralwidget)
        self.label_title.setGeometry(QtCore.QRect(20, -10, 151, 121))
        font = QtGui.QFont()
        font.setPointSize(20)
        font.setBold(True)
        font.setItalic(True)
        font.setWeight(75)
        self.label_title.setFont(font)
        self.label_title.setText(_fromUtf8(""))
        self.label_title.setPixmap(QtGui.QPixmap(_fromUtf8("images/title.png")))
        self.label_title.setScaledContents(True)
        self.label_title.setObjectName(_fromUtf8("label_title"))
        MainWindow.setCentralWidget(self.centralwidget)

        self.retranslateUi(MainWindow)
        QtCore.QMetaObject.connectSlotsByName(MainWindow)

        self.pushButton_go.clicked.connect( lambda: self.loginUser(MainWindow) )

    def loginUser(self, pmainwindow):
        flag = check_login_inputs(
            str( self.lineEdit_username.text() ),
            str( self.lineEdit_password.text() )
        )
        if( flag ):
            self.window = QtGui.QMainWindow()
            self.ui = Ui_MainWindow()
            self.ui.setupUi(self.window)
            self.ui.set_main_module(pmainwindow)
            self.window.show()
        else:
            print("Error: invalid username or password")
            show_message(
                "Invalid username or password", 
                "Error",
                False )
                

    def retranslateUi(self, MainWindow):
        MainWindow.setWindowTitle(_translate("MainWindow", "MyHouseRPi", None))
        self.label_username.setText(_translate("MainWindow", "Username", None))
        self.label_password.setText(_translate("MainWindow", "Password", None))
        self.pushButton_go.setText(_translate("MainWindow", "Go", None))

def create_login():
    import sys
    app = QtGui.QApplication(sys.argv)
    login_window = QtGui.QMainWindow()
    ui = Ui_LoginWindow()
    ui.setupUi(login_window)
    login_window.show()
    sys.exit(app.exec_())