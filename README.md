# Hardware Stats for Droptop Four

CPU usage and temperature, GPU usage and temperature, and RAM usage in the center of your Droptop bar.

![Hardware Stats](Source/Hardware_Stats-Utkarsh/Images/PreviewImage.png)

**HWiNFO64 is a prerequisite for temperatures.** Install it separately from [HWiNFO's official site](https://www.hwinfo.com/download/), keep it running in Sensors-only mode, and enable Gadget reporting for the CPU and GPU temperature sensors. HWiNFO64 is not bundled.

CPU, GPU, and RAM usage use Rainmeter measures. RAM temperature is not displayed.

## Install and configure

1. Download `Hardware Stats - Utkarsh (Droptop App).rmskin` from this repository.
2. Install it with Rainmeter and select a Droptop community app slot.
3. Follow the [HWiNFO setup and sensor mapping instructions](Source/Hardware_Stats-Utkarsh/README.md).

The default HWiNFO shortcut points to `#SKINSPATH#HardwareStats\@Resources\HWiNFO\HWiNFO64.exe`. Change it in the app's variables if you installed HWiNFO elsewhere.

## Source and community release

The app files are in `Source/Hardware_Stats-Utkarsh`. `VariablesDefault.inc` contains the installation defaults. Droptop creates the local `Variables.inc` for each user; that file is excluded from source control.

Version 26.1106 is [published in Droptop's community app releases](https://discord.com/channels/800124057923485728/1041735140566650920/threads/1568207500669362218). The HWiNFO requirement is included in the public description.

The hardware monitor is by Utkarsh. The app uses the official Droptop Sample App integration files by Cariboudjan, as credited in the app README. See [Droptop's community app documentation](https://docs.droptopfour.com/community-apps/start-making-a-new-app).
