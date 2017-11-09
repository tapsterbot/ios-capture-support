// test.js

var capture = require('../index')

console.log(capture.allow());
// Prints: Allowed!

console.log(capture.startPlugin());
// Prints: Starting!

console.log(capture.stopPlugin());
// Prints: Stopping!
