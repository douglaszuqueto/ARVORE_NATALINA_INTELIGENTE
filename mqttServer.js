var mosca = require('mosca');
var settings = {
  port: 1883,
  http: {
    port:80,
    bundle:true,
    static:'./'
  }
}
var MQTT_WS_SERVER = new mosca.Server(settings);
MQTT_WS_SERVER.on('clientConnected',function(client){
  console.log('New Client Connected: ',client.id);
});
MQTT_WS_SERVER.on('published',function(packet){
  console.log('Topic: ', packet.topic);
});
MQTT_WS_SERVER.on('ready',function(){
  console.log('Server MQTT and Sockets running');
})
