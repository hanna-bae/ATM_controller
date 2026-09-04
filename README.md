# ATM Controller 

A simple C++ implementation of an ATM controller that manages the basic ATM: 

1. insert a card 
2. Authenticate the card
3. Select and account 
4. Check balance 
5. Deposit funds 
6. Withdraw funds 
7. Eject the card 

The project focuses on the ATM controller logic. External banking systems, user interfaces, and ATM hardware are outside the scope of this implementation. 

# Getting Started 
## Installation 
Clone the repository:

```
git clone https://github.com/hanna-bae/ATM_controller.git 
cd ATM_controller 
```

Configure and build the project:

```
cmake -S . -B build 
cmake --build build 
```

## Run 
Run the example ATM flow:
```
./build/atm 
```
Example output:

Initial balance: 1000
After deposit: 1500
After withdrawal: 1200

## Tests 
Tests are implemented using GoogleTest and are located in the tests/ directory. 

Run all tests:
```
ctest --test-dir build --output-on-failure 
```
Or run the GoogleTest exetuable direclty:
```
./build/tests/atm_tests
```
