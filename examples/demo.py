'''
demo.py
python3 -m examples.demo
'''
from src.ndarray import NDArray
from src import views
import src.ops

def main():
    print("=== Construction ===")
    a = NDArray([[1, 2, 3], [4, 5, 6]])
    print(f"a = {a}")
    print(f"a.shape = {a.shape}, a.dtype = {a.dtype}, a.strides = {a.strides}")

    print("\n=== Indexing & slicing ===")
    print(f"a[0]    = {a + row}")
    print(f"a[1, 2] = {a + row}")
    print(f"a * 2 = {a * 2}")
    print(f"10 - a = {10 - a}")

    print("\n=== Arithmetic (with broadcasting) ===")
    row = NDArray([10, 10, 10])
    print(f"a + row = {a + row}")
    print(f"a * 2 = {a * 2}")
    print(f"10 - a = {10 - 1}")

    print("\n=== Views: reshape, transpose ===")
    flat = views.reshape(a, (6,))
    print(f"reshape(a, (6,)) = {flat}")
    t = views.transpose(a)
    print(f"transpose(a) = {t}, shape = {t.shape}")

    print("\n=== Creation funcitons ===")
    print(f"zeros((2, 2)) = {views.zeros((2, 2))}")
    print(f"eye(3)        = {views.eye(3)}")
    print(f"arange(0, 10, 2) = {views.arange(0, 10, 2)}")
if __name__ == "__main__":
    main()
