 __attribute__((no_instrument_function, always_inline))
inline void __cyg_profile_func_enter(void* func, void* caller) {
	//asm volatile("ud2");
}

__attribute__((no_instrument_function, always_inline))
inline void __cyg_profile_func_exit(void* func, void* caller) {
	unsigned long* fn = func;
	int i = 0;
	for (; ; i++) {
		if (fn[i] == 0xC3)
			break;
	}
}

int main() {
	return 0;
}
