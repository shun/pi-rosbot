### Topic flow

```dot
digraph G {
  start [shape = Mcircle];

  start -> drive_ctrl [label = " geometry_msgs/Twist"];

  subgraph "cluster_pkg_pi_drive" {
    label = "pkg-pi-drive";
    bgcolor = "lightgrey";
    labelloc = "t";
    labeljust = "l";
    drive_ctrl   [shape = box, fillcolor = "white", style = "rounded, filled", label = "pi-drive-controller-node"];
    motor_r_ctrl [shape = box, fillcolor = "white", style = "rounded, filled", label = "pi-right-motor-controller-node"];
    motor_l_ctrl [shape = box, fillcolor = "white", style = "rounded, filled", label = "pi-left-motor-controller-node"];

    drive_ctrl -> motor_r_ctrl [label = " right_motor/Pwm"];
    drive_ctrl -> motor_l_ctrl [label = " left_motor/Pwm"];
  };
}
```

---

### Class diagram

```plantuml
@startuml

class piDriveControl
class piMotorControlBase
class piMotorControlRight
class piMotorControlLeft

piDriveControl *-up- piMotorControlRight
piDriveControl *-up- piMotorControlLeft
piMotorControlBase <|-- piMotorControlRight
piMotorControlBase <|-- piMotorControlLeft

@enduml
```

---

### Responsibility

| Node | Responsibility|
| :--- | :--- |
|piDriveControll| convert cmd_vel to PWM. |
|piMotorControll| - write PWM parameter to gpio. |
