##_h

### class
```objectivec
class Strategy{
    virtual bool Search() = 0;
}

class AStarStrategy: public Strategy {
public:
    virtual bool Search();

private:
    void clear();
    double HeuristicCost();
    double GetResidualS();  - ?

private:
    bool change_lane_enabled_;
    std::unordered_set<const TopoNode*> open_set_;
    std::unordered_set<const TopoNode*> closed_set_; - 注意这里用的是const TopoNode
    std::unordered_set<const TopoNode*, const TopoNode*> came_from_;
    std::unordered_map<const TopoNode*, double> g_score_;
    std::unordered_map<const TopoNode*, double> enter_s_; - ?    

}

```
### note
- 自己的AStarStrategy也可以加入**change_lane_enabled**, but how?

##_c
### function
```objectivec
GetCostToNeighbor()
bool AdjustLaneChangeForward()
bool AdjustLaneChange()
void Clear() - 可以借鉴一下
bool Search()

bool Search()
{    
    Clear();
    AINFO << "Start A* search algorithm.";
    
    std::priority_queue<SearchNode> open_set_detail;
    
    SearchNode src_search_node(src_node) //TODO:where is SearchNode?
    src_search_node.f = HeuristicCost(src_node, dest_node); // 距终点的距离
    open_set_detail.push(src_search_node); // 从open_set_detail弹出source node
    // 这个是那个open_list - min heap

    open_set_.insert(src_node);
    g_score_[src_node] = 0.0; // 起点到该点的距离
    enter_s_[src_node] = src_node->StartS();

    SearchNode current_node;
    std::unordered_set<const TopoEdge*> next_edge_set;
    std::unordered_set<const TopoEdge*> sub_edge_set; - ?这里的edge是什么意思？
    while (!open_set_detail.empty()){
        current_node = open_set_detail.top();
        const auto* from_node = current_node.topo_node;
        if (current_node.topo_node == dest_node){
            if (!Reconstruct(came_from_, from_node, result_nodes)){ //这里的came_from_从哪里来的？
                AERROR << "Failed to reconstruct route.";
                return false;
            }
            return true;               
        }
        open_set.erase(from_node);       
        open_set_detail.pop();
        
        if (closed_set_.count(from_node) != 0) {
            // ir showed before, just skip ...
            continue;        
        }
        close_set_.emplace(from_node);

        //if residual_s is less than FLAGS_min_length_for_lane_change, only
        // move forward
        const auto& neighbor_edges = ....
        


}

}









```

### struct
```objectivec
struct SearchNode{ // 我觉得可以改成class的类型
    const TopoNode* topo_node = nullptr;
    double f = std::numeric_limits<double>::max;

    bool operator<(const SearchNode& node) const {
        // in order to let the top of priority queue is the smallest one
        return f > node.f;    
}
    

};
```