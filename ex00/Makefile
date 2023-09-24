NAME = convert
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -MMD -MP

# CXXFLAGS +=-fsanitize=undefined

SRCS = main.cpp \
	ScalarConverter.cpp

OBJS = $(SRCS:.cpp=.o)

DEPS = $(SRCS:.cpp=.d)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $(NAME)

clean:
	$(RM) $(OBJS) $(DEPS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

-include $(DEPS)
# ヘッダーがない時でもそのまま使う


# -MMD
# このオプションは、
# ソースファイルから依存関係ファイル（通常は .d という拡張子）を生成します。
# これによって、ヘッダーファイルが変更された場合に、
# それに依存するソースファイルだけが再コンパイルされるようになります。
# これはビルド時間の短縮に役立ちます。

# -MP
# このオプションは、
# -MMD または類似のオプションと一緒に使うことが多いです。
# -MP は "Phony Target" を生成するもので、
# 依存関係ファイル内に存在する各ヘッダーファイルに対して、
# 何もしない（empty）ルールを生成します。
# これは、ヘッダーファイルが削除された際にmakeが失敗するのを防ぐために使用されます。

# $^ は特殊な変数で、
# ターゲットの依存関係リスト（この場合、$(OBJS)）のすべての項目を参照します。