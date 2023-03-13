#include "ros/ros.h"
#include "sensor_msgs/PointCloud2.h"
#include "std_msgs/Header.h"

std::vector<double> sliding_value(100,0.0);
int counter = 0;

int packet_size = 1000000;

int main(int argc, char **argv)
{
    ros::init(argc, argv, "latency_checker");
    ros::NodeHandle n;
    ros::Publisher pub = n.advertise<sensor_msgs::PointCloud2>("/data", 1000);

    ros::Rate rate(60);

    sensor_msgs::PointCloud2 cloud;
    //cloud.header.stamp = ros::Time::now();

    for(int i = 0; i < packet_size; i++)
    {
        cloud.data.push_back((uint8_t)1);
    }

    while(ros::ok())
    {
        cloud.header.stamp = ros::Time::now();
        pub.publish(cloud);
        ros::spinOnce();
        rate.sleep();
    }
    ros::spin();
}