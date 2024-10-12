const addon = require('./build/Release/addon');

const inputText = "dean";
const encryptedText = addon.encrypt(inputText);
console.log(`Encrypted text: ${encryptedText}`);
