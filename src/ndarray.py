'''
ndarray.py - core NDArray class for Mini Numpy
Depends on: dtype.py
'''
from typing import List, Tuple, Any
from .dtype import DType, infer_dtype, cast_value

Shape = Tuple[int, ...]
Strides = Tuple[int, ...]

def _flatten_nested(nested: Any) -> Tuple[List[Any], Shape]:
    raise NotImplementedError
def _compute_strides(shape: Shape) -> Strides:
    raise NotImplementedError
def _normalize_index(index, ndim: int) -> tuple:
    raise NotImplementedError
class NDArray:
    def __init__(self, nested_or_flat, shape: Shape = None,
                 dtype: DType = None, strides: Strides = None,
                 _data: List[Any] = None, _offset: int = 0):
        raise NotImplementedError
    @property
    def ndim(self) -> int:
        raise NotImplementedError
    @property
    def size(self) -> int:
        raise NotImplementedError
    @property
    def size(self) -> int:
        raise NotImplementedError
    def _flat_offset(self, indices: Tuple[int, ...]) -> int:
        raise NotImplenmentedError
    def __getitem__(self, index):
        raise NotImplementedError
    def __setitem__(self, index, value):
        raise NotImplementedError
    def tolist(self) -> Any:
        raise NotImplementedError
    def __repr__(self) -> str:
        raise NotImplementedError
    def __eq__(self, other) -> bool:
        raise NotImplementedError
