/*********************************************************************
 *
 * Software License Agreement (BSD License)
 *
 *  Copyright (c) 2015, Hochschule Bonn-Rhein-Sieg, Germany
 *                      Inria, France
 *  All rights reserved.
 *
 *  Redistribution and use in source and binary forms, with or without
 *  modification, are permitted provided that the following conditions
 *  are met:
 *
 *   * Redistributions of source code must retain the above copyright
 *     notice, this list of conditions and the following disclaimer.
 *   * Redistributions in binary form must reproduce the above
 *     copyright notice, this list of conditions and the following
 *     disclaimer in the documentation and/or other materials provided
 *     with the distribution.
 *   * Neither the name of Hochschule Bonn-Rhein-Sieg, Germany and Inria, 
 *     France nor the names of its contributors may be used to 
 *     endorse or promote products derived from this software without 
 *     specific prior written permission.
 *
 *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 *  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 *  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 *  FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 *  COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 *  INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 *  BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 *  LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 *  CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 *  LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 *  ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 *  POSSIBILITY OF SUCH DAMAGE.
 *
 * Author: Niranjan Vilas Deshpande
 *         (niranjan.deshpande187@gmail.com)
 *
 * Supervised by: Sven Schneider (Hochschule Bonn-Rhein-Sieg)
 *                Prof. Dr. Paul G. Ploeger (Hochschule Bonn-Rhein-Sieg)
 *		          Dr. Anne Spalanzani (Inria)
 *********************************************************************/

#ifndef _SEMANTIC_PLANNER_GLOBAL_
#define _SEMANTIC_PLANNER_GLOBAL_

#include <ros/ros.h>
#include <costmap_2d/costmap_2d_ros.h> 
#include <semantic_costmap/semantic_costmap_ros.h> 
#include <semantic_planner_global/planner_core.h>
#include <string> 
#include <semantic_planner_global/semantic_dijkstra.h>
//#include <semantic_planner_global/gradient_path.h> 
#include <sem_nav_msgs/GetPlanObject.h>
#include <global_planner/potential_calculator.h>
//#include <global_planner/expander.h>
#include <global_planner/traceback.h> 
 

using namespace global_planner;
namespace semantic_planner 
{
	

	class SemanticPlannerGlobal : public global_planner::GlobalPlanner
	{

	public:
		/**
         * @brief  Default constructor for the SemanticPlannerGlobal object
         */
		SemanticPlannerGlobal();

		/**
         * @brief  Constructor for the SemanticPlannerGlobal object
         * @param  tf A reference to a TransformListener
         */
        //SemanticPlannerGlobal(std::string name, costmap_2d::Costmap2DROS* costmap);
        SemanticPlannerGlobal(std::string name, semantic_costmap::SemanticCostmapROS* costmap);

        /**
         * @brief  Default deconstructor for the SemanticPlannerGlobal object
         */
        ~SemanticPlannerGlobal();

        void initialization(std::string name, semantic_costmap::SemanticCostmapROS* costmap);

        /**
         * @brief  A service call that will return a path for the robot
         * @param  req The goal request
         * @param  resp The plan request
         * @return True if planning succeeded, false otherwise
         */
        bool planServiceForMoveRobot(nav_msgs::GetPlan::Request &req, nav_msgs::GetPlan::Response &resp);

        /**
         * @brief  A service call that will return a path for the object to be moved
         * @param  req The goal request in the form of geometric pose and object to be pushed
         * @param  resp The plan request
         * @return True if planning succeeded, false otherwise
         */
        bool planServiceForMoveObject(sem_nav_msgs::GetPlanObject::Request &req, sem_nav_msgs::GetPlanObject::Response &resp);


        bool makePlanObjectApproach(const geometry_msgs::PoseStamped& start, const geometry_msgs::PoseStamped& goal, 
                           std::vector<geometry_msgs::PoseStamped>& plan, semantic_map::Object& object);

        bool makePlanObjectPush(const geometry_msgs::PoseStamped& start, const geometry_msgs::PoseStamped& goal, 
                           std::vector<geometry_msgs::PoseStamped>& plan, semantic_map::Object& object);

        bool makePlanObject(const geometry_msgs::PoseStamped& start, const geometry_msgs::PoseStamped& goal, 
                           std::vector<geometry_msgs::PoseStamped>& plan, semantic_map::Object& object);      


        bool getPlan(double start_x, double start_y, double goal_x, double goal_y,
                const geometry_msgs::PoseStamped& goal, std::vector<geometry_msgs::PoseStamped>& plan);

    private:
        
    	void resetCostmap();
    	//costmap_2d::Costmap2DROS* global_costmap_;
        semantic_costmap::SemanticCostmapROS* global_costmap_;
		tf::TransformListener* tf_;


		bool initialize_;

		ros::ServiceServer make_plan_robot, make_plan_object;

		std::string tf_prefix_;

		global_planner::PotentialCalculator* p_calc;
		SemanticDijkstra* semantic_planner;
        global_planner::Traceback* path_maker;
	    float* potential_array;


    };


} 
//end namespace semantic_planner
#endif 
