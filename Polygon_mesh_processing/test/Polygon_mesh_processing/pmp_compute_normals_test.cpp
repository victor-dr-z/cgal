#include <CGAL/Exact_predicates_inexact_constructions_kernel.h>
#include <CGAL/Exact_predicates_exact_constructions_kernel.h>
#include <CGAL/Surface_mesh.h>
#include <CGAL/Polygon_mesh_processing/compute_normal.h>

#include <CGAL/Timer.h>

#include <iostream>
#include <fstream>

typedef CGAL::Exact_predicates_inexact_constructions_kernel Epic;
typedef CGAL::Exact_predicates_exact_constructions_kernel Epec;

template <typename K>
void test(const char* file_name)
{
  typedef K::Point_3 Point;
  typedef K::Vector_3 Vector;
  typedef CGAL::Surface_mesh<Point> Surface_mesh;
  typedef boost::graph_traits<Surface_mesh>::vertex_descriptor vertex_descriptor;
  typedef boost::graph_traits<Surface_mesh>::face_descriptor face_descriptor;
  
  Surface_mesh mesh;
  std::ifstream input(file_name);
  if (!(input >> mesh)){
    std::cerr << "Error: cannot read Surface_mesh : " << file_name << "\n";
    assert(false);
  }
  
  Surface_mesh::Property_map<face_descriptor, Vector> fnormals;
  bool created;
  boost::tie(fnormals, created) = mesh.add_property_map<face_descriptor,Vector>("f:normals",Vector(0,0,0));
  CGAL::Polygon_mesh_processing::compute_face_normals(mesh, fnormals);
  CGAL::Polygon_mesh_processing::compute_face_normals(mesh, fnormals,
    CGAL::Polygon_mesh_processing::parameters::vertex_point_map(mesh.points()));
  CGAL::Polygon_mesh_processing::compute_face_normals(mesh, fnormals,
    CGAL::Polygon_mesh_processing::parameters::vertex_point_map(mesh.points()).geom_traits(K()));

 Surface_mesh::Property_map<vertex_descriptor,Vector> vnormals;

  boost::tie(vnormals, created) = mesh.add_property_map<vertex_descriptor,Vector>("v:normals",Vector(0,0,0));
  CGAL::Polygon_mesh_processing::compute_vertex_normals(mesh, vnormals);
  CGAL::Polygon_mesh_processing::compute_vertex_normals(mesh, vnormals,
    CGAL::Polygon_mesh_processing::parameters::vertex_point_map(mesh.points())); 
  CGAL::Polygon_mesh_processing::compute_vertex_normals(mesh, vnormals,
    CGAL::Polygon_mesh_processing::parameters::vertex_point_map(mesh.points()).geom_traits(K()));

  CGAL::Polygon_mesh_processing::compute_normals(mesh, vnormals, fnormals);
  CGAL::Polygon_mesh_processing::compute_normals(mesh, vnormals, fnormals,
    CGAL::Polygon_mesh_processing::parameters::vertex_point_map(mesh.points()));
  CGAL::Polygon_mesh_processing::compute_normals(mesh, vnormals, fnormals,
    CGAL::Polygon_mesh_processing::parameters::vertex_point_map(mesh.points()).geom_traits(K()));

}

int main()
{
  test<Epic>("data/elephant.off");
  test<Epec>("data/elephant.off");

  std::cerr << "All done." << std::endl;
}
