## Testing the vpinball wine vbscript engine isolated

https://github.com/vpinball/vpinball

https://gitlab.winehq.org/wine/wine

### Development

This project requires meson to build. This in turn requires python3 and ninja-build. The test framework requires ruby 🙄

```
meson subprojects download
meson setup buildDir
meson test -C buildDir -v
```