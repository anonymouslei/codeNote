###Clothoid curves
is defined in terms of Fresnel integrals.
using clothoid curves is possible
to define trajectories with linear changes
in curvature since their curvature is equal to
their arc-length; making smooth transitions
between straight segments to curved ones and vice
versa. Clothoids have been implemented 
in the design of highways and railways
and are also suitbale for car-like robots.

###Bezier curve
these are parametric curves that rely
on control points to define their shape.
The core of Bezier curves are
the **Bernstein polynomials**.
these curves have been extensively used in 
CAGD applications, technical drawing,
aeronautical and automotive design.
####advantage
- their low computational cost, since the curve behavior
its defined by control points
- the constraints at the beginning and
the end of the curvature can be met
by correctly placing these control
points according to different properties.
####application
3rd and 4th degree Beziers are implemented
in automated vehicles, evaluating the best
applicable curve to the situation in hand(i.e. 
turns, roundabouts, lane change, obstacle avoidance, among others)

###spline curves
a splien is a piecewise polynomial
parametric curve divided in sub-intervals
that can be defined as polynomial curves, b-splines(that can also
be represented in Bezier curves)
or clothoid curves. the junction between each
sub-segment is called knot and they commonly
possess a high degree of smoothness
constraint at the joint
between the pieces of hte spline.
their approximation ability and the properties of their shape depend on the number of 
B-spline basis functions used for defining them.
