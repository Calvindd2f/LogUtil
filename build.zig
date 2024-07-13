const Builder = @import("std").build.Builder;

pub fn build(b: *Builder) void {
    const mode = b.standardReleaseOptions();

    const exe = b.addSharedLibrary("logutil", "LogUtil.cpp", .{
        .target = b.standardTargetOptions(.{}),
        .name = "logutil",
        .version = .{
            .major = 0,
            .minor = 0,
            .patch = 1,
        },
    });

    exe.setBuildMode(mode);
    exe.linkLibC();
    exe.linkSystemLibrary("c++");

    // Copy the header file to the output directory
    const hdr_dest = b.addSystemCommand(&[_][]const u8{
        "cp", "LogUtil.h", b.output_dir(),
    });
    hdr_dest.step.dependOn(&exe.step);

    // Install step
    const install_step = b.step("install", "Install the library and header file");
    install_step.dependOn(&exe.step);
    install_step.dependOn(&hdr_dest.step);
}
