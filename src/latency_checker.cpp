#include "ros/ros.h"
#include "sensor_msgs/PointCloud2.h"
#include "std_msgs/Header.h"

std::vector<double> sliding_value(10,0.0);
int counter = 0;

void callback(const sensor_msgs::PointCloud2::ConstPtr& msg)
{
   //ros::Time::now()

    ros::Duration latency = ros::Time::now() - msg->header.stamp;

    double dd = latency.toSec();

    sliding_value[counter++] = latency.toSec();
    ROS_INFO("COUNTER IS %d", counter);
    counter = counter%10;

    double avg_latency = 0;
    for(int i =0; i < 10; i++)
    {
        avg_latency += sliding_value[i];
    }
    avg_latency = avg_latency / 10.0;

   ROS_INFO("LATENCY IS %f", avg_latency);

}

int main(int argc, char **argv)
{
    ros::init(argc, argv, "latency_checker");
    ros::NodeHandle n;
    ros::Subscriber sub = n.subscribe("/data", 1000, callback);
    ros::spin();
}