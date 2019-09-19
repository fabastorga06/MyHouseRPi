import * as React from 'react';
import { 
  Text,
  View,
  StyleSheet,
  TextInput, 
  Button, 
  ImageBackground, 
  Image, 
  TouchableOpacity
} from 'react-native';

import backgroundImg from './../../images/background.jpg'
import logo from './../../images/logo.png'
import title from './../../images/title.png'

export default class Login extends React.Component {
  static navigationOptions = {
    title: 'MY HOUSE RPi'
  };

  constructor(props) {
    super(props);
    this.state = {
      user: '',
      password: '',
      warningMessage: ''
    };
  }

  _onUserChanged = event => {
    this.setState({
      user: event.nativeEvent.text
    });
  };

  _onPasswordChanged = event => {
    this.setState({
      password: event.nativeEvent.text
    });
  };

  _onLoginPress = () => {
    const user = '';
    const password = '';

    if (this.state.user === user && this.state.password === password) {
      this.setState({
        warningMessage: ''
      });
      this.props.navigation.navigate('MainMenu', {});
    }
    else {
      this.setState({
        warningMessage: 'User not available...'
      });
    }
  };

  render() {
    return (      
      <ImageBackground source={backgroundImg} style={styles.rootcontainer}>
        <View style={styles.logoContainer}>
          <Image source={logo} style={styles.logo} />
          <Image source={title} style={styles.titlelogin} />
        </View>
        <View style={styles.inputContainer}>
          <TextInput
            style={styles.input}
            value={this.state.user}
            onChange={this._onUserChanged}
            placeholder={'Username'}
            placeholderTextColor={'rgba(255, 255, 255, 0.7)'}
            underlineColorAndroid='transparent'/>
        </View>
        <View style={styles.inputContainer}>
          <TextInput
            style={styles.input}
            value={this.state.password}
            onChange={this._onPasswordChanged}
            placeholder={'Password'}
            secureTextEntry={true}
            placeholderTextColor={'rgba(255, 255, 255, 0.7)'}
            underlineColorAndroid='transparent'/>
        </View>
        <TouchableOpacity style={styles.botonLogin} onPress={this._onLoginPress}>
					<Text style={styles.text}>Login</Text>
				</TouchableOpacity>
        <Text style={styles.description}>{this.state.warningMessage}</Text>
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
    marginTop: 85,
    marginLeft: 20,
    marginBottom: 50,
    flexDirection: 'row'
  },
  logo: {
    height: 100,
    width: 100,
  },
  titlelogin : {
    height: 130,
    width: 130,
  },
  input: {
    width: 250,
    height: 50,
    borderRadius: 25,
    fontSize: 18,
    paddingLeft: 45,
    marginHorizontal: 25,
    backgroundColor: 'rgba(0, 0, 0, 0.35)',
    color: 'white'
  },
  inputContainer: {
    marginTop: 10
  },
  botonLogin: {
    width: 250,
    height: 85,
    borderRadius: 25,
    backgroundColor: "#006600",
    justifyContent: 'center',
    marginTop: 60,
    borderWidth: 2,
    borderColor: 'rgb(0, 0, 0)',
  },
  text: {
    color: 'white',
    fontSize: 20,
    fontWeight: 'bold',
    textAlign: 'center'
  },
  description: {
    marginTop: 40,
    fontSize: 16,
    color: '#ffffff',
    textAlign: 'center',
  }
});