# Development Guide - XIAO ePaper Serial Display

## Git Repository Setup Complete ✅

Your project is now under Git version control. Here's how to manage changes:

## Basic Git Workflow

### Making Changes
1. Edit your files (`.ino`, `driver.h`, `README.md`)
2. Test your changes
3. Stage and commit when ready

### Essential Git Commands

```bash
# Check what files have changed
git status

# See what changes were made
git diff

# Stage all changes
git add .

# Stage specific file
git add XIAO_ePaper_Serial_Display.ino

# Commit with descriptive message
git commit -m "Add new feature: XYZ"

# View commit history
git log --oneline

# View detailed log
git log
```

## Useful Development Commands

### Creating Feature Branches
```bash
# Create and switch to new branch
git checkout -b feature/new-display-mode

# Switch back to master
git checkout master

# Merge feature branch
git merge feature/new-display-mode
```

### Reverting Changes
```bash
# Revert to last commit (lose all uncommitted changes)
git reset --hard HEAD

# Revert to specific commit
git reset --hard <commit-hash>

# Create a new commit that undoes a previous commit
git revert <commit-hash>
```

### Viewing History and Changes
```bash
# See all commits with details
git log --graph --pretty=format:'%h - %an, %ar : %s'

# See changes in a specific commit
git show <commit-hash>

# Compare two commits
git diff <commit1>..<commit2>
```

## Project Structure

```
XIAO_ePaper_Serial_Display/
├── .git/                                    # Git repository data
├── .gitignore                              # Files to ignore
├── driver.h                                # Hardware configuration
├── XIAO_ePaper_Serial_Display.ino         # Main Arduino sketch
├── README.md                               # Project documentation
└── DEVELOPMENT.md                          # This file
```

## Best Practices

1. **Commit frequently** - Small, focused commits are better than large ones
2. **Write good commit messages** - Describe what and why, not just what
3. **Test before committing** - Make sure your code compiles and works
4. **Use branches for experiments** - Keep master stable

## Example Commit Messages

Good commit messages:
```
Add partial refresh option to reduce update time
Fix ghosting issue in updateDisplay function  
Update README with new serial commands
Optimize screen clearing sequence for faster updates
```

## Backup Strategy

Your code is now safely tracked in Git. Consider:
1. **Regular commits** to save incremental progress
2. **Creating tags** for stable versions: `git tag v1.0`
3. **Pushing to GitHub/GitLab** for cloud backup (optional)

## Next Steps

1. Make a change to test the workflow
2. Use `git status` and `git diff` to see changes
3. Commit your changes with `git add .` and `git commit -m "message"`
4. Create experimental branches for trying new features

Happy coding! 🚀
