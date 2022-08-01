# review of literature

## TECHNICAL TERMS

1. SPEED: Speed is the amount of distance per unit time at which the robot can move,
usually specified in inches per second or meters per second. The speed is usually
specified at a specific load or assuming that the robot is carrying a fixed weight. Actual
speed may vary depending upon the weight carried by the robot.
2. LOAD BEARING CAPACITY: Load bearing capacity is the maximum weightcarrying capacity of the robot. Robots that carry large weights, but must still be precise
are expensive.
3. ACCURACY: Accuracy is the ability of a robot to go to the specified position
without making a mistake. It is impossible to position a machine exactly. Accuracy is
therefore defined as the ability of the robot to position itself to the desired location with
the minimal error (usually 0.001 inch).
4. REPEATABILITY: Repeatability is the ability of a robot to repeatedly position itself
when asked to perform a task multiple times. Accuracy is an absolute concept,
repeatability is relative. Note that a robot that is repeatable may not be very accurate.
Likewise, an accurate robot may not be repeatable.
5. WORK ENVELOPE: Work envelope is the maximum robot reach, or volume within
which a robot can operate. This is usually specified as a combination of the limits of each
of the robot's parts. The figure below shows how a work-envelope of a robot is
documented.
6. WORKCELLS: Robots seldom function in an isolated environment. In order to do
useful work, robots must coordinate their movements with other machines and
equipment, and possibly with humans. A group of machines/equipment positioned with a
robot or robots to do useful work is termed a workcell. For example, a robot doing
welding on an automotive assembly line must coordinate with a conveyor that is moving
the car-frame and a laser-positioning / inspection robot that uses a laser beam to locate
the position of the weld and then inspect the quality of the weld when it is complete

## ROBOT ANATOMY
As mentioned in the introduction to the chapter, the manipulator or robotic arm
has many similarities to the human body. The mechanical structure of a robot is like the
skeleton in the human body. The robot anatomy is, therefore, the study of skeleton of
robot, that is, the physical construction of the manipulator structure.
The mechanical structure of a manipulator that consists of rigid bodies (links)
connected by means of articulations (joints), is segmented into an arm that ensures
mobility and reachability, a wrist that confers orientation, and an end- effector that
performs the required task. Most manipulators are mounted on a base fastened to the
floor or on the mobile platform of an autonomous guided vehicle (AGV). The
arrangement of base, arm, wrist, and end-effector is shown in Fig


fig 2.1 [link](https://external-content.duckduckgo.com/iu/?u=https%3A%2F%2F1.bp.blogspot.com%2F-2tCb80AtMQ4%2FXAjrt0gFkoI%2FAAAAAAAAkFg%2FG2ZmpHdrb_oZgRIIk9KcATZ1yvgtjsAvACLcBGAs%2Fs1600%2FNew%252BDoc%252B2018-12-06%252B14.39.26_1.jpg&f=1&nofb=1)
![alt](https://external-content.duckduckgo.com/iu/?u=https%3A%2F%2F1.bp.blogspot.com%2F-2tCb80AtMQ4%2FXAjrt0gFkoI%2FAAAAAAAAkFg%2FG2ZmpHdrb_oZgRIIk9KcATZ1yvgtjsAvACLcBGAs%2Fs1600%2FNew%252BDoc%252B2018-12-06%252B14.39.26_1.jpg&f=1&nofb=1)

### LINKS
The mechanical structure of a robotic manipulator is a mechanism, whose
members are rigid links or bars.

A rigid link that can be connected, at most, with two
other links is referred to as a binary link. Figure 2.2 shows two rigid binary "links, 1 and
2, each with two holes at the ends A, B, and C, D, respectively to connect with each other
or to other links.
Two links are connected together by a joint. By putting a pin through holes B and
C of links 1 and 2, an open kinematic chain is formed as shown in Fig. 2.3. The joint
formed is called a pin joint also known as a revolute or rotary joint.
12
Relative rotary motion between the links is possible and the two links are said to
be paired. In Fig. 2.3 links are represented by straight lines and rotary joint by a small
circle.
[fig2.2](https://4.bp.blogspot.com/-5RyiLkj0nM4/XAjsKxugVRI/AAAAAAAAkF0/uYdHYxOnMJ03zDuaZRRRXcYgBbh0GaWJgCLcBGAs/s1600/New%2BDoc%2B2018-12-06%2B14.39.26_2.jpg)

![fig2.2](https://4.bp.blogspot.com/-5RyiLkj0nM4/XAjsKxugVRI/AAAAAAAAkF0/uYdHYxOnMJ03zDuaZRRRXcYgBbh0GaWJgCLcBGAs/s1600/New%2BDoc%2B2018-12-06%2B14.39.26_2.jpg)

[fig2.3](https://3.bp.blogspot.com/-xq1iGUCKpUs/XAjrtrb5dDI/AAAAAAAAkFc/ORRRlra2inYnK4M1DJGMrMO3R51E3goXQCLcBGAs/s1600/New%2BDoc%2B2018-12-06%2B14.39.26_3.jpg)

![alt](https://3.bp.blogspot.com/-xq1iGUCKpUs/XAjrtrb5dDI/AAAAAAAAkFc/ORRRlra2inYnK4M1DJGMrMO3R51E3goXQCLcBGAs/s1600/New%2BDoc%2B2018-12-06%2B14.39.26_3.jpg)

### JOINTS AND JOINT NOTATION SCHEME

Many types of joints can be made between two links. However, only two basic
types are commonly used in industrial robots. 
These are:
* Revolute (R)
* Prismatic (P)
  
The relative motion of the adjoining links of a joint is either rotary or linear
depending on the type of joint. Revolute joint: It is sketched in Fig. 2.4(a). The two links
are joined by a pin (pivot) about the axis of which the links can rotate with respect to
each other. Prismatic join': It is sketched in Fig. 2.4(b). The two links are so jointed that
these can slide (linearly move) with respect to each other. Screw and nut (slow linear
motion of the nut), rack and pinion are ways to implement prismatic joints.
13
Other types of possible joints used are: planar (one surface sliding over another
surface); cylindrical (one link rotates about the other at 90° angle. Fig. 2.4) and spherical
(one link can move with respect to the other in three dimensions). Yet another variant of
rotary joint is the 'twist' joint, where two links remain aligned along a straight line but one
turns (twists) about the other around the link axis, Fig. 2.4(d).
At a joint, links are connected such that they can be made to move relative to each
other by the actuators. A rotary joint allows a pure rotation of one link relative to the
connecting link and prismatic joint allows a pure translation of one link relative 10 the
connecting link.

[2.4](https://image.slidesharecdn.com/mechatronics4-150326002145-conversion-gate01/95/mechatronics-4-8-638.jpg?cb=1427346140)

![alt](https://image.slidesharecdn.com/mechatronics4-150326002145-conversion-gate01/95/mechatronics-4-8-638.jpg?cb=1427346140)

The kinematic chain formed by joining two links is extended by connecting more
links. To form a manipulator one end of the chain is connected to the base or ground with
a joint. Such a manipulator is an open kinematic chain. The end-effector is connected to
the free end of the last link as illustrated ill Fig. 1.5. Closed kinematic chains are used in
special purpose manipulators such as parallel manipulators to create certain kind of
motion of the end-effector. The kinematic chain of the manipulator is characterized by
the degrees of freedom it has and the space its end-effector can sweep. These parameters
are discussed in next sections.

### DEGREES OF FREEDOM (DOF)

The number of independent movements that an object can perform in a 3-D space
is called the number of degrees of freedom (DOF). Thus a rigid body free in space has six
degrees of freedom- three for position and three for orientation.
These six independent movements pictured in Fig. 2.5 are:
14
(i) Three translations (T1, T2, T3), representing linear motions along three perpendicular
axes, specify the position of the body in space.
(ii) Three rotations (R1, R2, R3), which represent angular motions about the three axes
specify the orientation of the body in space.
Note from the above that six independent variables are required to specify the
location (position and orientation) of an object in 3-D space, that is. 2 x 3 = 6.
Nevertheless, in a 2-D space (a plane), an object has 3-DOF-two translator and one
rotational. For instance, link 1 and link 2 in Fig. 2.2 have 3-DOF each.

Consider an open kinematic chain of two links with revolute joints at A and B (or
C), as shown in Fig. 2.6. Here, the first link is connected to the ground by a joint at A.
Therefore, link I can only rotate about joint I (J I) with respect to ground and contributes
one independent variable (an angle), or in other words, it contributes one degree of
freedom. Link 2 can rotate about joint 2 (12 respect to link 1, contributing another
independent variable and so another DOF.
Thus, by induction, conclude that an open kinematic chain with one end
connected to the ground by a joint and the farther end of the last link free has as many degrees of freedom as the number of joints in the chain. It is assumed that each joint has
only one DOF.
The DOF is also equal to the number of links in the open kinematic chain. For
example, in Fig. 2.6, the open kinematic chain manipulator with two DOF has two links
and two joints.
The variable defining the motion of a link at a joint is called a joint-link variable.
Thus, for an n-DOF manipulator n independent joint-link variables are required to
completely specify the location (position and orientation) of each link (and joint),
specifying the location of the end-effector in space. Thus, for the two-link, in turn, 2-
DOF manipulator in Fig. 2.6, two variables are required to define location of end-point,
point D.

### ARM CONFIGURATION

The mechanics of the arm with 3-DOF depends on the type of three joints
employed and their arrangement. The purpose of the arm is to position the wrist in the 3-
D space and the arm bas following characteristic requirements.
• Links are long enough to provide for maximum reach in the space.
• The design is mechanically robust because the arm has to bear not only the load of
workpiece but also has to carry the wrist and the end-effector.
According to joint movements and arrangement of links, four well-distinguished
basic structural configurations are possible for the arm. These are characterized by the
distribution of three arm joints among prismatic and rotary joints, and arc named
according to the coordinate system employed or the shape of the space they sweep. The
four basic configurations arc:
1. Cartesian (rectangular) configuration - all three P joints.
2. Cylindrical configuration - one R and two P joints.
3. Polar (spherical) configuration - two R and one P joint.
4. Articulated (Revolute or Jointed-arm) Configuration - all three R-joints.

### THE END-EFFECTOR

The end-effector is external to the manipulator and its DOF do not combine with
the manipulator's DOF, as they do not contribute to manipulatability. Different endeffectors can be attached to the end of the wrist according to the task to be executed.
These can be grouped into two major categories:
1. Grippers
2. Tools

Grippers are end-effectors to grasp or hold the workpiece during the work cycle.
The applications include material handling, machine loading-unloading, pelletizing, and
other similar operations. Grippers employ mechanical grasping or other alternative ways
such as magnetic, vacuum, bellows, or others for holding objects. The proper shape and
size of the gripper and the method of holding are determined by the object to be grasped
and the task to be performed

For many tasks to be performed by the manipulator, the end-effector is a tool
rather than a gripper. For example, a cutting tool, a drill. a welding torch. a spray gun, or
a screwdriver is the end-effector for machining, welding, painting, or assembly task,
mounted at the wrist endpoint The tool is usually directly attached to the end of the wrist.
Sometimes, a gripper may be used to hold the tool instead of the workpiece. Tool changer
devices can also be attached to the wrist end for multi-tool operations in a work cycle


