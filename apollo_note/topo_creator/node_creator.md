##_h


##_c
###function
```objectivec
void InitNodeInfo();
```

```objectivec
void InitNodeInfo(){
    double lane_length = GetLaneLength(lane);
    node->set_lane_id(lane.id().id());
    node->set_road_id(road_id);
    AddOutBoundary(lane.left_voundary(), lane_length, node->mutable_left_out());
    AddOutBoundary(lane.right_);
    
}
```