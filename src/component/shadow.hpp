#pragma once

/* there used to be shadow class here, initially added in
 * https://github.com/CardinalModules/DrumKit/commit/0d20223f84753e46d28990a63b89cd14406ea32f
 *
 * due to incompatible license it was removed and recreated from scratch
 */

struct DKShadow {
  static constexpr const float kMargin = 40.f;
  static constexpr const float kRadius = 12.f;

  Rect _box = { 0.f, 0.f };
  Vec _pos = { 0.f, 0.f };
  float _size = 0.65f;
  float _strength = 1.f;

public:
  void setBox(const Rect& box) {
    _box = box;
  }

  void setShadowPosition(float x, float y) {
    _pos = Vec(x, y);
  }

  void setSize(float size) {
    _size = size;
  }

  void setStrength(float strength) {
    _strength = strength;
  }

  void draw(NVGcontext* vg) {
    const NVGcolor col = settings::preferDarkPanels
                       ? nvgRGBAf(0.3f, 0.3f, 0.3f, _strength)
                       : nvgRGBAf(0.f, 0.f, 0.f, _strength);

    nvgBeginPath(vg);
    nvgRect(vg, -kMargin/2, -kMargin/2, _box.size.x + kMargin, _box.size.y + kMargin);
    nvgFillPaint(vg, nvgBoxGradient(vg,
                                    _box.size.x / 3 + _pos.x,
                                    _box.size.y / 3 + _pos.y,
                                    _box.size.x * _size,
                                    _box.size.y * _size,
                                    kRadius,
                                    kRadius,
                                    col,
                                    nvgRGBAf(0.f, 0.f, 0.f, 0.f)));
    nvgFill(vg);
  };
};
