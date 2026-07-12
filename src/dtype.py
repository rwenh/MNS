'''
dtype.py - Data type system for Mini NumPy
'''
from enum import Enum

class DType(Enum):
    FLOAT64 = "float64"
    INT64 = "int64"
    BOOL = "bool"

_PROMOTION_TABLE = {
    frozenset({DType.BOOL}): DType.BOOL,
    frozenset({DType.BOOL, DType.INT64}): DType.INT64,
    frozenset({DType.BOOL, DType.FLOAT64}): DType.FLOAT64,
    frozenset({DType.INT64}): DType.FLOAT64,           # ← Changed this
    frozenset({DType.INT64, DType.FLOAT64}): DType.FLOAT64,
    frozenset({DType.FLOAT64}): DType.FLOAT64,
}

def promote(dtype_a: DType, dtype_b: DType) -> DType:
    """Promote two dtypes according to the promotion rules."""
    key = frozenset({dtype_a, dtype_b})
    if key in _PROMOTION_TABLE:
        return _PROMOTION_TABLE[key]
    raise ValueError(f"Cannot promote {dtype_a} and {dtype_b}")

def infer_dtype(value) -> DType:
    """Infer DType from a Python value."""
    if isinstance(value, bool):
        return DType.BOOL
    elif isinstance(value, int):
        return DType.INT64
    elif isinstance(value, float):
        return DType.FLOAT64
    else:
        raise TypeError(f"Unsupported type: {type(value)}")

def python_type_for(dtype: DType) -> type:
    """Return the corresponding Python type for a DType."""
    if dtype == DType.FLOAT64:
        return float
    elif dtype == DType.INT64:
        return int
    elif dtype == DType.BOOL:
        return bool
    raise ValueError(f"Unknown dtype: {dtype}")

def cast_value(value, dtype: DType):
    """Cast a value to the given dtype."""
    if dtype == DType.FLOAT64:
        return float(value)
    elif dtype == DType.INT64:
        return int(value)  # truncates toward zero
    elif dtype == DType.BOOL:
        return bool(value)
    raise ValueError(f"Cannot cast to {dtype}")
