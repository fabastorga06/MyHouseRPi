
import subprocess
import hashlib

def check_login_inputs(pusername, ppassword):
    users_file = open("users.info", "r")
    users_tuples_list = users_file.readlines()

    password_encoded = hashlib.sha256(ppassword).hexdigest()
    for i in users_tuples_list:
        if(
            i.split()[0] == pusername and
            i.split()[1] == password_encoded 
            ):
            return True
    return False