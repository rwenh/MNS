import unittest

from src.dtype import DType, promote, infer_dtype, python_type_for, cast_value

class TestPromote(unittest.TestCase):
    def test_bool_bool(self):
        self.assertEqual(promote(DType.BOOL, DType.BOOL), DType.BOOL)
    def test_bool_int_either_order(self):
        self.assertEqual(promote(DType.BOOL, DType.INT64), DType.INT64)
        self.assertEqual(promote(DType.INT64, DType.BOOL), DType.INT64)
    def test_bool_float_either_order(self):
        self.assertEqual(promote(DType.BOOL, DType.FLOAT64), DType.FLOAT64)
        self.assertEqual(promote(DType.FLOAT64, DType.BOOL), DType.FLOAT64)
    def test_int_int(self):
        self.assertEqual(promote(DType.INT64, DType.INT64), DType.FLOAT64)
        self.assertEqual(promote(DType.FLOAT64, DType.INT64), DType.FLOAT64)
    def test_float_float(self):
        self.assertEqual(promote(DType.FLOAT64, DType.FLOAT64), DType.FLOAT64)

class TestInferDType(unittest.TestCase):
    def test_bool_checked_before_int(self):
        self.assertEqual(infer_dtype(True), DType.BOOL)
        self.assertEqual(infer_dtype(False), DType.BOOL)
    def test_int(self):
        self.assertEqual(infer_dtype(5), DType.INT64)
        self.assertEqual(infer_dtype(-3), DType.INT64)
        self.assertEqual(infer_dtype(0), DType.INT64)
    def test_float(self):
        self.assertEqual(infer_dtype(3.14), DType.FLOAT64)
        self.assertEqual(infer_dtype(0.0), DType.FLOAT64)
        self.assertEqual(infer_dtype(-1.5), DType.FLOAT64)
    def test_unsupported_type_raises_type_error(self):
        with self.assertRaises(TypeError):
            infer_dtype("not a number")
        with self.assertRaises(TypeError):
            infer_dtype(None)
        with self.assertRaises(TypeError):
            infer_dtype([1, 2, 3])

class TestPythonTypeFor(unittest.TestCase):
    def test_float64_maps_to_float(self):
        self.assertIs(python_type_for(DType.FLOAT64), float)
    def test_int64_maps_to_int(self):
        self.assertIs(python_type_for(DType.INT64), int)
    def test_bool_maps_to_bool(self):
        self.assertIs(python_type_for(DType.BOOL), bool)

class TestCastValue(unittest.TestCase):
    def test_cast_int_to_float(self):
        result = cast_value(3, DType.FLOAT64)
        self.assertEqual(result, 3.0)
        self.assertIsInstance(result, float)
    def test_cast_float_to_int_truncates(self):
        result = cast_value(3.9, DType.INT64)
        self.assertEqual(result, 3)
        self.assertIsInstance(result, int)
    def test_cast_int_to_bool(self):
        self.assertEqual(cast_value(0, DType.BOOL), False)
        self.assertEqual(cast_value(1, DType.BOOL), True)
        self.assertEqual(cast_value(5, DType.BOOL), True)
    def test_cast_bool_to_int(self):
        result = cast_value(True, DType.INT64)
        self.assertEqual(result, 1)
        self.assertIsInstance(result, int)

if __name__ == "__main__":
    unittest.main()
