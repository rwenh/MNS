'''
broadcasting.py - Numpy-style broadcasting rules for Mini Numpy
'''
from itertools import zip_longest
from typing import Tuple

def broadcast_shapes(shape_a: Tuple[int, ...],
                     shape_b: Tuple[int, ...]) -> Tuple[int, ...]:
    raise NotImplementedError

def is_broadcastable(shape_a: Tuple[int, ...],
                     shape_b: Tuple[int, ...]) -> bool:
    raise NotImplementedError

def broadcast_strides(shape: Tuple[int, ...], strides: Tuple[int, ...],
                      target_shape: Tuple[int, ...]) -> Tuple[int, ...]:
    raise NotImplementedError
