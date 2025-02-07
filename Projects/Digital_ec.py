class Gates:
    def AND(self, *inp) -> str:
        for x in inp:
            if x == "0":
                return "0"
        return "1"
    
    def OR(self, *inp) -> str:
        for x in inp:
            if x == "1":
                return "1"
        return "0"
    
    def NOT(self, inp) -> str:
        return "1" if inp == "0" else "0"
    
    def NAND(self, *inp) -> str:
        return self.NOT(self.AND(*inp))
    
    def NOR(self, *inp) -> str:
        return self.NOT(self.OR(*inp))
    
    def XOR(self, *inp) -> str:
        return "1" if inp.count("1") % 2 == 1 else "0"
    
    def XNOR(self, *inp) -> str:
        return "1" if inp.count("1") % 2 == 0 else "0"

class Circuits(Gates):
    def HalfAdder(self, addend: str, augend: str) -> dict:
        return {"c": self.AND(addend, augend), "s": self.XOR(addend, augend)}

    def FullAdder(self, addend: str, augend: str, Cin = "0") -> dict:
        return {"c": self.OR(self.AND(addend, augend), self.AND(Cin, self.OR(addend, augend))), "s": self.XOR(addend, augend, Cin)}
    
    def input_balancer(self, addend: str, augend: str) -> tuple[str, str]:
        max_len = max(len(addend), len(augend))
        return addend.zfill(max_len), augend.zfill(max_len)

    def ParallelAdder(self, addend: str, augend: str, Cin = "0") -> str:
        addend, augend = self.input_balancer(addend, augend)
        n = len(addend)
        result = ""
        for i in range(n-1, -1, -1):
            full_adder_result = self.FullAdder(addend[i], augend[i], Cin)
            result = full_adder_result["s"] + result
            Cin = full_adder_result["c"]
        return result if Cin == "0" else Cin + result
    
    def ones_comp(self, inp: str) -> str:
        result = ""
        for x in inp:
            result += self.XOR("1", x)
        return result
    
    def ParallelAdderAndSubtracter(self, A: str, B: str, mode: int) -> str:
        if mode not in [0, 1]:
            raise ValueError(f"Invalid Mode value mode = {mode}")
        A, B = self.input_balancer(A, B)
        n = len(A)
        cin = "0"
        # Preprocessing the second string to make calculation easier
        if mode == 1:
            B = self.ones_comp(B)
            cin = "1"
        
        sum_result = "0" + self.ParallelAdder(A, B, cin)
        
        if len(sum_result) == n:  # Answer is in 2's complement form
            return "1" + self.ParallelAdder("1", self.ones_comp(sum_result))
        else:
            return sum_result[-n:]
    
    def shift_right(self, inp: str) -> str:
        return "0" + inp[:-1]
    
    def arithmetic_shift(self, inp: str) -> str:
        return inp[0] + inp[:-1]
    
    def BoothMultiplication(self, BR: str, QR: str) -> str:
        n = len(BR)
        SC = n    # Sequence Counter
        AC = "".zfill(n)
        BR1Comp = self.ones_comp(BR)
        qn1 = "0"
        qn = QR[-1]
        while SC != 0:
            if qn + qn1 == "10":
                AC = self.ParallelAdder(AC, BR1Comp, "1")[-n:]
            if qn + qn1 == "01":
                AC = self.ParallelAdder(AC, BR)[-n:]
            shift_result = self.arithmetic_shift(AC + QR + qn1)
            AC = shift_result[:n]
            QR = shift_result[n:2*n]
            qn1 = shift_result[2*n]
            qn = QR[-1]
            SC -= 1
        return AC + QR

class Solution:
    def binary2dec(self, binary: str) -> str:
        # Handle negative results in 2's complement
        if binary[0] == '1':  # Negative number
            n = len(binary)
            return str(int(binary, 2) - (1 << n))
        return str(int(binary, 2))

    def dec2bin(self, decimal: str, n: int) -> str:
        decimal_int = int(decimal)
        if decimal_int == 0:
            return "0"
        binary = bin(decimal_int & (2**n - 1))[2:]  # Ensure n-bit representation
        return binary.zfill(n)

    def multiply(self, num1: str, num2: str, n: int) -> str:
        ckt = Circuits()
        BR = self.dec2bin(num1, n)
        QR = self.dec2bin(num2, n)
        result = ckt.BoothMultiplication(BR, QR)
        return self.binary2dec(result)

# Example usage:
print(Solution().multiply("2", "3", 4))  # Should output 6 (using 4-bit representation)
