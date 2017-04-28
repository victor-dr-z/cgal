/*!
\ingroup PkgBGLConcepts
\cgalConcept

The concept `MutableFaceGraph` refines the concepts `FaceGraph` and `MutableHalfedgeGraph` and adds
the requirement for operations to add faces and to modify face-halfedge relations.

\cgalRefines `FaceGraph`
\cgalRefines `MutableHalfedgeGraph`
\cgalHasModel `CGAL::Polyhedron_3`
\cgalHasModel `CGAL::Surface_mesh`


class MutableFaceGraph{};

/*! \relates MutableFaceGraph
Adds a new face to the graph without initializing the connectivity.
 */
boost::graph_traits<MutableFaceGraph>::face_descriptor
add_face(MutableFaceGraph& g);

/*! \relates MutableFaceGraph
Removes `f` from the graph.
 */
boost::graph_traits<MutableFaceGraph>::face_descriptor
remove_face(boost::graph_traits<MutableFaceGraph>::face_descriptor f, MutableFaceGraph& g);

/*! \relates MutableFaceGraph
Sets the corresponding face of `h` to `f`.
 */
void
set_face(boost::graph_traits<MutableFaceGraph>::halfedge_descriptor h, boost::graph_traits<MutableFaceGraph>::face_descriptor f, MutableFaceGraph& g);

/*! \relates MutableFaceGraph
Sets the corresponding halfedge of `f` to `h`.
 */
void
set_halfedge(boost::graph_traits<MutableFaceGraph>::face_descriptor f, boost::graph_traits<MutableFaceGraph>::halfedge_descriptor h, MutableFaceGraph& g);
/*! \relates MutableFaceGraph
Indicates the expected size of vertices (`nv`), edges (`ed`) and faces (`nf`).
 */
void
reserve(MutableFaceGraph& g, boost::graph_traits<MutableFaceGraph>::vertices_size_type nv, boost::graph_traits<MutableFaceGraph>::vertices_size_type ne, boost::graph_traits<MutableFaceGraph>::vertices_size_type nf);
