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

#include "piDriveController.h"

namespace pidrive
{
piDriveController::piDriveController(const std::string & name, const rclcpp::NodeOptions & options)
  : rclcpp_lifecycle::LifecycleNode(name, options)
{
  pub_right_motor_cmd_pwm_ = this->create_publisher<std_msgs::msg::Int32>("right_motor/Pwm",  // topic name
                                                                          1);                 // queue size

  pub_left_motor_cmd_pwm_ = this->create_publisher<std_msgs::msg::Int32>("left_motor/Pwm",  // topic name
                                                                         1);                // queue size

  sub_cmd_vel_ = this->create_subscription<geometry_msgs::msg::Twist>(
      "geometry_msgs/msg/Twist",  // topic name
      1,                          // queue size
      std::bind(&piDriveController::twist_callback, this, std::placeholders::_1));

  // FIXME
  // not fail to create publisher/subscriber, probably. please correct me if
  // it's wrong.
}

CallbackReturn piDriveController::on_activate(const rclcpp_lifecycle::State & state)
{
  RCLCPP_INFO(get_logger(), "on_activate");

  return CallbackReturn::SUCCESS;
}

CallbackReturn piDriveController::on_deactivate(const rclcpp_lifecycle::State & state)
{
  RCLCPP_INFO(get_logger(), "on_deactivate");

  return CallbackReturn::SUCCESS;
}

CallbackReturn piDriveController::on_cleanup(const rclcpp_lifecycle::State & state)
{
  RCLCPP_INFO(get_logger(), "on_cleanup");

  return CallbackReturn::SUCCESS;
}

CallbackReturn piDriveController::on_shutdown(const rclcpp_lifecycle::State & state)
{
  RCLCPP_INFO(get_logger(), "on_shutdown");

  return CallbackReturn::SUCCESS;
}

CallbackReturn piDriveController::on_error(const rclcpp_lifecycle::State & state)
{
  RCLCPP_INFO(get_logger(), "on_error");

  return CallbackReturn::SUCCESS;
}

void piDriveController::twist_callback(const geometry_msgs::msg::Twist::SharedPtr msg)
{
  RCLCPP_INFO(get_logger(), "on_activate");

  std_msgs::msg::Int32 rpwm, lpwm;
  rpwm.data = lpwm.data = msg->linear.x;

  pub_right_motor_cmd_pwm_->publish(rpwm);
  pub_left_motor_cmd_pwm_->publish(lpwm);
}
}  // namespace pidrive
