const message = prompt("Enter a set of string for encrypt: "); 
console.log("The string going to encrypt: " + message); 
const key = parseInt(prompt("Enter a key: ")); 
console.log("Key: " + key); 
let resultStr = []; 
 
for (let i = 0; i < message.length; i++) { 
  let charCode = message.charCodeAt(i); 
  if (charCode >= 65 && charCode <= 90) { 
    charCode += key; 
    if (charCode > 90) { 
      charCode = (charCode - 26) + (65 - 1); 
    } 
  } else if (charCode >= 97 && charCode <= 122) { 
    charCode += key; 
    if (charCode > 122) { 
      charCode = (charCode - 26) + (97 - 1); 
    } 
  } 
  resultStr.push(String.fromCharCode(charCode));   
} 
 
 
console.log("Encrypted message: " + resultStr.join(""));