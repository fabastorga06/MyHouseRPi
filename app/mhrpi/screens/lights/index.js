import React from 'react';
import { 
  ImageBackground, 
  Text, 
  View, 
  TouchableOpacity, 
  StyleSheet,
  Image
} from 'react-native';

import backgroundImg from '../../images/background2.jpg';
import lightOn1 from '../../images/lighton.png';
import lightOff1 from '../../images/lightoff.png';
import lightOn2 from '../../images/lighton.png';
import lightOff2 from '../../images/lightoff.png';
import lightOn3 from '../../images/lighton.png';
import lightOff3 from '../../images/lightoff.png';
import lightOn4 from '../../images/lighton.png';
import lightOff4 from '../../images/lightoff.png';
import lightOn5 from '../../images/lighton.png';
import lightOff5 from '../../images/lightoff.png';

export default class Lights extends React.Component {

  static navigationOptions = {
    title: 'LIGHTS'
  };

  constructor(props)
  {
    super(props);

    this.state = {
      showLightImg1: true,
      showLightImg2: true,
      showLightImg3: true,
      showLightImg4: true,
      showLightImg5: true
    }
  }

  _renderImage1 = () => {
    var imgSource = this.state.showLightImg1 ? lightOn1 : lightOff1;
    return (
      <Image
        style={ styles.img }
        source={ imgSource }
      />
    );
  }

  _renderImage2 = () => {
    var imgSource = this.state.showLightImg2 ? lightOn2 : lightOff2;
    return (
      <Image
        style={ styles.img }
        source={ imgSource }
      />
    );
  }

  _renderImage3 = () => {
    var imgSource = this.state.showLightImg3 ? lightOn3 : lightOff3;
    return (
      <Image
        style={ styles.img }
        source={ imgSource }
      />
    );
  }

  _renderImage4 = () => {
    var imgSource = this.state.showLightImg4 ? lightOn4 : lightOff4;
    return (
      <Image
        style={ styles.img }
        source={ imgSource }
      />
    );
  }

  _renderImage5 = () => {
    var imgSource = this.state.showLightImg5 ? lightOn5 : lightOff5;
    return (
      <Image
        style={ styles.img }
        source={ imgSource }
      />
    );
  }

  _onLightsOnPress = () => {

  }

  _onLightsOffPress = () => {
    
  }

  render() {
    return (
      <ImageBackground source={backgroundImg} style={styles.container}>
        <View style={styles.imgContainer}>
          <Text style={styles.text}> Light 1 </Text>
          <TouchableOpacity
              onPress={ () => this.setState({ showLightImg1: !this.state.showLightImg1 }) } 
          >
            {this._renderImage1()}
          </TouchableOpacity>
        </View>

        <View style={styles.imgContainer}>
          <Text style={styles.text}> Light 2 </Text>
          <TouchableOpacity
              onPress={ () => this.setState({ showLightImg2: !this.state.showLightImg2 }) } 
          >
            {this._renderImage2()}
          </TouchableOpacity>
        </View>

         <View style={styles.imgContainer}>
          <Text style={styles.text}> Light 3 </Text>
          <TouchableOpacity
              onPress={ () => this.setState({ showLightImg3: !this.state.showLightImg3 }) } 
          >
            {this._renderImage3()}
          </TouchableOpacity>
        </View>

         <View style={styles.imgContainer}>
          <Text style={styles.text}> Light 4 </Text>
          <TouchableOpacity
              onPress={ () => this.setState({ showLightImg4: !this.state.showLightImg4 }) } 
          >
            {this._renderImage4()}
          </TouchableOpacity>
        </View>

         <View style={styles.imgContainer}>
          <Text style={styles.text}> Light 5 </Text>
          <TouchableOpacity
              onPress={ () => this.setState({ showLightImg5: !this.state.showLightImg5 }) } 
          >
            {this._renderImage5()}
          </TouchableOpacity>
        </View>

        <View style={styles.container}>
          <TouchableOpacity style={styles.button} onPress={this._onLightsOnPress}>
            <Text style={styles.textButton}>All Lights ON</Text>
          </TouchableOpacity>
          <TouchableOpacity style={styles.button} onPress={this._onLightsOffPress}>
            <Text style={styles.textButton}>All Lights OFF</Text>
          </TouchableOpacity>
        </View>

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
  },
  imgContainer: {
    flexDirection: 'row',
    marginTop: 30,
    marginLeft: 10,
  },
  img: {
    flex: 1,
    height: 50,
    width: 50,
  }, 
  text: {
    color: 'white',
    fontSize: 36,
    fontWeight: 'bold',
    textAlign: 'center',
  },
  textButton: {
    color: 'white',
    fontSize: 16,
    fontWeight: 'bold',
    textAlign: 'center',
  },
  button: {
    width: 185,
    height: 65,
    borderRadius: 25,
    backgroundColor: "#006600",
    justifyContent: 'center',
    flexDirection: 'column',
    borderWidth: 2,
    borderColor: 'rgb(0, 0, 0)',
  }
})