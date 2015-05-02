#!/usr/bin/python
import argparse, os, sys, subprocess, shutil, copy

def log(txt):
	sys.stdout.write(txt + "\n")
	sys.stdout.flush()

def run():
	params = {}

	path = os.getenv("TOOLCHAIN_PATH", "../toolchain")
	params["TOOLCHAIN_PATH"] = os.path.realpath(path)

	path = os.getenv("HFRAMEWORK_PATH", "../hFramework")
	if path is not None:
		params["HFRAMEWORK_PATH"] = os.path.realpath(path)

	path = os.getenv("HPYTHON_PATH", "../hPython")
	if path is not None:
		params["HPYTHON_PATH"] = os.path.realpath(path)

	path = os.getenv("HSENSORS_PATH", "../robocore-sensors")
	if path is not None:
		params["HSENSORS_PATH"] = os.path.realpath(path)

	args = argparse.ArgumentParser()
	args.add_argument("--debug", action="store_true")
	args.add_argument("--release", action="store_true")
	args.add_argument("--main", action="store_true")
	args = args.parse_args()

	types=["big"]
	versions=["0.9.5", "0.9.6", "0.9.7"]

	rmdir("bin/")
	os.mkdir("bin")

	for type in types:
		for version in versions:
			if args.main:
				if args.debug:
					build(type, version, True, "firmware/.", params)
				if args.release:
					build(type, version, False, "firmware/.", params)

def build(type, version, debug, path, params):
	log("{0} {1} {2}".format(type, version, debug))

	params = copy.copy(params)
	params["ROBOCORE_TYPE"] = type
	params["ROBOCORE_VERSION"] = version
	if debug:
		params["DEBUG"] = "1"
	else:
		params["DEBUG"] = "0"

	args = []
	args.append("cmake")
	args.append(path)
	args.append("-Bbuild_tmp")
	args += ["-D{0}={1}".format(k,v) for k, v in params.items()]

	rmdir("build_tmp/")
	subprocess.check_call(args)
	subprocess.check_call(["make", "-Cbuild_tmp/"])
	if debug:
		os.rename("build_tmp/hPyFramework.hex", "bin/hPyFrameworkd_{0}_{1}.hex".format(version, type))
	else:
		os.rename("build_tmp/hPyFramework.hex", "bin/hPyFramework_{0}_{1}.hex".format(version, type))

def rmdir(path):
	if os.path.exists(path):
		shutil.rmtree(path)

run()
rmdir("build_tmp/")
