//*************************************************************************************************
//rover-Autonomy Server
//State machine for ASTRA rover
//Last edited Sept 7, 2024
//*************************************************************************************************
//Maintained by: Daegan Brown
//Number: 423-475-4384
//Email: daeganbrown03@gmail.com
//*************************************************************************************************
//INCLUDES
//*************************************************************************************************

#include "rclcpp/rclcpp.hpp"                  //Needed for ros2 cpp 
#include "rclcpp_action/rclcpp_action.hpp"    //Needed for actions, specifically
#include "clucky_interfaces/action/auto_command.hpp"     //Use clucky_interfaces pkg


using AutoCommand = clucky_interfaces::action::AutoCommand;
using AutoCommandGoalHandle = rclcpp_action::ServerGoalHandle<AutoCommand>;
using namespace std::placeholders;

//*************************************************************************************************
// Global Variables
//*************************************************************************************************

int mission_type;
double gps_lat_target, gps_long_target, target_radius, period;

//*************************************************************************************************
// Server Nodes 
//*************************************************************************************************

// Primary Server Node
class AutoServerNode : public rclcpp::Node
{
    public:
        AutoServerNode() : Node("astra_auto_server")
        {
            astra_auto_server_ = rclcpp_action::create_server<AutoCommand>(
                this,
                "auto_command",
                std::bind(&AutoServerNode::goal_callback, this, _1, _2),
                std::bind(&AutoServerNode::cancel_callback, this, _1),
                std::bind(&AutoServerNode::handle_accepted_callback, this, _1)

                
            );
            RCLCPP_INFO(this->get_logger(), "Action server has been started uWu");
        }

    private:

        // Response Behavior
        rclcpp_action::GoalResponse goal_callback(
            const rclcpp_action::GoalUUID &uuid, std::shared_ptr<const AutoCommand::Goal> goal)
            {
                // Get rid of STDR outputs
                (void)uuid;
                (void)goal;

                return rclcpp_action::GoalResponse::ACCEPT_AND_EXECUTE;
            }

        // Cancel Behavior
        rclcpp_action::CancelResponse cancel_callback(
            const std::shared_ptr<AutoCommandGoalHandle> goal_handle)
            {
                // Get rid of STDR outputs
                (void)goal_handle;
                return rclcpp_action::CancelResponse::ACCEPT;
            }

        // Seems redundant
        void handle_accepted_callback(
            const std::shared_ptr<AutoCommandGoalHandle> goal_handle) 
            {
                // Pull request data from .action into global variables
                message_variable = goal_handle->get_goal()->message_variable;
                

                RCLCPP_INFO(this->get_logger(), "Executing the goal");
                execute_goal(goal_handle);
            }

        // Actual Code that runs when doing action request
        void execute_goal(
            const std::shared_ptr<AutoCommandGoalHandle> goal_handle)
            {
                
                // I dont remember why this is needed
                rclcpp::Rate loop_rate(2.0/period);

                //*********************************************************************************
                //                               FAKE PLACEHOLDER
                //*********************************************************************************
                int counter = 0;
                
                for (int i = 0; i < message_variable; i++)
                {
                    counter++;
                    RCLCPP_INFO(this->get_logger(), "%d", counter);
                    loop_rate.sleep();
                }
                //*********************************************************************************
                //                              END FAKE PLACEHOLDER
                //*********************************************************************************


                // Set final state and return result
                auto result = std::make_shared<AutoCommand::Result>();
                result->final_result = counter;
                goal_handle->succeed(result);
            }

        rclcpp_action::Server<AutoCommand>::SharedPtr astra_auto_server_;
        };



//*************************************************************************************************
// Main
//*************************************************************************************************

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<AutoServerNode>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}