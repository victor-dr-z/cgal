#include <CGAL/Polyhedron_3.h>
#include <CGAL/boost/graph/graph_traits_Polyhedron_3.h>
#include <CGAL/Simple_cartesian.h>
#include <CGAL/Exact_predicates_exact_constructions_kernel.h>

#include <CGAL/Polygon_mesh_processing/polygon_soup_to_polygon_mesh.h>
#include <CGAL/Polygon_mesh_processing/orient_polygon_soup.h>
#include <CGAL/IO/OFF_reader.h>

#include <string>
#include <fstream>
#include <iostream>

typedef CGAL::Simple_cartesian<double> SC;
typedef CGAL::Exact_predicates_exact_constructions_kernel Epec;


template <typename K>
void test(std::string fname, bool expected)
{
  typedef CGAL::Polyhedron_3<K> Polyhedron;
  std::vector<K::Point_3> points;
  std::vector< std::vector<std::size_t> > polygons;
  std::ifstream input(fname.c_str());

  if(!input)
  {
    std::cerr << "Error opening file " << fname << "\n";
    exit(EXIT_FAILURE);
  }

  if(!CGAL::read_OFF(input, points, polygons))
  {
    std::cerr << "Error parsing the OFF file " << fname << "\n";
    exit(EXIT_FAILURE);
  }


  bool is_mesh = CGAL::Polygon_mesh_processing::is_polygon_soup_a_polygon_mesh(polygons);
  std::cout << "is_polygon_soup_a_polygon_mesh(" << fname << ") == "
            << std::boolalpha << is_mesh << ";" << std::endl;
  assert(is_mesh == expected);

  if(is_mesh) {
    Polyhedron p;
    CGAL::Polygon_mesh_processing::polygon_soup_to_polygon_mesh(points, polygons, p);
    assert(p.is_valid());
  }

  if(!expected) {
    CGAL::Polygon_mesh_processing::orient_polygon_soup(points, polygons);
    bool is_mesh = CGAL::Polygon_mesh_processing::is_polygon_soup_a_polygon_mesh(polygons);
    std::cout << "After orientation: is_polygon_soup_a_polygon_mesh(" << fname << ") == "
              << std::boolalpha << is_mesh << ";" << std::endl;
    if(is_mesh)
    {
    Polyhedron p;
    CGAL::Polygon_mesh_processing::polygon_soup_to_polygon_mesh(points, polygons, p);
    assert(p.is_valid());
    }
  }

  std::cout << fname << " OK\n\n\n";
}

int main()
{
  test<SC>("data_polygon_soup/bad_cube.off", false);
  test<Epec>("data_polygon_soup/bad_cube.off", false);
  test<SC>("data_polygon_soup/isolated_singular_vertex_one_cc.off", false);

  test<SC>("data_polygon_soup/isolated_vertices.off", false);

  test<SC>("data_polygon_soup/nm_vertex_and_edge.off", false);
  test<SC>("data_polygon_soup/one_duplicated_edge.off", false);
  test<SC>("data_polygon_soup/one_duplicated_edge_sharing_vertex.off", false);
  test<SC>("data_polygon_soup/partial_overlap.off", false);
  test<SC>("data_polygon_soup/incompatible_orientation.off", false);

  test<SC>("data/blobby_3cc.off", true);
  test<SC>("data/elephant.off", true);
  test<SC>("data/joint_refined.off", true);
  test<SC>("data/mech-holes-shark.off", true);
  test<SC>("data/non_manifold_vertex.off", false);
  test<SC>("data/two_tris_collinear.off", true);
  test<SC>("data/U.off", true);
}
