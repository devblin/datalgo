# Recursion

- Types of Recursion:
  - Linear
    - Tail
    - Head
  - Tree
  - Indirect
  - Nested
- Time & Space Complexity of Recursive Function:

  ```
  void fun(int n) {
  	if(n > 0) {
  		printf("%d", n);
  		fun(n-1);
  	}
  }

  Calling above function for n = 3:
  ---------------------------------
        fun(3) -----> 1
  		  /\
  		 /	\
  		3  fun(2) -----> 2
  			  /\
  		 	 /	\
  			2	fun(1) -----> 3
  		  		  /\
  		 	 	 /	\
  				1	fun(0) -----> 4
  			  	   		|
  						X

  For n=3, fun() is called 4 times,
  So, for n = k fun() will be called (k+1) times
  Time Complexity -> O(n+1) = O(n)

  Output:
  -------
  3 2 1
  ```

- Recurrence Relation:

  ```
  Given Recursive Function:
  -------------------------

  void fun(int n) {  ----------> T(n)
  	if(n > 0) { -----------> 1
  		printf("%d", n); ---------> 1
  		fun(n-1); ----------> T(n-1)
  	}
  }

  T(n) = {
  			1, 			n = 0
  			T(n-1) + 2, n > 0
  		}

  T(n) = T(n-1) + 1
  T(n) = T(n-k) + k

  n-k = 0
  n = k

  T(n) = T(0) + n = 1 + n
  ```
