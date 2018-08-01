#!/bin/sh
LOG_FILE=/root/net_ping.log


get_cur_timeSecond()
{

	CurTime_S=`date +%S`
}

ping_x()
{
	IP=$1
	for i in 1 2 3 4 5
	do
		ping -c 3 -w 3 $IP > /root/net_ping.log
		if [ $? -eq 0 ]; then
			return 1;
		else
			return 0;
		fi

	done
}


if [ -f $LOG_FILE ]; then
	echo 'file exist' >> LOG_FILE
else
	touch $LOG_FILE
fi

#while true
#do
#	get_cur_timeSecond
#	if [ $CurTime_S -eq 10 ]
#			
#	else
#		sleep 1;
#	fi
#done

iwpriv ra0 set SiteSurvey=0
wifi_info=`iwpriv ra0 get_site_survey`
echo $wifi_ssid
echo 'Please input ssid name'
read ssid
channal = `echo $wifi_info | grep ssid |awk '{print $1}'` 


