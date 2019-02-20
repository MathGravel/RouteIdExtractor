#Cython library to implement Python-c++ interaction
from libcpp.vector cimport vector
from libcpp.unordered_set cimport unordered_set
from libcpp.unordered_map cimport unordered_map
from libcpp.memory cimport shared_ptr
from libcpp.string cimport string
from libcpp cimport bool
import csv

#Declaration of the c++ class Graph
cdef extern from '../cplusplus/Graph.h':
    cdef cppclass Graph:
        Graph() except +
        unordered_set[string] routeAtStation(unordered_set[string] stoptimesLoc,string tripsLoc) except +

cdef extern from "../cplusplus/Graph.cpp":
    pass

cdef class PyGraph:
    cdef Graph *c_Graph  # C++ class instance
    cdef unordered_set[string] correctTrips
    cdef unordered_set[string] route_ids

    def __cinit__(self, dataLoc, staName):
        self.c_Graph = new Graph()
        stopTLoc = dataLoc + "/stop_times.txt"
        stopLoc = dataLoc + "/stops.txt"
        tripsLoc = dataLoc + "/trips.txt"
        correctStops = self.getCorrectStops(stopLoc,staName,2)
        self.correctTrips = self.getCorrectTrips(stopTLoc,correctStops)
        self.route_ids = self.c_Graph.routeAtStation(self.correctTrips,str.encode(tripsLoc))


    def __dealloc__(self):
        if self.c_Graph != NULL:
            del self.c_Graph
    
    def getCorrectStops(self,fileLoc,str stopName,id_pos):
        stops = []
        with open(fileLoc,newline='') as fromfile:
            reader = csv.reader(fromfile,delimiter=',', quotechar='"')
            next(reader)
            for row in reader:
                if row[2].find(stopName) > -1:
                    stops.append(row[0])
        return stops

    def getCorrectTrips(self,fileLoc,stops):
        cdef unordered_set[string] trip
        with open(fileLoc,newline='') as fromfile:
            reader = csv.reader(fromfile,delimiter=',', quotechar='"')
            next(reader)
            for row in reader:
                if row[3] in stops:
                    trip.insert(str.encode(row[0]))
        return trip
    
    def routeAtStation(self):
        vals = set()
        for data in self.route_ids:
            vals.add(data.decode())
        return vals