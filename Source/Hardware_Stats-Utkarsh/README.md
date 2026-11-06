# Hardware Stats for Droptop Four

By Utkarsh. Version 26.1106.

![Hardware Stats preview](Images/PreviewImage.png)

Displays CPU usage and temperature, GPU usage and temperature, and physical RAM usage in the center of the Droptop bar. Based on the author's existing HardwareStats monitor. The readout follows Droptop's font and color settings and hides when there is insufficient space between the folders and app buttons.

## Prerequisites

- Windows 10 or later, Rainmeter 4.5.7 or later, and Droptop Four.
- **HWiNFO64 must be installed separately and running for CPU and GPU temperatures.** Download it from https://www.hwinfo.com/download/ . HWiNFO is third-party software and is not included in this installer.
- Enable HWiNFO's Gadget reporting and export your CPU package temperature and your chosen GPU temperature. Shared Memory is not used by this app.

CPU and RAM usage use Rainmeter's built-in measures. GPU usage uses Rainmeter's bundled UsageMonitor plugin. HWiNFO supplies the temperatures. When HWiNFO is not running or either temperature is unavailable, both temperatures display N/A, matching the original monitor.

## Configure HWiNFO64

1. Start HWiNFO64 in Sensors-only mode and leave it running.
2. Open sensor settings, choose HWiNFO Gadget, and enable reporting to Gadget.
3. Enable Report value in Gadget for the CPU package temperature and the GPU temperature you want to display. Select temperature sensors whose exported values are Celsius.
4. Check the exported sensor labels in Registry Editor under HKEY_LOCAL_MACHINE\SOFTWARE\HWiNFO64\VSB or HKEY_CURRENT_USER\SOFTWARE\HWiNFO64\VSB. Match LabelN/SensorN to ValueRawN. Sensor indexes differ across computers.
5. In the app's Variables/Variables.inc, set HSC.RegistryHive to the hive containing your sensors. Set HSC.CPUTempValue and HSC.GPUTempValue to the matching ValueRawN names. Defaults are HKEY_LOCAL_MACHINE, ValueRaw0 for CPU, and ValueRaw1 for GPU.
6. Set HSC.HWiNFOExe to your HWiNFO64.exe path if you want the app's launch shortcut to work. The default is #SKINSPATH#HardwareStats\@Resources\HWiNFO\HWiNFO64.exe, matching the original portable setup. You can run HWiNFO from another location instead.
7. Refresh Droptop after saving the mapping. Configure HWiNFO to start with Windows yourself if desired; this app does not add a startup task.

Official Rainmeter instructions: https://docs.rainmeter.net/tips/hwinfo/

## Install

Install Hardware Stats - Utkarsh (Droptop App).rmskin and select a community app slot when prompted. Enable that app in Droptop. Click its chip icon for setup instructions, the HWiNFO shortcut, and the sensor mapping file.

If migrating from the author's original custom include, disable the old @IncludeHardwareStats line in Droptop/DropdownBar/DropdownBar.ini before enabling this community version to avoid displaying the monitor twice. Other users do not need to edit Droptop's core files.

GPU usage is the aggregate reported by Rainmeter UsageMonitor; on computers with multiple GPUs it may not correspond to the GPU selected for temperature. RAM is shown as a usage percentage; this app does not display RAM temperature.

## Community release

Submit the installer in the official Droptop Discord using /community_app new_release. Follow the bot prompts for the description and optional GitHub source link. See https://docs.droptopfour.com/community-apps/compile-and-share-the-app .

Droptop's Config/MainConfig.inc, Settings/Config/MainConfig.inc, Startup/Startup.ini, and blank icon are derived from the installed official Sample App by Cariboudjan. The hardware measures and centered readout come from the author's existing HardwareStats.inc. The original installed monitor is not modified by this package preparation.