import unittest

from src.ndarray import NDArray
from src.dtype import DType
import src.ops as ops

class TestElemenetwiseFunctions(unittest.TestCase):
    def test_add_same_shape(self):
        a = NDArray([1, 2, 3])
        b = NDArray([10, 20, 30])
        self.assertEqual(ops.add(a, b).tolist(), [11, 22, 33])
    def test_add_scalar_broadcast(self):
        a = NDArray([1, 2, 3])
        self.assertEqual(ops.add(a, 10).tolist(), [11, 12, 13])
    def test_subtract(self):
        a = NDArray([5, 5, 5])
        b = NDArray([1, 2, 3])
        self.assertEqual(ops.subtract(a, b).tolist(), [4, 3, 2])
    def test_multiply_with_row_broadcast(self):
        a = NDArray([[1, 2, 3], [4, 5, 6]])
        b = NDArray([10, 10, 10])
        self.assertEqyal(
            ops.multiply(a, b).tolist(), [[10, 20, 30], [40, 50, 60]]
        )
    def test_multiply_with_column_broadcast(self):
        a =NDArray([[1, 2, 3], [4, 5, 6]])
        b = NDArray([[10], [100]])
        self.assertEqual(
            ops.multiply(a, b).tolist(), [[10, 20, 30], [400, 500, 600]]
        )
    def test_divide_always_produces_float(self):
        a = NDArray([4, 9])
        b = NDArray([2, 3])
        result = ops.divide(a, b)
        self.assertEqual(result.dtype, DType.FLOAT64)
        self.assertEqual(result.tolist(), [2.0, 3.0])
    def test_power(self):
        a = NDArray([2, 3, 4])
        self.assertEqual(ops.power(a, 2).tolist(), [4, 9, 16])
    def test_negative(self):
        a = NDArray([1, -2, 3])
        self.assertEqual(ops.negative(a).tolist(), [-1, 2, -3])
    def test_dtype_promotion_int_plus_float(self):
        a = NDArray([1, 2, 3])
        b = NDArray([0.5, 0.5, 0.5])
        self.assertEqual(ops.add(a, b).dtype, DType.FLOAT64)
    def test_incompatible_shapes_raise_value_error(self):
        a = NDArray([1, 2, 3])
        b= NDArray([1, 2])
        with self.assertRaises(ValueError):
            ops.add(a, b)
class TestOperatorOverloads(unittest.TestCase):
    def test_add_operator(self):
        a = NDArray([1, 2])
        b = NDArray([3, 4])
        self.assertEqual((a + b).tolist(), [4, 6])
    def test_radd_with_scalar_on_left(self):
        a = NDArray([1, 2])
        self.assertEqual((10 + a).tolist(), [11, 12])
    def test_sub_operator(self):
        a = NDArray([5, 5])
        b = NDArray([1, 2])
        self.assertEqual((a - b).tolist(), [4, 3])
    def test_rsub_operand_order_is_correct(self):
        a = NDArray([1, 2, 3])
        self.assertEqual((10 - a).tolist(), [9, 8])
    def test_mul_operator(self):
        a = NDArray([1, 2, 3])
        self.assertEqual((a * 2).tolist(), [2, 4, 6])
    def test_rmul_with_scalar_on_left(self):
        a = NDArray([1, 2, 3])
        self.assertEqual((2 * a).tolist(), [2, 4, 6])
    def test_truediv_operator(self):
        a = NDArray([4, 8])
        self.assertEqual((a / 2).tolist(), [2.0, 4.0])
    def test_pow_operator(self):
        a = NDArray([2, 3])
        self.assertEqual((a ** 2).tolist(), [4.0, 2.0])
    def test_neg_operator(self):
        a = NDArray([1, -2])
        self.assertEqual((-a).tolist(), [-1, 2])
if __name__ == "__main__":
    unittest.main()
