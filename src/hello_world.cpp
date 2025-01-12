#include <rclcpp/rclcpp.hpp>


int main(int argc, char** argv)
{
    // プロセスの初期化
    rclcpp::init(argc, argv);
    // ノードの初期化
    auto node = rclcpp::Node::make_shared("hello_world_node");
    // ループ間隔を1Hzに設定
    rclcpp::WallRate loop(1);
    // Ctrl + C が押されるまでループ
    while(rclcpp::ok())
    {
        RCLCPP_INFO(node->get_logger(), "Hello World!");
        loop.sleep();   //ループ周期が1Hzとなるよう時間調整
    }
    // プロセスの終了
    rclcpp::shutdown();
    return 0;
}
