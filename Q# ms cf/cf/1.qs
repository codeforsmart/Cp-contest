namespace Solution {

    open Microsoft.Quantum.Intrinsic;
    open Microsoft.Quantum.Measurement;
    open Microsoft.Quantum.Canon;

    operation Solve2 (unitary : (Qubit[] => Unit is Adj+Ctl)) : Int {
        // your code here
        //return 1;
        
        using(qs = Qubit[2])
        {
        X(qs[1]);
        unitary(qs);
        //return 1;
        let result = M(qs[0]);
        ResetAll(qs);
        return result == One ? 1 | 0;
        }
        
    }
    operation Solve (unitary : (Qubit[] => Unit is Adj+Ctl)) : Int {
        // your code here
            mutable ans = -1;
            using(qs = Qubit[2])
            {
            X(qs[1]);
            X(qs[0]);
            unitary(qs);
            //return 1;
            let result1 = M(qs[0]);
            let result2 = M(qs[1]);
            ResetAll(qs);
            
            
            
            if(result1 == Zero )
            {
                set ans = 2;
            }
            if(result2 == Zero) 
            {
                set ans = 1;
            }

            }

            if(ans==-1)
            {
                using(qs = Qubit[2])
                {
                X(qs[0]);
                unitary(qs);
                //return 1;
                let result1 = M(qs[0]);
                let result2 = M(qs[1]);
                ResetAll(qs);
                
                

                if(result1 == One )
                {
                    set ans = 0;
                }
                else{ set ans = 3;}

                }
            }
            return ans;
        }
    

}
