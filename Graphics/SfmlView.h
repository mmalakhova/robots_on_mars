#pragma once

#include "IView.h"
#include <memory>
#include <chrono>

namespace sf
{
class RenderWindow;
class Text;
class Font;
}

namespace merc
{

class TerrainView;

class SfmlView final : public IView
{
public:
    SfmlView();
    virtual ~SfmlView();

    virtual const std::string& ScanConsole() override;

    virtual void Render(const Player& player) override;

    virtual void Present() override;

    virtual void Open() override;

    virtual void Close() override;
private:

    void CreateContext();

    std::unique_ptr<sf::RenderWindow> m_window;
    std::unique_ptr<sf::Text> m_consoleText;
    std::unique_ptr<sf::Text> m_score;
    std::unique_ptr<sf::Font> m_font;
    std::unique_ptr<TerrainView> m_terrain;

    std::string m_consoleInput;

    enum ConsoleCommand : unsigned char
    {
        Backspace = 8,
        Enter = 13,

        Count,
    };

    std::chrono::steady_clock::time_point m_lastPresent;
};

}
