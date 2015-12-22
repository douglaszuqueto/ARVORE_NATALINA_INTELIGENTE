var mqtt = require('mqtt');
var options = {
  clientId: 'Subscriber',
  port: 1883
}
var client = mqtt.connect('mqtt://10.42.0.1', options);
client.on('connect', function(){
  client.subscribe('arvore/1');
});
client.on('message',function(topic,message){
  var message = message.toString();
  console.log('Topic: ',topic, ' | ', 'Message: ', message);
});
