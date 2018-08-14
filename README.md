# Proof of concept for run-time linking

The idea is to be able to link C++ code from different packages at run-time.
To demonstrate, install **packA** and **pack** in any order, and then run the following code:

```{r}
library(packB)
.Call("runner", 1, 2, PACKAGE="packB")
```

The `runner` C++ function (in **packB**) will first attach **packA**;
then use R's API to search for a C function in the shared library of **packA**;
and finally, execute that C function and return a result (in this case, addition of the two scalars).

This mechanism provides more options for the **beachmat** API, in that we no longer need to define the universe of all matrix representations at compile time.
