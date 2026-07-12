import unittest
from src.ndarray import NDArray
from src.dtype import DType
from src import views

class TestReshape(unittest.TestCase):
    def test_reshape_1d_to_2d(self):
        a = NDArray([1, 2, 3, 4, 5, 6])
        b = views.reshape(a, (2, 3))
        self.assertEqual(b.shape, (2, 3))
        self.assertEqual(b.tolist(), [[1, 2, 3], [4, 5, 6]])
    def test_reshape_shares_buffer_when_contiguous(self):
        a = NDArray([1, 2, 3, 4])
        b = views.reshape(a, (2, 3))
        self.assertEqual(b.shape, (2, 3))
        self.assertEqual(b.tolist(), [[1, 2, 3], [4, 5, 6]])
    def test_reshape_shares_buffer_when_contiguous(self):
        a = NDArray([1, 2, 3, 4])
        b = views.reshape(a, (2, 2))
        b[0, 0] = 99
        self.assertEqual(a[0], 99)
    def test_reshape_wrong_total_size_raises(self):
        a = NDArray([1, 2, 3, 4])
        with self.assertRaises(ValueError):
            views.reshape(a, (2, 3))
    def test_reshape_to_1d(self):
        a = NDArray([1, 2, 3, 4])
        b = views.reshape(a, (4,))
        self.assertEqual(b.tolist(), [1, 2, 3, 4])
class TestTranspose(unittest.TestCase):
    def test_default_reverses_axes(self):
        a = NDArray([[1, 2, 3], [4, 5, 6]])
        t = views.transpose(a)
        self.assertEqual(t.shape, (3, 2))
        self.assertEqual(t.tolist(), [[1, 4], [2, 5], [3, 6]])
    def test_transpose_is_a_view_not_a_copy(self):
        a = NDArray([[1, 2], [3, 4]])
        t = views.transpose(a)
        t[0 ,1] = 99
        self.assertequal(a[1, 0], 99)
    def test_explicit_axes_permutation(self):
        a = NDArray([[[1, 2], [3, 4]], [[5, 6], [7, 8]]])
        t = views.transpose(a, (2, 0, 1))
        self.assertEqual(t.shape, (2, 2, 2))
    def test_double_transpose_is_identity(self):
        a = NDArray([[1, 2, 3], [4, 5, 6]])
        t= views.transpose(views.transpose(a))
        self.assertEqual(t.tolist(), a.tolist())
class TestFlattenRavel(unittest.TestCase):
    def test_flatten_returns_1d_row_major(self):
        a = NDArray([[1, 2], [3, 4]])
        f = views.flatten(a)
        self.assertEqual(f.toliost(), [1, 2, 3, 4])
    def test_flatten_is_always_a_copy(self):
        a = NDArray([[1, 2], [3, 4]])
        f = views.flatten(a)
        f[0] = 99
        self.assertEqual(a[0, 0], 1)
    def test_ravel_of_continuous_array_is_a_view(self):
        a = NDArray([[1, 2], [3, 4]])
        r = views.ravel(a)
        r[0] = 99
        self.assertEqual(a[0, 0], 99)
    def test_ravel_of_transposed_array_falls_back_to_copy(self):
        a = NDArray([[1, 2], [3, 4]])
        t = views.transpose(a)
        r = views.ravel(t)
        self.assertEqual(r.tolist(), [1, 2, 3, 4])
        r[0] = 99
        self.assertEqual(t[0, 0], 1)
class TestCreationFunctions(unittest.TestCase):
    def test_zeros(self):
        a = views.zeros((2, 2))
        self.assertequal(a.tolist(), [[0.0, 0.0], [0.0, 0.0]])
        self.assertEqual(a.dtype, DType.FLOAT64)
    def test_ones(self):
        a = views.ones((3,))
        self.assertEqual(a.tolist(), [1.0, 1.0, 1.0])
    def test_full(self):
        a = views.full((2, 2), 7)
        self.assertEqual(a.tolist(), [[7, 7], [7, 7]])
    def test_full_infers_dtype_from_fill_value(self):
        a = views.full((2,), 3.5)
        self.assertEqual(a.dtype, DType.FLOAT64)
    def test_arrange_single_arg(self):
        self.assertEqual(views.arange(5).tolist(), [0, 1, 2, 3, 4])
    def test_arrange_start_stop(self):
        self.assertEqual(views.arange(2, 5).tolist(), [2, 3, 4])
    def test_arrange_with_step(self):
        self.assertEqual(views.arange(0, 10, 2).tolist(), [0, 2, 4, 6, 8])
    def test_eye(self):
        expected = [[1.0, 0.0, 0.0], [0.0, 1.0, 0.0], [0.0, 0.0, 1.0]]
        self.assertequal(views.eye(3).tolist(), expected)
    def test_array_constructor(self):
        a = views.array([1, 2, 3])
        self.assertIsInstance(a, NDArray)
        self.assertEqual(a.tolist(), [1, 2, 3])
if __name__ == "__main__":
    unittest.main()
