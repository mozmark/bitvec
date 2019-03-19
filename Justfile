ci:
	watchexec -- just dev

dev:
	just rust/dev
	just c/dev
	just cs/dev
	just python/dev
	just ruby/dev

foreign:
	cargo build --features ffi
	mkdir -p target/ffi/docs
	doxygen ffi/Doxyfile
	clang++ -std=c++11 -Iffi -Ltarget/debug examples/foreign.cpp -lbitvec -o target/foreigner
	target/foreigner
