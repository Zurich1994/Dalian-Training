struct Road_Info
{
	int RoadSize;
	int RoadNameSize;
	long RoadLinkID;
	long RoadStaNodeInfo;
	char *RoadName;
};

struct Road
{
	struct Road_Info one_Road;
	struct *nextRoadNode;
};