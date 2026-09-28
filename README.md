<div align="center">

# ⚙️ C Preprocessor

**A lightweight C preprocessor written in C, from scratch.**

Strips comments, expands macros, and resolves `#include` directives, producing a clean, preprocessed source file.

![Language](https://img.shields.io/badge/language-C-00599C?style=for-the-badge&logo=c&logoColor=white)
![Status](https://img.shields.io/badge/status-active-16a34a?style=for-the-badge)
![PRs](https://img.shields.io/badge/PRs-welcome-4f46e5?style=for-the-badge)

</div>

---

## ✨ Features

| Feature | Description | Module |
|---|---|---|
| 🧹 **Line comment removal** | Strips `// ...` comments | `comment.c` |
| 🧹 **Block comment removal** | Strips `/* ... */` comments | `comment.c` |
| 🔁 **Macro replacement** | Expands `#define` macros throughout the source | `macro.c` |
| 📊 **Definition counting** | Counts macro definitions up front | `macro.c` |
| 🧠 **Macro storage** | Allocates memory and stores parsed definitions | `macro.c` |
| 📎 **Header inclusion** | Processes `#include` and writes headers to output | `headerfile.c` |

---

## 🏗️ Architecture

`main.c` acts as the driver. It reads the C source file, delegates work to the directive-handling and source-transform modules, and writes everything to the preprocessed output file.

```mermaid
flowchart TD

subgraph group_driver["Preprocessing driver"]
  node_main["Preprocessing driver<br/>[main.c]"]
end

subgraph group_directives["Directive handling"]
  node_macro_count["Count definitions<br/>[macro.c]"]
  node_macro_memory["Allocate macro storage<br/>[macro.c]"]
  node_macro_parse["Store definitions<br/>[macro.c]"]
  node_include["Include headers<br/>[headerfile.c]"]
end

subgraph group_transforms["Source transforms"]
  node_line_comments["Remove line comments<br/>[comment.c]"]
  node_block_comments["Remove block comments<br/>[comment.c]"]
  node_macro_replace["Replace macros<br/>[macro.c]"]
end

node_user(("User"))
node_input["C source file"]
node_output["Preprocessed file"]

node_user -->|"invokes"| node_main
node_input -->|"reads"| node_main
node_main -->|"opens"| node_output
node_main -->|"counts definitions"| node_macro_count
node_main -->|"allocates storage"| node_macro_memory
node_main -->|"scans definitions"| node_macro_parse
node_main -->|"processes includes"| node_include
node_main -->|"removes comments"| node_line_comments
node_main -->|"removes comments"| node_block_comments
node_main -->|"replaces macros"| node_macro_replace
node_include -->|"writes headers"| node_output
node_macro_replace -->|"writes transformed lines"| node_output

click node_main "https://github.com/syampullamar/preprocessor/blob/main/main.c"
click node_macro_count "https://github.com/syampullamar/preprocessor/blob/main/macro.c"
click node_macro_memory "https://github.com/syampullamar/preprocessor/blob/main/macro.c"
click node_macro_parse "https://github.com/syampullamar/preprocessor/blob/main/macro.c"
click node_include "https://github.com/syampullamar/preprocessor/blob/main/headerfile.c"
click node_line_comments "https://github.com/syampullamar/preprocessor/blob/main/comment.c"
click node_block_comments "https://github.com/syampullamar/preprocessor/blob/main/comment.c"
click node_macro_replace "https://github.com/syampullamar/preprocessor/blob/main/macro.c"

classDef toneBlue fill:#dbeafe,stroke:#2563eb,stroke-width:1.5px,color:#172554
classDef toneAmber fill:#fef3c7,stroke:#d97706,stroke-width:1.5px,color:#78350f
classDef toneMint fill:#dcfce7,stroke:#16a34a,stroke-width:1.5px,color:#14532d
classDef toneIndigo fill:#e0e7ff,stroke:#4f46e5,stroke-width:1.5px,color:#312e81
class node_main,node_user toneBlue
class node_macro_count,node_macro_memory,node_macro_parse,node_include toneAmber
class node_line_comments,node_block_comments,node_macro_replace toneMint
class node_input,node_output toneIndigo
```

> 💡 **Tip:** on GitHub, each box in the diagram links straight to its source file.

### Color legend

| Color | Meaning |
|---|---|
| 🟦 Blue | Entry point: the user and the driver |
| 🟨 Amber | Directive handling (`#define`, `#include`) |
| 🟩 Green | Source transforms (comments, macro expansion) |
| 🟪 Indigo | Input and output files |

---

## 🔄 How It Works

1. **Invoke**: the user runs the preprocessor from the command line.
2. **Read**: `main.c` opens the C source file and creates the output file.
3. **Scan directives**: `macro.c` counts `#define` entries, allocates storage, and stores each definition.
4. **Process includes**: `headerfile.c` resolves `#include` directives and writes header contents to the output.
5. **Transform source**: `comment.c` removes line and block comments, then `macro.c` replaces macros in the remaining code.
6. **Write**: the transformed lines land in the preprocessed file.

---

## 📁 Project Structure

```
preprocessor/
├── main.c         # Driver: orchestrates the whole pipeline
├── macro.c        # Macro counting, storage, parsing and replacement
├── comment.c      # Line (//) and block (/* */) comment removal
├── headerfile.c   # #include handling
└── README.md
```

---

## 🚀 Getting Started

### Prerequisites

- A C compiler such as `gcc` or `clang`
- `make` (optional)

### Build

```bash
git clone https://github.com/syampullamar/preprocessor.git
cd preprocessor
gcc -Wall -Wextra -o preprocessor main.c macro.c comment.c headerfile.c
```

### Run

```bash
./preprocessor input.c output.c
```

---

## 🧪 Example

**Input** (`input.c`)

```c
#define PI 3.14159
#define SQUARE(x) ((x) * (x))

/* Compute the area of a circle */
float area(float r) {
    return PI * SQUARE(r); // area = πr²
}
```

**Output** (`output.c`)

```c
float area(float r) {
    return 3.14159 * ((r) * (r));
}
```

---

## 🗺️ Roadmap

- [ ] Conditional compilation (`#ifdef`, `#ifndef`, `#else`, `#endif`)
- [ ] Function-like macro argument handling edge cases
- [ ] `#undef` support
- [ ] Better error messages with line numbers
- [ ] Unit tests

---

## 🤝 Contributing

Contributions, issues, and feature requests are welcome!

1. Fork the repository
2. Create your branch: `git checkout -b feature/my-feature`
3. Commit your changes: `git commit -m "Add my feature"`
4. Push and open a Pull Request

---

## 📄 License

Distributed under the MIT License. See `LICENSE` for details.

---

<div align="center">

**Built by [Syam Prasad Pullamar](https://github.com/syampullamar)**

If you found this useful, consider giving it a ⭐

</div>
