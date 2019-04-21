#include "ros/ros.h"
#include "std_msgs/String.h"

/**
 * ROSのシンプルなメッセージ受信プログラム(Subscriber)
 */
void chatterCallback(const std_msgs::String::ConstPtr& msg) {
  /* chatterトピックを購読したときに呼ばれる処理 */

  ROS_INFO("I heard: [%s]", msg->data.c_str());
    /* 受信したメッセージを標準出力に表示 */
}

int main(int argc, char **argv) {
  ros::init(argc, argv, "listener");
  ros::NodeHandle nh;
  ros::Subscriber sub = nh.subscribe("chatter", 100, chatterCallback);
    /* chatterトピックをバッファサイズ100で購読開始 */
  ros::spin();
}
