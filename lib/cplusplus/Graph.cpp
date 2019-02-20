#include "Graph.h"

/*
Input : 
	std::unordered_set<std::string> stoptimes : Trips_ids exracted linked to the Stop_id associated to the searched station
	std::string tripsLoc : Trips file location
*/
std::unordered_set<std::string> Graph::routeAtStation (std::unordered_set<std::string> stoptimes,std::string tripsLoc){
	std::unordered_set<std::string> routes = std::unordered_set<std::string>();
	bool checkRoutes = true;
    std::ifstream is(tripsLoc);
    if(is.fail()){
        throw -1;
    }
	//We modify the inputstream delimiters to treat multiple cases
	is.imbue(std::locale(is.getloc(), std::unique_ptr<Parser>(new Parser).release()));
	std::string t;
	int i = 0;
	//We skip the headers info
	while (i < 7){
	 	is >> t;
	 	i++;
	}	
	//We note the routes_ids found that are linked as follows Routes_ids-Trips_ids-Stops_ids-stops_name
	std::string route_id,trip_id;	
	while (is && checkRoutes) {
		is >> route_id >> t >> trip_id;
		if (stoptimes.count(trip_id) > 0) {
			routes.insert(route_id);
		}
		is.ignore(400,'\n');
	}
	
	 return routes;
}

   