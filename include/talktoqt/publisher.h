#ifndef PUBLISHER
#define PUBLISHER

#include <chrono>
#include <functional>
#include <memory>
#include <string>

#include <rclcpp/rclcpp.hpp>
#include "std_msgs/msg/string.hpp"


#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <iostream>


#define PORT 3000


class MinimalPublisher : public rclcpp::Node
{

public:
  MinimalPublisher();

private:
  void timer_callback(void);
  rclcpp::TimerBase::SharedPtr timer_;
  rclcpp::Publisher<std_msgs::msg::String>::SharedPtr publisher_;
  size_t count_;
  void SendSocket(const char*);
};


#endif /* PUBLISHER */
