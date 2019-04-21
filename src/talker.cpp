#include "ros/ros.h"
#include "std_msgs/String.h"

/**
 * ROSのシンプルなメッセージ送信プログラム(Publisher)
 */
int main(int argc, char **argv) {
  ros::init(argc, argv, "talker");
  ros::NodeHandle nh;
  ros::Publisher pub = nh.advertise<std_msgs::String>("chatter", 100);
    /* chatterトピックにバッファサイズ100で配信開始 */
  ros::Rate loop_rate(10); /* 1秒間に10回(10Hz)の頻度で実行 */

  while (ros::ok()) {
    std_msgs::String msg;
    msg.data = "Hello world!";
    ROS_INFO(msg.data.c_str()); /* 標準出力にメッセージを出力 */
    pub.publish(msg); /* chatterトピックにメッセージを配信 */
    ros::spinOnce();
    loop_rate.sleep();
  }
}
