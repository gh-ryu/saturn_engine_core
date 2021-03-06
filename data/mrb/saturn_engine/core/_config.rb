# This script is run at engine initialization
saten_mrb_glyph_init(5) # number of glyph sets
# ID | Filename | Number of glyphs | Number of colors |
# Glyph width | Glyph Height | Animated set?
saten_mrb_load_glyph_file(0, "data/img/saturn_engine/glyph_symbol.png",
                          46, 16, 16, 16, false)
saten_mrb_load_glyph_file(1, "data/img/saturn_engine/glyph_latin.png",
                          53, 16, 16, 16, false)
saten_mrb_load_glyph_file(2, "data/img/saturn_engine/glyph_hiragana.png",
                          80, 16, 16, 16, false)
# Icons and animated icons have to be loaded with 0 colors
saten_mrb_load_glyph_file(3, "data/img/saturn_engine/glyph_icon.png",
                          5, 0, 16, 16, false)
saten_mrb_load_glyph_file(4, "data/img/saturn_engine/glyph_anime.png",
                          3, 0, 16, 16, true)

Saten::Text.set_glyph_height(16)

#Saten::Text.new("。\\G[3:0:1]\\G[3:0:1]\\G[4:0:0]Test Zeile 1\n\\C[2]Zeile 2\n\\C[3]Zeile 3!\\C[0]。", 1.0, 0, 120)
#Saten::Text.new("hello world 2", 1.0, 0, 200)
#Saten::Text.new("hello world 3。「」", 1.0, 0, 220)

#Saten::Text.update(1, nil, 1.0, 0, 200)
#

def myfunc(str)
  return str
end

#Saten::Text.remap(1, 2) // Use this to simulate multiple fonts

Saten::Text.modfnc_reg("myfunc")
