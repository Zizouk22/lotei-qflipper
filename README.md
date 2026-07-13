

https://github.com/user-attachments/assets/026177db-b18d-437a-8670-7ccf5799bc9e

<img width="686" height="411" alt="IMG_9806" src="https://github.com/user-attachments/assets/0e165538-80c4-457a-b36a-4331c0b58be4" />
<img width="682" height="408" alt="IMG_9804" src="https://github.com/user-attachments/assets/3ae68568-b233-458a-a736-937bb4b0b3d7" />
<img width="683" height="397" alt="IMG_9805" src="https://github.com/user-attachments/assets/c2223c8c-0d02-4a31-b9bb-34edef6ee2fe" />

# 🐬 Hyper-Zero-UI (HZUI)

[![Latest release](https://img.shields.io/github/v/release/DUNKINKKD/lotei-qflipper?color=ff4fa3&label=release)](https://github.com/DUNKINKKD/lotei-qflipper/releases/latest)
[![Downloads](https://img.shields.io/github/downloads/DUNKINKKD/lotei-qflipper/total?color=ff4fa3)](https://github.com/DUNKINKKD/lotei-qflipper/releases)
[![License](https://img.shields.io/badge/license-GPLv3-ff4fa3.svg)](LICENSE)
[![Stars](https://img.shields.io/github/stars/DUNKINKKD/lotei-qflipper?color=ff4fa3)](https://github.com/DUNKINKKD/lotei-qflipper/stargazers)
[![100% local](https://img.shields.io/badge/AI-100%25%20local-ff4fa3)](#)
[![Powered by Ollama](https://img.shields.io/badge/powered%20by-Ollama-ff4fa3)](https://ollama.com)

> **Unofficial fork** of [qFlipper](https://github.com/flipperdevices/qFlipper), the Flipper Zero desktop app. Not affiliated with or endorsed by Flipper Devices.

A heavily-customized qFlipper UI starring **LOTEI** — a snarky, **100% local** AI dolphin that lives inside the app — plus a full pink makeover, a runtime color editor, neural voice, and a live Flipper-screen mirror.

**Local by default — no API keys, no cloud, no cost.** LOTEI runs entirely on your machine via [Ollama](https://ollama.com). If your local model feels underpowered, an **optional cloud brain** (DeepSeek) is one click away in the chat header — it keeps full Flipper tool access, and your API key is stored locally, never synced. Toggle `⌂ local` ⇄ `☁ cloud` to switch anytime.

<!-- Screenshots: on GitHub, click the pencil (Edit) on this README and drag your
     images / video right here — GitHub uploads + hosts them and inserts the markdown
     for you, no need to commit the files. -->

## ✨ Features

- **🐬 LOTEI** — a local-AI chat assistant (Ollama + `qwen2.5:7b`) built right into the app: a flirty, vain, RAM-glutton pink dolphin with **agentic tools**, all over qFlipper's existing RPC link.
- **🛠️ Full agentic toolset** — LOTEI drives the Flipper end-to-end: browse/read files, **create/delete/rename** files & folders, **stat** paths and read **free space**, save scripts, **launch any app** directly (a built-in like Sub-GHz/NFC/Bad USB, or any `.fap` by path), press buttons, and **reboot**. Give it a goal, it chains the calls itself.
- **☁ Optional cloud brain** — switch LOTEI from local Ollama to **DeepSeek** (OpenAI-compatible) right from the chat header when you want stronger answers. Same agentic Flipper tools, streamed live; the API key + model are set in-app (⚙) and stored locally.
- **🎭 Swappable personalities** — pick a preset from the setup wizard: the default snarky pink dolphin, or others including an **"Agent black-hat (FR)"** — a cold, French-speaking rogue operator that just executes. A chosen preset fully replaces the default character *and* language.
- **🎙️ Neural voice** — local [Piper](https://github.com/rhasspy/piper) text-to-speech with a click-to-cycle voice switcher and mood-based tempo. Falls back to Windows SAPI if Piper isn't installed.
- **🎨 Live color editor** — recolor the *entire* UI at runtime, every color individually, with live preview. Persists across launches. (Click **COLORS**, top-left.)
- **👁️ Flipper-screen mirror** — watch the device's 128×64 screen live in the chat panel as LOTEI works.
- **🎵 Music player** — drop `.mp3`s into a `Music/` folder next to the exe; shuffle-plays in the footer.
- **💖 Full pink theme** throughout.

## 🧰 Requirements

- **Windows 10/11** (64-bit)
- **[Qt 6.4.2](https://www.qt.io/)** (`msvc2019_64`) — easiest via [`aqt`](https://github.com/miurahr/aqtinstall). Modules: `qtdeclarative qttools qtserialport qt5compat qtmultimedia qtspeech qtimageformats svg`. Put Qt on a **different drive** than this source (a qmake quirk — otherwise the build fails in `dfu`).
- **MSVC 2019** build tools + [`jom`](https://wiki.qt.io/Jom)
- **[Ollama](https://ollama.com)** + the `qwen2.5:7b` model (~4.7 GB). A GPU with ≥6 GB VRAM is recommended (runs on CPU too, just slower).

## 🔨 Build

```bat
git clone <your-fork-url> --recursive qFlipper-src
cd qFlipper-src
:: optionally override the defaults: set QT_DIR=...  set VS_VCVARS=...  set JOM=...
build_pink.bat
```

Output: `build\qFlipper.exe`. For the first run, copy Qt's DLLs/plugins next to it with `windeployqt`:

```bat
"%QT_DIR%\bin\windeployqt.exe" --qmldir application build\qFlipper.exe
```

After that, `build_pink_inc.bat` is the fast incremental build for code/QML changes.

## 🐬 Set up LOTEI (the AI + voice)

1. **Ollama** — install it, then: `ollama pull qwen2.5:7b`
2. **Piper voice** — run the setup script, pointing it at the folder that holds `qFlipper.exe`:
   ```powershell
   ./setup-lotei.ps1 -AppDir .\build
   ```
   This downloads Piper + a few neural voices into `<AppDir>\piper\`.
3. **(Optional) Music** — drop `.mp3` files into `<AppDir>\Music\`.
4. Make sure `ollama serve` is running, then launch `qFlipper.exe`. LOTEI wakes up and says hi. 🐬

> LOTEI auto-discovers any extra Piper `.onnx` voices you drop into `piper\voices\` — grab more from the [Piper voices catalog](https://huggingface.co/rhasspy/piper-voices). Click his voice name to cycle them.

## 🧩 What was added on top of qFlipper

Most LOTEI work lives in `application/`: `loteibackend.{h,cpp}` (the AI backend, the agentic tools, the local/cloud provider switch, the personality presets, Piper TTS, and the `LoteiPalette` color engine), `components/LoteiChat.qml` (the chat panel, screen mirror, and cloud-settings popup), `components/MusicPlayer.qml`, and the color editor in `components/MainWindow.qml`.

One capability reaches deeper: **`launch_app`** wires the Flipper's `App.StartRequest` protobuf message — which ships in the firmware but qFlipper never exposed — through every layer (`plugins/flipperproto0/apprequest.*`, `ProtobufPluginInterface::appStart`, the `flipperproto0` plugin, `ProtobufSession::appStart`, and `backend/flipperzero/rpc/appstartoperation.*`). The base project structure is otherwise unchanged from [upstream qFlipper](https://github.com/flipperdevices/qFlipper#project-structure).

## 🙏 Credits

- **[qFlipper](https://github.com/flipperdevices/qFlipper)** — Flipper Devices (the base app this forks)
- **[Piper](https://github.com/rhasspy/piper)** — Michael Hansen / rhasspy (neural TTS)
- **[Ollama](https://ollama.com)** + **[Qwen2.5](https://github.com/QwenLM/Qwen2.5)** — the local LLM stack

## 📜 License

**GPLv3**, inherited from qFlipper — see [LICENSE](LICENSE). This is an independent, unofficial fork. "Flipper Zero" and "qFlipper" are trademarks of Flipper Devices Inc.; this project is not affiliated with them.
