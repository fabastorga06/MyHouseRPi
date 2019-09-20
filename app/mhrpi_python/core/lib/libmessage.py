from PyQt4 import QtGui

# Show warning/info message to prevent 
# something wrong with the app
def show_message(pmessage, ptitle, isInfo):
    msg_box = QtGui.QMessageBox()
    if (isInfo):
        msg_box.setIcon(QtGui.QMessageBox.Information)
    else:
        msg_box.setIcon(QtGui.QMessageBox.Warning)
    msg_box.setText(pmessage)
    msg_box.setWindowTitle(ptitle)
    msg_box.setStandardButtons(QtGui.QMessageBox.Ok)
    msg_box.exec_()