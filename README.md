# Reflecta Monster Moto #

Reflecta Monster Moto exposes commands to allow a host to control a [Sparkfun Monster Moto Shield](https://www.sparkfun.com/products/10182) over the Arduino's USB or UART (Serial) port.

The commands exposed are:

- Drive (power0, power1): Turn on the motors using power levels from -255 to 255
- BrakeGround: Coast to a stop
- BrakeVcc: Hard brake using battery power to halt the drive shafts
- ReadCurrent: Read the current consumed by the motors

## Installing to Arduino

To install this library, upload sketch ReflectaMonsterMoto to your Arduino.  Note that you must first [install the Reflecta Arduino libraries](https://github.com/JayBeavers/Reflecta#getting-started).

## Calling from NodeJS

To call this library, use the [node-reflecta](https://github.com/JayBeavers/node-reflecta) library which can be installed using npm:

```
npm install reflecta
```

A simple example is:

```javascript
var reflecta = require('reflecta');
reflecta.detect(function(error, boards, ports) {

  // Choose the first board found
  var board = boards[0];
  board.moto1.drive(75, 75);
  board.moto1.brakeGround();
});
```

[A simple example](https://github.com/JayBeavers/node-reflecta/blob/master/samples/moto1.js) can be found in the node-reflecta project.

### Future Work ###

- Add error checking for power levels
- Add nodejs sample program that translatest joystick -> drive commands