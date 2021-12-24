## SEPP TM
An app to inject basic SEPP telemetry into the OBSW datapool. Sets the following parameters:
- Linux Uptime (in seconds)
- Memory Usage
- CPU Usage
- Disk Usage
- OOM Counter
- Number of files in toGround
- Number of files in toGroundLP
- System Status
- FPGA image loaded
- Dual core activated
- Number of experiments active
- Status of the CAN bridges

## Running the app
The provider is the NMF Supervisor and the consumer is this app.

```bash
./src/sepp_tm_app
```