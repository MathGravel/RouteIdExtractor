# RouteIdExtractor
Extracteur d'identifiants de routes pour la carte GTFS de New York.

#Pré-requis
RouteIdExtractor uitlise les libraries suivantes:
 ..* python-csv
 ..* Cython
 ..* STL
 
 ---
 
## Installation
(Avertissement : La librarie a été conçu selon les normes de Python 3)

Pour compiler le programme, il suffit d'éxécuter les commandes suivante :
```
pip3 install Cython
python3 setup.py build_ext --inplace 
```

---

## Utilisation
```
python3 main.py --station="Station name here" --dataLoc = "data folder location here"
```
