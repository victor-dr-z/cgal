/*!
\ingroup PkgGeneralizedMapsConcepts
\cgalConcept

The concept `GeneralizedMap` defines a <I>d</I>-dimensional generalized map.

\cgalHasModel \ref  CGAL::Generalized_map "CGAL::Generalized_map<d,Items,Alloc>"

*/
 //@{
class GeneralizedMap {
public:

/// \name Creation
/// @{

/*!
%Default constructor creating an empty generalized map.
*/
GeneralizedMap();

/*!
Construct a new generalized map from another one. The new generalized map is created by copying the darts and the non void attributes of gmap. GMap must be a model of `GeneralizedMap` concept, which can be defined with a different dimension and/or different attributes than `*this`. In this case, only permutations that are common to `gmap` and `*this`, and only non void i-attributes of `gmap` whose info type is the same to the info of non void i-attributes of `*this`, are copied.
*/
template<typename GMap>
GeneralizedMap(const GMap& gmap);

/// @}

/// \name Types
/// @{

/*!
%Dart type, a model of the `GDart` concept.
*/
typedef unspecified_type Dart;

/*!
%Dart handle type, equal to `Dart::Dart_handle`.
*/
typedef unspecified_type Dart_handle;

/*!
%Dart const handle type, equal to `Dart::Dart_const_handle`.
*/
typedef unspecified_type Dart_const_handle;

/*!
Size type (an unsigned integral type).
*/
typedef unspecified_type size_type;

/// @}

/// \name Constants
/// @{

/*!
The dimension <I>d</I> of the generalized map, equal to `Dart::dimension`.
*/
static unsigned int dimension;

/*!
The number of available Boolean marks of the generalized map.
*/
static size_type NB_MARKS;

/// @}

/// \name Types for Attributes
/// @{

/*!
The tuple of cell attributes. It contains at most \ref GeneralizedMap::dimension "dimension"`+1` types (one for each possible cell of the generalized map). Each type of the tuple must be either a model of the `CellAttribute` concept or `void`.  The first type corresponds to 0-attributes, the second to 1-attributes and so on.  If the <i>i <sup>th</sup></i> type in the tuple is `void`, <I>(i-1)</I>-attributes are disabled. Otherwise, <I>(i-1)</I>-attributes are enabled and have the given type. If the size of the tuple is <I>k</I>, with <I>k</I>\f$ <\f$\ref GeneralizedMap::dimension "dimension"`+1`, \f$ \forall\f$<I>i</I>: <I>k</I>\f$ \leq\f$<I>i</I>\f$ \leq\f$\ref GeneralizedMap::dimension "dimension", <I>i</I>-attributes are disabled.
*/
typedef unspecified_type Attributes;

  /*!
    `Attribute_type<i>::%type` is the type of <I>i</I>-attributes, a model of `CellAttribute` concept. \ref CellAttribute::Dart_handle "Attribute_type<i>::type::Dart_handle" is equal to \ref GeneralizedMap::Dart_handle "Dart_handle", and \ref CellAttribute::Dart_const_handle "Attribute_type<i>::type::Dart_const_handle" is equal to \ref GeneralizedMap::Dart_const_handle "Dart_const_handle". \pre 0\f$ \leq\f$<I>i</I>\f$ \leq\f$\ref GeneralizedMap::dimension "dimension" and <I>i</I>-attributes are non `void`. \note It can be implemented using a nested template class.
  */
  template <unsigned int i>
  using Attribute_type = unspecified_type;

  /*!
  `Attribute_handle<i>::%type` is a handle to <I>i</I>-attributes, equal to \link Dart::Attribute_handle `Dart::Attribute_handle<i>::type` \endlink. \pre 0\f$ \leq\f$<I>i</I>\f$ \leq\f$\ref GeneralizedMap::dimension "dimension" and <I>i</I>-attributes are non void. \note It can be implemented using a nested template class.
  */
  template <unsigned int i>
  using Attribute_handle = unspecified_type;

  /*!
  `Attribute_handle<i>::%type` is a const handle to <I>i</I>-attributes, equal to \link Dart::Attribute_const_handle `Dart::Attribute_const_handle<i>::type` \endlink. \pre 0\f$ \leq\f$<I>i</I>\f$ \leq\f$\ref GeneralizedMap::dimension "dimension" and <I>i</I>-attributes are non void. \note It can be implemented using a nested template class.
  */
  template <unsigned int i>
  using Attribute_const_handle = unspecified_type;

/// @}

/// \name Range Types
/// @{

/*!
%Range of all the darts of the generalized map. This type is a model of `Range` concept, its iterator type is bidirectional and its value type is \ref GeneralizedMap::Dart "Dart".
*/
typedef unspecified_type Dart_range;

/*!
Const range of all the darts of the generalized map. This type is a model of `ConstRange` concept, its iterator type is bidirectional and its value type is \ref GeneralizedMap::Dart "Dart".
*/
typedef unspecified_type Dart_const_range;


/*!
`Attribute_range<i>::%type` is the range of all the <I>i</I>-attributes. `Attribute_range<i>::%type` is a model of `Range` concept, its iterator type is bidirectional and its value type is \link GeneralizedMap::Attribute_type `Attribute_type<i>::type` \endlink. \pre 0\f$ \leq\f$<I>i</I>\f$ \leq\f$\ref GeneralizedMap::dimension "dimension" and <I>i</I>-attributes are non void. \note It can be implemented using a nested template class.
*/
  template <unsigned int i>
  using Attribute_range = unspecified_type;


/*! `Attribute_const_range<i>::%type` is the const range of all the <I>i</I>-attributes. `Attribute_const_range<i>::%type` is a model of `ConstRange` concept, its iterator type is bidirectional and its value type is \link GeneralizedMap::Attribute_type `Attribute_type<i>::type`\endlink. \pre 0\f$ \leq\f$<I>i</I>\f$ \leq\f$\ref GeneralizedMap::dimension "dimension" and <I>i</I>-attributes are non void. \note It can be implemented using a nested template class.
*/
template <unsigned int i>
using Attribute_const_range = unspecified_type;

/*!
%Range of all the darts of the `<Alpha...>` orbit. This type is a model of `Range` concept, its iterator type is forward and its value type is \ref GeneralizedMap::Dart "Dart".
*/
template<unsigned int... Alpha>
using Dart_of_orbit_range = unspecified_type;

/*!
Const range of all the darts of the `<Alpha...>` orbit. This type is a model of `ConstRange` concept, its iterator type is forward and its value type is \ref GeneralizedMap::Dart "Dart".
*/
template<unsigned int ... Alpha>
using Dart_of_orbit_const_range = unspecified_type;

/*!
%Range of all the darts of an <I>i</I>-cell. Cells are considered in <I>dim</I> dimension, with 0\f$ \leq\f$<I>i</I>\f$ \leq\f$<I>dim+1</I> and 0\f$ \leq\f$<I>dim</I>\f$ \leq\f$\ref GeneralizedMap::dimension "dimension". If <I>i==dim+1</I>, range of all the darts of a connected component. This type is a model of `Range` concept, its iterator type is forward and its value type is \ref GeneralizedMap::Dart "Dart".
*/
template<unsigned int i,unsigned int dim=dimension>
using Dart_of_cell_range = unspecified_type;

/*!
Const range of all the darts of the <I>i</I>-cell. Cells are considered in <I>dim</I> dimension, with 0\f$ \leq\f$<I>i</I>\f$ \leq\f$<I>dim+1</I> and 0\f$ \leq\f$<I>dim</I>\f$ \leq\f$\ref GeneralizedMap::dimension "dimension". If <I>i==dim+1</I>, range of all the darts of a connected component. This type is a model of `ConstRange` concept, its iterator type is forward and its value type is \ref GeneralizedMap::Dart "Dart".
*/
template<unsigned int i,unsigned int dim=dimension>
using Dart_of_cell_const_range = unspecified_type;

/*!
%Range of one dart of each <I>i</I>-cell incident to one <I>j</I>-cell. Cells are considered in <I>dim</I> dimension, with 0\f$ \leq\f$<I>i</I>\f$ \leq\f$<I>dim+1</I>, 0\f$ \leq\f$<I>j</I>\f$ \leq\f$<I>dim+1</I> and 0\f$ \leq\f$<I>dim</I>\f$ \leq\f$\ref GeneralizedMap::dimension "dimension". If <I>i</I>==<I>dim+1</I>, consider each connected component instead of each <I>i</I>-cell. If <I>j</I>==<I>dim+1</I>, consider one connected component instead of one <I>j</I>-cell. This type is a model of `Range` concept, its iterator type is forward and its value type is \ref GeneralizedMap::Dart "Dart".
*/
template<unsigned int i,unsigned int j,unsigned int dim=dimension>
using One_dart_per_incident_cell_range = unspecified_type;

/*!
Const range of one dart of each <I>i</I>-cell incident to one <I>j</I>-cell. Cells are considered in <I>dim</I> dimension, with 0\f$ \leq\f$<I>i</I>\f$ \leq\f$<I>dim+1</I>, 0\f$ \leq\f$<I>j</I>\f$ \leq\f$<I>dim+1</I> and 0\f$ \leq\f$<I>dim</I>\f$ \leq\f$\ref GeneralizedMap::dimension "dimension". If <I>i==dim+1</I>, consider each connected component instead of each <I>i</I>-cell. If <I>j==dim+1</I>, consider one connected component instead of one <I>j</I>-cell. This type is a model of `ConstRange` concept, its iterator type is forward and its value type is \ref GeneralizedMap::Dart "Dart"
*/
template<unsigned int i,unsigned int j,unsigned int dim=dimension>
using One_dart_per_incident_cell_const_range = unspecified_type;

/*!
%Range of one dart of each <I>i</I>-cell of the generalized map. Cells are considered in <I>dim</I> dimension, with 0\f$ \leq\f$<I>i</I>\f$ \leq\f$<I>dim+1</I> and 0\f$ \leq\f$<I>dim</I>\f$ \leq\f$\ref GeneralizedMap::dimension "dimension". If <I>i==dim+1</I>, consider each connected component instead of each <I>i</I>-cell. This type is a model of `Range` concept, its iterator type is forward and its value type is \ref GeneralizedMap::Dart "Dart".
*/
template<unsigned int i,unsigned int dim=dimension>
using One_dart_per_cell_range = unspecified_type;

/*!
Const range of one dart of each <I>i</I>-cell of the generalized map. Cells are considered in <I>dim</I> dimension, with 0\f$ \leq\f$<I>i</I>\f$ \leq\f$<I>dim+1</I> and 0\f$ \leq\f$<I>dim</I>\f$ \leq\f$\ref GeneralizedMap::dimension "dimension". If <I>i==dim+1</I>, consider each connected component instead of each <I>i</I>-cell. This type is a model of `ConstRange` concept, its iterator type is forward and its value type is \ref GeneralizedMap::Dart "Dart".
*/
template<unsigned int i,unsigned int dim=dimension>
using One_dart_per_cell_const_range = unspecified_type;

/// @}

/// \name Access Member Functions
/// @{

/*!
Returns true iff the generalized map is empty, i.e.\ it contains no dart.
*/
bool is_empty() const;

/*!
Returns true iff the generalized map is valid.

A generalized map is valid (see Sections \ref sseccombimapanddarts and \ref sseccombimapvalidity) if for all its darts `d` \f$\in\f$`darts()`:

- \f$ \forall\f$<I>i</I>, 0\f$ \leq\f$<I>i</I>\f$ \leq\f$\ref GeneralizedMap::dimension "dimension": \f$ \alpha_i(\alpha_i(d))=d\f$;
- \f$ \forall\f$<I>i</I>, <I>j</I>, 0\f$ \leq\f$<I>i</I>\f$ <\f$<I>i</I>+2\f$ \leq\f$<I>j</I>\f$ \leq\f$\ref GeneralizedMap::dimension "dimension" such that <I>j</I>\f$ \geq\f$ 3: \f$ \alpha_j(\alpha_i(\alpha_j(\alpha_i(d))))=d\f$;
- \f$ \forall\f$<I>i</I>, 0\f$ \leq\f$<I>i</I>\f$ \leq\f$\ref GeneralizedMap::dimension "dimension" such that <I>i</I>-attributes are non void:
  + \f$ \forall\f$<I>d2</I> in the same <I>i</I>-cell than <I>d</I>: <I>d</I> and <I>d2</I> have the same <I>i</I>-attribute;
  + \f$ \forall\f$<I>d2</I>  in a different <I>i</I>-cell than <I>d</I>: <I>d</I> and <I>d2</I> have different <I>i</I>-attributes.
*/
bool is_valid() const;

/*!
Returns true iff the generalized map is without <I>i</I>-boundary.

The map is without <I>i</I>-boundary if there is no `i`-free dart.
\pre 0\f$ \leq\f$<I>i</I>\f$ \leq\f$\ref GeneralizedMap::dimension "dimension".
*/
bool is_without_boundary(unsigned int i) const;

/*!
Returns true iff the generalized map is without boundary in all dimensions.
*/
bool is_without_boundary() const;

/*!
Returns the number of darts in the generalized map.
*/
size_type number_of_darts() const;

/*!
Returns the number of <I>i</I>-attributes in the generalized map.
\pre 0\f$ \leq\f$<I>i</I>\f$ \leq\f$\ref GeneralizedMap::dimension "dimension", and <I>i</I>-attributes are non void.
*/
template <unsigned int i>
size_type number_of_attributes() const;

/*! Returns true if dh points to a used dart (i.e.\ valid).
 */
bool is_dart_used(Dart_const_handle dh) const;

/*!
Returns \f$ \alpha_j\f$(\f$ \alpha_i\f$(`*dh`)).
Overloads of this member function are defined that take from one to nine integer as arguments. For each function, alphas are applied in the same order as their indices are given as parameters.

For example `alpha(dh,1)`=\f$ \alpha_1\f$(`*dh`),
and `alpha(dh,1,2,3,0)`=\f$ \alpha_0\f$(\f$ \alpha_3\f$(\f$ \alpha_2\f$(\f$ \alpha_1\f$(`*dh`)))).
\pre 0\f$ \leq\f$<I>i</I>\f$ \leq\f$\ref GeneralizedMap::dimension "dimension", 0\f$ \leq\f$<I>j</I>\f$ \leq\f$\ref GeneralizedMap::dimension "dimension" and `*dh`\f$ \in\f$`darts()`.
*/
Dart_handle alpha(Dart_handle dh, int i, int j);

/*!
Returns \f$ \alpha_j\f$(\f$ \alpha_i\f$(`*dh`)). Overloads of this member function are defined that take from one to nine integer as arguments.
\pre 0\f$ \leq\f$<I>i</I>\f$ \leq\f$\ref GeneralizedMap::dimension "dimension", 0\f$ \leq\f$<I>j</I>\f$ \leq\f$\ref GeneralizedMap::dimension "dimension" and `*dh`\f$ \in\f$`darts()`.

*/
Dart_const_handle alpha(Dart_const_handle dh, int i, int j) const;

/*!
Returns \f$ \alpha_j\f$(\f$ \alpha_i\f$(`*dh`)). Overloads of this member function are defined that take from one to nine integer as template arguments. For each function, alphas are applied in the same order as their indices are given as template arguments.

For example `alpha<1>(dh)`=\f$ \alpha_1\f$(`*dh`), and `alpha<1,2,3,0>(dh)`=\f$ \alpha_0\f$(\f$ \alpha_3\f$(\f$ \alpha_2\f$(\f$ \alpha_1\f$(`*dh`)))). \pre 0\f$ \leq\f$<I>i</I>\f$ \leq\f$\ref GeneralizedMap::dimension "dimension", 0\f$ \leq\f$<I>j</I>\f$ \leq\f$\ref GeneralizedMap::dimension "dimension" and `*dh`\f$ \in\f$`darts()`.
*/
template<int i, int j>
Dart_handle alpha(Dart_handle dh);

/*!
Returns \f$ \alpha_j\f$(\f$ \alpha_i\f$(`*dh`)). Overloads of this member function are defined that take from one to nine integer as template arguments.
\pre 0\f$ \leq\f$<I>i</I>\f$ \leq\f$\ref GeneralizedMap::dimension "dimension", 0\f$ \leq\f$<I>j</I>\f$ \leq\f$\ref GeneralizedMap::dimension "dimension" and `*dh`\f$ \in\f$`darts()`.

*/
template<int i, int j>
Dart_const_handle alpha(Dart_const_handle dh) const;

/*!
Returns true iff dart `*dh` is <I>i</I>-free.
\pre 0\f$ \leq\f$<I>i</I>\f$ \leq\f$\ref GeneralizedMap::dimension "dimension".
*/
bool is_free(Dart_const_handle dh, unsigned int i) const;

/*!
Returns true iff dart `*dh` is <I>i</I>-free.
\pre 0\f$ \leq\f$<I>i</I>\f$ \leq\f$\ref GeneralizedMap::dimension "dimension".
*/
template<unsigned int i>
bool is_free(Dart_const_handle dh) const;

/*!
Returns the highest dimension <I>i</I> such that dart `*dh` is not <I>i</I>-free. -1 if `dh` is free for any dimension.
*/
int highest_nonfree_dimension(Dart_const_handle dh) const;

/*!
Returns \f$ \alpha_0(dh)\f$ i.e. a handle to a dart belonging to the same edge than dart `*dh`, and not to the same vertex. `NULL` if such a dart does not exist.
*/
Dart_handle  other_extremity(Dart_handle dh);

/*!
Returns \f$ \alpha_0(dh)\f$ i.e. a const handle to a dart belonging to the same edge than dart `*dh`, and not to the same vertex, when the dart is const. `NULL` if such a dart does not exist.
*/
Dart_const_handle  other_extremity(Dart_const_handle dh) const;

/*!
Displays on `os` the number of elements of the generalized map. Its number of darts, its number of <I>i</I>-cells, for each <I>i</I>, 0\f$ \leq\f$<I>i</I>\f$ \leq\f$\ref GeneralizedMap::dimension "dimension", and its number of connected components.

Example of output for a 3D generalized map containing two disjoint generalized tetrahedra:

<TT>\#Darts=24, \#0-cells=8, \#1-cells=12, \#2-cells=8, \#3-cells=2, \#ccs=2</TT>
*/
std::ostream& display_characteristics(std::ostream & os) const;

/// @}

/// \name Attributes Access Member Functions
/// @{
///
/*!
Returns a handle to the <I>i</I>-attribute associated to dart `*dh`.
\pre 0\f$ \leq\f$<I>i</I>\f$ \leq\f$\ref GeneralizedMap::dimension "dimension", and <I>i</I>-attributes are non `void`.
*/
template <unsigned int i> Attribute_handle<i>::type attribute(Dart_handle dh);

/*!
Returns a const handle to the <I>i</I>-attribute associated to dart `*dh`, when the dart is const.
\pre 0\f$ \leq\f$<I>i</I>\f$ \leq\f$\ref GeneralizedMap::dimension "dimension", and <I>i</I>-attributes are non `void`.
*/
template <unsigned int i>
Attribute_const_handle<i>::type attribute(Dart_const_handle dh) const;

/*!
Returns one dart of the cell associated to the <I>i</I>-attribute `*ah`. `NULL` if \ref CellAttribute::Supports_cell_dart "Supports_cell_dart" of <I>i</I>-attributes  is equal to \ref CGAL::Tag_false "Tag_false".
\pre 0\f$ \leq\f$<I>i</I>\f$ \leq\f$\ref GeneralizedMap::dimension "dimension", <I>i</I>-attributes are non `void` and `ah`!=NULL.
*/
template<unsigned int i>
Dart_handle dart_of_attribute(typename Attribute_handle<i>::type ah);

/*!
Returns one dart of the cell associated to the const <I>i</I>-attribute `*ah`. `NULL` if \ref CellAttribute::Supports_cell_dart "Supports_cell_dart" of <I>i</I>-attributes is equal to \ref CGAL::Tag_false "Tag_false".
\pre 0\f$ \leq\f$<I>i</I>\f$ \leq\f$\ref GeneralizedMap::dimension "dimension", <I>i</I>-attributes are non `void` and `ah`!=NULL.
*/
template<unsigned int i>
Dart_const_handle dart_of_attribute(typename Attribute_const_handle<i>::type ah) const;

/*!
Returns the information of the <I>i</I>-attribute `*ah`. Defined only if \ref CellAttribute::Info "Info" of <I>i</I>-attributes is not `void`.
\pre 0\f$ \leq\f$<I>i</I>\f$ \leq\f$\ref GeneralizedMap::dimension "dimension", <I>i</I>-attributes are non `void` and `ah`!=NULL.
*/
template <unsigned int i>
Attribute_type<i>::type::Info& info_of_attribute(typename Attribute_handle<i>::type ah);

/*!
Returns the information of the const <I>i</I>-attribute `*ah`. Defined only if \ref CellAttribute::Info "Info" of <I>i</I>-attributes is not `void`.
\pre 0\f$ \leq\f$<I>i</I>\f$ \leq\f$\ref GeneralizedMap::dimension "dimension", <I>i</I>-attributes are non `void` and `ah`!=NULL.
*/
template <unsigned int i>
const Attribute_type<i>::type::Info& info_of_attribute(typename Attribute_const_handle<i>::type ah) const;

/*!
A shorcut for \link GeneralizedMap::info_of_attribute `info_of_attribute<i>`\endlink`(`\link GeneralizedMap::attribute `attribute<i>`\endlink`(adart))`.
\pre \ref GeneralizedMap::attribute "attribute<i>"`(adart)!=NULL`.
*/
template<unsigned int i>
typename Attribute_type<i>::type::Info & info(Dart_handle adart);

/*!
A shorcut for \link GeneralizedMap::info_of_attribute(typename Attribute_const_handle<i>::type)const `info_of_attribute<i>`\endlink`(`\link GeneralizedMap::attribute(Dart_const_handle)const `attribute<i>`\endlink`(adart))` for const handle.
\pre \link GeneralizedMap::attribute(Dart_const_handle)const `attribute<i>`\endlink`(adart)!=NULL`.
*/
template<unsigned int i>
const typename Attribute_type<i>::type::Info & info(Dart_const_handle adart) const;

/*!
A shorcut for \link GeneralizedMap::dart_of_attribute `dart_of_attribute<i>`\endlink`(`\link GeneralizedMap::attribute `attribute<i>`\endlink`(adart))`.
\pre `attribute<i>(adart)!=NULL`.
*/
template<unsigned int i>
Dart_handle & dart(Dart_handle adart);

/*!
A shorcut for \link GeneralizedMap::dart_of_attribute(typename Attribute_const_handle<i>::type)const `dart_of_attribute<i>`\endlink`(`\link GeneralizedMap::attribute(Dart_const_handle)const `attribute<i>`\endlink`(adart))` for const handle.
\pre `attribute<i>(adart)!=NULL`.
*/
template<unsigned int i>
Dart_const_handle dart(Dart_const_handle adart) const;

/*! Returns true if ah points to a used i-attribute (i.e.\ valid).
\pre 0\f$ \leq\f$<I>i</I>\f$ \leq\f$\ref GeneralizedMap::dimension "dimension", and <I>i</I>-attributes are non `void`.
 */
template<unsigned int i>
bool is_attribute_used(typename Attribute_const_handle<i>::type ah) const;

/// @}

/// \name Transformations Between Handles and Instances
/// @{

/*!
Returns the dart handle of `d`.
\pre `d`\f$ \in\f$`darts()`.
*/
Dart_handle dart_handle(Dart& d);

/*!
Returns the dart const handle of `d`.
\pre `d`\f$ \in\f$`darts()`.
*/
Dart_const_handle dart_handle(const Dart& d) const;

/// @}

/// \name Range Access Member Functions
/// @{

/*!
Returns a range of all the darts in the generalized map.
*/
Dart_range& darts();

/*!
Returns a const range of all the darts in the generalized map.
*/
Dart_const_range& darts() const;

/*!
Returns a range of all the <I>i</I>-attributes in the generalized map.
\pre 0\f$ \leq\f$<I>i</I>\f$ \leq\f$\ref GeneralizedMap::dimension "dimension", and <I>i</I>-attributes are non void.
*/
template<unsigned int i> Attribute_range<i>::type & attributes();

/*!
Returns a const range of all the <I>i</I>-attributes in the generalized map.
\pre 0\f$ \leq\f$<I>i</I>\f$ \leq\f$\ref GeneralizedMap::dimension "dimension", and <I>i</I>-attributes are non void.
*/
template<unsigned int i> Attribute_const_range<i>::type & attributes() const;

/*!
Returns a range of all the darts of the orbit `<Alpha...>(*dh)`. The first element in the range points onto `*dh`.
\pre `*dh`\f$ \in\f$`darts()` and `Alpha...` is a sequence of integers \f$ i_1\f$,\f$ \ldots\f$,\f$ i_k\f$, such that 0\f$ \leq\f$\f$ i_1\f$\f$ <\f$\f$ i_2\f$\f$ <\f$\f$ \ldots\f$\f$ <\f$\f$ i_k\f$\f$ \leq\f$\ref GeneralizedMap::dimension "dimension", and (\f$ i_1\f$\f$ \neq\f$ 0 or \f$ i_2\f$\f$ \neq\f$ 1).
*/
template<unsigned int ... Alpha> Dart_of_orbit_range darts_of_orbit(Dart_handle dh);

/*!
Returns a const range of all the darts of the orbit `<Alpha...>(*dh)`. The first element in the range points onto `*dh`.
\pre Same as for the non const version.
*/
template<unsigned int ... Alpha> Dart_of_orbit_const_range darts_of_orbit(Dart_const_handle dh) const;

/*!
Returns a range of all the darts of the <I>i</I>-cell containing `*dh`. The first element in the range points onto `*dh`. <I>i</I>-cells are considered in <I>dim</I> dimension. If <I>i==dim+1</I>, range of all the darts of the connected component containing `dh`.
\pre `*dh`\f$ \in\f$`darts()`, 0\f$ \leq\f$<I>i</I>\f$ \leq\f$<I>dim+1</I> and 0\f$ \leq\f$<I>dim</I>\f$ \leq\f$\ref GeneralizedMap::dimension "dimension".
*/
template<unsigned int i,unsigned int dim=dimension> Dart_of_cell_range darts_of_cell(Dart_handle dh);

/*!
Returns a const range of all the darts of the <I>i</I>-cell containing `*dh`. The first element in the range points onto `*dh`. <I>i</I>-cells are considered in <I>dim</I> dimension. If <I>i==dim+1</I>, const range of all the darts of the connected component containing `*dh`.
\pre Same as for the non const version.
*/
template<unsigned int i,unsigned int dim=dimension> Dart_of_cell_const_range darts_of_cell(Dart_const_handle dh) const;

/*!
Returns a range of one dart of each <I>i</I>-cell incident to the <I>j</I>-cell containing `*dh`. The first element in the range points onto `*dh`. Cells are considered in <I>dim</I> dimension. If <I>i==dim+1</I>, consider each connected component instead of each <I>i</I>-cell. If <I>j==dim+1</I>, consider the connected component containing `*dh` instead of the <I>j</I>-cell.
\pre `*dh`\f$ \in\f$`darts()`, 0\f$ \leq\f$<I>i</I>\f$ \leq\f$<I>dim+1</I>, 0\f$ \leq\f$<I>j</I>\f$ \leq\f$<I>dim+1</I> and 0\f$ \leq\f$<I>dim</I>\f$ \leq\f$\ref GeneralizedMap::dimension "dimension".
*/
template<unsigned int i,unsigned int j,unsigned int dim=dimension> One_dart_per_incident_cell_range one_dart_per_incident_cell(Dart_handle dh);

/*!
Returns a const range of one dart of each <I>i</I>-cell incident to the <I>j</I>-cell containing `*dh`. The first element in the range points onto `*dh`. Cells are considered in <I>dim</I> dimension. If <I>i==dim+1</I>, consider each connected component instead of each <I>i</I>-cell. If <I>j==dim+1</I>, consider the connected component containing `*dh` instead of the <I>j</I>-cell.
\pre Same as for the non const version.
*/
template<unsigned int i,unsigned int j,unsigned int dim=dimension> One_dart_per_incident_cell_const_range one_dart_per_incident_cell(Dart_const_handle dh) const;

/*!
Returns a range of one dart of each <I>i</I>-cell in the generalized map. Cells are considered in <I>dim</I> dimension. If <I>i==dim+1</I>, range of one dart of each connected component in the generalized map. 
\pre 0\f$ \leq\f$<I>i</I>\f$ \leq\f$<I>dim+1</I> and 0\f$ \leq\f$<I>dim</I>\f$ \leq\f$\ref GeneralizedMap::dimension "dimension".
*/
template<unsigned int i,unsigned int dim=dimension> One_dart_per_cell_range one_dart_per_cell();

/*!
Returns a const range of one dart of each <I>i</I>-cell in the generalized map. Cells are considered in <I>dim</I> dimension. If <I>i==dim+1</I>, const range of one dart of each connected component in the generalized map.
\pre Same as for the non const version.
*/
template<unsigned int i,unsigned int dim=dimension> One_dart_per_cell_const_range one_dart_per_cell() const;

/// @}

/// \name Modifiers
/// @{

/*!
Creates a new dart in the generalized map, and returns the corresponding handle. Calls the constructor of dart having `T1` as parameter. A new dart is initialized to be <I>i</I>-free, \f$ \forall\f$<I>i</I>: 0\f$ \leq\f$<I>i</I>\f$ \leq\f$\ref GeneralizedMap::dimension "dimension", and to have no associated attribute for each non void attribute. Overloads of this member function are defined that take from zero to nine arguments. With zero argument, `%create_dart()` creates a new dart by using the default constructor.

*/
template<typename T1>
Dart_handle create_dart(T1 t1);

/*!
Removes `*dh` from the generalized map.
\pre `*dh`\f$ \in\f$`darts()`.

*/
void erase_dart(Dart_handle dh);

/*!
Creates a new <I>i</I>-attribute in the generalized map, and returns the corresponding handle. Calls the constructor of <I>i</I>-attribute having `T1` as parameter. Overloads of this member function are defined that take from zero to nine arguments. With zero argument, `create_attribute<i>()` creates a new <I>i</I>-attribute by using the default constructor.
\pre 0\f$ \leq\f$<I>i</I>\f$ \leq\f$\ref GeneralizedMap::dimension "dimension", and <I>i</I>-attributes are non void.
*/
template<unsigned int i,typename T1> Attribute_handle<i>::type create_attribute(T1 t1);

/*!
Removes the <I>i</I>-attribute `*ah` from the generalized map.
\pre 0\f$ \leq\f$<I>i</I>\f$ \leq\f$\ref GeneralizedMap::dimension "dimension", <I>i</I>-attributes are non void, and `*ah`\f$ \in\f$\ref GeneralizedMap::attributes() "attributes<i>()".
*/
template <unsigned int i> void erase_attribute(Attribute_handle<i>::type ah);

/*!
Associates the <I>i</I>-attribute of all the darts of the <I>i</I>-cell containing `*dh` to `*ah`.
\pre `*dh`\f$ \in\f$`darts()`, 0\f$ \leq\f$<I>i</I>\f$ \leq\f$\ref GeneralizedMap::dimension "dimension", <I>i</I>-attributes are non void, and `*ah`\f$ \in\f$\ref GeneralizedMap::attributes() "attributes<i>()".
*/
template <unsigned int i> void set_attribute(Dart_handle dh, Attribute_handle<i>::type ah);

/*!
Deletes all the darts and all the attributes of the generalized map.
*/
void clear();

/*!
Assignment operator. All darts and attributes are duplicated, and the former generalized map is deleted.
*/
GeneralizedMap& operator= (const GeneralizedMap& cmap);

/*!
Swap the current generalized map with `cmap`. There is no copy of darts and attributes thus this method runs in constant time.
*/
void swap(GeneralizedMap& cmap);

/// @}

/// \name Attributes management
/// @{

/*!
Returns the status of the management of the attributes of the generalized map. <code>true</code> if the high level operations update the non void attributes (default value); <code>false</code> otherwise.
*/
bool are_attributes_automatically_managed() const;

/*!
Set the status of the managment of the attributes of the generalized map.

\cgalAdvancedBegin
After calling `set_automatic_attributes_management(false)`, all high level operations will not update non void attributes, until the call of `set_automatic_attributes_management(true)`. The call of `set_automatic_attributes_management(true)` call the \link GeneralizedMap::correct_invalid_attributes `correct_invalid_attributes()`\endlink function.
\cgalAdvancedEnd

*/
void set_automatic_attributes_management(bool update_attributes);

/*!
Correct the invalid attributes of the generalized map. We can have invalid attribute either if we have called \link GeneralizedMap::set_automatic_attributes_management `set_automatic_attributes_management(false)`\endlink before to use some modification operations or if we have modified the generalized map by using low level operations.

\f$ \forall i \f$, 0 \f$ \leq \f$ i \f$ \leq \f$ \ref GeneralizedMap::dimension "dimension" such that the i-attributes are non void, \f$ \forall \f$ d \f$ \in\f$`darts()`:
 - if there exists a dart `d2` in the same i-cell than `d` with a different i-attribute, then the i-attribute of `d2` is set to the i-attribute of `d`;
 - if there exists a dart `d2` in a different i-cell than `d` with the same i-attribute, then the i-attribute of all the darts in i-cell(`d`) is set to a new i-attribute (copy of the original attribute);
 - ensures that \link GeneralizedMap::dart_of_attribute `dart_of_attribute(d)`\endlink \f$ \in \f$ i-cell(`d`).
*/
void correct_invalid_attributes();

/// @}

/// \name Operations
/// @{

/*!
Returns true iff `*dh1` can be <I>i</I>-sewn with `*dh2` by keeping the generalized map valid. This is true if there is a bijection <I>f</I> between all the darts of the orbit <I>D1</I>=\f$ \langle{}\f$\f$ \alpha_0\f$,\f$ \ldots\f$,\f$ \alpha_{i-2}\f$,\f$ \alpha_{i+2}\f$,\f$ \ldots\f$,\f$ \alpha_d\f$\f$ \rangle{}\f$(<I>*dh1</I>) and <I>D2</I>=\f$ \langle{}\f$\f$ \alpha_0\f$,\f$ \ldots\f$,\f$ \alpha_{i-2}\f$,\f$ \alpha_{i+2}\f$,\f$ \ldots\f$,\f$ \alpha_d\f$\f$ \rangle{}\f$(<I>*dh2</I>) satisfying: <I>f</I>(<I>*dh1</I>)=<I>*dh2</I>, and for all <I>e</I>\f$ \in\f$<I>D1</I>, for all <I>j</I>\f$ \in\f${1,\f$ \ldots\f$,<I>i</I>-2,<I>i</I>+2,\f$ \ldots\f$,<I>d</I>},
<I>f</I>(\f$ \alpha_j\f$(<I>e</I>))=\f$ \alpha_j\f$(<I>f</I>(<I>e</I>)).
\pre 0\f$ \leq\f$<I>i</I>\f$ \leq\f$\ref GeneralizedMap::dimension "dimension", `*dh1`\f$ \in\f$`darts()`, and `*dh2`\f$ \in\f$`darts()`.
*/
template <unsigned int i> bool is_sewable(Dart_const_handle dh1, Dart_const_handle dh2) const;

/*!
  <I>i</I>-sew darts `*dh1` and `*dh2`, by keeping the generalized map valid. Links by \f$ \alpha_i\f$ two by two all the darts of the orbit <I>D1</I>=\f$ \langle{}\f$\f$ \alpha_0\f$,\f$ \ldots\f$,\f$ \alpha_{i-2}\f$,\f$ \alpha_{i+2}\f$,\f$ \ldots\f$,\f$ \alpha_d\f$\f$ \rangle{}\f$(`*dh1`) and <I>D2</I>=\f$ \langle{}\f$\f$ \alpha_0\f$,\f$ \alpha_2\f$,\f$ \ldots\f$,\f$ \alpha_{i-2}\f$,\f$ \alpha_{i+2}\f$,\f$ \ldots\f$,\f$ \alpha_d\f$\f$ \rangle{}\f$(`*dh2`) such that <I>d2</I>=<I>f</I>(<I>d1</I>).

<I>f</I> is the bijection between <I>D1</I> and <I>D2</I> satisfying: <I>f</I>(<I>*dh1</I>)=<I>*dh2</I>, and for all <I>e</I>\f$ \in\f$<I>D1</I>, for all <I>j</I>\f$ \in\f${1,\f$ \ldots\f$,<I>i</I>-2,<I>i</I>+2,\f$ \ldots\f$,<I>d</I>}, <I>f</I>(\f$ \alpha_j\f$(<I>e</I>))=\f$ \alpha_j^{-1}\f$(<I>f</I>(<I>e</I>)).

If \link GeneralizedMap::are_attributes_automatically_managed `are_attributes_automatically_managed()`\endlink`==true`, when necessary, non void attributes are updated to ensure the validity of the generalized map: for each <I>j</I>-cells <I>c1</I> and <I>c2</I> which are merged into one <I>j</I>-cell during the sew, the two associated attributes <I>attr1</I> and <I>attr2</I> are considered. If one attribute is NULL and the other not, the non NULL attribute is associated to all the darts of the resulting cell. When the two attributes are non NULL, functor \ref CellAttribute::On_merge "Attribute_type<i>::type::On_merge" is called on the two attributes <I>attr1</I> and <I>attr2</I>. If set, the dynamic onmerge function of <i>i</i>-attributes is also called on <I>attr1</I> and <I>attr2</I>. Then, the attribute <I>attr1</I> is associated to all darts of the resulting <I>j</I>-cell. Finally, attribute <I>attr2</I> is removed from the generalized map.
\pre \ref GeneralizedMap::is_sewable "is_sewable<i>(dh1,dh2)".

\cgalAdvancedBegin
If \link GeneralizedMap::are_attributes_automatically_managed `are_attributes_automatically_managed()`\endlink`==false`, non void attributes are not updated; thus the generalized map can be no more valid after this operation.
\cgalAdvancedEnd

*/
template <unsigned int i> void sew(Dart_handle dh1,Dart_handle dh2);

/*!
  <I>i</I>-unsew darts `*dh` and \f$ \alpha_i\f$`(*dh)`, by keeping the generalized map valid. Unlinks by \f$ \alpha_i\f$ all the darts in the orbit \f$ \langle{}\f$\f$ \alpha_0\f$,\f$ \ldots\f$,\f$ \alpha_{i-2}\f$,\f$ \alpha_{i+2}\f$,\f$ \ldots\f$,\f$ \alpha_d\f$\f$ \rangle{}\f$(`*dh`). If \link GeneralizedMap::are_attributes_automatically_managed `are_attributes_automatically_managed()`\endlink`==true`, when necessary, non void attributes are updated to ensure the validity of the generalized map: for each <I>j</I>-cell <I>c</I> split in two <I>j</I>-cells <I>c1</I> and <I>c2</I> by the operation, if <I>c</I> is associated to a <I>j</I>-attribute <I>attr1</I>, then this attribute is duplicated into <I>attr2</I>, and all the darts belonging to <I>c2</I> are associated with this new attribute. Finally, the functor \ref CellAttribute::On_split "Attribute_type<i>::type::On_split" is called on the two attributes <I>attr1</I> and <I>attr2</I>. If set, the dynamic onsplit function of <i>i</i>-attributes is also called on <I>attr1</I> and <I>attr2</I>. \pre 0\f$ \leq\f$<I>i</I>\f$ \leq\f$\ref GeneralizedMap::dimension "dimension", `*dh`\f$ \in\f$`darts()` and `*dh` is not <I>i</I>-free.

\cgalAdvancedBegin
If \link GeneralizedMap::are_attributes_automatically_managed `are_attributes_automatically_managed()`\endlink`==false`, non void attributes are not updated thus the generalized map can be no more valid after this operation.
\cgalAdvancedEnd
*/
template <unsigned int i> void unsew(Dart_handle dh);

/*!
Links `*dh1` and `*dh2` by \f$ \alpha_i\f$. The generalized map can be no more valid after this operation. If \link GeneralizedMap::are_attributes_automatically_managed `are_attributes_automatically_managed()`\endlink`==true`, non void attributes of `*dh1` and `*dh2` are updated: if one dart has an attribute and the second dart not, the non null attribute is associated to the dart having a null attribute. If both darts have an attribute, the attribute of `*dh1` is associated to `*dh2`.
\pre 0\f$ \leq\f$<I>i</I>\f$ \leq\f$\ref GeneralizedMap::dimension "dimension", `*dh1`\f$ \in\f$`darts()`, `*dh2`\f$ \in\f$`darts()` and (<I>i</I>\f$ <\f$ 2 or `dh1`\f$ \neq\f$`dh2`).
*/
template <unsigned int i> void link_alpha(Dart_handle dh1, Dart_handle dh2);

/*!
Unlinks `*dh` and \f$ \alpha_i\f$(`*dh`) by \f$ \alpha_i\f$. The generalized map can be no more valid after this operation. Attributes of `*dh` and \f$ \alpha_i\f$(`*dh`) are not modified.
\pre 0\f$ \leq\f$<I>i</I>\f$ \leq\f$\ref GeneralizedMap::dimension "dimension", `*dh`\f$ \in\f$`darts()`, and `*dh` is not <I>i</I>-free.
*/
template <unsigned int i> void unlink_alpha(Dart_handle dh);

/// @}

/// \name Dynamic Onmerge/Onsplit functors
/// @{

/*!
  Return the current dynamic onsplit function associated with i-attributes. This is a boost:function returning void and having two references to \link GeneralizedMap::Attribute_type `Attribute_type<i>::type`\endlink as parameters. The onsplit function is returned by reference so that we can modify it.
*/
  template<int i>
  boost::function<void(typename Attribute_type< i >::type&,
                       typename Attribute_type< i >::type&)>&
  onsplit_function();

/*!
  Return the current dynamic onsplit function associated with i-attributes, when *this is const. This is a boost:function returning void and having two references to \link GeneralizedMap::Attribute_type `Attribute_type<i>::type`\endlink as parameters.
*/
  template<int i>
  const boost::function<void(typename Attribute_type< i >::type&,
                             typename Attribute_type< i >::type&)>&
  onsplit_function() const;

/*!
  Return the current dynamic onmerge function associated with i-attributes. This is a boost:function returning void and having two references to \link GeneralizedMap::Attribute_type `Attribute_type<i>::type`\endlink as parameters. The onmerge function is returned by reference so that we can modify it.
*/
  template<int i>
  boost::function<void(typename Attribute_type< i >::type&,
                       typename Attribute_type< i >::type&)>&
  onmerge_function();

/*!
  Return the current dynamic onmerge function associated with i-attributes, when *this is const. This is a boost:function returning void and having two references to \link GeneralizedMap::Attribute_type `Attribute_type<i>::type`\endlink as parameters.
*/
  template<int i>
  const boost::function<void(typename Attribute_type< i >::type&,
                             typename Attribute_type< i >::type&)>&
  onmerge_function() const;

/// @}

/// \name Boolean Marks
/// @{

/*!
Reserves a new mark. Returns its index. If there is no more available free mark, throw the exception Exception_no_more_available_mark.
*/
size_type get_new_mark() const;

/*!
Returns true iff `m` is a reserved mark of the generalized map. \pre 0\f$ \leq\f$<I>m</I>\f$ <\f$\ref  GeneralizedMap::NB_MARKS "NB_MARKS".
*/
bool is_reserved(size_type m) const;

/*!
Returns true iff `*dh` is marked for `m`.
\pre \ref GeneralizedMap::is_reserved "is_reserved(m)" and `*dh`\f$ \in\f$`darts()`.
*/
bool is_marked(Dart_const_handle dh, size_type m) const;

/*!
Marks `*dh` for `m`.
\pre \ref GeneralizedMap::is_reserved "is_reserved(m)" and `*dh`\f$ \in\f$`darts()`.
*/
void mark(Dart_const_handle dh, size_type m) const;

/*!
Unmarks `*dh` for the mark `m`.
\pre \ref GeneralizedMap::is_reserved "is_reserved(m)" and `*dh`\f$ \in\f$`darts()`.
*/
void unmark(Dart_const_handle dh, size_type m) const;

/*!
Inverse the mark `m` for all the darts of the generalized map. All the marked darts become unmarked and all the unmarked darts become marked.
\pre \ref GeneralizedMap::is_reserved "is_reserved(m)".
*/
void negate_mark(size_type m) const;

/*!
Unmarks all the darts of the generalized map for `m`.
\pre \ref GeneralizedMap::is_reserved "is_reserved(m)".
*/
void unmark_all(size_type m) const;

/*!
Returns the number of marked darts for `m`.
\pre \ref GeneralizedMap::is_reserved "is_reserved(m)".
*/
size_type number_of_marked_darts(size_type m) const;

/*!
Return the number of unmarked darts for `m`.
\pre \ref GeneralizedMap::is_reserved "is_reserved(m)".
*/
size_type number_of_unmarked_darts(size_type m) const;

/*!
Frees mark `m`.
\pre \ref GeneralizedMap::is_reserved "is_reserved(m)".
*/
void free_mark(size_type m) const;

/// @}
}; /* end GeneralizedMap */
//@}

