import * as React from 'react';
import {
  Text,
  View,
  StyleSheet,
  ImageBackground,
  Image,
  TouchableOpacity
} from 'react-native';
import io from 'socket.io-client';

//var net = require('react-native-tcp')
import net from 'react-native-tcp'

import backgroundImg from './../../images/background.jpg'
import logo from './../../images/logo.png'
import title from './../../images/title.png'

const SOCKET_URL = '192.168.43.119:5005';

export default class MainMenu extends React.Component {
  static navigationOptions = {
    title: 'OPTIONS'
  };

  constructor(props) {
    super(props);

    this.state = {
      connected: false
    };
  }

  // //SOCKET_URL = '192.168.43.119:5005';
  // socket = io(SOCKET_URL, {
  //   transports: ['websocket'],
  //   reconnectionAttempts: 15, //Nombre de fois qu'il doit réessayer de se connecter
  //   jsonp: false,
  //   path: '/',
  // });

  // startSocketIO = () => {
  //   this.socket.connect();

  //   this.socket.on('connect', () => {
  //     this.socket.send('message');
  //   });
  // }

  client = new net.Socket()

  writeSocket(msg) {
    this.client.connect(5005, '192.168.43.119',()=>{
      this.client.write(msg)
    });

    this.client.on('data', (data) => { 
      console.log(data);
    });
  }

  _onLightsPress = () => {
    this.props.navigation.navigate('Lights', {});
  };

  _onDoorsPress = () => {

    this.writeSocket('hola mundo');

    var number = '101010011',
      output = []

    for (var i = 0, len = number.length; i < len; i += 1) {
      output.push(+number.charAt(i));
    }
    //alert(output);
  };

  _onCameraPress = () => {
    this.props.navigation.navigate('Camera', {});
  };

  render() {
    return (

      <ImageBackground source={backgroundImg} style={styles.rootcontainer}>
        <View style={styles.logoContainer}>
          <Image source={logo} style={styles.logo} />
          <Image source={title} style={styles.titlelogin} />
        </View>

        <TouchableOpacity style={styles.buttons} onPress={this._onLightsPress}>
          <Text style={styles.text}>ON/OFF Lights</Text>
        </TouchableOpacity>

        <TouchableOpacity style={styles.buttons} onPress={this._onDoorsPress}>
          <Text style={styles.text}>Doors Status</Text>
        </TouchableOpacity>

        <TouchableOpacity style={styles.buttons} onPress={this._onCameraPress}>
          <Text style={styles.text}>Check House</Text>
        </TouchableOpacity>

      </ImageBackground>
    );
  }
}

const styles = StyleSheet.create({
  rootcontainer: {
    flex: 1,
    alignItems: 'center'
  },
  logoContainer: {
    marginTop: 40,
    marginLeft: 20,
    marginBottom: 280,
    flexDirection: 'row'
  },
  logo: {
    height: 100,
    width: 100,
  },
  titlelogin: {
    height: 130,
    width: 130,
  },
  buttons: {
    width: 200,
    height: 50,
    borderRadius: 25,
    backgroundColor: "#006600",
    justifyContent: 'center',
    marginTop: 5,
    borderWidth: 2,
    borderColor: 'rgb(0, 0, 0)',
  },
  text: {
    color: 'white',
    fontSize: 14,
    fontWeight: 'bold',
    textAlign: 'center'
  }
});
