#include "unity.h"
#include "state_machine.h"

void setUp(){}

void tearDown(){}

void test_idle_state(void){
    SystemState state;
    state = updateSystemState(25, 30, 10, 0, 0);
    TEST_ASSERT_EQUAL(SYSTEM_IDLE, state);
}

void test_cooling_state(void){
    SystemState state;
    state = updateSystemState(35, 30, 10, 0, 0);
    TEST_ASSERT_EQUAL(SYSTEM_COOLING, state);
}

void test_warning_state(void){
    SystemState state;
    state = updateSystemState(45, 30, 10, 0, 0);
    TEST_ASSERT_EQUAL(SYSTEM_WARNING, state);
}

void test_fault_state(void){
    SystemState state;
    state = updateSystemState(25, 30, 10, 1, 0);
    TEST_ASSERT_EQUAL(SYSTEM_FAULT, state);
}

void test_emergency_stop(void)
{
    SystemState state;
    state = updateSystemState(25, 30, 10, 0, 1);

    TEST_ASSERT_EQUAL(SYSTEM_EMERGENCY_STOP, state);
}

int main(void) {
    UNITY_BEGIN();
    // State machine tests
    RUN_TEST(test_idle_state);
    RUN_TEST(test_cooling_state);
    RUN_TEST(test_warning_state);
    RUN_TEST(test_fault_state);
    RUN_TEST(test_emergency_stop);

    return UNITY_END();
}
