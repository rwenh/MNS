import unittest

from src.broadcasting import broadcast_shapes, is_broadcastable, broadcast_strides

class TestBroadcastShapes(unittest.TestCase):
    def test_identical_shapes(self):
        self.assertEqual(broadcast_shapes((2, 3), (2, 3)), (2, 3))
    def test_scalar_with_array(self):
        self.assertEqual(broadcast_shapes((), (2, 3)), (2, 3))
        self.assertEqual(broadcast_shapes((2, 3), ()), (2, 3))
    def test_row_vector_broadcast(self):
        self.assertEqual(broadcast_shapes((3,), (2, 3)), (2, 3))
    def test_column_vector_broadcast(self):
        self.assertEqual(broadcast_shapes((2, 1), (2, 3)), (2, 3))
    def test_both_operands_stretch(self):
        self.assertEqual(broadcast_shapes((1, 3), (2, 1)), (2, 3))
    def test_different_ndim_left_padded(self):
        self.assertEqual(broadcast_shapes((4,), (3, 4)), (3, 4))
    def test_incompatible_dims_raise_value_error(self):
        with self.assertRaises(ValueError):
            broadcast_shapes((2, 3), (2, 4))
    def test_incompatible_different_ndim_raises(self):
        with self.assertRaises(ValueError):
            broadcast_shapes((3, 4), (2,))
class TestIsBroadcastable(unittest.TestCase):
    def test_true_case(self):
        self.assertTrue(is_broadcastable((2, 1), (1, 3)))
    def test_false_case(self):
        self.assertFalse(is_broadcastable((2, 3), (2, 4)))
    def test_identical_shapes_are_broadcastable(self):
        self.assertTrue(is_broadcastable((5,), (5,)))
class TestBroadcastStrides(unittest.TestCase):
    def test_no_stretch_needed_strides_unchanged(self):
        self.assertEqual(broadcast_strides((2, 3), (3, 1), (2, 3)), (3, 1))
    def test_stretch_row_vector_into_2d(self):
        self.assertEqual(broadcast_strides((3,), (1,), (2, 3)), (0, 1))
    def test_stretch_column_vector(self):
        self.assertEqual(broadcast_strides((2, 1), (1, 1), (2, 3)), (1, 0))
    def test_stretch_scalar_into_2d(self):
        self.assertEqual(broadcast_strides((), (), (2, 3)), (0, 0))
if __name__ == "__main__":
    unittest.main()
