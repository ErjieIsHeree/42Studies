def validate_ingredients(ingredients: str) -> str:
    ingredients_l = ingredients.split(" ")
    for ingredient in ingredients_l:
        match ingredient:
            case "fire" | "water" | "earth" | "air":
                pass
            case _:
                return f"{ingredients} - INVALID"
    return f"{ingredients} - VALID"
