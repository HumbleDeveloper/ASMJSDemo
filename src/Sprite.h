//
//  Sprite.h
//  HumbleASMJSDemo
//
//  Created by Edward Rudd on 2/25/15.
//
//

#pragma once

#include "Renderable.h"
#include "Texture.h"

#include "Vector2.h"
#include "Rect.h"

class Sprite : public Renderable {
    TextureRef m_texture;
    Vector2f m_position;
    Vector2f m_size;
    Vector2f m_center;
    float m_angle;
	int m_frame;
	bool m_has_frames;
public:
    Sprite(TextureRef m_texture);
    virtual void render(Renderer& rend);

    void set_position(const Vector2f& position) { m_position = position; }
    const Vector2f& position() const { return m_position; }
    void move_position_by(const Vector2f& adjust_position);

    void set_angle(float angle) { m_angle = angle; }
    float angle() { return m_angle; }
    void rotate_by(float angle) { m_angle += angle; }

    void set_center(const Vector2f& center) { m_center = center; }
    const Vector2f& center() const { return m_center; }

	void set_size(const Vector2f& size);
    const Vector2f& size() const { return m_size; }

	void set_frame(int frame) { m_frame = frame; }
	int frame() { return m_frame; }
	Recti frame_rect(int frame);

    Rectf bounds() const {
        return Rectf(m_position - m_center, m_size);
    }
};