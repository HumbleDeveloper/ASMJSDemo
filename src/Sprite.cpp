//
//  Sprite.cpp
//  HumbleASMJSDemo
//
//  Created by Edward Rudd on 2/25/15.
//
//

#include "Sprite.h"
#include "Renderer.h"

Sprite::Sprite(TextureRef texture)
    : m_texture(texture),
    m_size(m_texture->size().as<float>()),
    m_angle(0.0f),
	m_frame(0),
	m_has_frames(false)
{
}

void Sprite::set_size(const Vector2f& size)
{
	// TODO validate that m_size is cleanly divisible into texture size?
	m_has_frames = (m_size != size);
	m_size = size;
}

void Sprite::render(Renderer& rend)
{
	if (m_has_frames) {
		Recti src = frame_rect(m_frame);
		Recti dst = Rectf((m_position - m_center), m_size).as<int>();
		rend.draw_texture(m_texture, src, dst, m_angle);
	} else {
		rend.draw_texture(m_texture, (m_position - m_center).as<int>(), m_angle);
	}
}

Recti Sprite::frame_rect(int frame)
{
	int pos_x, pos_y, frame_y;
	pos_x = frame * m_size.x;
	frame_y = pos_x / m_texture->width();
	pos_x %= m_texture->width();
	pos_y = frame_y * m_size.y;
	if ((pos_y + m_size.y) > m_texture->height()) {
		return Recti(m_size.as<int>());
	}
	return Recti(pos_x, pos_y, m_size.x, m_size.y);
}

void Sprite::move_position_by(const Vector2f &adjust_position)
{
    m_position += adjust_position;
}