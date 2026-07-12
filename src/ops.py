'''
ops.py - Elementwise arithmetic operations for Mini Numpy
Depends on - ndarray.py,  broadcasting.py, dtype.py
'''
import operator
from itertools import product
from typing import Union
from .ndarray import NDArray, _compute_strides
from .broadcasting import broadcast_shapes
from .dtype import DType, promote, cast_value, infer_dtype

Number = Union[int, float, bool]
Operand = Union[NDArray, Number]

def _as_shape_and_getter(x: Operand):
    raise NotImplementedError
def _iter_indices(shapes):
    raise NotImplementedError
def _elementwise_binary(a: Operand, b: operand, py_pop) -> NDArray:
    raise NotImplementedError
def add(a: Operand, b: Operand) -> NDArray:
    raise NotImplementedError
def multiply(a: Operand, b: Operand) -> NDArray:
    raise NotImplementedError
def negative(a: NDArray) -> NDArray:
    raise NotImplementedError
def _install_operators():
    NDArray.__add__ = lambda self, other: add(self, other)
    NDArray.__radd__ = lambda self, other: add(other, self)
    NDArray.__sub__ = lambda self, other: subtract(self, other)
    NDArray.__rsub__ = lambda self, other: subtract(other, self)
    NDArray.__mul__ = lambda self, other: multiply(self, other)
    NDArray.__rmul__ = lambda self, other: multiply(other, self)
    NDArray.__truediv__ = lambda self, other: divide(self, other)
    NDArray.__rtruediv__ = lambda self, other: divide(other, self)
    NDArray.__pow__ = lambda self, other: power(self, other)
    NDArray.__neg__ = lambda self: negative(self)
_install_operators()
