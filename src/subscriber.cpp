#include "ros/ros.h"
#include "sensor_msgs/PointCloud2.h"
#include "std_msgs/Header.h"

std::vector<double> sliding_value(100,0.0);
int counter = 0;

void callback(sensor_msgs::PointCloud2 cloud)
{
	//Messages.std_msgs.Time t = ROS.GetTime();
	//t.data.sec += 18000;


	double cloud_time = cloud.header.stamp.data.sec + (cloud.header.stamp.data.nsec / 1000000000.0);

	double current_time = t.data.sec + (t.data.nsec / 1000000000.0);

	double latency = current_time - cloud_time;

	Debug.Log("Current latency is "+  latency);
}

int main(int argc, char **argv)
{
    ros::init(argc, argv, "latency_checker");
    ros::NodeHandle n;
    ros::Subscriber sub = n.subscribe("/data", 1000);

    ros::spin();
}
