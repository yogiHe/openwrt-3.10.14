#!/bin/sh
iwpriv ra0 set SiteSurvey=0
sleep 2
iwpriv ra0 get_site_survey

#wifi_info_l=`iwpriv ra0 get_site_survey | grep "smartlock2"`



echo 'Please input ssid name'
read ssid
#channal = `echo $wifi_info | grep ssid |awk '{print $1}'`

wifi_info=`iwpriv ra0 get_site_survey | grep "$ssid"`
if [ $? -eq 0 ]; then
	echo "select successful"
else
	echo "select fail:do not have this ssid"i
	exit
fi

echo $wifi_info
wifi_channal=`echo $wifi_info | awk '{print $1}'`
wifi_ssid=`echo $wifi_info | awk '{print $2}'`
wifi_authmode=`echo $wifi_info | awk '{print $4}' | awk -F/ '{print $1}'`
wifi_encrytype=`echo $wifi_info | awk '{print $4}' | awk -F/ '{print $2}'`
echo "channal $wifi_channal"
echo $wifi_ssid
echo "please input wifi password"
read wifi_pwd

iwpriv apcli0 set ApCliEnable=0
iwpriv apcli0 set ApCliAuthMode=WPA2PSK
iwpriv apcli0 set ApCliEncrypType=AES
iwpriv apcli0 set ApCliSsid=$wifi_ssid
iwpriv apcli0 set ApCliWPAPSK=$wifi_pwd
iwpriv apcli0 set ApCliEnable=1

wireless_channel=`cat /etc/config/wireless | grep "option channel"`
echo $wireless_channel
sed -i "s/$wireless_channel/	option channel '$wifi_channal'/g" /etc/config/wireless

wireless_ApCliEnable=`cat /etc/config/wireless | grep "ApCliEnable"`
if [ $? -eq 0 ]; then
	sed -i "s/$wireless_ApCliEnable/option ApCliEnable '1'/g" /etc/config/wireless

else
	echo "	option ApCliEnable '1'" >> /etc/config/wireless
fi

wireless_ApCliAuthMode=`cat /etc/config/wireless | grep "ApCliAuthMode"`
if [ $? -eq 0 ]; then
	 sed -i "s/$wireless_ApCliAuthMode/option ApCliAuthMode '$wifi_authmode'/g" /etc/config/wireless

else
	echo "	option ApCliAuthMode 'WPA2PSK'" >> /etc/config/wireless
fi

wireless_ApCliEncryType=`cat /etc/config/wireless | grep "ApCliEncrypType"`
if [ $? -eq 0 ]; then

	sed -i "s/$wireless_ApCliEncryType/option ApCliEncrypType '$wifi_encrytype'/g" /etc/config/wireless
else

	echo "	option ApCliEncrypType 'AES'" >> /etc/config/wireless
fi

wireless_ApCliSsid=`cat /etc/config/wireless | grep "ApCliSsid"`
if [ $? -eq 0 ]; then
	sed -i "s/$wireless_ApCliSsid/option ApCliSsid '$wifi_ssid'/g" /etc/config/wireless
else
	echo "	option ApCliSsid '$wifi_ssid'" >> /etc/config/wireless
fi

wireless_ApCliWPAPSK=`cat /etc/config/wireless | grep "ApCliWPAPSK"`
if [ $? -eq 0 ]; then
	 sed -i "s/$wireless_ApCliWPAPSK/option ApCliWPAPSK '$wifi_pwd'/g" /etc/config/wireless
else
	echo " 	option ApCliWPAPSK '$wifi_pwd'" >>  /etc/config/wireless
fi

