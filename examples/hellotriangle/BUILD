package(default_visibility = ["//visibility:private"])

filegroup(
    name = "source",
    srcs = glob([
        "*.h",
        "*.cpp",
    ]),
)

SHADER_FILES = glob(["shaders/**/*"])

cc_binary(
    name = "hellotriangle",
    srcs = [":source"],
    data = SHADER_FILES,
    linkopts = [
        "-lX11",    
        "-lpthread",    
        "-lGL",
        "-ldl",
    ],
    visibility = ["//visibility:public"],
    deps = [
        "//grok3d",
        "@glm",
    ],
)
