#include <rclcpp/rclcpp.hpp>


int main(int argc, char** argv)
{
    // プロセスの初期化
    rclcpp::init(argc, argv);   //ROS2 プログラムの初期化を行う関数．プログラムの最初に呼び出す必要がある
    // ノードの初期化
    auto node = rclcpp::Node::make_shared("hello_world_node");  //ノードとして他のノードと通信を行うためのクラス.make_shared メソッドを用いてスマートポインタとしてインスタンスを生成する．コンストラクタにはノード名を string 型で与える．
    // ループ間隔を1Hzに設定
    rclcpp::WallRate loop(1);   //ループ間隔を調整するためのクラス ．コンストラクタでループの周期[Hz]を指定する．
    // Ctrl + C が押されるまでループ
    while(rclcpp::ok()) //[rclcpp::ok]プロセスが実行中かどうかを判別する関数．
    {
        RCLCPP_INFO(node->get_logger(), "Hello World!");    //printf のように文字列を表示するマクロ． printf とほぼ同じフォーマット指定が可能．
        //ループ周期が1Hzとなるよう時間調整
        loop.sleep();     //sleep メソッドを呼び出すと，ループ周期が設定された周期になるように調整する．なお，ループ内の処理が重く，ループ周期を超えた場合，sleep メソッドを呼び出してもウイトをかけずにループを再開する．
    }
    // プロセスの終了
    rclcpp::shutdown();     //実行している ROS プロセスの終了処理を行う．プログラム終了時に必ず記述する．
    return 0;
}
