# preprocessor
A C-based Preprocessor project that implements core preprocessing functionalities such as comment removal, macro replacement, and header file inclusion.


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

classDef toneNeutral fill:#f8fafc,stroke:#334155,stroke-width:1.5px,color:#0f172a
classDef toneBlue fill:#dbeafe,stroke:#2563eb,stroke-width:1.5px,color:#172554
classDef toneAmber fill:#fef3c7,stroke:#d97706,stroke-width:1.5px,color:#78350f
classDef toneMint fill:#dcfce7,stroke:#16a34a,stroke-width:1.5px,color:#14532d
classDef toneRose fill:#ffe4e6,stroke:#e11d48,stroke-width:1.5px,color:#881337
classDef toneIndigo fill:#e0e7ff,stroke:#4f46e5,stroke-width:1.5px,color:#312e81
classDef toneTeal fill:#ccfbf1,stroke:#0f766e,stroke-width:1.5px,color:#134e4a
class node_main,node_user toneBlue
class node_macro_count,node_macro_memory,node_macro_parse,node_include toneAmber
class node_line_comments,node_block_comments,node_macro_replace toneMint
class node_input,node_output toneIndigo
