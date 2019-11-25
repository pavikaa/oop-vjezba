#include<iostream>
#include<string>
class Device
{
protected:
	bool PoweredOn;
	std::string DeviceID, Manufacturer;
public:
	Device() :PoweredOn(0), DeviceID("123"), Manufacturer("NoName") {};
	Device(bool OnOff,std::string DeviceID,std::string Manufacturer):PoweredOn(OnOff),DeviceID(DeviceID),Manufacturer(Manufacturer){}
	void OnOffSwitch();
};
void Device::OnOffSwitch()
{
	if (PoweredOn)
		PoweredOn = 0;
	PoweredOn = 1;
}
class USBDevice:public virtual Device
{
protected:
	bool Connected;
	std::string USBStandard;
public:
	USBDevice():Device(),Connected(0),USBStandard("2.0"){}
	USBDevice(bool OnOff, std::string DeviceID, std::string Manufacturer,bool Connected,std::string USBStandard):Device(OnOff,DeviceID,Manufacturer),Connected(Connected),USBStandard(USBStandard){}
	virtual void ConnectDisconnect();
};
void USBDevice::ConnectDisconnect()
{
	if (Connected)
		Connected = 0;
	Connected = 1;
}
class NetworkDevice :public virtual Device
{
protected:
	bool Connected;
	std::string NetworkStandard;
public:
	NetworkDevice(): Device(), Connected(0), NetworkStandard("802.11a"){}
	NetworkDevice(bool OnOff, std::string DeviceID, std::string Manufacturer, bool Connected, std::string NetworkStandard) :Device(OnOff, DeviceID, Manufacturer), Connected(Connected), NetworkStandard(NetworkStandard){}
	virtual void ConnectDisconnect();
};
void NetworkDevice::ConnectDisconnect()
{
	if (Connected)
	Connected = 0;
	Connected = 1;
}
class WirelessAdapter :public USBDevice,public NetworkDevice
{
	int noOfAntennas;
	std::string gain;
public:
	WirelessAdapter():noOfAntennas(0),gain("80db"),USBDevice(),NetworkDevice(){}
	WirelessAdapter(int noOfAntennas,std::string gain,bool USBOnOff, std::string USBDeviceID, std::string USBManufacturer, bool USBConnected, std::string USBStandard, bool NetworkDeviceOnOff, std::string NetworkDeviceID, std::string NetworkDeviceManufacturer, bool NetworkDeviceConnected, std::string NetworkStandard):noOfAntennas(noOfAntennas),gain(gain),USBDevice(USBOnOff,USBDeviceID,USBManufacturer,USBConnected,USBStandard),NetworkDevice(NetworkDeviceOnOff,NetworkDeviceID,NetworkDeviceManufacturer,NetworkDeviceConnected,NetworkStandard){}
	void ConnectDisconnect();
	void Status();
};
void WirelessAdapter::ConnectDisconnect()
{
	USBDevice::ConnectDisconnect();
	NetworkDevice::ConnectDisconnect();
}
void WirelessAdapter::Status()
{
	if (USBDevice::Connected)
		std::cout << "USB uredaj je spojen." << std::endl;
	else
		std::cout << "USB uredaj nije spojen." << std::endl;
	if (NetworkDevice::Connected)
			std::cout << "Mrezni uredaj je spojen." << std::endl;
	else
		std::cout << "Mrezni uredaj nije spojen." << std::endl;
}
int main()
{
	WirelessAdapter wa;
	wa.Status();
	wa.ConnectDisconnect();
	wa.Status();
	
}