# -*- coding: utf-8 -*-

# Form implementation generated from reading ui file 'qtdesigner/main.ui'
#
# Created by: PyQt4 UI code generator 4.12.1
#
# WARNING! All changes made in this file will be lost!

from PyQt4 import QtCore, QtGui

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

class Ui_MainWindow(object):
    def setupUi(self, MainWindow):
        MainWindow.setObjectName(_fromUtf8("MainWindow"))
        MainWindow.resize(391, 428)
        self.centralwidget = QtGui.QWidget(MainWindow)
        self.centralwidget.setObjectName(_fromUtf8("centralwidget"))
        self.label_background = QtGui.QLabel(self.centralwidget)
        self.label_background.setGeometry(QtCore.QRect(-10, 0, 851, 511))
        self.label_background.setText(_fromUtf8(""))
        self.label_background.setPixmap(QtGui.QPixmap(_fromUtf8("images/background.jpg")))
        self.label_background.setObjectName(_fromUtf8("label_background"))
        self.label_logo = QtGui.QLabel(self.centralwidget)
        self.label_logo.setGeometry(QtCore.QRect(30, 20, 101, 81))
        self.label_logo.setText(_fromUtf8(""))
        self.label_logo.setPixmap(QtGui.QPixmap(_fromUtf8("images/logo.png")))
        self.label_logo.setScaledContents(True)
        self.label_logo.setObjectName(_fromUtf8("label_logo"))
        self.label_title = QtGui.QLabel(self.centralwidget)
        self.label_title.setGeometry(QtCore.QRect(150, 20, 201, 91))
        self.label_title.setText(_fromUtf8(""))
        self.label_title.setPixmap(QtGui.QPixmap(_fromUtf8("images/title.png")))
        self.label_title.setScaledContents(False)
        self.label_title.setObjectName(_fromUtf8("label_title"))
        self.button_on = QtGui.QPushButton(self.centralwidget)
        self.button_on.setGeometry(QtCore.QRect(100, 140, 41, 21))
        self.button_on.setObjectName(_fromUtf8("button_on"))
        self.button_off = QtGui.QPushButton(self.centralwidget)
        self.button_off.setGeometry(QtCore.QRect(140, 140, 41, 21))
        self.button_off.setObjectName(_fromUtf8("button_off"))
        self.label_light_1 = QtGui.QLabel(self.centralwidget)
        self.label_light_1.setGeometry(QtCore.QRect(30, 140, 66, 17))
        self.label_light_1.setObjectName(_fromUtf8("label_light_1"))
        self.button_off_2 = QtGui.QPushButton(self.centralwidget)
        self.button_off_2.setGeometry(QtCore.QRect(140, 170, 41, 21))
        self.button_off_2.setObjectName(_fromUtf8("button_off_2"))
        self.button_on_2 = QtGui.QPushButton(self.centralwidget)
        self.button_on_2.setGeometry(QtCore.QRect(100, 170, 41, 21))
        self.button_on_2.setObjectName(_fromUtf8("button_on_2"))
        self.label_light_2 = QtGui.QLabel(self.centralwidget)
        self.label_light_2.setGeometry(QtCore.QRect(30, 170, 66, 17))
        self.label_light_2.setObjectName(_fromUtf8("label_light_2"))
        self.button_off_3 = QtGui.QPushButton(self.centralwidget)
        self.button_off_3.setGeometry(QtCore.QRect(140, 200, 41, 21))
        self.button_off_3.setObjectName(_fromUtf8("button_off_3"))
        self.button_on_3 = QtGui.QPushButton(self.centralwidget)
        self.button_on_3.setGeometry(QtCore.QRect(100, 200, 41, 21))
        self.button_on_3.setObjectName(_fromUtf8("button_on_3"))
        self.label_light_3 = QtGui.QLabel(self.centralwidget)
        self.label_light_3.setGeometry(QtCore.QRect(30, 200, 66, 17))
        self.label_light_3.setObjectName(_fromUtf8("label_light_3"))
        self.button_off_4 = QtGui.QPushButton(self.centralwidget)
        self.button_off_4.setGeometry(QtCore.QRect(140, 230, 41, 21))
        self.button_off_4.setObjectName(_fromUtf8("button_off_4"))
        self.button_on_4 = QtGui.QPushButton(self.centralwidget)
        self.button_on_4.setGeometry(QtCore.QRect(100, 230, 41, 21))
        self.button_on_4.setObjectName(_fromUtf8("button_on_4"))
        self.label_light_4 = QtGui.QLabel(self.centralwidget)
        self.label_light_4.setGeometry(QtCore.QRect(30, 230, 66, 17))
        self.label_light_4.setObjectName(_fromUtf8("label_light_4"))
        self.button_off_5 = QtGui.QPushButton(self.centralwidget)
        self.button_off_5.setGeometry(QtCore.QRect(140, 260, 41, 21))
        self.button_off_5.setObjectName(_fromUtf8("button_off_5"))
        self.button_on_5 = QtGui.QPushButton(self.centralwidget)
        self.button_on_5.setGeometry(QtCore.QRect(100, 260, 41, 21))
        self.button_on_5.setObjectName(_fromUtf8("button_on_5"))
        self.label_light_5 = QtGui.QLabel(self.centralwidget)
        self.label_light_5.setGeometry(QtCore.QRect(30, 260, 66, 17))
        self.label_light_5.setObjectName(_fromUtf8("label_light_5"))
        self.button_check = QtGui.QPushButton(self.centralwidget)
        self.button_check.setGeometry(QtCore.QRect(240, 140, 101, 27))
        self.button_check.setObjectName(_fromUtf8("button_check"))
        self.button_report = QtGui.QPushButton(self.centralwidget)
        self.button_report.setGeometry(QtCore.QRect(240, 180, 101, 27))
        self.button_report.setObjectName(_fromUtf8("button_report"))
        self.text_box = QtGui.QTextEdit(self.centralwidget)
        self.text_box.setGeometry(QtCore.QRect(210, 210, 161, 161))
        self.text_box.viewport().setProperty("cursor", QtGui.QCursor(QtCore.Qt.ForbiddenCursor))
        self.text_box.setReadOnly(True)
        self.text_box.setObjectName(_fromUtf8("text_box"))
        self.button_all_on = QtGui.QPushButton(self.centralwidget)
        self.button_all_on.setGeometry(QtCore.QRect(30, 320, 141, 27))
        self.button_all_on.setObjectName(_fromUtf8("button_all_on"))
        self.button_all_off = QtGui.QPushButton(self.centralwidget)
        self.button_all_off.setGeometry(QtCore.QRect(30, 350, 141, 27))
        self.button_all_off.setObjectName(_fromUtf8("button_all_off"))
        self.button_pdf = QtGui.QPushButton(self.centralwidget)
        self.button_pdf.setGeometry(QtCore.QRect(220, 380, 141, 27))
        self.button_pdf.setObjectName(_fromUtf8("button_pdf"))
        MainWindow.setCentralWidget(self.centralwidget)

        self.retranslateUi(MainWindow)
        QtCore.QMetaObject.connectSlotsByName(MainWindow)

    def retranslateUi(self, MainWindow):
        MainWindow.setWindowTitle(_translate("MainWindow", "MyHouseRpi - Control", None))
        self.button_on.setText(_translate("MainWindow", "ON", None))
        self.button_off.setText(_translate("MainWindow", "OFF", None))
        self.label_light_1.setText(_translate("MainWindow", "Light 1", None))
        self.button_off_2.setText(_translate("MainWindow", "OFF", None))
        self.button_on_2.setText(_translate("MainWindow", "ON", None))
        self.label_light_2.setText(_translate("MainWindow", "Light 2", None))
        self.button_off_3.setText(_translate("MainWindow", "OFF", None))
        self.button_on_3.setText(_translate("MainWindow", "ON", None))
        self.label_light_3.setText(_translate("MainWindow", "Light 3", None))
        self.button_off_4.setText(_translate("MainWindow", "OFF", None))
        self.button_on_4.setText(_translate("MainWindow", "ON", None))
        self.label_light_4.setText(_translate("MainWindow", "Light 4", None))
        self.button_off_5.setText(_translate("MainWindow", "OFF", None))
        self.button_on_5.setText(_translate("MainWindow", "ON", None))
        self.label_light_5.setText(_translate("MainWindow", "Light 5", None))
        self.button_check.setText(_translate("MainWindow", "Check house", None))
        self.button_report.setText(_translate("MainWindow", "Get report", None))
        self.button_all_on.setText(_translate("MainWindow", "Turn ON All lights", None))
        self.button_all_off.setText(_translate("MainWindow", "Turn OFF All lights", None))
        self.button_pdf.setText(_translate("MainWindow", "Generate PDF", None))
    
    def set_main_module(self, pmodule):
        self.main = pmodule
        self.main.hide()
