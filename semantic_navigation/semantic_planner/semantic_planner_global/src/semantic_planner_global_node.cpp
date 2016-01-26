/*********************************************************************
*
* Software License Agreement (BSD License)
*
* Copyright (c) 2008, Willow Garage, Inc.
* All rights reserved.
*
* Redistribution and use in source and binary forms, with or without
* modification, are permitted provided that the following conditions
* are met:
*
* * Redistributions of source code must retain the above copyright
* notice, this list of conditions and the following disclaimer.
* * Redistributions in binary form must reproduce the above
* copyright notice, this list of conditions and the following
* disclaimer in the documentation and/or other materials provided
* with the distribution.
* * Neither the name of the Willow Garage nor the names of its
* contributors may be used to endorse or promote products derived
* from this software without specific prior written permission.
*
* THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
* "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
* LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
* FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
* COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
* INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
* BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
* LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
* CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
* LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
* ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
* POSSIBILITY OF SUCH DAMAGE.
*
* Author: Niranjan Deshpande
*********************************************************************/

#include <ros/ros.h>
//#include <semantic_planner_global/planner_core.h>
#include <semantic_planner_global/semantic_planner_global.h>

#include <costmap_2d/costmap_2d_ros.h>
#include <costmap_2d/costmap_2d.h>


int main(int argc, char** argv)
{
	ros::init(argc, argv, "semantic_planner_global");

	tf::TransformListener tf(ros::Duration(10));

    //costmap_2d::Costmap2DROS* global_costmap_ = new costmap_2d::Costmap2DROS("global_costmap", tf);
    //global_planner::GlobalPlanner global_planner("planner", global_costmap_->getCostmap(), global_costmap_->getGlobalFrameID());

    //semantic_planner::SemanticPlannerGlobal global_planner( &tf );
    
    //costmap_2d::Costmap2DROS* planner_costmap_ros, *controller_costmap_ros_;

    //create the ros wrapper for the planner's costmap... and initializer a pointer we'll use with the underlying map
    //planner_costmap_ros = new costmap_2d::Costmap2DROS("global_costmap", tf);

    //ROS_INFO_STREAM(planner_costmap_ros);

    //create the ros wrapper for the controller's costmap... and initializer a pointer we'll use with the underlying map
    //controller_costmap_ros_ = new costmap_2d::Costmap2DROS("local_costmap", tf);

    //move_object::PushAction push_action(&tf, planner_costmap_ros, controller_costmap_ros_);

    //ROS_INFO_STREAM(goal_);

    //we'll send a goal to the robot to move 1 meter forward
    //goal.target_pose.header.frame_id = "base_link";
    //goal.target_pose.header.stamp = ros::Time::now();
   
    //goal.point.x = 1.0;
    //goal.point.y = 1.0;


    ros::spin();

    

    return(0);

}