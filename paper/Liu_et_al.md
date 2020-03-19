## methods to deal with the non-convexity
- convexification: transforming the non-convex problem into a convex one.
  - dis: only handle quadratic cost function
- sequential quadratic programming: approximates the non-convex as a sequence of quadratic programming(QP) problems and solves them iteratively.
  - this method has been successfully applied to offline robot motion planning.
  - dis: not real time
- transform the non-convex problem to semidefinite programming(SDP)
  - dis: 
     - highly depends on the linearity of hte system
     - may not be able to handle diverse obstacles. 
- lossless convexification by augmenting the space
  - dis:
     - may not generalize to non-differentiable problems.
- successive linear approximation to remove non-convex constraints

the mian idea of the CFS algorithm is to transform the original problem into a sequence of convex subproblems by obtaining convex feasible sets within the non-convex domain, then iteratively solve the convex subproblems until convergence.
the difference between CFS and SQP lies in the way to obtain the convex subproblems.
## catalogue
### 2. proposes a benchmark optimization problem
2.1 the benchmark problem
Assumption 2.1 J is smooth and  strictly convex.

Assumption 2.2 the set is connected and closed, with piecewise smooth and non-self-intersecting boundary. for every point x, there exists an n-dimensional convex polytope. it specifies the geometric features of the feasible set, where the first part deals with the topological features and the second part ensures that there is convex neighborhood for any point. Note that equality
constraints are excluded by Assumption 2.2 as the dimension of the neighborhood for any point
satisfying a equality constraint is strictly less than n.

### 3. discusses the proposed CFS algorithm in solving the benchmark problem
### 4. shows the feasibility and convergence of the algorithm 
### 5. illustrates the application of the algorithm on motion planning problems for mobile robots
13页看完了。
