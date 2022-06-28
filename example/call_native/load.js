var sdk = require("./export1.js");
console.log(sdk);
sdk.onRuntimeInitialized = () => {
  console.log(sdk._show_me_the_answer());
  console.log(sdk._add(1.1, 1.2));
  sdk._print_the_answer();
};
