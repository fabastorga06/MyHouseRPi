# MyHouseRPi

You have to install pip and fpdf libraries in order to use app program. You can execute the following commands: 

`
$ sudo apt-get install python-pip
`

`
$ pip install fpdf
`

Then, you can run the app program:

`
$ python app.py
`

An user interface must open, like the following window:

![gui](https://github.com/fabastorga06/MyHouseRPi/blob/master/gui.jpg)

Next step is to execute C server inside your Raspberry Pi. So you have to compile first, remember to make a cross-compilation for the device architecture. Then execute it with a port as parameter: 
`
$ make
`

`
$ sudo ./MyHouse <port>
`

Now, you can use the program successfully.