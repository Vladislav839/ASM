#include <iostream>

struct Vector3D {
  long long X;
  long long Y;
  long long Z;
};

struct Vector2D {
  double X;
  double Y;
};

extern "C" Vector3D* SUM(Vector3D& v1, Vector3D& v2);
extern "C" double* GetLength(Vector2D& v1);

int main() {
  auto v1 = Vector3D{5, 10, 15};
  auto v2 = Vector3D{3, 4, 7};

  auto v = *SUM(v1, v2);
  std::cout << "Sum of vectors" << std::endl;
  std::cout << v.X << " " << v.Y << " " << v.Z << std::endl;

  auto v3 = Vector2D{5, 7};
  std::cout << *GetLength(v3) << std::endl;
}
