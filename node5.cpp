/*
  * toragi_pkg1/パッケージのnode1の実装
  *    node5を出版者として生成し.topic3にデータを送信する。
  *    topic3は独自形式のHuman型
*/
#include "ros/ros.h"
#include "toragi_pkg1/Human.h"

#include <iostream>
using namespace std;

int main(int argc, char **argv)
{
  ros::init(argc, argv, "node5");
  ros::NodeHandle nh;
  ros::Publisher pub = nh.advertise<toragi_pkg1::Human>("topic3", 1000);

  ros::Rate loop_rate(0.2);

  while(ros::ok())
  {
    toragi_pkg1::Human msg;
    cout << "Enter Name [str]:" << endl;
    cin >> msg.name;
    cout << "Enter Height [int/cm]:" << endl;
    cin  >> msg.height;
    cout << "Enter Weight [float/kg]:" << endl;
    cin >> msg.weight;

    ROS_INFO("published info:");
    ROS_INFO("   name: %s height: %d weight: %.2f", msg.name.c_str(), msg.height, msg.weight);



    pub.publish(msg);

    ros::spinOnce();
    loop_rate.sleep();


  }
  return 0;

}
