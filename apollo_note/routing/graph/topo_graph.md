##_h

###class
```objectivec
class TopoGraph{
public:
    bool LoadGraph(const Graph& filename);
    MapVersion() const;
    MapDistrict() const;
    const TopoNode* GetNode(const std::string& id) const; - 我的lanelet没有id了，怎么办。。。
    void GetNodesByRoadId() const;

private:
    void Clear();
    bool LoadNodes(const Graph& graph);
    bool LoadEdges(const Graph& graph);

private:
    std::string map_version_;
    std::string map_district_;
    std::vector<std::shared_ptr<TopoNode> > topo_nodes; ? node 和 edge的关系
    std::vector<std::shared_ptr<TopoNode> > topo_edges_;
    std::unordered_map<std::string, int> node_index_map_; ? 
    std::unordered_map<std::string, std::unordered_set<const TopoNode*> > road_node_map_;

}

```

##_c

###function
`LoadNodes`

```objectivec
LoadGraph(){
    Clear();
    map_version_ = graph.hdmap_version();
}
```