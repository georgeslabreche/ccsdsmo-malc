## Demo App
Reference app that showcases how to use the MAL C API to develop apps for the [OPS-SAT spacecraft](https://opssat1.esoc.esa.int/). The app does a simple request operation the list [NMF apps](https://nanosat-mo-framework.github.io/) installed in SEPP.

## Running the app
The provider is the NMF Supervisor and the consumer is this app.

### Generic demo
```bash
./src/demo_app -h <provider_host> -p <provider_port> -c <consumer_port>
```

### getValue
```bash
./src/demo_getvalue
```