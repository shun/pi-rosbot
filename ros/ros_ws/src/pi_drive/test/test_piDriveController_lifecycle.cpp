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

#include "gtest/gtest.h"
#include "rclcpp/rclcpp.hpp"

TEST(TestPiDriveControllerLifecycle, Unconfigured)
{
  if (!rclcpp::ok())
  {
    rclcpp::init(0, nullptr);
  }
  ASSERT_EQ(1, 0);
}

TEST(TestPiDriveControllerLifecycle, Cleaningup)
{
  if (!rclcpp::ok())
  {
    rclcpp::init(0, nullptr);
  }
  ASSERT_EQ(1, 0);
}

TEST(TestPiDriveControllerLifecycle, Configureing)
{
  if (!rclcpp::ok())
  {
    rclcpp::init(0, nullptr);
  }
  ASSERT_EQ(1, 0);
}

TEST(TestPiDriveControllerLifecycle, Inactive)
{
  if (!rclcpp::ok())
  {
    rclcpp::init(0, nullptr);
  }
  ASSERT_EQ(1, 0);
}

TEST(TestPiDriveControllerLifecycle, Deactivating)
{
  if (!rclcpp::ok())
  {
    rclcpp::init(0, nullptr);
  }
  ASSERT_EQ(1, 0);
}

TEST(TestPiDriveControllerLifecycle, Activating)
{
  if (!rclcpp::ok())
  {
    rclcpp::init(0, nullptr);
  }
  ASSERT_EQ(1, 0);
}

TEST(TestPiDriveControllerLifecycle, Active)
{
  if (!rclcpp::ok())
  {
    rclcpp::init(0, nullptr);
  }
  ASSERT_EQ(1, 0);
}

TEST(TestPiDriveControllerLifecycle, ShuttingDown)
{
  if (!rclcpp::ok())
  {
    rclcpp::init(0, nullptr);
  }
  ASSERT_EQ(1, 0);
}

TEST(TestPiDriveControllerLifecycle, ErrorProcessing)
{
  if (!rclcpp::ok())
  {
    rclcpp::init(0, nullptr);
  }
  ASSERT_EQ(1, 0);
}

TEST(TestPiDriveControllerLifecycle, Finalized)
{
  if (!rclcpp::ok())
  {
    rclcpp::init(0, nullptr);
  }
  ASSERT_EQ(1, 0);
}
