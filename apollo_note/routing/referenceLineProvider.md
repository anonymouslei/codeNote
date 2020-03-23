## ReferenceLineProvider
参考线提供器主要完成的工作是计算车辆在规划路径上的短期可行路径。在控制规划地图pnc Map
中，有一个功能是路径段routeSegments生成最终路径Path，这个Path就是车辆在规划
路径上的可行路径，但是路径是以`std::vector<common::math::LineSegment2d>`和
`std::vector<MapPathPoint> path_points_` 的离散形式存在的。本节参考线提供器就是
对上述的Path进行样条函数Spline插值。

主要步骤：
1. 路径点采样与轨迹点矫正
2. knots分段与二次规划进行参考线平滑

除了参考线平滑，参考线提供器还提供参考线拼接的功能。

### 参考线平滑：路径点采样与轨迹点矫正
控制规划地图Pnc Map根据当前车辆状态与Routing模块规划路径相应可以得到

### 参考线平滑：knots分段与二次规划进行参考线平滑
主要思路是：将anchor_point分成n组，每组用一个多项式函数去拟合，可以得到n个多项式汉书。

$$ x' = f_i(s) = a_{i0} + a_{i1}s + a_{i2}s^2 +a_{i3}s^3 + a_{i4}s^4 + a_{i5}s^5 $$

$$ y' = g_i(s) = b_{i0} + b_{i1}s + b_{i2}s^2 +b_{i3}s^3 + b_{i4}s^4 + b_{i5}s^5 $$

Reference Line Smoother
1. Objective Function
1.1 Segment routing function
segment routing path into n segments. each segment trajectory is defined by two polynomials
1.2 define objective function of optimization for each segment
for example: minial snap
    ？不需要考虑和参考线的距离吗？
1.3 convert  the cost function to QP formulation
2. constraints
2.1 Joint smoothness constraints
    this constraint smoothes the spline joint. Let's assume two segments.

