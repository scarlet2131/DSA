def solve():
    # Read the number of recipes
    N = int(input())
    
    # Dictionary to store the recipe for each potion
    recipe_dict = {}
    
    # Read the recipes and fill the recipe dictionary
    for _ in range(N):
        recipe = input().strip()
        potion, ingredients = recipe.split("=")
        ingredients = ingredients.split("+")
        recipe_dict[potion] = ingredients
    
    # The potion we need to brew
    target_potion = input().strip()
    
    # Memoization dictionary to store the minimum magical orbs required for each potion
    potion_cache = {}
    
    # Function to calculate the minimum number of magical orbs for a given potion
    def min_orbs(potion):
        # If we've already computed the result for this potion, return the cached value
        if potion in potion_cache:
            return potion_cache[potion]
        
        # If the potion doesn't have a recipe (i.e., it's an ingredient), it requires 0 orbs
        if potion not in recipe_dict:
            potion_cache[potion] = 0
            return 0
        
        # Get the ingredients of the potion
        ingredients = recipe_dict[potion]
        
        # Calculate the number of magical orbs required for each ingredient recursively
        total_orbs = 0
        for ingredient in ingredients:
            total_orbs += min_orbs(ingredient)
        
        # The orbs required to brew this potion is the number of ingredients minus 1
        potion_cache[potion] = total_orbs + len(ingredients) - 1
        
        return potion_cache[potion]
    
    # Calculate and print the minimum orbs for the target potion
    print(min_orbs(target_potion))


solve()