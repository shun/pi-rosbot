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

#include "piDriveContller.h"

piDriveContller::piDriveContller(const std::string & name, const rclcpp::NodeOption & options = rclcpp::NodeOption())
{
}

CallbackReturn piDriveContller::on_configure(const rclcpp_lifecycle::State & state)
{
  pub_right_motor_cmd_pwm_ = this.create_publisher<std_msgs::msg::Int32>("right_motor/Pwm",  // topic name
                                                                         1);                 // queue size

  pub_left_motor_cmd_pwm_ = this.create_publisher<std_msgs::msg::Int32>("left_motor/Pwm",  // topic name
                                                                        1);                // queue size

  sub_cmd_vel_ = this->create_subscription<geometory_msgs::msg::Twist>(
      "geometory_msgs/msg/Twist",  // topic name
      1,                           // queue size
      std::bind(&piDriveContller::twist_callback, this, std::placeholders::_1));

  // FIXME
  // not fail to create publisher/subscriber, probably. please correct me if
  // it's wrong.
  return CallbackReturn::SUCCESS;
}

CallbackReturn piDriveContller::on_activate(const rclcpp_lifecycle::State & state)
{
  return CallbackReturn::SUCCESS;
}

CallbackReturn piDriveContller::on_deactivate(const rclcpp_lifecycle::State & state)
{
  return CallbackReturn::SUCCESS;
}

CallbackReturn piDriveContller::on_cleanup(const rclcpp_lifecycle::State & state)
{
  return CallbackReturn::SUCCESS;
}

CallbackReturn piDriveContller::on_shutdown(const rclcpp_lifecycle::State & state)
{
  return CallbackReturn::SUCCESS;
}

CallbackReturn piDriveContller::on_error(const rclcpp_lifecycle::State & state)
{
  return CallbackReturn::SUCCESS;
}

void piDriveContller::twist_callback(const geometory_msgs::msg::TwistPtr msg)
{
  int rpwm, lpwm;
  rpwm = lpwm = msg->x;

  pub_right_motor_cmd_pwm_->publish(rpwm);
  pub_left_motor_cmd_pwm_->publish(lpwm);
}
