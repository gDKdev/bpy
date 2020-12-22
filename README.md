# bpy

Just a quick project to convert brackets into indention. It reads a file and output the converted content into a file or
to the console.

For the next version, a substitute for shebang got added to execute files directly.

It might be also useful to convert from JSON to a subset of YAML or other stuff.

## Usage

```bpy <input> [output]```

input: path to a file that should be converted

output: path to a file that should be created (optional, without it the result will printed to the console)

It will skip a normal shebang ```#!/path/to/a/executable``` but will replace ```##!/path/to/a/executable``` with it.

## Alternatives

u/SvenNeve mentioned that projects like this already exist. Apparently I'm just to bad to google. Check out Braces,
Python with braces Bython, ...