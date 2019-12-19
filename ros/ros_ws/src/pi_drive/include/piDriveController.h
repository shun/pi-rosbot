/*!
 * License: MIT license
 * Copyright 2019 KUDO Shunsuke
 *
 * Permission is hereby granted, free of charge, to any person obtaining
 * a copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to
 * whom the Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
 * IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,
 * DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR
 * OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE
 * OR OTHER DEALINGS IN THE SOFTWARE.
 */

#ifndef __PIDRIVECONTROLLER_H__
#define __PIDRIVECONTROLLER_H__

#include <memory>

#include "rclcpp/rclcpp.hpp"
//#include "rclcpp/node_options.hpp"
//#include "rclcpp/publisher.hpp"
#include "rclcpp_lifecycle/lifecycle_node.hpp"
#include "std_msgs/msg/int32.hpp"
#include "geometry_msgs/msg/twist.hpp"

using CallbackReturn = rclcpp_lifecycle::node_interfaces::LifecycleNodeInterface::CallbackReturn;

namespace pidrive
{
class piDriveController : public rclcpp_lifecycle::LifecycleNode
{
public:
  explicit piDriveController(const std::string & name, const rclcpp::NodeOptions & options = rclcpp::NodeOptions());

  CallbackReturn on_configure(const rclcpp_lifecycle::State & state);
  CallbackReturn on_activate(const rclcpp_lifecycle::State & state);
  CallbackReturn on_deactivate(const rclcpp_lifecycle::State & state);
  CallbackReturn on_cleanup(const rclcpp_lifecycle::State & state);
  CallbackReturn on_shutdown(const rclcpp_lifecycle::State & state);
  CallbackReturn on_error(const rclcpp_lifecycle::State & state);

private:
  void publish_pwm(const int pwm);
  void twist_callback(const geometry_msgs::msg::Twist::SharedPtr msg);

private:
  std::shared_ptr<rclcpp::Subscription<geometry_msgs::msg::Twist>> sub_cmd_vel_;

  std::shared_ptr<rclcpp_lifecycle::LifecyclePublisher<std_msgs::msg::Int32>> pub_right_motor_cmd_pwm_;

  std::shared_ptr<rclcpp_lifecycle::LifecyclePublisher<std_msgs::msg::Int32>> pub_left_motor_cmd_pwm_;
};

}  // namespace pidrive
#endif  // __PIDRIVECONTROLLER_H__
