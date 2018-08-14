# Proof of concept for run-time linking

The idea is to be able to link C++ code from different packages at run-time.
To demonstrate, install **packA** and **packB** in any order, and then run the following code in an R session:

```{r}
library(packB)
.Call("runner", 1, 2, PACKAGE="packB")
```

The `runner` C++ function (in **packB**) will first attach **packA** to the current section;
use R's `R_getCCallable` mechanism to search for a C function in the shared library of **packA**;
and finally, execute that C function and return a result (in this case, addition of the two supplied scalars).

This strategy provides more options for the **beachmat** API, in that we no longer need to define the universe of all matrix representations at compile time.
The aim is to allow downstream packages implementing their own matrix representations to also implement their own C++ routines that can be exploited by **beachmat**.
This is more efficient than relying on block realization via R for arbitrary matrices.
