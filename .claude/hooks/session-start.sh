#!/bin/bash
# PULPissimo session startup hook
# Installs Bender (RTL dependency manager) so that make targets work.
# Commercial EDA tools (QuestaSim, SpyGlass, Genus) must be available
# in PATH via your site's EDA environment (module load / eda aliases).

set -euo pipefail

# Only run in remote Claude Code web sessions
if [ "${CLAUDE_CODE_REMOTE:-}" != "true" ]; then
  exit 0
fi

REPO_ROOT="$(git rev-parse --show-toplevel 2>/dev/null || echo "$CLAUDE_PROJECT_DIR")"
UTILS_BIN="$REPO_ROOT/utils/bin"

echo "[session-start] PULPissimo environment setup starting..."

# ── 1. Install Bender (RTL dependency manager) ──────────────────────────────
if [ ! -f "$UTILS_BIN/bender" ]; then
  echo "[session-start] Installing Bender 0.28.0..."
  mkdir -p "$UTILS_BIN"
  cd "$UTILS_BIN"
  curl --proto '=https' --tlsv1.2 -sSf \
    https://pulp-platform.github.io/bender/init | bash -s -- 0.28.0
  touch "$UTILS_BIN/bender"
  echo "[session-start] Bender installed: $($UTILS_BIN/bender --version)"
else
  echo "[session-start] Bender already present: $($UTILS_BIN/bender --version)"
fi

# Add bender to PATH for this session
echo "export PATH=\"$UTILS_BIN:\$PATH\"" >> "${CLAUDE_ENV_FILE:-/dev/null}"
export PATH="$UTILS_BIN:$PATH"

# ── 2. Checkout RTL dependencies (if not already done) ──────────────────────
cd "$REPO_ROOT"
if [ ! -d ".bender" ]; then
  echo "[session-start] Checking out RTL IP dependencies via Bender..."
  "$UTILS_BIN/bender" checkout
  echo "[session-start] Bender checkout complete."
else
  echo "[session-start] Bender checkout cache present (.bender/)."
fi

# ── 3. Python venv for boot ROM generation tools ────────────────────────────
if [ -f "$REPO_ROOT/sw/bootcode/requirements.txt" ]; then
  VENV_DIR="$REPO_ROOT/utils/.venv"
  if [ ! -d "$VENV_DIR" ]; then
    echo "[session-start] Creating Python venv for boot ROM tools..."
    python3 -m venv "$VENV_DIR"
    "$VENV_DIR/bin/pip" install -q \
      -r "$REPO_ROOT/sw/bootcode/requirements.txt"
    echo "[session-start] Python venv ready."
  else
    echo "[session-start] Python venv already present."
  fi
  echo "export PATH=\"$VENV_DIR/bin:\$PATH\"" >> "${CLAUDE_ENV_FILE:-/dev/null}"
fi

echo "[session-start] PULPissimo environment setup complete."
echo "[session-start] Note: EDA tools (vsim, sg_shell, genus) must be"
echo "[session-start]       loaded separately via your site EDA environment."
