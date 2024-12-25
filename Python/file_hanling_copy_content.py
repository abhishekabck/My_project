source_add = "./output.txt"
destination_add = "./destination.txt"

# Opening source file
try:
    with open(source_add, "r") as sfile:
        with open(destination_add, "w") as dfile:
            dfile.write(sfile.read())
    print("Copied Successfully..")
except FileNotFoundError:
    print("Source Not Find.")
except Exception as e:
    print("Certain Error occured:", e)
