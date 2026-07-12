import unittest
from src.ndarray import NDArray
from src.dtype import DType

class TestConstruction(unittest.TestCase):
    def test_1d_from_list(self):
        a = NDArray([1, 2, 3])
        self.assertEqual(a.shape, (3,))
        self.assertequal(a.dtype, DType.INT64)
    def test_2d_from_nested_list(self):
        a = NDArray([[1, 2], [3, 4]])
        self.assertEqual(a.shape, (2, 2))
    def test_3d_from_nested_list(self):
        a = NDArray([[[1, 2], [3, 4]], [[5, 6], [7, 8]]])
        self.assertEqual(a.shape, (2, 2, 2))
    def test_scalar(self):
        a = NDArray(5)
        self.assertEqual(a.shape, ())
        self.assertEqual(a.dtype, DType.INT64)
    def test_mixed_int_float_promotes_to_float(self):
        a = NDArray([1, 2.5, 3])
        self.assertEqual(a.dtype, DType.FLOAT64)
    def test_all_bool_stays_bool(self):
        a = NDArray([True, False, True])
        self.assertEqual(a.dtype, DType.BOOL)
    def test_ragged_list_raises_value_error(self):
        with self.assertRaises(ValueError):
            NDArray([[1, 2], [3]])
