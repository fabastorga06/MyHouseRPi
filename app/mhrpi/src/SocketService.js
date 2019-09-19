import React, { Component } from 'react';
import { Text, View, StyleSheet } from 'react-native';
import { Constants } from 'expo';
import io from 'socket.io-client';

const SOCKET_URL = '192.168.43.119:5005';

export default class App extends Component {

  socket = io.connect(SOCKET_URL, {
    transports: ['websocket'],
    reconnectionAttempts: 15 //Nombre de fois qu'il doit réessayer de se connecter
  });

  state = {
    conncted: false
  };
  

  componentDidMount() {
    this.onConnectSocket();
  }

  onConnectSocket = () => {
    //Vérification si socket n'est pas à null
    if(this.socket) {
      //Ecoute de l'évènement
      this.socket.on('connect', () => {
        this.socket.emit('i-am-connected'); // Emission d'un message

        //Modification du status de connexion
        this.setState({
          connected: true
        });
      });
    }
  }

  write(msg) {
    if(this.socket) {
      //Ecoute de l'évènement
      this.socket.on('connect', () => {
        this.socket.emit('i-am-connected'); // Emission d'un message

      });
    }
  }

  render() {
    return (
      <View style={styles.container}>
      </View>
    );
  }
}

const styles = StyleSheet.create({
  container: {
    flex: 1,
    alignItems: 'center',
    justifyContent: 'center',
    paddingTop: Constants.statusBarHeight,
    backgroundColor: '#ecf0f1',
  },
});