from distutils.core import setup
from Cython.Build import cythonize
from distutils.extension import Extension
from Cython.Distutils import build_ext

ext_modules = [Extension("graph", ["lib/python/graphpy.pyx"],language='c++',build_dir="lib/python",depends=["lib/cplusplus/*"])]

setup(
  name = 'GransStationRoutes',
  version='1.0',
  description='Grand Station Extractor',
  author='Mathieu Gravel',
  author_email='mathieu.gravel.officiel@gmail.com',
  url='...',
  cmdclass = {'build_ext': build_ext},
  ext_modules = ext_modules,
  dist_dir = 'lib/python',
)
