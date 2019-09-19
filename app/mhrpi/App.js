import { createStackNavigator } from 'react-navigation';
// import io from 'socket.io-client'

import Login from './screens/login';
import MainMenu from './screens/mainmenu';
import Lights from './screens/lights';
import Camera from './screens/camera';

const App = createStackNavigator({
  Login : {screen: Login},
  MainMenu : {screen: MainMenu},
  Lights: {screen: Lights},
  Camera : {screen: Camera}
})

// const SOCKET_URL = '192.168.43.119:5005';
// const socket = io(SOCKET_URL, {
//   transports: ['websocket'],
//   reconnectionAttempts: 15 //Nombre de fois qu'il doit réessayer de se connecter
// });

// export const startSocketIO = () => {
//   socket.connect();

//   socket.on('connect', () => {
//     socket.emit('i-am-connected'); 
//   });
// }

export default App