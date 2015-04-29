#ifndef MATCHERGENERATOR_H
#define MATCHERGENERATOR_H

#include "css/cssselector.h"
#include "matchers.h"

/**
 * The MatcherGenerator allows building a @see Matcher from a css selector.
 *
 * The following selectors and combinations of selectors are currently supported
 *
 * id-selector ( #id ): Matches objectName property of a QObject @see NameMatcher
 * type-selector ( Type ): Matches the cpp class name or the Qml  @see QmlTypeMatcher
 * attribute-selector equals ( [attr=value] ): Matches a property by equality @see PropertyMatcher
 * pseudo-selector  ( :last-child, :first-child, :nth-child(1) ): Matches by index in parent @see IndexedMatcher
 * universal-selector ( * ) : Matches any node @see AnyMatcher
 * compound-selector child ( A B ) : Matches children B that have A as their parent @see
 *
 * combined selectors: Any combinations of the selectors above @see AndMatcher
 *
 *
 * TODO:
 *  pseudo-selector ( :not ) - can have any kind of selector inside
 *  pseudo-selector ( :nth-child, :nth-last-child ) - pretty strange & complex rules, eg. 1n2
 *  compound-selector direct child ( A > B )
 *  compound-selector sibling ( A + B )
 *  attribute-selector substring ( [attr~=value] )
 *  attribute-selector regexp ( ? )
 *
 */
class MatcherGenerator : public css::SelectorMatcherGenerator
{
public:
    /**
     * Convinience method to parse the given css selector and generate matchers from it.
     * Will always create a new MatcherGenerator and css::CssSelector instance, so might
     * not be best suited for batch creation or frequent parsing.
     *
     * @param selector The allowed css selectors
     * @param error The error, true if something fails
     * @return the list of matchers that were generated
     */
    static MatcherList parse(const QString& selector, bool* error);

    /// Creates a new, empty matcher generator to be used with @see css::CssSelector
    MatcherGenerator();
    /// Destructor
    virtual ~MatcherGenerator();

    /**
     * Returns the list of matchers that were generated
     * @return the generated matchers
     */
    MatcherList results() const;

private:
    // Clears all the intermediate steps and allows reusing the matcher generator for another parse
    void clear();
    // combines current and new matcher with AND
    void updateCurrentMatcher(SharedMatcher newMatcher);

    // resulting list of all matchers
    MatcherList m_resultingMatchers;
    // current matcher
    SharedMatcher m_currentMatcher;
    // current compound matcher
    SharedMatcher m_currentCompoundMatcher;


// SelectorMatcherGenerator interface
private:
    void cssparser_begin();

    void cssparser_handle_new_selector_list();
    void cssparser_handle_new_compound_selector();

    void cssparser_handle_universal_selector();
    void cssparser_handle_pseudo_class_selector(const std::string *pseudo_class);
    void cssparser_handle_pseudo_class_function_selector(const std::string *pseudo_class, const std::string *function);
    void cssparser_handle_id_selector(const std::string *id);
    void cssparser_handle_class_selector(const std::string *cssclass);
    void cssparser_handle_type_selector(const std::string *type);
    void cssparser_handle_empty_attribute_selector(const std::string *attribute);
    void cssparser_handle_attribute_selector(const std::string *attribute, const std::string *cssoperator, const std::string *value);

    void cssparser_finish(bool okay);

    friend class css::CssSelector;
};


#endif // MATCHERGENERATOR_H

