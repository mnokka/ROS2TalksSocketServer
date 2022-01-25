// Copyright 2016 Open Source Robotics Foundation, Inc.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.


#include "publisher.h"

using namespace std::chrono_literals;

/* This example creates a subclass of Node and uses std::bind() to register a
 * member function as a callback from the timer. */

MinimalPublisher::MinimalPublisher()
: Node("minimal_publisher"), count_(0)
{
  publisher_ = this->create_publisher<std_msgs::msg::String>("topic", 10);
  timer_ = this->create_wall_timer(500ms, std::bind(&MinimalPublisher::timer_callback, this));
}

void MinimalPublisher::timer_callback(void)
{

	static int randnumber;
	static int counter=0;
	/* initialize random seed: */
	srand (time(NULL));

  /* generate secret number between 1 and 100: */
  randnumber = rand() % 100 + 1;
  auto message = std_msgs::msg::String();
 // message.data = "Messaging messaging " + std::to_string(count_++);
  message.data = std::to_string(count_++) + ": Measured temperature: " + std::to_string(randnumber);
  RCLCPP_INFO(this->get_logger(), "First publisher.Publishing: '%s'", message.data.c_str());
  publisher_->publish(message);
  if (counter>5) {
	  SendSocket(message.data.c_str());
	  counter=0;
  }
  counter++;

}


void MinimalPublisher::SendSocket(const char *message) {
	printf("SendSocket called ....\n");
	std::cout << "ROS2 message passed to socket server: " << message <<"\n";

	static int sock = 0;//, valread;

	static struct sockaddr_in serv_addr;
	char buffer[1024] = {0};

	if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0)
			{
				printf("\n CLIENT ERROR: Socket creation error \n");
				return ;
			}

	serv_addr.sin_family = AF_INET;
	serv_addr.sin_port = htons(PORT);

	// Convert IPv4 and IPv6 addresses from text to binary form
	if(inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr)<=0)
			{
				printf("\nCLIENT ERROR: Invalid address/ Address not supported \n");
				return;
			}

	if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
			{
				printf("\nCLIENT ERROR: Connection Failed \n");
				return;
			}

	send(sock , message , strlen(message) , 0 );
	//valread = read( sock , buffer, 1024);
	printf("%s\n",buffer );
    std::cout << "--------------------------------------------------------------------------------------------\n";

}

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<MinimalPublisher>());
  rclcpp::shutdown();
  return 0;
}
