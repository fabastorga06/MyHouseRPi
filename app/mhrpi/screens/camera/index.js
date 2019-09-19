import React from 'react';
import { 
  ImageBackground, 
  FlatList, 
  Text, 
  View, 
  Alert, 
  TouchableOpacity, 
  StyleSheet
} from 'react-native';
import backgroundImg from '../../images/background2.jpg';

export default class Camera extends React.Component {

  static navigationOptions = {
    title: 'CAMERA'
  };

  constructor(props)
  {
    super(props);

    this.state = {
    }
  }

  render() {
    return (
      <ImageBackground source={backgroundImg} style={styles.container}>
       
      </ImageBackground>
    );
  }
}

const styles = StyleSheet.create({
  container: {
    flexDirection: 'column',
    flex: 1,
    width: "100%",
    height: "100%",
    justifyContent: 'center',
    alignItems: 'center'
  }
})