#!/usr/bin/env python
# -*- coding: utf-8 -*-
from __future__ import print_function
import sys
import argparse 
import graph

#Main function. We take the station and build a PyGraph object that reads the entire map and extract the routes_ids
#associated with the station name given.
def main(dataLoc,stationName):
    cc = graph.PyGraph(dataLoc,stationName)
    routes = cc.routeAtStation()
    print(routes,sep="\n")








if __name__ == "__main__":
    parser = argparse.ArgumentParser(description = 'Input the name of the station you wish to extract its known routes.')
    parser.add_argument('--station', default='Grand Central - 42 St', help='Station name', type=str)
    parser.add_argument('--dataLoc', default='data', help='Datafiles location', type=str)   
    args = parser.parse_args()
    main(args.dataLoc,args.station)
