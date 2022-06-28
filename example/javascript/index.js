var importObject = {
    "imports" : { imported_func: arg => console.log(arg)  }
};

WebAssembly.instantiateStreaming("./simple.wasm", importObject)
