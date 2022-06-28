var sdk = require("./export1.js");
console.log(sdk);
sdk.onRuntimeInitialized = () => {
  var input_ptr = sdk._malloc(4);
  //sdk.HEAP32.set(45, input_ptr / 4);
  sdk.setValue(input_ptr, 45, "i32");
  var int_ptr = sdk._get_int_ptr(input_ptr);
  console.log("JS{int_ptr:" + int_ptr + "}");
  var int_value = sdk.HEAP32[int_ptr >> 2];
  console.log("JS{int_value:" + int_value + "}");

  char_ptr = sdk._get_char_str();
  var uint8array = new Uint8Array(6);
  var offset = char_ptr;
  for (var i = 0; i < 6; i++) {
    var letter = sdk.HEAP8[char_ptr];
    char_ptr += 1;
    uint8array[i] = letter;
    console.log(uint8array[i])
  }
  var str = new TextDecoder().decode(uint8array);
  console.log(str);

  sdk._free(int_ptr);
};
