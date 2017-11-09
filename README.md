iOS Capture Support
===================

A Node.js addon for allowing screen capture from tethered iOS devices. 
It doesn't do the actual screen capturing or recording, 
but it performs the required actions to enable capture to happen.

## Install

    npm install ios-capture-support

## Example usage

    var capture = require('ios-capture-support')
    capture.allow()
    capture.startPlugin()
    capture.stopPlugin()
