[Hardware_Stats-Utkarsh.Style]
W=((((#TopHeight#+#TopBarIconHOffset#)*1.5))-((((#TopHeight#+#TopBarIconHOffset#)*1.5)%1)))
[Hardware_Stats-Utkarsh]
Meter=Image
MeterStyle=InfoStyle | CustomAppModifierStyle
SolidColor=0,0,0,0

[HSC.CPU]
Measure=CPU
Processor=0
UpdateDivider=-1
Group=UpdateMeasure1S

[HSC.GPU]
Measure=Plugin
Plugin=UsageMonitor
Alias=GPU
Index=0
UpdateDivider=-1
Group=UpdateMeasure1S

[HSC.GPUPercent]
Measure=Calc
Formula=Clamp(HSC.GPU,0,100)
UpdateDivider=-1
Group=UpdateMeasure1S

[HSC.RAM]
Measure=PhysicalMemory
UpdateDivider=-1
Group=UpdateMeasure1S

[HSC.RAMTotal]
Measure=PhysicalMemory
Total=1
UpdateDivider=-1
Group=UpdateMeasure1S

[HSC.RAMPercent]
Measure=Calc
Formula=(HSC.RAMTotal>0?(100*HSC.RAM/HSC.RAMTotal):0)
UpdateDivider=-1
Group=UpdateMeasure1S

[HSC.CPUTemp]
Measure=Registry
RegHKey=#HSC.RegistryHive#
RegKey=SOFTWARE\HWiNFO64\VSB
RegValue=#HSC.CPUTempValue#
Substitute=" °C":"°C","":"N/A"
UpdateDivider=-1
Group=UpdateMeasure1S

[HSC.GPUTemp]
Measure=Registry
RegHKey=#HSC.RegistryHive#
RegKey=SOFTWARE\HWiNFO64\VSB
RegValue=#HSC.GPUTempValue#
Substitute=" °C":"°C","":"N/A"
UpdateDivider=-1
Group=UpdateMeasure1S

[HSC.HWiNFO]
Measure=Process
ProcessName=HWiNFO64.exe
UpdateDivider=-1
Group=UpdateMeasure1S
IfCondition=(HSC.HWiNFO=1)&&(HSC.CPUTemp>0)&&(HSC.GPUTemp>0)
IfTrueAction=[!SetOption HSC.Text Text "CPU [*HSC.CPU:0*]%  [*HSC.CPUTemp:0*][\x00B0]C   |   GPU [*HSC.GPUPercent:0*]%  [*HSC.GPUTemp:0*][\x00B0]C   |   RAM [*HSC.RAMPercent:0*]%"][!UpdateMeter HSC.Text][!Redraw]
IfFalseAction=[!SetOption HSC.Text Text "CPU [*HSC.CPU:0*]%  N/A   |   GPU [*HSC.GPUPercent:0*]%  N/A   |   RAM [*HSC.RAMPercent:0*]%"][!UpdateMeter HSC.Text][!Redraw]
[HSC.Text]
Meter=String
Text=CPU [HSC.CPU:0]%  [HSC.CPUTemp:0][\x00B0]C   |   GPU [HSC.GPUPercent:0]%  [HSC.GPUTemp:0][\x00B0]C   |   RAM [HSC.RAMPercent:0]%
X=([TopBar:W]/2)
Y=((#TopBarTextYOffset#+#TopHeight#/2)-((#TopBarTextYOffset#+#TopHeight#/2)%1))
StringAlign=CenterCenter
FontFace=#TopBarFontName#
FontSize=#TopBarFontSize#
FontWeight=#FontWeight#
FontColor=#TopBarFontColor1#,#TopBarTitleOpacity#
AntiAlias=#TopBarAntiAlias#
DynamicVariables=1
UpdateDivider=-1
Group=UpdateMeter1S
Hidden=([BlankSpaceMarkerBEGIN:X]>[HSC.Text:X]?1:([BlankSpaceMarkerEND:X]<[HSC.Text:XW]?1:0))
ToolTipText=HWiNFO64 is required and must be running with Gadget reporting enabled. CPU and GPU temperatures are in Celsius. RAM shows physical memory usage.
