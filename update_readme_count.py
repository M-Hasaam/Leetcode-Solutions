import os
import re
from collections import Counter

# Step 1: Count difficulties
counter = Counter()
for folder in os.listdir("."):
    readme_path = os.path.join(folder, "README.md")
    if os.path.isdir(folder) and os.path.exists(readme_path):
        with open(readme_path, encoding="utf-8") as f:
            content = f.read()
            match = re.search(r"Difficulty-(Easy|Medium|Hard)", content)
            if match:
                counter[match.group(1)] += 1

# Step 2: Generate the new stats block
total = sum(counter.values())
stats_block = f"""
### 📈 Problem Breakdown (Updated Automatically)

| Difficulty | Count |
|------------|-------|
| 🟢 Easy     | {counter['Easy']} |
| 🟡 Medium   | {counter['Medium']} |
| 🔴 Hard     | {counter['Hard']} |
| **Total**   | **{total}** |
"""

# Step 3: Replace the block inside main README.md
readme_main = "README.md"
with open(readme_main, "r", encoding="utf-8") as f:
    content = f.read()

# Replace block between specific markers (or add them if missing)
start_marker = "<!-- PROBLEM_COUNT_START -->"
end_marker = "<!-- PROBLEM_COUNT_END -->"

pattern = f"{start_marker}.*?{end_marker}"
replacement = f"{start_marker}\n{stats_block.strip()}\n{end_marker}"
new_content = re.sub(pattern, replacement, content, flags=re.DOTALL)

# Write updated README
with open(readme_main, "w", encoding="utf-8") as f:
    f.write(new_content)

print("✅ README.md has been updated with the latest problem count.")
