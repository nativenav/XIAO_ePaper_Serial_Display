#!/bin/bash

echo "=== GitHub Authentication Setup ==="
echo
echo "Choose your preferred authentication method:"
echo "1. Personal Access Token (Easiest)"
echo "2. SSH Key (Most Secure)"
echo "3. GitHub CLI (Most Convenient)"
echo

read -p "Enter choice (1-3): " choice

case $choice in
    1)
        echo
        echo "=== Personal Access Token Setup ==="
        echo "1. Go to: https://github.com/settings/personal-access-tokens/tokens"
        echo "2. Click 'Generate new token (classic)'"
        echo "3. Give it a name: 'XIAO ePaper Project'"
        echo "4. Select scope: 'repo' (full control of private repositories)"
        echo "5. Generate and copy the token"
        echo
        echo "Then run:"
        echo "git push -u origin main"
        echo "Username: nativenav"
        echo "Password: [paste your token]"
        ;;
    2)
        echo
        echo "=== SSH Key Setup ==="
        echo "Generating SSH key..."
        ssh-keygen -t ed25519 -C "nativenav@github.com" -f ~/.ssh/id_ed25519
        echo
        echo "Add this public key to GitHub:"
        echo "https://github.com/settings/ssh/new"
        echo
        cat ~/.ssh/id_ed25519.pub
        echo
        echo "After adding to GitHub, change remote to SSH:"
        echo "git remote set-url origin git@github.com:nativenav/XIAO_ePaper_Serial_Display.git"
        echo "git push -u origin main"
        ;;
    3)
        echo
        echo "=== GitHub CLI Setup ==="
        echo "Run these commands:"
        echo "gh auth login --web"
        echo "git push -u origin main"
        ;;
    *)
        echo "Invalid choice"
        exit 1
        ;;
esac

echo
echo "After authentication is set up, your local repository will be"
echo "connected to: https://github.com/nativenav/XIAO_ePaper_Serial_Display"
