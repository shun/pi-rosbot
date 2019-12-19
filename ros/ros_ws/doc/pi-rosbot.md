### Topic flow

```dot
digraph G {
  start [shape = Mcircle];

  start -> drive_ctrl [label = " geometry_msgs/msg/Twist"];

  subgraph "cluster_pkg_pi_drive" {
    label = "pkg: pidrive";
    bgcolor = "lightgrey";
    labelloc = "t";
    labeljust = "l";
    drive_ctrl   [shape = box, fillcolor = "white", style = "rounded, filled", label = "piDriveController_node"];
    motor_r_ctrl [shape = box, fillcolor = "white", style = "rounded, filled", label = "piRightMotorController-node"];
    motor_l_ctrl [shape = box, fillcolor = "white", style = "rounded, filled", label = "piLeftMotorController-node"];

    drive_ctrl -> motor_r_ctrl [label = " right_motor/Pwm"];
    drive_ctrl -> motor_l_ctrl [label = " left_motor/Pwm"];
  };
}
```

---

### Class diagram

```plantuml
@startuml

class piDriveController
class piMotorController

piDriveController "1" *-up- "2" piMotorController

@enduml
```

---

### Responsibility

| Node | Responsibility|
| :--- | :--- |
|piDriveControll| convert cmd_vel to PWM. |
|piMotorControll| - write PWM parameter to gpio. |
