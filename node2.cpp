/*
  * toragi_pkg1 パッケージのnode2の実装
  *   node2を購読者として生成し、topic1からのデータを受信する。
  *    追加テキスト
  *   topic1は文字列型String
  */
#include "ros/ros.h"
#include "std_msgs/String.h"

void topiclCallback(const std_msgs::String::ConstPtr &msg)
 {
  std::string node_name = ros::this_node::getName();
  ROS_INFO("%s heard: [%s]", node_name.c_str(), msg->data.c_str());
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "node2");

  ros::NodeHandle nh;
  ros::Subscriber sub = nh.subscribe("topic1", 1000, topiclCallback);

  ros::spin();
  return 0;

}
