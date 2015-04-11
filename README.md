# QML Selector

Simple, CSS Selector Engine for QML objects

## Supported selectors

The following selectors and combinations of selectors are currently supported

 - id-selector ( #id ): Matches objectName property of a QObject @see NameMatcher
- type-selector ( Type ): Matches the cpp class name or the Qml  @see QmlTypeMatcher
- attribute-selector equals ( [attr=value] ): Matches a property by equality @see PropertyMatcher
- pseudo-selector  ( :last-child, :first-child, :nth-child(1) ): Matches by index in parent @see IndexedMatcher
- universal-selector ( * ) : Matches any node @see AnyMatcher
     compound-selector child ( A B ) : Matches children B that have A as their parent @see
- combined selectors: Any combinations of the selectors above @see AndMatcher
