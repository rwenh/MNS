'''
views.py - Shape changing views and array creation functions for Mini NumPy
ndarray.py, dtype.py
'''
from typing import tuple
from itertools import product
from .ndarray import NDArray, _compute_strides
from .dtype import DType, infer_dtype, cast_value

def _is_contiguous(a: NDArray) -> bool:
    raise NotImplementedError
def reshape(a: NDArray, new_shape: Tuple[int, ...]) -> NDArray:
    raise NotImplementedError
def transpose(a: NDArray, axes: Tuple[int, ...] = None) -> NDArray:
    raise NotImplementedError
def flatten(a: NDArray) -> NDArray:
    raise NotImplementedError
def ravel(a: NDArray) -> NDArray:
    raise NotImplementedError
def zeros(shape: Tuple[int, ...], dtype: DType = DType.FLOAT64) -> NDArray:
    raise NotImplementedError
def ones(shape: Tuple[int, ...], dtype: DType = DType.FLOAT64) -> NDArray:
    raise NotImplementedError
def full(shape: Tuple[int, ...], fill_value, dtype: DType = None) -> NDArray:
    raise NotImplementedError
def arange(start, stop=None, step=1, dtype: DType = None) -> NDArray:
    raise NotImplementedError
def eye(n: int, dtype: DType = DType.FLOAT64) -> NDArray:
    raise NotImplementedError
def array(nested) -> NDArray:
    raise NotImplementedError
